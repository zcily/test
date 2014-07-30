#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

int main(int argc, char**argv)
{
    if(argc != 3){
        cout <<  "Please entery the file name !!!" << endl;
        return EXIT_FAILURE;
    }

    ifstream testFile(*(argv + 1), ios::in | ios::binary | ios::ate);
    if(testFile.good())
        cout << "open file success" << endl;
    else
        cout << "open file fail!!!" << endl;

    int end = testFile.tellg();
    cout << "the begin location is " << end << endl;
    testFile.seekg(0, ios::beg);

    char temp[end + 1];
    memset(temp, 0, sizeof(temp));

    testFile.read(temp, end);

    cout << "the file content  : " << temp << endl;

    return EXIT_SUCCESS;
}
