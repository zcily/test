#include <stdlib.h>

#include "Sales_data.h"

using namespace MySales;
using std::cout;
using std::endl;

int main(int argc, char**argv)
{
    salesData test("1", 100);
    salesData test2("2", 1220);
    test = test + test2;

    return EXIT_SUCCESS;
}
