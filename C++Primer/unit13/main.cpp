#include "employee.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace MyEmployEE;

int main(int argc, char**argv)
{
#if 0
    Employee test1("testone"); 
    Employee test2("testtwo");

    Employee test3 = test1;

    test1.show();
    test2.show();
    test3.show();

    HasPtr testS1("testS1");
    HasPtr testS2("testS2");

    testS1.show();
    testS2.show();

    testS1 = testS2;

    testS1.show();
    testS2.show();
#endif
    vector<HasPtr> temp;

		
    HasPtr test1("gb");
    HasPtr test2("md");
    HasPtr test3("dd");
    HasPtr test4("hd");
    HasPtr test5("fd");

	temp.push_back(test1);
	temp.push_back(test2);
	temp.push_back(test3);
	temp.push_back(test4);
	temp.push_back(test5);

	cout << "******************************" << endl << endl;
	for(vector<HasPtr>::iterator it = temp.begin(); it != temp.end(); ++it) {
		it->show();
	}
	cout << "******************************" << endl << endl;

	sort(temp.begin(), temp.end());

	cout << "***************new***************" << endl << endl;
	for(vector<HasPtr>::iterator it = temp.begin(); it != temp.end(); ++it) {
		it->show();
	}
	cout << "***************new***************" << endl << endl;



    return EXIT_SUCCESS;
}
