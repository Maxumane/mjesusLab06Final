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