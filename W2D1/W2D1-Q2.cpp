// QUESTION 2:
#include <iostream>

using namespace std;

int changeAllDigitsToTheGivenChar(char arr[], char ch, int &count) {
    int replaced = 0;                               // Number of characters replaced
    for(int i = 0; arr[i] != '\0'; i++) {           // Loop through C-string until it reaches null
        if(arr[i] == ch) {                          // Increment counter when array element is the 
            count++;                                // same as replacement character
        }
        else if(48 <= arr[i] && 57 >= arr[i]) {     // Replace array element if it is a number and 
            arr[i] = ch;                            // increment replaced
            replaced++;
        }
    }
    cout << "\nHere is the new array: " << arr << endl;
    return replaced;
}

int main() {
    char array[] = {'H', '1', '0', '2', 'o', '\0'}; // PLEASE CHANGE [Array to be tested]
    char ch = '?';                                  // PLEASE CHANGE [Replacement character]
    int count = 0;                                  // Number of array elements identical to ch
    int replaced = changeAllDigitsToTheGivenChar(array, ch, count);
    cout << replaced << " character(s) were replaced and \'" << ch << "\' occurred in the array " << count << " time(s)." << endl;
    return 0;
}