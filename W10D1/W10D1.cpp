#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <iomanip>
#include <vector>

using namespace std; 

class User {
    private: 
        int    m_id; 
        string m_name; 
    public: 
        User(int id, string name): m_id(id), m_name(name) {

        }

        virtual string toString() {
           stringstream ss; 
           ss << "ID(" << m_id << ") NAME("<< m_name << ")" ; 
           return ss.str() ; 
        }

        bool isIDLarger(User & another) { 
           return m_id > another.m_id ; 
        }
};

class BadValueException : public runtime_error {
    public:
        BadValueException(string errMsg) : runtime_error(errMsg) {

        }
};

class Student : public User {
    private:
        double gpa;

    public:
        Student(int _id, string _name, double _gpa) :
            User(_id, _name), gpa(_gpa) {
                stringstream error;
                if(_id < 0) error << "[ERROR] Negative Student ID: " << _id << ". ID must be a non-negative integer. Try again.";
                if(_gpa < 0.0 || _gpa > 4.0) error << "[ERROR] Out-of-bounds GPA: " << fixed << setprecision(2) << gpa << ". GPA must be between 0.0 and 4.0. Try again.";
                if((error.str()).length()) throw new BadValueException(error.str());
        }
        
        virtual string toString() {
            stringstream out;
            out << User::toString() << " GPA(" << fixed << setprecision(2) << gpa << ")";
            return out.str();
        }

        bool isGPAGreater(Student &s) {
            return this->gpa > s.gpa;
        }
};

class GradStudent : public Student {
    private:
        int gradYear;
    
    public:
        GradStudent(int _id, string _name, double _gpa, int _gradYear) :
            Student(_id, _name, _gpa), gradYear(_gradYear) {

            }

        GradStudent(int _id, string _name, double _gpa) :
            Student(_id, _name, _gpa), gradYear(2021) {
                
            }
        
        string toString() {
            stringstream out;
            out << Student::toString() << " GRADUATION-YEAR(" << gradYear << ")";
            return out.str();
        }
};

void getLowest(vector<Student*> &vect, Student* &lowID, Student* &lowGPA) {
    lowID = vect[0];
    lowGPA = vect[0];
    for(int i = 1; i < vect.size(); i++) {
        if(!vect[i]->isIDLarger(*lowID)) lowID = vect[i];
        if(!vect[i]->isGPAGreater(*lowGPA)) lowGPA = vect[i];
    }
}

Student* createOneStudent() {
    int attempts = 0;
    while(attempts < 3) {
        try {
            int _id;
            double _gpa;
            string _name;
            cout << "\nEnter ID: ";
            cin >> _id;
            cout << "Enter GPA: ";
            cin >> _gpa;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, _name);
            
            return new Student(_id, _name, _gpa);
        }
        catch(BadValueException *e) {
            attempts++;
            cout << "\n" << e->what() << endl;
        }
    }
    return nullptr;
};

int main() {
    // QUESTION 4 OUTPUT:
    Student* lowID;
    Student* lowGPA;
    vector<Student*> vect;
    vect.push_back(new Student(2000, "John Smith", 4.0));
    vect.push_back(new Student(2500, "Sara Johnson", 3.8));
    vect.push_back(new GradStudent(3000, "Nancy Brown", 3.5));
    vect.push_back(new GradStudent(3500, "David Miller", 3.9, 2026));

    getLowest(vect, lowID, lowGPA);

    cout << "QUESTION 4:" << endl;
    for(int i = 0; i < vect.size(); i++) {
        cout << "\tvect[" << i << "]: " << vect[i]->toString() << endl;
    }
    cout << "\n\tgetLowest(vect): " << endl;
    cout << "\tLowest ID: " << lowID->toString() << endl;
    cout << "\tLowest GPA: " << lowGPA->toString() << endl;
    cout << endl;

    // QUESTION 5 OUTPUT:
    cout << "QUESTION 5: " << endl;
    Student* s = createOneStudent();
    if(s == nullptr) cout << "\nUnable to create student after three attempts." << endl;
    else cout << "\nSuccess! Here is the new student:\n" << s->toString() << endl;
    cout << endl;

    return 0;
}