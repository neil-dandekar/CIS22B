// QUESTION 2:
#include <iostream>

using namespace std;

int changeAllDigitsToTheGivenChar(char (&arr)[], char ch, int &count) {
    int replaced = 0;
    for(int i = 0; arr[i] != '\0'; i++) {
        if(arr[i] == ch) {
            count++;
        }
        else if(48 <= arr[i] && 57 >= arr[i]) {
            arr[i] = ch;
            replaced++;
        }
    }
    return replaced;
}

int main() {
    char array[] = {'H', '1', '0', '2', 'o', '\0'}; // PLEASE CHANGE [Array to be tested]
    char ch = '?';     // PLEASE CHANGE [Replacement character]
    int count;
    int replaced = changeAllDigitsToTheGivenChar(array, ch, count);
    cout << "Here is the new array: " << array << " and " << replaced << " character(s) were replaced";
    return 0;
}