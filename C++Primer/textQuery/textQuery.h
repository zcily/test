#ifndef __TEXTQUERY_H__
#define __TEXTQUERY_H__

#include <memory>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

namespace MyTextQuery
{
    class queryResult
    {
        friend ostream & operator<<(ostream& out, const queryResult&);
        public:
            using line_no = vector<string>::size_type;
            queryResult(const string &findValue, shared_ptr<set<line_no>> LN, shared_ptr<vector<string>> fileName);
        private:
            string sought;
            shared_ptr<set<line_no>> lines;
            shared_ptr<vector<string>> file;
    };

    class textQuery
    {
        public:
            textQuery(ifstream &fileName); 
            queryResult query(const string &) const;
        private:
            using line_no = vector<string>::size_type;
            shared_ptr<vector<string>> textFile;
            map<string, shared_ptr<set<line_no>>> wm;
    };
};

#endif
