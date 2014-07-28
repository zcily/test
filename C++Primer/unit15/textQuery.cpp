#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include "textQuery.h"

namespace MyTextQuery
{
    queryResult::queryResult(const string &findValue, shared_ptr<set<line_no>> LN, shared_ptr<vector<string>> fileName)
        :sought(findValue)
        ,lines(LN)
        ,file(fileName)
    {
        cout << "get the init result  " << endl;
        cout << "sought :  " << this->sought << endl;
    }

    ostream & operator<<(ostream& out, const queryResult& QueryResult)
    {
        out << "the result : " << endl << QueryResult.sought << "  occurs " << QueryResult.lines->size() << "  times" << endl;

        set<vector<string>::size_type>::iterator it = QueryResult.lines->begin();

        for( ; it != QueryResult.lines->end(); ++it){
            out << "(line "  << *it + 1 << " ) " << QueryResult.file->at(*it) << endl;
        }
        return out; 
    }

    textQuery::textQuery(ifstream &fileName)
        : textFile(new vector<string>)
    {
        string tempText; 
        while(getline(fileName, tempText)) {
            textFile->push_back(tempText);
            istringstream wordLines(tempText); 
            int lineNumber = textFile->size() - 1;
            string word;
            while(wordLines >> word){
                shared_ptr<set<line_no>> &lines = wm[word];
                if(!lines)
                    lines.reset(new set<line_no>);
                lines->insert(lineNumber);
            }
        }
    }

    queryResult textQuery::query(const string &keyWords) const
    {
        static shared_ptr<set<line_no>> nulldata(new set<line_no>);

        map<string, shared_ptr<set<line_no>>>::const_iterator findWords = wm.find(keyWords);
        if(findWords != wm.end()) 
            return queryResult(keyWords, findWords->second, textFile);
        else
            return queryResult(keyWords, nulldata, textFile);
    }
};
