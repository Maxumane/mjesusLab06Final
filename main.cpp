#include <iostream>
#include "Dictionary.hpp"


int main() {

    dictionary ten;
    int choice;
    bool endCon = false;
    while(!endCon) {
        cout << "1 - Print dictionary" << endl <<
             "2 - Find word definition" << endl <<
             "3 - Enter new word and definition" << endl <<
             "4 - Quit" << endl;
        cin >> choice;
        switch (choice) {

            case 1:
                ten.printWords();
                break;
            case 2:
                ten.getDefinition();
                break;
            case 3:
                ten.addWord();
                break;
            case 4:
                endCon = true;
                break;
        }
    }

    std::cout << "Quit" << std::endl;
    return 0;
}
