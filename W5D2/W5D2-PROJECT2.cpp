#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Expression {
    private:
        int operand1;
        int operand2;
        char operator1;

    public:
        Expression(int operand1, int operand2, char operator1) :    // Class constructor
            operand1(operand1), operand2(operand2), operator1(operator1) {
        }

        char getOperator() {    // Returns member operator
            return operator1;
        }

        int getResult() {   // Calculates and returns member expression result
            switch (operator1) {
                case '+':
                    return operand1 + operand2;
                    break;

                case '-':
                    return operand1 - operand2;
                    break;

                case '*':
                    return operand1 * operand2;
                    break;

                case '/':
                    return operand1 / operand2;
                    break;

                case '%':
                    return operand1 % operand2;
                    break;
                
                default:
                    return 0;
                    break;
            }
            return 0;
        }

        string toString() {     // Returns expression as string
            stringstream out;
            out << operand1 << "\t" << operator1 << "\t" << operand2 << "\t=\t" << getResult();
            return out.str();
        }
};

void add(vector<Expression> &vect) {    // Adds an expression to vect
    cout << "\tEnter an expression: ";  // Prompt user for an expression
    int operand1, operand2;
    char operator1;

    cin >> operand1;
    if(cin.fail()) {    // Handles input error for first operand
        cin.clear();    // Error occurs if cin.fail()
        cin.ignore(INT_MAX, '\n');
        cout << "\t\tInvalid operand. Operands may only be integers. Try again.\n" << endl;
        return add(vect);
    }
    
    cin >> operator1;
    bool incOperator1 = operator1 != '+' &&
                        operator1 != '-' &&
                        operator1 != '*' &&
                        operator1 != '/' &&
                        operator1 != '%';
    if(cin.fail() || incOperator1) {    // Handles input error for operator
        cin.clear();                    // Error occurs if cin.fail() or operator is not
        cin.ignore(INT_MAX, '\n');      // '+', '-', '*', '/', or '%'
        cout << "\t\tInvalid operator \'" << operator1 << "\'. Operators may only be \'+\', \'-\', \'*\', \'/\', or \'%\'. Try again.\n" << endl;
        return add(vect);
    }
    
    cin >> operand2;
    if(cin.fail()) {    // Handles input error for first operand
        cin.clear();    // Error occurs if cin.fail()
        cin.ignore(INT_MAX, '\n');
        cout << "\t\tInvalid operand. Operands may only be integers. Try again.\n" << endl;
        return add(vect);
    }

    Expression e(operand1, operand2, operator1);    // Creates expression object from user input
    cout << "\t\t" << e.toString() << endl;         // Prints the new expression object
    vect.push_back(e);                              // Adds the expression object to vect
}

void listall(vector<Expression> vect) {     // Prints all saved expressions
    if(vect.size() == 0) {                  // Ends method call if there are no expressions
        cout << "\tThere are no expressions. Please create some." << endl;
        return;
    }
    cout << "\tAll expressions: " << endl;
    for(int i = 0; i < vect.size(); i++) {  // Loops through vect and prints all expressions
        cout << "\t\t" << i + 1 << ":\t\b\b\b\b\b" << vect[i].toString() << endl;
    }
}

void listbyoperator(vector<Expression> &vect) {     // Prints all expressions by given operator
    if(vect.size() == 0) {                          // Ends method call if there are no expressions
        cout << "\tThere are no expressions. Please create some." << endl;
        return;
    }

    cout << "\tEnter an operator: ";                // Prompts user for expression to search for
    char operator1;
    cin >> operator1;
    bool incOperator1 = operator1 != '+' &&
                        operator1 != '-' &&
                        operator1 != '*' &&
                        operator1 != '/' &&
                        operator1 != '%';
    if(cin.fail() || incOperator1) {                // Handles input error for operator
        cin.clear();                                // Error occurs if cin.fail() or operator is not
        cin.ignore(INT_MAX, '\n');                  // '+', '-', '*', '/', or '%'
        cout << "\t\tInvalid operator \'" << operator1 << "\'. Operators may only be \'+\', \'-\', \'*\', \'/\', or \'%\'. Try again.\n" << endl;
        return listbyoperator(vect);
    }

    for(int i = 0; i < vect.size(); i++) {          // Prints all expressions with the given operator
        if(vect[i].getOperator() == operator1) cout << "\t" << i + 1 << ":\t" << vect[i].toString() << endl;
    }
}

void listsummary(vector<Expression> vect) {         // Prints all expression data
    if(vect.size() == 0) {
        cout << "\tThere are no expressions. Please create some." << endl;
        return;
    }
    int addition = 0;                               // Counter for all addition expressions
    int subtraction = 0;                            // Counter for all subtraction expressions
    int multiplication = 0;                         // Counter for all multiplication expressions
    int division = 0;                               // Counter for all division expressions
    int modulus = 0;                                // Counter for all modulus expressions
    int max = -99999;                               // Temp max expression result
    int min = 99999;                                // Temp min expression result
    for(int i = 0; i < vect.size(); i++) {          // Loop through vect
        switch(vect[i].getOperator()) {             // Increment corresponding operator counter given expression operation
            case '+':
                addition++;
                break;

            case '-':
                subtraction++;
                break;

            case '*':
                multiplication++;
                break;

            case '/':
                division++;
                break;

            case '%':
                modulus++;
                break;
        }
        if(vect[i].getResult() < min) min = vect[i].getResult();        // Sets new max if given expression result is larger than current max
        if(vect[i].getResult() > max) max = vect[i].getResult();        // Sets new min if given expression result is smaller than current min
    }
    cout << "\tTotal number of expressions: "<< vect.size() << endl;    // Prints data
    cout << "\t\tNumber of '+' expressions: " << addition << endl;
    cout << "\t\tNumber of '-' expressions: " << subtraction << endl;
    cout << "\t\tNumber of '*' expressions: " << multiplication << endl;
    cout << "\t\tNumber of '/' expressions: " << division << endl;
    cout << "\t\tNumber of '%' expressions: " << modulus << endl;
    cout << "\t\tLargest expression: " << max << endl;
    cout << "\t\tSmallest expression: " << min << endl;
}

void getCommand() {             // Gets command from user and calls corresponding function
    cout << "Welcome to expression management program." << endl;

    vector<Expression> vect;    // Vector to store all expression objects
    bool off = false;           // Sentinal value
    while(!off) {
        cout << "\nPlease enter a command (add, listall, listbyoperator, listsummary, and exit): ";     // Prompts user for command
        string command;
        cin >> command;
        
        if(command == "add") {                  // Calls 'add' function if 'add' command is entered
            add(vect);
        }

        else if(command == "listall") {         // Calls 'listall' function if 'listall' command is entered
            listall(vect);
        }

        else if(command == "listbyoperator") {  // Calls 'listbyoperator' function if 'listbyoperator' command is entered
            listbyoperator(vect);
        }

        else if(command == "listsummary") {     // Calls 'listsummary' function if 'listsummary' command is entered
            listsummary(vect);
        }

        else if(command == "exit") {            // Calls 'exit' function if 'exit' command is entered
            cout << "\n\tThank you! Goodbye." << endl;
            off = true;                         // Turns off sentinal value
        }

        else {  // Handles input error for command. Error occurs if 'add', 'listall', 'listbyoperator', 'listsummary', or 'exit' is not entered
            cout << "\tUnsupported command. Valid commands include \'add\', \'listall\', \'listbyoperator\', \'listsummary\', and \'exit\'." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {
    getCommand();   // Gets command from user and runs program
    return 0;
}