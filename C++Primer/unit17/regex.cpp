#include <iostream>
#include <stdlib.h>
#include <string>
#include <regex>

using namespace std;

int main(int argc, char**argv)
{
	string pattern("^cei");

#if 1
	regex r(pattern);
	smatch results;

	string test_str = "receipt freind theif receive";
	if(regex_search(test_str, results, r))
		cout << results.str() << endl;
#endif
	return EXIT_SUCCESS;
}
