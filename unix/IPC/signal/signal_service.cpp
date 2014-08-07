#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <wait.h>

#include "signal_common.h"

using namespace std;

int main(int argc, char**argv)
{
	int ser_fd = 0;
	int cli_fd = 0;
	int fk_pid = 0;
	message msg;
	char service_fifo_write[CONTENT_BUFFER] = {0};
	char service_fifo_read[CONTENT_BUFFER] = {0};

	memset(&msg, 0, sizeof(message));
	memset(service_fifo_write, '\0', sizeof(service_fifo_write));
	memset(service_fifo_read, '\0', sizeof(service_fifo_read));


	if(mkfifo(SER_FIFO_INFO, 0777) && errno != EEXIST) {
		perror("create the ser fifo error : ");	
		return EXIT_FAILURE;
	}

	if(-1 == (ser_fd = open(SER_FIFO_INFO, O_RDONLY))){
		perror("open ser fifo error : ");	
		return EXIT_FAILURE;
	}

	if(-2 == read(ser_fd, &msg, sizeof(message))){
		perror("ser read from client error ");	
		return EXIT_FAILURE;
	}

	cout << "client pid : " << msg.client_pid << "  content : " << msg.data << endl;

	if((fk_pid = fork()) == -1){
		perror("in service fork erro : ");	
		exit(EXIT_FAILURE);
	}else if(0 == fk_pid){
		int service_fifo_write_fd = 0;
		char write_buffer[CONTENT_BUFFER] = {0};

		memset(write_buffer, '\0', sizeof(write_buffer));

		sprintf(service_fifo_write, CLI_FIFO_INFO, msg.client_pid);
		sprintf(service_fifo_write, "%s_read", service_fifo_write);

		if(mkfifo(service_fifo_write, 0777) && errno != EEXIST){
			perror("create the client write error : ");	
			exit(EXIT_FAILURE);
		}

		if(-1 == (service_fifo_write_fd = open(service_fifo_write, O_WRONLY))){
			perror("service open error : ");
			exit(EXIT_FAILURE);
		}

		while(1){
			cin.getline(write_buffer, sizeof(write_buffer));

			write(service_fifo_write_fd, write_buffer, strlen(write_buffer) + 1);				

			if(0 == strncmp(write_buffer, "quit", strlen("quit"))){
				cout << "service quit" << endl;
				break;
			}
			memset(write_buffer, '\0', sizeof(write_buffer));
		}

		unlink(service_fifo_write);

	}else {
		int service_fifo_read_fd = 0;
		char read_buffer[CONTENT_BUFFER] = {0};

		memset(read_buffer, '\0', sizeof(read_buffer));

		sprintf(service_fifo_read, CLI_FIFO_INFO, msg.client_pid);
		sprintf(service_fifo_read, "%s_write", service_fifo_read);
		
		if(mkfifo(service_fifo_read, 0777) && errno != EEXIST){
			perror("create the client fifo error : ");	
			exit(EXIT_FAILURE);
		}

		if(-1 == (service_fifo_read_fd = open(service_fifo_read, O_RDONLY))){
			perror("service open fifo read fd error : ");	
			exit(EXIT_FAILURE);
		}

		while(1){
			if(-1 == read(service_fifo_read_fd, read_buffer, sizeof(read_buffer))){
				perror("service read error : ");	
				exit(EXIT_FAILURE);
			}

			if(0 == strncmp(read_buffer, "quit", strlen("quit"))){
				cout << "recvice from client quit"	 << endl;
				break;
			}

			cout << "read from client : " << read_buffer << endl;
			memset(read_buffer, '\0', sizeof(read_buffer));
		}
		waitpid(fk_pid, NULL, 0);
		unlink(service_fifo_read);
	}

	close(ser_fd);
	unlink(SER_FIFO_INFO);

	return EXIT_SUCCESS;
}
