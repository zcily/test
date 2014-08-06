#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

using namespace std;

#define CLI_FIFO_INFO "cli_%d_fifo"
#define SER_FIFO_INFO "ser_fifo"

const size_t BUFF_SIZE = 1024;
const size_t TEN_M  = (1024 * 10); 


struct message
{
	pid_t client_pid;
	char data[BUFF_SIZE];
};

#define TEST_CLIENT_AND_SERVICE 1

int main(int argc, char**argv)
{
	int fifo_fd = 0;
	int fifo_client_fd = 0;
	size_t data_send = 0;
	char buffer[BUFF_SIZE + 1] = {0};
	ssize_t read_length = 0;
	ssize_t write_length = 0;
	message msg;
	char client_fifo_info[1024];

	if(argc != 2) {
		cout << "you need to enter fifo name and mode(service or client)." << endl;
		return EXIT_FAILURE;
	}

	if(0 != access(SER_FIFO_INFO, F_OK)) {
		if(-1 == mkfifo(SER_FIFO_INFO, 0777)){
			perror("mkfifo error");	
			return EXIT_FAILURE;
		}
	}

	memset(buffer, '\0', sizeof(buffer));

	if(0 == strncmp(*(argv + 1), "client", strlen("client"))){
		if(-1 == (fifo_fd = open(SER_FIFO_INFO, O_WRONLY))){
			perror("open fifo file error ");	
			return EXIT_FAILURE;
		}
#if TEST_CLIENT_AND_SERVICE
		memset(client_fifo_info, '\0', sizeof(client_fifo_info));	
		msg.client_pid = getpid();
		cout << "the pid is : " << getpid() << endl;
		sprintf(client_fifo_info, CLI_FIFO_INFO, getpid());
		sprintf(msg.data, "send message by zwy\n");

		write(fifo_fd, &msg, sizeof(struct message));

		if(0 != access(client_fifo_info, F_OK)){
			if(-1 == mkfifo(client_fifo_info, 0777)){
				perror("mkfifo client fifo info");	
				return EXIT_FAILURE;
			}
		}

		if(-1 == (fifo_client_fd = open(client_fifo_info, O_RDONLY))){
			perror("open client fifo error");	
			return EXIT_FAILURE;
		}

		int res = 0;
		if((res = read(fifo_client_fd, &msg, sizeof(struct message))) > 0){
			cout << "the message is : "	 << msg.data << endl;
		}
#else
		while(data_send < TEN_M){
			sprintf(buffer, "test write fifo by program %d", data_send);
			if(-1 == (write_length = write(fifo_fd, buffer, strlen(buffer) + 1))) {
				perror("write data error ");	
				return EXIT_FAILURE;
			}
			data_send += write_length;
			memset(buffer, '\0', sizeof(buffer));
		}
#endif
	}else if(0 == strncmp(*(argv + 1), "service", strlen("service"))){
		if(-1 == (fifo_fd = open(SER_FIFO_INFO, O_RDONLY))){
			perror("read fifo file error ");
			return EXIT_FAILURE;
		}

#if TEST_CLIENT_AND_SERVICE
		memset(&msg, '\0', sizeof(message));
		int res = 0;
		if((res = read(fifo_fd, &msg, sizeof(struct message))) > 0){
			cout << "the message from   :  " << msg.client_pid << "  is : "	 << msg.data << endl;
		}

		sprintf(client_fifo_info, CLI_FIFO_INFO, msg.client_pid);

		//for ensure the client fifo is exist!!!
		if(0 != access(client_fifo_info, F_OK)){
			if(-1 == mkfifo(client_fifo_info, 0777)){
				perror("mkfifo client fifo info");	
				return EXIT_FAILURE;
			}
		}
		//write back;
		if(-1 == (fifo_client_fd = open(client_fifo_info, O_WRONLY))){
			perror("write client back error");	
			return EXIT_FAILURE;
		}

		write(fifo_client_fd, &msg, sizeof(message));
#else
		do{
			read_length = read(fifo_fd, buffer, sizeof(buffer));
			cout << "read data length : " << read_length << "   :  " << buffer << endl;
			memset(buffer, '\0', sizeof(buffer));
		}while(read_length > 0);
#endif
	}else {
		cout << "enter argv is wrong!!!" << endl;
	}

	close(fifo_fd);
	close(fifo_client_fd);
	unlink(SER_FIFO_INFO);
	unlink(client_fifo_info);

	return EXIT_SUCCESS;
}
