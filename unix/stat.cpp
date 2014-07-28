#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

void showFileInfor(const char* direntName, const char* fileName)
{
	struct stat st;
	char completeFileName[1024]  = {0};
	memset(completeFileName, 0, sizeof(completeFileName));

	if(*direntName == '.' && *(direntName + 1) == '\0')
		sprintf(completeFileName, "%s", fileName);
	else
		sprintf(completeFileName, "%s%s", direntName, fileName);

	cout << completeFileName << endl;
	lstat(".", &st);
}

void myLs(const char* dirName)
{
	DIR* myDir;
	struct dirent* myFile;

	if(!dirName)
		return;

	myDir = opendir(dirName);

	while(myFile = readdir(myDir)) {
		if((myFile->d_name[0] == '.' && myFile->d_name[1] == '\0') || 
				myFile->d_name[0] == '.' &&  myFile->d_name[1] == '.' && myFile->d_name[2] == '\0' )
			continue;
		showFileInfor(dirName, myFile->d_name);
	}
}

int main(int argc, char**argv)
{	
	if(!argv[1])
		myLs(".");
	else 
		myLs(*(argv + 1));
	return EXIT_SUCCESS;
}
