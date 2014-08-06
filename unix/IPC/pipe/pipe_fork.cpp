#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char**argv)
{
	int pipes[2] = {0,0};
	pid_t fork_fg;
	const char writeBuffer[] = "just test by zhangwuyi";
	char readBuffer[1024];

	memset(readBuffer, '\0', sizeof(readBuffer));
	if( -1 == pipe(pipes)){
		perror("create pipe error");	
		return EXIT_FAILURE;
	}

	fork_fg = vfork();
	cout << "********** fork_fg : " << fork_fg << endl;
	if( -1 == fork_fg) {
		perror("fork error");	
		exit(EXIT_FAILURE);
	}else if(0 == fork_fg){
		//和 pipe_write.cpp配套使用.
		char buffer[BUFSIZ] = {0};
		memset(buffer, '\0', sizeof(buffer));
		sprintf(buffer, "%d", pipes[1]);	
		close(pipes[0]);
		execl("write", "write", buffer, (char*)0);

	//	write(pipes[1], writeBuffer, sizeof(writeBuffer));
		close(pipes[1]);
		exit(EXIT_SUCCESS);
	}else {	
		close(pipes[1]);
		wait(NULL);

		read(pipes[0], readBuffer, sizeof(readBuffer));
		close(pipes[0]);

		cout << "read from child: " << endl << readBuffer << endl;
	}

	return EXIT_SUCCESS;
}
