#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <stack>

using namespace std;

template <class T>
vector<int>::iterator find_value_by_iterator(vector<int>::iterator begin, vector<int>::iterator end, T value);

void test_add_value()
{
    vector<int> value;
    
    for(int i = 0; i < 10; ++i) {
        value.push_back(i); 
    }

    for(vector<int>::iterator begin = value.begin(); begin != value.end(); ) {
        if(!(*begin % 2)) {
            begin = value.insert(begin, *begin++); 
            begin += 2;
        }else {
            begin = value.erase(begin); 
        }
    }

    for(vector<int>::iterator begin = value.begin(); begin != value.end(); ++begin) {
        cout << "__"  << *begin;
    }
    cout << endl;
}

int main(int argc, char**argv)
{
    vector<int> num;

    for(int i = 0; i < 500; ++i) {
        num.push_back(i); 
    }

    vector<int>::iterator temp;
    temp = find_value_by_iterator(num.begin(), num.end(), 155);
    cout << "the value you want to find is : " << *temp << endl;
    test_add_value();
    return EXIT_SUCCESS;
}

template <class T>
vector<int>::iterator find_value_by_iterator(vector<int>::iterator begin, vector<int>::iterator end, T value)
{
    while(begin != end) {
        if(*begin == value) 
            break;
        ++begin;
    }
    return begin;
}
