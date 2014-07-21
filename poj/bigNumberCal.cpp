#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <ctype.h>

using namespace std;


void add(const string & baseNumber, const string& otherNumber)
{
	unsigned int baseintNumber[100] = {0};
	unsigned int basefloatNumber[100] = {0};

	unsigned int otherIntNumber[100] = {0};
	unsigned int otherFlNumber[100] = {0};

	unsigned int resultInt[101] = {0};
	unsigned int resultFl[100] = {0};

	memset(baseintNumber, 0, 100);
	memset(basefloatNumber, 0, 100);
	memset(otherIntNumber, 0, 100);
	memset(otherFlNumber, 0, 100);
	memset(resultInt, 0, 100);
	memset(resultFl, 0, 100);

	string baseIntegerNumberString; 
	string baseFloatNumberString;
	string otherIntegerNumberString;
	string otherFloatNumberString;
	int beyoneValue = 0;
// parse number to array
	if(baseNumber.find(".") != -1) {
		baseIntegerNumberString = baseNumber.substr(0, baseNumber.find("."));
		baseFloatNumberString = baseNumber.substr(baseNumber.find(".") + 1, baseNumber.size());	
	}else {
		baseIntegerNumberString = baseNumber;	
		baseFloatNumberString = string("0");
	}

	for(int i = 0; i < baseIntegerNumberString.size(); ++i){
		baseintNumber[i] = baseIntegerNumberString.at(baseIntegerNumberString.size() - i - 1) - '0';
	}

	for(int i = baseFloatNumberString.size() - 1; baseFloatNumberString.size() != 0 && i >= 0; --i){
		basefloatNumber[100 - i - 1] = baseFloatNumberString.at(i) - '0';
	}

	if(otherNumber.find(".") != -1) {
		otherIntegerNumberString = otherNumber.substr(0, otherNumber.find("."));
		otherFloatNumberString = otherNumber.substr(otherNumber.find(".") + 1, otherNumber.size());	
	}else{
		otherIntegerNumberString = otherNumber;	
		otherFloatNumberString = string("0");
	}

	for(int i = 0; i < otherIntegerNumberString.size(); ++i){
		otherIntNumber[i] = otherNumber.at(otherIntegerNumberString.size() - i - 1) - '0';
	}

	for(int i = otherFloatNumberString.size() - 1; otherFloatNumberString.size() != 0 && i >= 0; --i){
		otherFlNumber[100 - i - 1] = otherFloatNumberString.at(i) - '0';
	}
//-- end parse number to array	

// cal the value
	for(int i = max(baseFloatNumberString.size(), otherFloatNumberString.size()); i > 0; --i){

		if(i == 1){
			beyoneValue = (basefloatNumber[100 - i] + otherFlNumber[100 - i] + resultFl[100 - i]) / 10;
		}else {
			resultFl[100 - i + 1] = (basefloatNumber[100 - i] + otherFlNumber[100 - i] + resultFl[100 - i]) / 10;
		}
		resultFl[100 - i] = (basefloatNumber[100 - i] + otherFlNumber[100 - i] + resultFl[100 - i]) % 10;
	}

	for(int i = 0; i < max(baseIntegerNumberString.size(), otherIntegerNumberString.size()); ++i){
		if(i == 0)
			resultInt[i] = beyoneValue;
		resultInt[i+1] = (baseintNumber[i] + otherIntNumber[i] + resultInt[i]) / 10;
		resultInt[i] = (baseintNumber[i] + otherIntNumber[i] + resultInt[i]) % 10;
	}
// show the result
	for(int i = 0; i <= max(baseIntegerNumberString.size(), otherIntegerNumberString.size()); ++i){
		cout << resultInt[max(baseIntegerNumberString.size(), otherIntegerNumberString.size()) - i];
	}
	cout << ".";

	for(int i = 0; i <= max(baseFloatNumberString.size(), otherFloatNumberString.size()); ++i){
		cout << resultFl[100 - i - 1];	
	}
	cout << endl;
}	

bool checkEnteryIsRight(const string& baseNumber, const string &otherNumber)
{
	for(string::const_iterator it = baseNumber.begin(); it != baseNumber.end(); ++it) {
		if(*it == '.')
			continue;

		if(!isdigit(*it)){
			return false;	
		}
	}

	for(string::const_iterator it = otherNumber.begin(); it != otherNumber.end(); ++it) {
		if(*it == '.')
			continue;

		if(!isdigit(*it)){
			return false;	
		}
	}

	return true;
}
int main(int argc, char**argv)
{
	string baseNumber;
	string otherNumber;

	while(cin >> baseNumber >> otherNumber) {
		if(!checkEnteryIsRight(baseNumber, otherNumber)){
			cout << "please entery the right number again!!!" << endl;
			cin.clear();
			continue;
		}
		add(baseNumber, otherNumber);
	}
	return EXIT_SUCCESS;
}
