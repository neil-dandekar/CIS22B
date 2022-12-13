// QUESTION 1, 2, & 3:
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string toUpper(string s) { // Function I created to convert passed string to uppercase
    for(int i = 0; i < s.length(); i++) if(s[i] > 90) s[i] -= 32;   // If ASCII code for character is greater than 90 (lowercase),
    return s;                                                       // then subtract 32 (uppercase)
}

class VarNameException : public runtime_error { // Creates invalid variable name exception
    public:
        VarNameException(string errMsg) : runtime_error(errMsg) {
        }
};

class Variable {
    private:
        string name;
        string description;

    public:
        Variable(string _name, string _description) :     // Constructor method
            name(_name), description(_description) {
            // Checks if does not start with a letter + throws error with according message:
            if(!(_name[0] >= 65 || _name[0] <= 90) || !(_name[0] >= 97 && _name[0] <= 122)) {
                throw new VarNameException("Invalid name. Name must begin with a letter. Try again.");
            }
            // Checks if name contains a space + throws error with according message:
            else if(_name.find(" ") != string::npos ) {
                throw new VarNameException("Invalid name. Name cannot contain spaces. Try again.");
            }
        }

        virtual string toString() {                     // Returns Variable object as string
            stringstream out;
            out << "VAR(" << name << ") DESC(" << description << ")";
            return out.str();
        }

        virtual bool contains(string search) {          // Searches if the search string occurs in object's name or description
            return (toUpper(this->name).find(toUpper(search)) != string::npos) || 
                (toUpper(this->description).find(toUpper(search)) != string::npos);
        }
};

class VariableString: public Variable { // Class VariableString inherits from class Variable
    private:
        string value;

    public:
        VariableString(string name, string description, string value) :     // Constructor method
            Variable(name, description), value(value) {
        }

        string toString() {                 // Returns VariableString object as string;
            stringstream out;               // uses parent class toString() method
            out << Variable::toString() << " VALUE(" << this->value << ")";
            return out.str();
        }

        bool contains(string search) {      // Searches if the search string occurs in object's name, 
                                            // description, or value; uses parent toString() method
            return Variable::contains(search) || (toUpper(this->value).find(toUpper(search)) != string::npos);
        }
};

Variable* createVariableObject() { // Creates Variable or VariableString object (dynamically) from user input
    string _name, _description, _value;                 // Input variables
    cout << "\nEnter your variable's name: ";           // Prompts user for variable name
    getline(cin, _name);                                // Stores input into variable 
    cout << "Enter your variable's description: ";      // Prompts user for variable description
    getline(cin, _description);                         // Stores input into variable 
    cout << "Enter your variable's value (Optional): "; // Prompts user for variable value (Optional)
    getline(cin, _value);                               // Stores input into variable 

    if(!_value.length()) return new Variable(_name, _description);  // Checks if a value was entered then accordingly
    else return new VariableString(_name, _description, _value);    // returns either Variable or VariableString pointer
}

int main() {
    // QUESTION 1, 2, & 3 OUTPUT:
    bool validName = false; // Sentinal value
    while(!validName) {     // Loops until valid name is entered
        // Try/Catch block to handle invalid name error(s)
        try {
            // Creates new variable object but can throw VarNameException exception:
            Variable* v = createVariableObject();
            // Informs user of success and prints new object if no exceptions are thrown:
            cout << "\nSuccess! Here is your new variable: " << v->toString() << endl;
            validName = true; // End loop because valid name was entered
        }
        catch(VarNameException *e) {
            cout << "\n" << e->what() << endl; // Prints the error message when caught
        }
    }
    return 0;
}