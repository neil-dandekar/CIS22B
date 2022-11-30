#include <iostream>
#include <sstream>

using namespace std;

void printMenu() {  // Prints the menu options
    cout << "\nExpression Menu:\n   1. Enter a new expression\n   2. Show the largest expression\n   3. Show all expressions\n   4. Exit \nEnter Option: ";
}

int getUserChoice() {       // Gets user's menu option choice
    int userChoice;
    bool off = false;
    while (!off) {          // Loop until valid choice is entered
        printMenu();
        cin >> userChoice;

        if(cin.fail()) {    // If cin fails, print error message and prompt for new input
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "\nPlease try again. Only numbers 1, 2, 3, or 4 are valid." << endl;
            return getUserChoice();     // Recursion; calls input again
        }
        off = true;         // End loop
        return userChoice;
    }
    return userChoice;
}

string makeExpression(int operand1, int operand2, char operator1, int &result) {    // Creates expression from operand1,
    stringstream out;                                                               // operator2, and operator2
    switch (operator1) {    // Switch block to generate result given the operator
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            result = operand1 / operand2;
            break;
        case '%':
            result = operand1 % operand2;
            break;
        default:
            break;
    }
    out << operand1 << "\t" << operator1 << "\t" << operand2 << "\t=\t" << result;
    return out.str();
}

string getExpression(int &result) {            // Gets expression from user input
    cout << "\tPlease enter an expression: ";  // Prompt user for an expression
    int operand1, operand2;
    char operator1;
    string expression;

    cin >> operand1;
    if(cin.fail()) {    // Handles input error for first operand
        cin.clear();    // Error occurs if cin.fail()
        cin.ignore(INT_MAX, '\n');
        cout << "\t\tInvalid operand. Operands may only be integers. Try again.\n" << endl;
        return getExpression(result);
    }
  
    cin >> operator1;
    bool incOperator1 = operator1 != '+' && operator1 != '-' &&
                        operator1 != '*' && operator1 != '/' && operator1 != '%';
    if(cin.fail() || incOperator1) {    // Handles input error for operator
        cin.clear();                    // Error occurs if cin.fail() or operator is not
        cin.ignore(INT_MAX, '\n');      // '+', '-', '*', '/', or '%'
        cout << "\t\tInvalid operator \'" << operator1 << "\'. Operators may only be \'+\', \'-\', \'*\', \'/\', or \'%\'. Try again.\n" << endl;
        return getExpression(result);
    }
    
    cin >> operand2;
    if(cin.fail()) {    // Handles input error for first operand
        cin.clear();    // Error occurs if cin.fail()
        cin.ignore(INT_MAX, '\n');
        cout << "\t\tInvalid operand. Operands may only be integers. Try again.\n" << endl;
        return getExpression(result);
    }
    
    return makeExpression(operand1, operand2, operator1, result);
}

void Choice1(stringstream &expressionList, int &maxResult, string &maxExpression) {     // Menu option 1
    int currentResult;
    string currentExpression = getExpression(currentResult);    // Gets new expression
    expressionList << "\t\t" << currentExpression << endl;      // Adds new expression to expressionList
    if(currentResult > maxResult) {                             // Determines the new largest expression if needed
        maxResult = currentResult;
        maxExpression = currentExpression;
    }
    cout << "\t\t" << currentExpression << endl;                // Prints the new expression
}

void Choice2(stringstream &expressionList, string maxExpression) {  // Menu option 2
    // Determines if there are no expressions and according tells the user
    if((expressionList.str()).length() == 0) cout << "\tThere are no expressions. Please enter an expression." << endl;
    // Otherwise, prints the maxExpression
    else cout << "\tLargest Expression:\n\t\t"  << maxExpression << endl;
}

void Choice3(stringstream &expressionList) {    // Menu option 3
    // Determines if there are no expressions and according tells the user
    if((expressionList.str()).length() == 0) cout << "\tThere are no expressions. Please enter an expression." << endl;
    // Otherwise, prints expressionList
    else cout << "\tAll Expressions:\n"  << expressionList.str();
}

void getCommand() {     // Gets command from user and calls corresponding menu option function
    stringstream expressionList;
    string maxExpression;
    string currentExpression;
    int maxResult = INT_MIN;
    int currentResult;
    cout << "Welcome to the Expression Recording Program" << endl;

    bool off = false;   // Sentinal value
    while(!off) {
        int userChoice = getUserChoice();   // Gets user menu optino
        switch(userChoice) {                // Switch block calling corresponding function based on userinput
            case 1:
                Choice1(expressionList, maxResult, maxExpression);
                break;
            case 2:
                Choice2(expressionList, maxExpression);
                break;
            case 3:
                Choice3(expressionList);
                break;
            case 4:
                cout << "\nThank you! Goodbye." << endl;
                off = true;                 // Turns off sentinal value
                break;
            default:
                cout << "\nInvalid option. Options are 1, 2, 3, or 4. Please try again." << endl;
        }
    }
}

int main() {
    getCommand();   // Gets command from user and runs program
    return 0;
}