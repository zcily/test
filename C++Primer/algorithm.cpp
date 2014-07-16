#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;
#if 0
void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    vector<string>::iterator end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string&a, const string &b){return a.size() > b.size();});
}

#endif
void count_string_number()
{
    map<string, size_t> word_count;
    
    string word;
    while(cin >> word)
        ++word_count[word];

    for(map<string, size_t>::iterator mapTest = word_count.begin(); mapTest != word_count.end(); ++mapTest) {
        cout << mapTest->first << "  :  " << mapTest->second << endl;
    }
}

const string &tranform(const string &s, const map<string, string> &m){
    map<string, string>::const_iterator temp = m.find(s);
    if(temp != m.end()){
        cout << "find the key : " << s << "  value : " << temp->second << endl;
    }else{
        cout << "not find the key value !!!"  << endl;
    }
}

void word_transform()
{
    ifstream orignalFile;

    orignalFile.open("newFile", ios::in);

    map<string, string>trans_map;

    string key, value;

    while(orignalFile >> key && getline(orignalFile, value)){
        if(value.size() > 1)
            trans_map[key] = value.substr(1);
    }

    string text;
    while(getline(cin, text)){
        istringstream str(text);
        string word;
        while(str>>word){
            cout << "word :: *" << word << "*" << endl;
            tranform(word, trans_map);
        }
    }
}

int main(int argc, char**argv)
{
    vector<int> test;
    
    for(int i = 0; i < 100; ++i) {
        if(i>= 50 && i <=60)
            test.push_back(51); 
        else 
            test.push_back(i); 
    }

    vector<int>::iterator value = find(test.begin(), test.end(), 55);

    cout << "the value " << ((value == test.end()) ? "not find " : " find : ");
    if(value != test.end())
        cout << "  " << *value;
    cout << endl;

    int count_number = count(test.begin(), test.end(), 51);
    cout << "********** the count : " << count_number << endl;

    list<string> testStringList;

    for(int i = 0; i < 100; ++i) {
        testStringList.push_back(string("100")); 
    }
    //count_string_number();

    word_transform();
    return 0;
}
