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

	cout << "output by get value : " << endl;
	for(size_t i = 0; i < temp.list_length(); ++i){
		cout << "__" << temp[i];
	}
	cout << endl;

	cout << "dsdddd " << endl;
	for(size_t i = 0; i < temp.list_length(); ++i){
		cout << "__" << temp[i];
	}
	cout << endl;

	temp.show();


	temp.sort();

	linkList<int> test2;
	for(int i = 35; i < 66; ++i){
		test2.push_tail(i);
		++i;
	}
	cout << "temp : " << endl;
	temp.show();
	cout << "test2 : " << endl;
	test2.show();
	
	temp.mergeList(test2);

	return EXIT_SUCCESS;
}
