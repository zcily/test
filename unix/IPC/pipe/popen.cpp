#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
// just for test nullptr
class B
{
	public:
		B(int a){_a = a;};
		int _a;
};

const class nullptr_t
{
	public:
	    template<typename T> operator T*() const { return (T*)0; }
		template<typename C, typename T> operator T C::*() const { return (T C::*)0; }
	private:
		void operator&() const;
} nullptr = {};


int* np1 = nullptr;
int B::* test = nullptr;

//end test nullptr


int testPipeAboutRead(char**argv)
{
	FILE *pipe = nullptr;
	char readBuffer[1024] = {0};

	string readBufferString;

	memset(readBuffer, '\0', sizeof(readBuffer));
		
	if( !(pipe = popen(*(argv + 1), "r"))) {
		perror("popen error");
		return EXIT_FAILURE;
	}

	size_t result = 0;

	while((result = fread(readBuffer, sizeof(char), sizeof(readBuffer), pipe)))
	{
		cout << readBuffer;
		memset(readBuffer, '\0', sizeof(readBuffer));
	}

	cout << endl;
	pclose(pipe);

	return EXIT_SUCCESS;
}

int testPipeAboutWrite(char**argv)
{
	FILE* pipe = nullptr;
	const char writeBuffer[] = "Just test for out put";

	if(!(pipe = popen(*(argv + 1), "w"))){
		perror("popen error");	
		return EXIT_FAILURE;
	}

	fwrite(writeBuffer, sizeof(char), sizeof(writeBuffer), pipe);
				
	pclose(pipe);
	return EXIT_SUCCESS;
}

int main(int argc, char**argv)
{
	if(argc != 2)
		return EXIT_FAILURE;

	return testPipeAboutRead(argv);
	//return testPipeAboutWrite(argv);
}
