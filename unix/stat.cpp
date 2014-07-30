#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <time.h>

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
	if(lstat(".", &st) == -1) {
		perror("stat error!!!");	
		return;	
	}

	printf("File type:                ");

	switch (st.st_mode & S_IFMT) {
	case S_IFBLK:  printf("block device\n");            break;
	case S_IFCHR:  printf("character device\n");        break;
	case S_IFDIR:  printf("directory\n");               break;
	case S_IFIFO:  printf("FIFO/pipe\n");               break;
	case S_IFLNK:  printf("symlink\n");                 break;
	case S_IFREG:  printf("regular file\n");            break;
	case S_IFSOCK: printf("socket\n");                  break;
	default:       printf("unknown?\n");                break;
	}

	printf("I-node number:            %ld\n", (long) st.st_ino);

	printf("Mode:                     %lo (octal)\n",
		(unsigned long) st.st_mode);

	printf("Link count:               %ld\n", (long) st.st_nlink);
	printf("Ownership:                UID=%ld   GID=%ld\n",
		(long) st.st_uid, (long) st.st_gid);

	printf("Preferred I/O block size: %ld bytes\n",
		(long) st.st_blksize);
	printf("File size:                %lld bytes\n",
		(long long) st.st_size);
	printf("Blocks allocated:         %lld\n",
		(long long) st.st_blocks);

	printf("Last status change:       %s", ctime(&st.st_ctime));
	printf("Last file access:         %s", ctime(&st.st_atime));
	printf("Last file modification:   %s", ctime(&st.st_mtime));
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

int a = 0;
int main(int argc, char**argv)
{	
	if(!argv[1])
		myLs(".");
	else 
		myLs(*(argv + 1));
	return EXIT_SUCCESS;
}
