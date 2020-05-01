//
// Created by wyatt on 4/30/2020.
//

#include "trivialMatching.h"
trivialMatching::trivialMatching() {
    cout << "Testing data set on trivial algorithm" << endl;
}

void trivialMatching::findMatches(string content, string find){
    int position = 0;
    bool match = false;
    while(position < content.length()) {
        if (content[position] == find[0]) { //if first letter matches
            match = checkRest(content, find, position);
            if(match){
                cout << "Match found start : " << position - find.length() + 1<< endl;
            }
        } else {
            position++; //else look at next charachter
        }
    }
}

bool trivialMatching::checkRest(string content, string find, int& position){  //checks if rest of string matches, updates position
    for(int i = 1; i < find.length(); i++){
        position++; //increment position
        if(content[position] != find[i]){
            return false; // if doesnt match exit loop and return false
        }
    }
    return true; // if all match return true
}