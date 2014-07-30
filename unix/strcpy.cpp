#include <iostream>
#include <stdlib.h>

using namespace std;

char* myStrcpy(char* desSrc, const char* orignalSrc)
{
	if(!desSrc || !orignalSrc  || (desSrc == orignalSrc))
		return NULL;

	char *temp = desSrc;

	while((*desSrc++ = *orignalSrc++) != '\0') {}
	return temp;
}

int main(int argc,char**argv)
{
	const char os[100] = {"faslfjaslfkja;slkfj;l"};
	char ds[100] = {0};

	cout << "****** " << ds << endl;

	myStrcpy(ds, os);

	cout << "***** " << ds << endl;

	return EXIT_SUCCESS;
}
