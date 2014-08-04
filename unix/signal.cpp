#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void catchSignal(int i)
{
	if(i == SIGUSR1)
		cout << "catch the signal user1" <<  endl;
	else if(i == SIGUSR2)
		cout << "catch the signal user2" << endl;
	else if(i == SIGQUIT)
		cout << "catch the quit signal" << endl;
	else if(i == SIGINT)
		cout << "catch the int signal" << endl;
	else if(i == SIGKILL)
		cout << "catch the kill signal" << endl;
}

int main(int argc, char**argv)
{
	signal(SIGUSR1, catchSignal);
	signal(SIGUSR2, catchSignal);
	signal(SIGQUIT, catchSignal);
	signal(SIGINT, catchSignal);
	signal(SIGKILL, catchSignal);

	for(;;){
		sleep(1);	
	}
	return EXIT_SUCCESS;
}
