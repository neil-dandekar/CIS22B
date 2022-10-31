#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void printMenu() {
  cout << "Expression Menu:\n   1. Enter a new expression\n   2. Show the largest expression\n   3. Show all expressions\n   4. Exit " << endl;
}

int getUserChoice() {
  printMenu();
  int userChoice;
  while (true) {
    cout << "\nEnter Option: ";
    cin >> userChoice;

    if (cin.fail() == false)
      return userChoice;
    cout << "Please try again. Only numbers 1, 2, 3, or 4 are valid." << endl;
  }
}

string Choice1() {
  int operand1;
  char operation;
  int operand2;
  string expression;

  cout << "Please enter an expression: ";
  cin >> expression;
  stringstream sin(expression);
  sin >> operand1;
  sin >> operand2;
  /*
  getline(sin, operation);
  cout << operand1 << endl;
  cout << operation << endl;
  cout << operand2 << endl;
  if (sin.fail()) {
    cout << "\nPlease try again. Only numerical operands and operators (+, -, *, "/, or %) are valid." << endl;
    Choice1();
  }
  */

  if (operation == '+') {
    return to_string(operand1) + " + " + to_string(operand2) + " = " + to_string(operand1 + operand2);
  }

  else if (operation == '-') {
    return to_string(operand1) + " - " + to_string(operand2) + " = " + to_string(operand1 - operand2);
  }

  else if (operation == '*') {
    return to_string(operand1) + " * " + to_string(operand2) + " = " +
           to_string(operand1 * operand2);
  }

  else if (operation == '/') {
    return to_string(operand1) + " / " + to_string(operand2) + " = " +
           to_string(operand1 / operand2);
  }

  else if (operation == '%') {
    return to_string(operand1) + " % " + to_string(operand2) + " = " +
           to_string(operand1 % operand2);
  }

  cout << "bruhPlease try again. Only numerical operands and operators (+, -, *, "
          "/, or %) are valid."
       << endl;
  Choice1();
}

/*
string Choice2() {
  return "";
}

string Choice3() {
    return "";
}

string Choice4() {
    return "";
}
*/

void evaluateChoice(int userChoice) {
  switch (userChoice) {
  case 1:
    Choice1();
    break;
  case 2:
    // Choice2();
    break;
  case 3:
    // Choice3();
    break;
  case 4:
    exit(0);
  }
}

int main() {
    cout << "Welcome to the Expression Recording Program" << endl;
    while (true) {
        evaluateChoice(getUserChoice());
    }
    return 0;
}
