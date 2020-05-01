//
// Created by wyatt on 4/30/2020.
//

#ifndef STRING_MATCHING_TRIVIALMATCHING_H
#define STRING_MATCHING_TRIVIALMATCHING_H

#include <iostream>
#include <string>
using namespace std;

class trivialMatching {
public:
    trivialMatching();
    void findMatches(string, string);
    bool checkRest(string, string, int&);

};


#endif //STRING_MATCHING_TRIVIALMATCHING_H
