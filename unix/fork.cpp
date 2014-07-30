#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

using namespace std;

int main(int argc, char**argv)
{
	pid_t pid;
	int fd;
	int fd_creat;
	int file_size;
	int f_size;
	int c_size;

	char fileContent[4096]={0};
	char temp[100] = {0};

	memset(fileContent, '\0', sizeof(fileContent));
	memset(temp, '\0', sizeof(temp));

	if((fd = open("stat.cpp", O_RDONLY)) == -1){
		perror("open file error");	
		return EXIT_FAILURE;
	}

	if((file_size = lseek(fd, 0, SEEK_END)) == -1){
		perror("seek end");
		return EXIT_FAILURE;
	}
	lseek(fd, 0, SEEK_SET);

	f_size = 0;
	c_size = file_size / 2 + 1;

	if((fd_creat = open("stat.bak", O_CREAT | O_WRONLY, 0644)) == -1) {
		perror("creat stat.bak failed");	
		return EXIT_FAILURE;
	}
	printf("************** fd  : %d  fd_creat : %d\n", fd,fd_creat);

	if((pid = fork()) < 0) {
		perror("fork erro");	
		return EXIT_FAILURE;
	}else if(0==pid){
		int new_fd;

		if((new_fd = open("stat.cpp", O_RDONLY)) == -1){
			perror("open file error");	
			return EXIT_FAILURE;
		}

		int new_fd_creat;

		if((new_fd_creat = open("stat.bak", O_CREAT | O_WRONLY, 0644)) == -1) {
			perror("creat stat.bak failed");	
			return EXIT_FAILURE;
		}

		int position = c_size;	
		int read_size = 0;

		char child_temp[100] = {0};
		memset(child_temp, '\0', sizeof(child_temp));

		while(position != file_size){
			if( -1 == lseek(new_fd, position, SEEK_SET)){
				perror("seek in new_fd");	
				return EXIT_FAILURE;
			}
			if( (read_size = read(new_fd, child_temp, sizeof(child_temp))) == -1){
				perror("child read error");	
				return EXIT_FAILURE;
			}

			if( -1 == lseek(new_fd_creat, position, SEEK_SET)){
				perror("can not seek ");	
				return EXIT_FAILURE;
			}
			if( -1 == write(new_fd_creat, child_temp, read_size)){
				perror("write error");	
				return EXIT_FAILURE;
			}
			position += read_size;
			memset(child_temp, '\0', sizeof(child_temp));
		}
		cout << "int child over" << endl;
		close(new_fd);
		close(new_fd_creat);
	}else{
		int position = f_size;	
		int read_size = 0;

		while(position != (file_size / 2)){
			if( -1 == lseek(fd, position, SEEK_SET)){
				perror("seek in fd");	
				return EXIT_FAILURE;
			}
			if( (read_size = read(fd, temp, sizeof(temp))) == -1){
				perror("child read error");	
				return EXIT_FAILURE;
			}
			if( -1 == lseek(fd_creat, position, SEEK_SET)){
				perror("can not seek ");	
				return EXIT_FAILURE;
			}
			if( -1 == write(fd_creat, temp, read_size)){
				perror("write error");	
				return EXIT_FAILURE;
			}
			if(position + read_size >= file_size / 2)
				read_size = file_size / 2 - position;
			position += read_size;
			memset(temp, '\0', sizeof(temp));
		}	
		cout << "int father over" << endl;
		wait();	

		close(fd);
		close(fd_creat);
	}
	return EXIT_SUCCESS;
}
