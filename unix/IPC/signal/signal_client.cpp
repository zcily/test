#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <wait.h>

#include "signal_common.h"

using namespace std;

static void catch_signal(int signal_number)
{
	if(signal_number == SIGALRM){
			
	}else if(signal_number == SIGCHLD){
		cout << "the child progress quit"	 << endl;
	}
}

int main(int argc, char**argv)
{
	int ser_fd;
	int cli_fd;
	char client_fifo_info_read[CONTENT_BUFFER] = {0};
	char client_fifo_info_write[CONTENT_BUFFER] = {0};

	message msg;
	pid_t fk_pid;

	memset(&msg, 0, sizeof(message));
	memset(client_fifo_info_read, '\0', sizeof(client_fifo_info_read));
	memset(client_fifo_info_write, '\0', sizeof(client_fifo_info_write));

	if(mkfifo(SER_FIFO_INFO, 0777) && errno != EEXIST) {
		perror("create the ser fifo error : ");	
		return EXIT_FAILURE;
	}

	if(-1 == (ser_fd = open(SER_FIFO_INFO, O_WRONLY))){
		perror("open ser fifo error : ");	
		return EXIT_FAILURE;
	}

	msg.client_pid = getpid();
	sprintf(msg.data, "begin connect to service\n");
	
	if(-1 == write(ser_fd, &msg, sizeof(message))){
		perror("ser read from client error ");	
		return EXIT_FAILURE;
	}

	sprintf(client_fifo_info_read, CLI_FIFO_INFO, getpid());
	sprintf(client_fifo_info_read, "%s_read", client_fifo_info_read);

	if(mkfifo(client_fifo_info_read, 0777) && errno != EEXIST){
		perror("create the client fifo error : ");	
		return EXIT_FAILURE;
	}

	sprintf(client_fifo_info_write, CLI_FIFO_INFO, getpid());
	sprintf(client_fifo_info_write, "%s_write", client_fifo_info_write);

	if(mkfifo(client_fifo_info_write, 0777) && errno != EEXIST){
		perror("create the client write error : ");	
		exit(EXIT_FAILURE);
	}

	signal(SIGALRM, catch_signal);
	signal(SIGCHLD, catch_signal);

	if((fk_pid = fork()) == -1){
		perror("in client fork error : ");
		return EXIT_FAILURE;
	}else if(0 == fk_pid){

		int client_write_fd = 0;	
		char client_write_buffer[CONTENT_BUFFER] = {0};
		
		memset(client_write_buffer, '\0', sizeof(client_write_buffer));

		if( (client_write_fd = open(client_fifo_info_write, O_WRONLY)) == -1){
			perror("in child open client info erro write : ");		
			exit(EXIT_FAILURE);
		}

		while(1){
			cin.getline(client_write_buffer, sizeof(client_write_buffer));

			write(client_write_fd, client_write_buffer, strlen(client_write_buffer) + 1);

			if(0 == strncmp(client_write_buffer, "quit", strlen("quit"))){
				cout << "client quit" << endl;
				break;	
			}
			memset(client_write_buffer, '\0', sizeof(client_write_buffer));
		}

		unlink(client_fifo_info_write);
	}else {			
		int client_read_fd = 0;
		char client_read_buffer[CONTENT_BUFFER] = {0};
		int readLength = 0;

		memset(client_read_buffer, '\0', sizeof(client_read_buffer));	

		if( (client_read_fd = open(client_fifo_info_read, O_RDONLY)) == -1){
			perror("in child open client info erro : ");		
			exit(EXIT_FAILURE);
		}

		while(1){
			if((readLength = read(client_read_fd, client_read_buffer, sizeof(client_read_buffer))) == -1){
				perror("in client child read error : ");	
				exit(EXIT_FAILURE);
			}

			cout << "read from service : " << client_read_buffer << endl;

			if(0 == strncmp(client_read_buffer, "quit", strlen("quit"))){
				cout << "recvice quit command from service" << endl;
				break;
			}

			memset(client_read_buffer, '\0', sizeof(client_read_buffer));
		}

		waitpid(fk_pid, NULL, 0);
		unlink(client_fifo_info_read);
	}

	close(ser_fd);
	unlink(SER_FIFO_INFO);

	return EXIT_SUCCESS;
}
