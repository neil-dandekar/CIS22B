#include <iostream>
#include <sstream>

using namespace std;

class Expression {
    private:
        int operand1;
        int operand2;
        char operator1;

    public:
        string toString() {
            stringstream out;
            out << operand1 << "     " << operator1 << "     " << operand2 << " = " <<;
            return out.str();
        }

        


};