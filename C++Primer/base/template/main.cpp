#include "template.h"
#include <stdlib.h>

using namespace MyTemplateClass;

int main(int argc, char**argv)
{
	testTemplate<int> t1;
	testTemplate<double> t2;

	cout << "1 value : " << t1.value() << endl;
	testCall(t1);
	testCall(t2);

	cout << "2 value : " << t1.value() << endl;	
	cout << "2 value : " << t2.value() << endl;	

	return EXIT_SUCCESS;
}
