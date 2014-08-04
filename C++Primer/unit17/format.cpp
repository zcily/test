#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(int argc, char**argv)
{
	// for bool
	
	cout << "************ no format :   true : " << true  << "  false : " << false << endl;
	cout << "************ format    : " << boolalpha <<  "  true : " << true  << "  false : " << false << endl;
	cout << "************ format    : " << "  true : " << true  << noboolalpha  << "  false : " << false << endl;

	cout << endl;
	// for octal hex decimal
	cout << showbase;	 // for example 0x 0
	// for uppercase
	cout << uppercase;
	cout << "************ default  : " << 20 << " " << 1024 << endl;
	cout << "************ octal    : " << oct << 20 << " " << 1024 << endl;
	cout << "************ hex      : " << hex << 20 << " " << 1024 << endl;
	cout << "************ decimal  : " << dec << 20 << " " << 1024 << endl;
	//clear the format
	cout << nouppercase;
	cout << noshowbase;

	// for float 
	cout << "Precision : " << cout.precision() << " , Value : " << sqrt(2.0) << endl;

	cout.precision(12);
	cout << "Precision : " << cout.precision() << " , Value : " << sqrt(2.0) << endl;
	cout.precision(3);
	cout << "Precision : " << cout.precision() << " , Value : " << sqrt(2.0) << endl;

	// for show point
	cout << 10.0 << endl;

	cout << showpoint << 10.0 << noshowpoint << "          " << 10.0 << endl;
	return EXIT_SUCCESS;
}
