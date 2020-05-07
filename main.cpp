//
// Created by wyatt on 4/30/2020.
//

#include <iostream>
#include <fstream>
#include <string>
#include "trivialMatching.h"
#include "boyerMoore.h"
#include "KMP.h"
#include "algorithm"
#include <chrono>

using namespace std::chrono;
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
    content.erase(remove(content.begin(), content.end(), '\n'), content.end());
    content.erase(remove(content.begin(), content.end(), ' '), content.end());
    string find;
    cout << "Please enter a search" << endl;
    cin >> find;
    find.erase(remove(find.begin(), find.end(), ' '), find.end());
    cout << "Searching for : " << find << endl;
    auto start = high_resolution_clock::now(); //start time
    trivialMatching trivial(content, find); //trivial algorithm
    auto end = high_resolution_clock::now(); //send time
    auto duration = duration_cast<nanoseconds>(end - start);
    int seconds = duration.count();
    cout << seconds << " microseconds" << endl;

    start = high_resolution_clock::now();
    boyerMoore BM(content, find); //boyerMoore algorithm
    end = high_resolution_clock::now(); //send time
     duration = duration_cast<microseconds>(end - start);
     seconds = duration.count();
    cout << seconds << " microseconds" << endl;

    start = high_resolution_clock::now();
    KMP kmp(content, find); //Knuth Morris Pratt algorithm
     end = high_resolution_clock::now(); //send time
     duration = duration_cast<microseconds>(end - start);
     seconds = duration.count();
    cout << seconds << " microseconds" << endl;







    cout << "Processes Finished" << endl;
    return 0;
}

