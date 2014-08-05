#include <unistd.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  
#include <iostream>

using namespace std;

int main(int argc, char *argv[])  
{  
	int length = 0;  
	int file_descriptor;  
	const char buffer[] = "test from pipe write...";  

	cout << "write data begin" << endl;
	sscanf(argv[1], "%d", &file_descriptor);  
	length = write(file_descriptor, buffer, BUFSIZ);  

	cout << "write data over" << endl;

	return EXIT_SUCCESS;  
}
