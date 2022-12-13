// QUESTION 1 & 2:
#include <iostream>
#include <sstream>

using namespace std;

class Degree {
    private:
        bool    isCummeLaude;
        int     gradYear;
        string  subject;

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

        Degree* clone() {
            return this;
        }
};

class Task {
    private:
        int     day;
        int     month;
        string  taskName;

    public:
        Task(string _taskName, int _month, int _day) : 
            day(_day), month(_month), taskName(_taskName) {
        }

        bool hasTheSameDay(Task t) {
            return (this->day == t.day) && (this->month == t.month);
        }

        bool contains(string s) {
            return taskName.find(s) != string::npos;
        }

        string toString() {
            stringstream out;
            out << "TASK(" << taskName << ") DATE(" << month << "/" << day << ")";
            return out.str();
        }
};

int main() {
    // TEST DATA:
    Degree  myDegree1(" ", 2022, true);
    Degree  myDegree2("Computer Science", 2022, false);
    Degree  myDegree3 = *(myDegree1.clone());
    Degree  myDegree4 = *(myDegree2.clone());
    Task    myTask1("Midterm Exam", 10, 18);
    Task    myTask2("Final Exam", 12, 18);
    Task    myTask3("Study", 10, 18);

    // QUESTION 1 OUTPUT:
	cout << "QUESTION 1:" << endl;
    cout << "Degree 1 to string: " << myDegree1.toString() << endl;
    cout << "Degree 2 to string: " << myDegree2.toString() << endl;
    cout << "Degree 1 and Degree 2 have the same grad year: " << boolalpha << myDegree1.hasTheSameGradYear(myDegree2) << endl;
    cout << "Degree 1 is invalid: " << boolalpha << myDegree1.isInvalid() << endl;
    cout << "Degree 2 is invalid: " << boolalpha << myDegree2.isInvalid() << endl;
    cout << "Degree 3 = Degree 1 (clone) tostring: " << myDegree3.toString() << endl;
    cout << "Degree 4 = Degree 2 (clone) tostring: " << myDegree4.toString() << endl;
    cout << endl;

    // QUESTION 2 OUTPUT:
	cout << "QUESTION 2:" << endl;
    cout << "Task 1 to string: " << myTask1.toString() << endl;
    cout << "Task 2 to string: " << myTask2.toString() << endl;
    cout << "Task 3 to string: " << myTask3.toString() << endl;
    cout << "Task1 has the same day as Task2: " << boolalpha << myTask1.hasTheSameDay(myTask2) << endl;
    cout << "Task1 has the same day as Task3: " << boolalpha << myTask1.hasTheSameDay(myTask3) << endl;
    cout << "Task1 contains \"Exam\": " << boolalpha << myTask1.contains("Exam") << endl;
    cout << "Task2 contains \"Exam\": " << boolalpha << myTask2.contains("Exam") << endl;
    cout << "Task3 contains \"Exam\": " << boolalpha << myTask3.contains("Exam") << endl;
    cout << endl;


    return 0;
}