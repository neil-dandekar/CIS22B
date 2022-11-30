// QUESTION 1:
#include <iostream>
#include <sstream>

using namespace std;

class Degree {
    private:
        string subject;
        int gradYear;
        bool isCummeLaude;

    public: 
        Degree(string subject, int gradYear, bool isCummeLaude) :
            subject(subject), gradYear(gradYear), isCummeLaude(isCummeLaude) {
            }

        string toString() {
            stringstream output;
            string cummeLaude = this->isCummeLaude ? "Yes" : "No";
            output << "SUBJECT(" << subject << ") GRAD-YEAR(" 
                   << gradYear << ") CUMME-LAUDE(" << cummeLaude << ")";
            return output.str();
        }

        bool hasTheSameGradYear(Degree degree2) {
            if(this->gradYear == degree2.gradYear) return true;
            else return false;
        }
        
        bool isInvalid() {
            if(gradYear < 0 || subject.find_first_not_of(' ') == string::npos || subject == "") return true;
            else return false;
        }

        Degree clone() {
            return *this;
        }
};

class Task {
    private:
        int day;
        int month;
        string taskName;

    public:
        
};

int main() {
    // TEST DATA:
    Degree myDegree1(" ", 2022, true);
    Degree myDegree2("Computer Science", 2022, false);
    Degree myDegree3 = myDegree1.clone();
    Degree myDegree4 = myDegree2.clone();

    // QUESTION 1 OUTPUT:
    cout << "Degree 1 to string: " << myDegree1.toString() << endl;
    cout << "Degree 2 to string: " << myDegree2.toString() << endl;
    cout << "Degree 1 and Degree 2 have the same grad year: " << boolalpha << myDegree1.hasTheSameGradYear(myDegree2) << endl;
    cout << "Degree 1 is invalid: " << boolalpha << myDegree1.isInvalid() << endl;
    cout << "Degree 2 is invalid: " << boolalpha << myDegree2.isInvalid() << endl;
    cout << "Degree 3 = Degree 1 (clone) tostring: " << myDegree3.toString() << endl;
    cout << "Degree 4 = Degree 2 (clone) tostring: " << myDegree4.toString() << endl;


    return 0;
}