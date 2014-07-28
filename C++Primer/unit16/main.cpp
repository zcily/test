#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <list>

#include "blob.h"

using namespace std;
using namespace Myblob;

#if 0
template <typename T> int compare(const T & A, const T & B)
{
	if(A > B)
		return 1;
	else if (A < B)
		return -1;
	return 0;
}
#endif
template <unsigned N, unsigned M> int compare(const char (&p1)[N], const char (&p2)[M])
{
	cout << "lenth p1 " << strlen(p1) << " lenth p2 " << strlen(p2) << endl;
	return strncmp(p1, p2, min(strlen(p1), strlen(p2)));
}

template <typename T1, typename T> T1 Myfind(T1 begin, T1 end, const T& value)
{
	for(; begin != end; ++begin){
		if(*begin == value)	
			return begin;
	}
	return end;
}

void test16_4(void)
{
	vector<int> vt1;
	for(int i = 0; i < 100 ; ++i)
		vt1.push_back(i);

	int wantToFindValue = 0;
	cin >> wantToFindValue; 
	vector<int>::iterator findValue = Myfind(vt1.begin(), vt1.end(), wantToFindValue);
	if(vt1.end() != findValue)
		cout << "you want to find value is : " << *findValue << endl;
	else
		cout << "not find the value" << endl;

	list<string> lt1;
	char temp[100] = {0};
	memset(temp, '\0', sizeof(temp));
	for(int i = 0; i < 100; ++i) {
		snprintf(temp, sizeof(temp), "test%d", i);
		lt1.push_back(temp);
	}

	string wantTofindString;
	cin >> wantTofindString;

	list<string>::iterator findString = Myfind(lt1.begin(), lt1.end(), wantTofindString);
	if(lt1.end() != findString)
		cout << "you want to find string : " << *findString << endl;
	else
		cout << "not find the string" << endl;
}

template <typename T, unsigned N> void Myprint(const T (&array)[N])
{
	for(int i = 0; i < N; ++i) {
		cout << "_" << array[i];
	}
	cout << endl;
}

void test16_5(void)
{
	int intArray[10] = {0, 1,2 ,3 ,4,8,23,1};
	char charArray[14] = {'a','b','c','d','e','f',};

	cout << "**************************** print intArray **********************"<< endl;
	Myprint(intArray);
	cout << endl << "**************************** print charArray **********************"<< endl;
	Myprint(charArray);
}

void blob_test(void)
{
	Blob<string> test = {"a", "b", "c"};
	string temp("testing");
	test.push_back(temp);

	cout << test.back() << endl;
}

int main(int argc, char**argv)
{
	blob_test();	
	return EXIT_SUCCESS;
}
