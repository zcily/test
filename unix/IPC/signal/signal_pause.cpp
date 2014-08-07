#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

using namespace std;

static void catch_signal(int signal_number)
{
	cout << "recvice the signal " << signal_number << endl;
}

int main(int argc, char**argv)
{
	alarm(5);
	signal(SIGALRM, catch_signal);

	for(;;)	
	{
		cout << "befor pause" << endl;
		pause();	
		cout << "after pause" << endl;
		alarm(2);
	}
	return EXIT_SUCCESS;
}
