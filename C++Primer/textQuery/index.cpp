#include "textQuery.h"
#include <stdlib.h>
#include <fstream>

using namespace MyTextQuery;

int main(int argc, char**argv)
{
    if(argc != 3)
        return EXIT_FAILURE;
    cout << "*** file : " << *(argv + 1)  << " want to find value :  " << *(argv + 2)<< endl;
    ifstream MyFile(*(argv + 1)); 
    textQuery tq(MyFile);
    queryResult tr = tq.query(string(*(argv + 2)));
    cout << tr;
    return EXIT_SUCCESS;
}
