// QUESTION 1, 2, & 3:
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string toUpper(string s) {                                          // Function I created to convert passed string to uppercase
    for(int i = 0; i < s.length(); i++) if(s[i] > 90) s[i] -= 32;   // If ASCII code for character is greater than 90 (lowercase),
    return s;                                                       // then subtract 32 (uppercase)
}

class Variable {
    private:
        string name;
        string description;

    public:
        Variable(string name, string description) :     // Constructor method
            name(name), description(description) {
        }

        virtual string toString() {                     // Returns Variable object as string
            stringstream out;
            out << "VAR(" << name << ") DESC(" << description << ")";
            return out.str();
        }

        virtual bool contains(string search) {          // Searches if the search string occurs in object's name or description
            return (toUpper(this->name).find(toUpper(search)) != string::npos) || (toUpper(this->description).find(toUpper(search)) != string::npos);
        }
};

class VariableString: public Variable {     // Class VariableString inherits from class Variable
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

vector<Variable*> contains(vector<Variable*> vect, string search) {         // Returns a vector containing pointers to Variable
    vector<Variable*> vectContains;                                         // objects from the passed array which contain the
    for(int i = 0; i < vect.size(); i++) {                                  // search string; uses member contains() methods
        if(vect.at(i)->contains(search)) vectContains.push_back(vect[i]);
    }
    return vectContains;
}

int main() {
    // QUESTION 1 OUTPUT:
    Variable var1("isSuccessful", "successful flag indicator");

    cout << "QUESTION 1:" << endl;
    cout << "var1.toString(): " << var1.toString() << endl;
    cout << "var1.contains(\"success\"): " << boolalpha << var1.contains("success") << endl;
    cout << "var1.contains(\"Success\"): " << boolalpha << var1.contains("Success") << endl;
    cout << "var1.contains(\"Flag\"): " << boolalpha << var1.contains("Flag") << endl;
    cout << "var1.contains(\"hello\"): " << boolalpha << var1.contains("hello") << endl;
    cout << endl;

    // QUESTION 2 OUTPUT:
    VariableString varS1("greeting", "a welcome message", "Hello, World!");

    cout << "QUESTION 2:" << endl;
    cout << "varS1.toString(): " << varS1.toString() << endl;
    cout << "varS1.contains(\"Greet\"): " << boolalpha << varS1.contains("Greet") << endl;
    cout << "varS1.contains(\"world\"): " << boolalpha << varS1.contains("world") << endl;
    cout << "varS1.contains(\"variable\"): " << boolalpha << varS1.contains("variable") << endl;
    cout << endl;

    // QUESTION 3 OUTPUT:
    Variable var2("isBlue", "blue flag indicator");
    VariableString varS2("color", "my favorite color", "Blue");
    vector<Variable*> vect;
    vect.push_back(&var1);
    vect.push_back(&var2);
    vect.push_back(&varS1);
    vect.push_back(&varS2);
    vector<Variable*> vectContains = contains(vect, "blue");
    cout << "QUESTION 3:" << endl;
    cout << "vect:" << endl;
    for(int i = 0; i < vect.size(); i++) {
        cout << "\tvect[" << i << "]: " << vect[i]->toString() << endl;
    }
    cout << "contains(vect, \"blue\"): " << endl;
    for(int i = 0; i < vectContains.size(); i++) {
        cout << "\tvectContains[" << i << "]: " << vectContains[i]->toString() << endl;
    }
}