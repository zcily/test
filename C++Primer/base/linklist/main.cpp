#include <iostream>
#include <stdlib.h>
#include "list.h"

using namespace std;
using namespace MyList;

int main(int argc, char**argv)
{
	linkList<int> temp(10);		

	for(int i = 55; i<60; ++i)
		temp.push_tail(i);

	for(int i = 10; i < 15; ++i)
		temp.push_head(i);

	temp.push_value_by_postion(101, 58);

	temp.show();

	temp.delete_value(13);

	temp.show();

	temp.modify_value(10, 11111);
	temp.show();

	int findValue = 0;
	cin >> findValue;

	cout << "want to find value : " << findValue << "   : " << (temp.find_value(findValue) ? "true" : "false") << endl;

	temp.clear_all_value();

	temp.show();

	temp.push_value_by_postion(151, 58);

	temp.show();

	return EXIT_SUCCESS;
}
