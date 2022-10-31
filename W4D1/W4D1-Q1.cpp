// QUESTION 1:
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    string word;                              // Placeholder for argv element
    for (int i = 1; i < argc; i++) {
        word = argv[i];                       // Saving current argv element to word variable
        if(word.find("/?") != string::npos || 
           word.find("/h") != string::npos || 
           word.find("-?") != string::npos) { // Checking if word contains "/?"", "/h", or "-?"
            cout << "true" << endl;           // Print true if it contains specified string
        }
        else cout << "false" << endl;         // Print false if it does not contain specified string
    }
}

// TEST CASE 1:
// /Users/neildandekar/Documents/VSCode\ Projects/CIS22B/WeekFourDayOne "/?" "ONE /?" "ONE /? TWO" "-?" "ONE -?" "ONE /h"

// TEST CASE 2:
// /Users/neildandekar/Documents/VSCode\ Projects/CIS22B/WeekFourDayOne "/" "/??" "ONE ?" "? H" "HH" "??" "ONE ?/"