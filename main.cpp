//
// Created by wyatt on 4/30/2020.
//

#include <iostream>
#include <fstream>
#include <string>
#include "trivialMatching.h"

using namespace std;
//checks if file open, if not prompt for user to enter one and retry
bool checkOpen(string& fileName, ifstream& file){
    if (file.is_open()) {
        return true;
    } else {
        cout << "Please enter a valid file name" << endl;
        cin >> fileName;
        file.open(fileName);
        return false;
    }
}

int main(){

    ifstream file;
    string filename = "text.txt";
    file.open(filename);// set file name (** Change to arg **)
    bool open = false;
    int count = 0;

    // checks if opens, prompts user to try again if fails
    while(!open && count < 10) { // maximum of 10 failed attempts
        open = checkOpen(filename, file); //function to check if open
        count ++;
    }

    if(count == 10){ // if maximum attempts reached, exit the program
        cout << "Maximum attempts reached. Exiting Program..." << endl;
        exit(-1);
    }

    //read in the whole text file into one string
    string content;
    content.assign( (istreambuf_iterator<char>(file) ),
                    (istreambuf_iterator<char>()    ) );

    //string test = "bedfgjsi sjdt bet sjdof beef sjiof sdofbetssfid";
    string find = "bet"; //string you are searching for

    trivialMatching trivial; // new object
    trivial.findMatches(content, find); // find matches method



    cout << "Processes Finished" << endl;
    return 0;
}

