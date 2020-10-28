//
// Created by Max on 2020-10-27.
//

#include <map>
#include <fstream>

#ifndef MJESUSLAB06FINAL_DICTIONARY_HPP
#define MJESUSLAB06FINAL_DICTIONARY_HPP

using namespace std;



class dictionary {
private:
    ifstream idictDoc {"../dictionary.txt"};
    ofstream odictDoc;// Opens data for writing
    map<string, string> wordMap;

public:
    dictionary();
    ~dictionary();
    void printWords();
    void getDefinition();
    void addWord();
};


#endif //MJESUSLAB06FINAL_DICTIONARY_HPP
