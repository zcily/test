#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

void testone()
{
    vector<string> test;
    string temp;
    while(cin >> temp ) {
        test.push_back(temp);
    }

    for(vector<string>::iterator begin = test.begin(); begin != test.end() ; ++begin){
        for(int j = 0; j < begin->size(); ++j) {
            (*begin)[j] = toupper((*begin)[j]);
        }
    }
    
    for(int i = 0; i < test.size(); ++i)
        cout << "__" << test.at(i);
    cout << endl;

}


void testtwo()
{
    vector<int> test;
    int temp = 0;
    while(cin >> temp)
        test.push_back(temp);


    for(int i = 0; i < test.size(); ++i) {
        if(i <= test.size() - 2)
            cout << test.at(i)  << "  +  " << test.at(i+1) << "  =  " << test.at(i) + test.at(i+1) << endl;
    }

    cout << "************************** \n\n\n";

    for(int i = 0; i < test.size() / 2; ++i) {
        cout << test.at(i) << "   +   " << test.at(test.size() - i - 1) <<  "   = "  << test.at(i) + test.at(test.size() - i - 1) << endl;
    }
}

void testthree()
{
    vector<int> test(10);
    
    int temp = 0;

    for(int i = 0;i < 10; ++i) {
        cin >> test[i];
    }

    for(int i = 0; i < test.size(); ++i){
        cout << (test.at(i) *= 2) << endl;
    }
}

void erfeng()
{
    vector<int> test;

    for(int i = 0; i < 50000; ++i){
        test.push_back(i); 
    }

    vector<int>::iterator begin = test.begin();
    vector<int>::iterator end   = test.end();

    vector<int>::iterator mid   = begin + (end - begin) / 2;
    vector<int>::iterator mid_old = mid;

    bool findValueFlag = true;
    int wantToFindValue = 0;
    cin >> wantToFindValue; 

    while(*mid != wantToFindValue){
        if(*mid > wantToFindValue){ 
            end = mid;
        }
        else {
            begin = mid + 1;
        }
        mid = begin + (end - begin) / 2;
        if(mid_old == mid) {
            findValueFlag = false;
            break;
        }
        mid_old = mid;
    }
    if(findValueFlag)
        cout << "the value you want to find is " << *mid << endl;
    else
        cout << "can not find the value" << endl;
}

int main(int argc, char**argv)
{
    erfeng();
    return 0;
}
