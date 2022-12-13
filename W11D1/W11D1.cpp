#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Expression { // Expression class
    private:
        int operand1;
        int operand2;
        char operator1;

    public:
        Expression(int operand1, int operand2, char operator1) : // Class constructor
            operand1(operand1), operand2(operand2), operator1(operator1) {
        }

        char getOperator() { // Returns member operator
            return operator1;
        }

        int getResult() {    // Calculates and returns member expression result
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

        virtual string toString() { // Virtual toString() to be compatible with/overriden by NamedExpression
            stringstream out;
            out << operand1 << "\t" << operator1 << "\t" << operand2 << "\t=\t" << getResult();
            return out.str();
        }
};

class NamedExpression : public Expression { // NamedExpression class inheriting from Expression class
    private:
        string name;
        Expression *e;

    public:
        NamedExpression(string _name, int _operand1, int _operand2, char _operator1) : 
        name(_name), Expression(_operand1, _operand2, _operator1) {
        }

        virtual string toString() {          // Virtual toString() overrides Expression class toString() method
            stringstream out;                // Uses Expression::toString() in overriden declaration
            out << Expression::toString() << "\tNAME(" << name << ")"; 
            return out.str();
        }
};

class ExpressionManager { // Manages array of Expression* objects
    private:
        int length;         // Tracks length of current array
        Expression** arr;   // Array pointer that points to the array of Expression* objects
    
    public:
        ExpressionManager() : length(0) { // Default constructor
            arr = new Expression*[length];
        }

        void push_back(Expression* e) { // Adds a new element to the array
            this->length += 1;          // Increments length of array because an element is being added
            // Dynamically allocates new array of the new length (one larger than the previous length)
            Expression** newArray = new Expression*[length];
            for(int i = 0; i < length - 1; i++) { // Increments through the new array and sets all values
                newArray[i] = *(arr + i);         // before the last index equal to the values of the current array
            }

            newArray[length-1] = e;               // Sets value of the last index equal to the new Expression* being added
            arr = newArray;                       // Sets current array pointer to the newarray
        }

        Expression* get(int i) { // Returns the element of the array at the given index, i
            return *(arr + i);
        }

        int size() { // Returns the size of the array
            return length;
        }
};

void getExpression(string &_name, int &_operand1, int &_operand2, char &_operator1) { // Creates a named or unnamed expression
    cout << "\tEnter an expression: ";  // Prompt user for an expression
    string input;
    getline(cin, input);
    stringstream sin(input);            // Save input in stringstream

    sin >> _name;                       // Temporary name
    sin >> _operator1;                  // Temporary operator
    stringstream operand(_name);
    switch(_operator1) {
        case '=': {                     // If operator is '=', then it is a named expression
            // Check if name does not begin with a letter:
            if(!(_name[0] >= 65 || _name[0] <= 90) || !(_name[0] >= 97 && _name[0] <= 122)) {
                cin.clear();            // Clears the input buffer + Error message below:
                cout << "\t\tInvalid name. To enter a name, write the name of the expression followed by equals, "
                     << "then the expression. Names must begin with an alphabetical character, upper or lower case. "
                     << "Try again.\n" << endl;
                return getExpression(_name, _operand1, _operand2, _operator1); // Recursion until user input is correct
            }

            sin >> _operand1;
            if(sin.fail()) {    // Handles input error for invalid first operand
                cin.clear();    // Clears the input buffer + Error message below:
                cout << "\t\tInvalid operand. Operands may only be integers. Try again.\n" << endl;
                return getExpression(_name, _operand1, _operand2, _operator1); // Recursion until user input is correct
            }
            
            sin >> _operator1;
            bool incOperator1 = _operator1 != '+' &&
                                _operator1 != '-' &&
                                _operator1 != '*' &&
                                _operator1 != '/' &&
                                _operator1 != '%';
            if(sin.fail() || incOperator1) {    // Handles input error for invalid operator or sin.fail()
                cin.clear();                    // Clears the input buffer + Error message below:
                cout << "\t\tInvalid operator \'" << _operator1 << "\'. Operators may only be \'+\', \'-\', \'*\', \'/\', "
                     << "or \'%\'. Try again.\n" << endl;
                return getExpression(_name, _operand1, _operand2, _operator1); // Recursion until user input is correct
            }
            break;
        }

        case '+':
        case '-':
        case '*':
        case '/':
        case '%': {
            _name = "";
            operand >> _operand1;
            if(operand.fail()) {    // Handles input error for invalid first operand
                cin.clear();        // Clears the input buffer + Error message below:
                cout << "\t\tInvalid operand. Operands may only be integers. Try again.\n" << endl;
                return getExpression(_name, _operand1, _operand2, _operator1); // Recursion until user input is correct
            }
            break;
        }

        default: {
            operand >> _operand1;
            if(!operand.fail()) {   // Checks if user attempted named or unnamed expression; displays according errors:
                cin.clear();        // Clears the input buffer
                // Error message for empty operator (incomplete expression):
                if(!_operator1) cout << "\t\tIncomplete expression. Expressions must be entered like this: <operand1> "
                                         << "<operator> <operand2>. Try again.\n" << endl;
                // Error message for invalid operator (incomplete expression):
                else cout << "\t\tInvalid operator \'" << _operator1 << "\'. Operators may only be \'+\', \'-\', \'*\', "
                          << "\'/\', or \'%\'. Try again.\n" << endl;
                return getExpression(_name, _operand1, _operand2, _operator1); // Recursion until user input is correct
            }
            else {
                cin.clear();        // Clears the input buffer + Error message for incomplete named expression below:
                cout << "\t\tIncomplete named expression. Named expressions must be entered like this: <name> = "
                     << "<expression>. Also, names must begin with an alphabetical character, upper or lower case. Try "
                     << "again.\n" << endl;
                return getExpression(_name, _operand1, _operand2, _operator1); // Recursion until user input is correct
            }
            break;
        }
    }

    sin >> _operand2;
    if(sin.fail()) {    // Handles input error for invalid second operand
        cin.clear();    // Clears the input buffer + Error message below:
        cout << "\t\tIncomplete or invalid operand. Operands may only be integers. Try again.\n" << endl;
        return getExpression(_name, _operand1, _operand2, _operator1); // Recursion until user input is correct
    }
}

void add(ExpressionManager &array) { // Adds an expression to the array
    int    operand1, operand2;       // Simple expression variables
    char   operator1;
    string name;

    cin.ignore();                     // Prepare input buffer for expression input
    getExpression(name, operand1, operand2, operator1); // Returns expression by reference

    // Depending on if name is empty, an Expression* or NamedExpression* pointer is created and added to the array
    if(!name.length()) array.push_back(new Expression(operand1, operand2, operator1));
    else array.push_back(new NamedExpression(name, operand1, operand2, operator1));

    // Prints new expression
    cout << "\t\t" << array.get(array.size()-1)->toString() << endl; // .get() is used to index through the array
}

void listall(ExpressionManager &array) { // Prints all saved expressions
    if(array.size() == 0) {              // Ends method call if there are no expressions
        cout << "\tThere are no expressions. Please create some." << endl;
        return;
    }
    cout << "\tAll expressions: " << endl;
    for(int i = 0; i < array.size(); i++) { // Loops through the array and prints all expressions
        cout << "\t" << i + 1 << ":\t" << array.get(i)->toString() << endl; // .get() is used to index through the array
    }
}

void listbyoperator(ExpressionManager &array) { // Prints all expressions by given operator
    if(array.size() == 0) {                     // Ends method call if there are no expressions
        cout << "\tThere are no expressions. Please create some." << endl;
        return;
    }

    cout << "\tEnter an operator: ";             // Prompts user for expression to search for
    char operator1;
    cin >> operator1;
    bool incOperator1 = operator1 != '+' &&
                        operator1 != '-' &&
                        operator1 != '*' &&
                        operator1 != '/' &&
                        operator1 != '%';
    if(cin.fail() || incOperator1) {             // Handles input error for invalid operator or cin.fail()
        cin.clear();                             // Clears the input buffer
        cin.ignore(INT_MAX, '\n');
        cout << "\t\tInvalid operator \'" << operator1 << "\'. Operators may only be \'+\', \'-\', \'*\', \'/\', "
             << "or \'%\'. Try again.\n" << endl;
        return listbyoperator(array);             // Recursion until user input is correct
    }

    for(int i = 0; i < array.size(); i++) {       // Prints all expressions with the given operator
        // .get() is used to index through the array:
        if(array.get(i)->getOperator() == operator1) cout << "\t" << i + 1 << ":\t" << array.get(i)->toString() << endl;
    }
}

void listsummary(ExpressionManager &array) { // Prints all expression data
    if(array.size() == 0) {                  // Ends method call if there are no expressions     
        cout << "\tThere are no expressions. Please create some." << endl;
        return;
    }
    int addition = 0;                         // Counter for all addition expressions
    int subtraction = 0;                      // Counter for all subtraction expressions
    int multiplication = 0;                   // Counter for all multiplication expressions
    int division = 0;                         // Counter for all division expressions
    int modulus = 0;                          // Counter for all modulus expressions
    int max = -99999;                         // Temp max expression result
    int min = 99999;                          // Temp min expression result
    for(int i = 0; i < array.size(); i++) {   // Loop through the array
        switch(array.get(i)->getOperator()) { // Increment corresponding operator counter given expression operation
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
        // Sets new max if given expression result is larger than current max
        if(array.get(i)->getResult() < min) min = array.get(i)->getResult(); // .get() is used to index through the array
        // Sets new min if given expression result is smaller than current min
        if(array.get(i)->getResult() > max) max = array.get(i)->getResult(); // .get() is used to index through the array
    }

    cout << "\tTotal number of expressions: "<< array.size() << endl; // Prints data
    cout << "\t\tNumber of '+' expressions: " << addition << endl;
    cout << "\t\tNumber of '-' expressions: " << subtraction << endl;
    cout << "\t\tNumber of '*' expressions: " << multiplication << endl;
    cout << "\t\tNumber of '/' expressions: " << division << endl;
    cout << "\t\tNumber of '%' expressions: " << modulus << endl;
    cout << "\t\tLargest expression: " << max << endl;
    cout << "\t\tSmallest expression: " << min << endl;
}

void getCommand() { // Gets command from user and calls corresponding function
    cout << "Welcome to the named expression management program." << endl;

    ExpressionManager array; // ExpressionManager array object to store all expression objects
    bool off = false;        // Sentinal value
    while(!off) {
        // Prompts user for command
        cout << "\nPlease enter a command (add, listall, listbyoperator, listsummary, and exit): ";
        string command;
        cin >> command;
        
        if(command == "add") {                  // Calls 'add' function if 'add' command is entered
            add(array);
        }

        else if(command == "listall") {         // Calls 'listall' function if 'listall' command is entered
            listall(array);
        }

        else if(command == "listbyoperator") {  // Calls 'listbyoperator' function if 'listbyoperator' command is entered
            listbyoperator(array);
        }

        else if(command == "listsummary") {     // Calls 'listsummary' function if 'listsummary' command is entered
            listsummary(array);
        }

        else if(command == "exit") {            // Calls 'exit' function if 'exit' command is entered
            cout << "\n\tThank you! Goodbye." << endl;
            off = true;                         // Turns off sentinal value
        }

        else {  // Handles input error for command. Error occurs if 'add', 'listall', 'listbyoperator', 'listsummary', or 
                // 'exit' is not entered
            cin.clear(); // Clears the input buffer + Error message below:
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\tUnsupported command. Valid commands include \'add\', \'listall\', \'listbyoperator\', \'listsummary\', "
                 << "and \'exit\'. Try again." << endl;
        }
    }
}

int main() {
    getCommand();   // Gets command from user and runs program
    return 0;
}