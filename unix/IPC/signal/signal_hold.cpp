#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

using namespace std;

static void catch_signal(int signal_number)
{
	if(signal_number == SIGCHLD){
		cout << "the child progress exit" << endl;
		exit(EXIT_SUCCESS);
	}
}

int main(int argc, char**argv)
{
	pid_t fk_pid;

	signal(SIGCHLD, catch_signal);

	if((fk_pid = vfork()) < 0){
		perror("vfork error : ");
		return EXIT_FAILURE;
	}else if(0 == fk_pid){
		for(int i = 0; i < 5; ++i){
			usleep(500 * 1000);	
			cout << "child sleeping" << endl;
		}
	}else{
		for(int i = 0; i < 10; ++i)	{
			usleep(500 * 1000);	
			cout << "father sleeping" << endl;
		}
	}

	return EXIT_SUCCESS;
}
