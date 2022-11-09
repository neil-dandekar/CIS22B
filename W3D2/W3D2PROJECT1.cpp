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

    // if(cin.fail()) {
    //   cout << "Please try again. Only numbers 1, 2, 3, or 4 are valid." << endl;
    //   cin.clear();
    //   cin.ignore(INT_MAX, '\n');
    //   return userChoice;
    // }
    return userChoice;
  }  
}

string Choice1() {
  int operand1;
  char operator1;
  int operand2;
  string expression;

  cout << "Please enter an expression: ";
  cin >> expression;
  stringstream sin(expression);
  sin >> operand1 >> operator1 >> operand2;
  cout << "Operator:  " << operator1 << endl;

  stringstream out;
  switch (operator1) {
    case '+':
      out << operand1 << " " << operator1 << operand2 << operand1 + operand2;
      break;
    case '-':
      out << operand1 << " " << operator1 << operand2 << operand1 - operand2;
      break;
    case '*':
      out << operand1 << " " << operator1 << operand2 << operand1 * operand2;
      break;
    case '/':
      out << operand1 << " " << operator1 << operand2 << operand1 / operand2;
      break;
    case '%':
      out << operand1 << " " << operator1 << operand2 << operand1 % operand2;
      break;
    
    default:
      break;

    return out.str();
  }
  return " ";
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
