#include <iostream>
#include <stdlib.h>
#include <memory>
#include <string>

using namespace std;

struct zeroStruct
{
    int a;
    char test[0];
};
int main(int argc, char**argv)
{
    //shared_ptr<int> test = make_shared<int>(42);
    cout << "******** " << sizeof(zeroStruct) << endl;
    return EXIT_SUCCESS;
}
