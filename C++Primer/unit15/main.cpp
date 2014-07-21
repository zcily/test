#include "quote.h"
#include <stdlib.h>

using namespace MyVirtual;

int main(int argc, char**argv)
{
	Bulk_quote bq("testBook", 55, 100, 0.5);
	Quote& temp = bq;
	
	cout << "the price : " << temp.net_price(99)	<< endl;

	bq.test1(1);

	return EXIT_SUCCESS;
}
