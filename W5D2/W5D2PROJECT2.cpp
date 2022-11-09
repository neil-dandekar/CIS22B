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
        string toString() {
            stringstream out;
            out << operand1 << "     " << operator1 << "     " << operand2 << " = " << getResult();
            return out.str();
        }

        int getResult() {
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
};

void add() {
    cout << "Enter an expression: " << endl;
    int operand1, operand2;
    char operator1;
    stringstream sin;
    sin >> operand1 >> operator1 >> operand2;
    cout << sin.str();
}

string getCommand() {
            cout << "Please enter a command (add, listall, listbyoperator, listsummary, and exit): " << endl;
            string command;
            cin >> command;
            if(command == "add") {
                add();
            }
            else if(command == "listall") {

            }
            else if(command == "listbyoperator") {
                
            }
            else if(command == "listsummary") {
                
            }
            else if(command == "exit") {
                
            }
            else {
                return "";
            }
        }

int main() {
    cout << "Welcome to expression management program." << endl;
    return 0;
}