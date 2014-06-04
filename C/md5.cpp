#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

struct md5_file
{ 
    char *md5_file_value;
    char *md5_file_name;
};


void find_same_value(md5_file *all_md5_file, int length) {
    vector<md5_file*> same_file;
    vector<vector<md5_file*> > same_files;
    bool first_find_flag = true;
    for(int i = 0; i < length; ++i) {
        for(int j = i; j < length; ++j) {
            if(j == i)
                continue;
            if(!strncmp(all_md5_file[i].md5_file_value, all_md5_file[j].md5_file_value, strlen(all_md5_file[i].md5_file_value))) {
                if(first_find_flag) {
                    same_file.push_back(&all_md5_file[i]); 
                    first_find_flag = false;
                }
                same_file.push_back(&all_md5_file[j]);
            }
        }
        if(!first_find_flag) {
            same_files.push_back(same_file);     
            same_file.clear();
            first_find_flag = true;
        }
    }

    if(0 == same_files.size()) {
        printf("\033[31mNot Find The Same Files!!!!!\033[0m\n");
        return;
    }

    for(vector<vector<md5_file*> >::iterator same_begin = same_files.begin(); same_begin != same_files.end();++same_begin){
        for(vector<md5_file*>::iterator s_file = (*same_begin).begin(); s_file != (*same_begin).end(); ++s_file) { 
            printf("*********same file name : %32s   value : %32s\n", (*s_file)->md5_file_name, (*s_file)->md5_file_value); 
        }
    }
}

int main(int argc, char**argv)
{
    md5_file testFile[1024];
    memset(&testFile, 0, 1024);
    char name[1024] = {0};
    char *value, *save_ptr, *temp;


    system("rm md5.txt");
    system("md5sum * > md5.txt");
    system("sed -i 's/  /$/g' md5.txt");

    ifstream read_file;
    read_file.open("md5.txt");
    int i = 0;
    
    while(read_file.good() && !read_file.eof()) {
        memset(name, 0, 1024);
        read_file.getline(name, 1024); 
        temp = name;
        int j = 0;
        for(j = 0, temp ; ; temp = NULL) {
            value = strtok_r(temp, "$", &save_ptr);
            if(!value)
                break;
            ++j;
            if(1 == j) {
                testFile[i].md5_file_value = new char[strlen(value) + 1];
                memset(testFile[i].md5_file_value, '0', strlen(value) + 1);
                strncpy(testFile[i].md5_file_value, value, strlen(value) + 1);
            }
            else if( 2 == j) {
                testFile[i].md5_file_name = new char[strlen(value) + 1];
                memset(testFile[i].md5_file_name, '0', strlen(value) + 1);
                strncpy(testFile[i].md5_file_name, value, strlen(value) + 1);
            }
        }
        ++i;
    }
    --i;
    find_same_value(testFile, i);
    return 0;
}
