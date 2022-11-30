// QUESTION 2:
#include <iostream>

using namespace std;

bool isSimpleDigitsAndBlanks(char* arr, int &numBlanks) {
    numBlanks = 0;      // Reset counter
    int notNum = 0;     // Number of characters that are not integers or blanks
    for(int i = 0; arr[i] != '\0'; i++) {               // Loop through C-String
        if(arr[i] == ' ') numBlanks++;                  // Increment numBlanks if current character is a blank
        else if(48 > arr[i] || arr[i] > 57) notNum++;   // Increment notNum if current character is not an integer
    }
    return notNum == 0;     // Return true if there were no non-integer characters
}

int main() {
    // TEST DATA:
    char arr1[] = "1";
    char arr2[] = "123";
    char arr3[] = " 123";
    char arr4[] = " 123 ";
    char arr5[] = "123 456 789";
    char arr6[] = "";
    char arr7[] = "A";
    char arr8[] = "1A";
    char arr9[] = " A";
    char arr10[] = " 1 A";
    char arr11[] = "123 456 ABC";
    int numBlanks;  // Number of blanks in the C-String

    // OUTPUT:
    cout << "| arr | allNums | #Blanks |" << endl;
    cout << "|  1  |  "  << boolalpha << isSimpleDigitsAndBlanks(arr1, numBlanks)  << "   |    " << numBlanks << "    |" << endl;
    cout << "|  2  |  "  << boolalpha << isSimpleDigitsAndBlanks(arr2, numBlanks)  << "   |    " << numBlanks << "    |" << endl;
    cout << "|  3  |  "  << boolalpha << isSimpleDigitsAndBlanks(arr3, numBlanks)  << "   |    " << numBlanks << "    |" << endl;
    cout << "|  4  |  "  << boolalpha << isSimpleDigitsAndBlanks(arr4, numBlanks)  << "   |    " << numBlanks << "    |" << endl;
    cout << "|  5  |  "  << boolalpha << isSimpleDigitsAndBlanks(arr5, numBlanks)  << "   |    " << numBlanks << "    |" << endl;
    cout << "|  6  |  "  << boolalpha << isSimpleDigitsAndBlanks(arr6, numBlanks)  << "   |    " << numBlanks << "    |" << endl;
    cout << "|  7  |  "  << boolalpha << isSimpleDigitsAndBlanks(arr7, numBlanks)  <<  "  |    " << numBlanks << "    |" << endl;
    cout << "|  8  |  "  << boolalpha << isSimpleDigitsAndBlanks(arr8, numBlanks)  <<  "  |    " << numBlanks << "    |" << endl;
    cout << "|  9  |  "  << boolalpha << isSimpleDigitsAndBlanks(arr9, numBlanks)  <<  "  |    " << numBlanks << "    |" << endl;
    cout << "|  10 |  "  << boolalpha << isSimpleDigitsAndBlanks(arr10, numBlanks) <<  "  |    " << numBlanks << "    |" << endl;
    cout << "|  11 |  "  << boolalpha << isSimpleDigitsAndBlanks(arr11, numBlanks) <<  "  |    " << numBlanks << "    |" << endl;
}