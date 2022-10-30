// QUESTION 1:
#include <iostream>

using namespace std;

int countTheFirstNumber(int &firstNum) {
  int count = 1; // Counter for number of times firstNum is repeated
  cout << "Enter a number: ";
  cin >> firstNum; // Assign firstNum with value of the first number
  
  if (firstNum == 0) { // If firstNum is 0, return count = 0;
    return count;
  }

  int currentNum;
  while(true) { // Loop asking for numbers from the users until 0 is entered
    cout << "Enter a number: ";
    cin >> currentNum;
    if (currentNum == 0) return count; // Return count if 0 is entered
    else if (currentNum == firstNum) count++; // Increment count if user enters value of firstNum
  }
  return count;
}

int main() {
  int num;
  int count = countTheFirstNumber(num);
  cout << "\nThe first number, " << num << " was entered " << count << " time(s)." << endl; // Print result
  return 0;
}