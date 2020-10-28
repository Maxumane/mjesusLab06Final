//
// Created by Max on 2020-10-27.
//

#include <iostream>
#include <algorithm>
#include "Dictionary.hpp"


dictionary::dictionary() {
    string word;
    string definition;
    int stringDecider = 1;
    while ((getline(idictDoc, word))) {
        if (word == "") {
            continue;
        }
        getline(idictDoc, definition);
        wordMap.insert(make_pair(word, definition));
    }
}


dictionary::~dictionary() {
    odictDoc.close();
    idictDoc.close();
}

void dictionary::printWords() {

    for(auto it = wordMap.begin(); it != wordMap.end(); ++it)
    {
        cout << it->first << " - " << it->second << endl;
    }

}

void dictionary::getDefinition() {
    string searchKey;
    cout << "Enter the word you're looking for." << endl;
    cin >> searchKey;
    std::for_each(searchKey.begin(), searchKey.end(), [](char & c){
        c = ::tolower(c);
    });
    map<string, string>::iterator oneNumber = wordMap.find(searchKey);



    if (oneNumber == wordMap.end()) {
        cout << "The word doesn't exist in the dictionary" << endl;
    } else {
        cout << oneNumber->first << " - " << oneNumber->second << endl;
    }
}


void dictionary::addWord() {
    string addKey;
    string definition;
    cout << "Enter the word you'd like to add" << endl;
    cin >> addKey;
    std::for_each(addKey.begin(), addKey.end(), [](char & c){
        c = ::tolower(c);
    });
    map<string, string>::iterator oneNumber = wordMap.find(addKey);
    while(oneNumber != wordMap.end()) {
        cout << "That world already exists in the dictionary, enter a new one." << endl;
        cin >> addKey;
        oneNumber = wordMap.find(addKey);
    }

    if (oneNumber == wordMap.end()) {
        cout << "Add definition below " << endl;
        cin.ignore();
        getline(cin, definition);
        wordMap.insert(make_pair(addKey, definition));
        odictDoc.open("../dictionary.txt", std::ios_base::app);


        odictDoc << addKey << endl << definition << endl;
        odictDoc.close();
    }
    cout << "Added" << endl;
}

