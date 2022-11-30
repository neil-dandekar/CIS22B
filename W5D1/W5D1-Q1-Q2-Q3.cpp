// QUESTION 1, 2, & 3:
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Course {
    private:
        string courseDesc;
        int units;
        int numDay;
    
    public:

		Course(string courseDesc, int units, int numDay) :			// Constructor method
			courseDesc(courseDesc), units(units), numDay(numDay) {
		}

		string getCourseDesc() 										// Getter method for Course Description
		{return courseDesc;}

		int getUnits() 												// Getter method for Number of Units
		{return units;}
		
		int getNumDay() 											// Getter method for Day Number
		{return numDay;}

		string numDayToDay() {										// Converts day number to string
			stringstream day;
            switch(numDay) {
                case 1: day << "Monday";
                        break;
                case 2: day << "Tuesday";
                        break;
                case 3: day << "Wednesday";
                        break;
                case 4: day << "Thursday";
                        break;
                case 5: day << "Friday";
                        break;
                case 6: day << "Saturday";
                        break;
                case 7: day << "Sunday";
                        break;
				default: day << numDay;
						 break;
            }
			return day.str();
		}

        string toString() {											// Converts Course object data to string
            stringstream out;
            out << "COURSE(" << courseDesc << ") UNITS(" << units << ") DAY(" << numDayToDay() << ")";
            return out.str();
        }

        bool hasTheSameDay(Course course1) 							// Compares if two Course objects have the same day
		{return numDay == course1.numDay;}

		bool invDesc() 												// Checks for empty or blank course description
		{return courseDesc.find_first_not_of(' ') == string::npos || courseDesc == "";}

		bool invUnits() 											// Checks for negative units
		{return units < 0;}

		bool invDay() 												// Checks for day number outside of 1 to 7
		{return numDay < 1 || numDay > 7;}

        bool isInvalid() {											// Checks if course description, units, and/or
			if(invDesc() || invUnits() || invDay()) return true;	// day number is invalid
			else return false;
        }
};

void analyzeInvalid(Course arr[], int arraySize, int &invDesc, int &invUnits, int &invDays, int &totUnits) {
	invDesc = invUnits = invDays = totUnits = 0;					// Initialize variables to 0
	for(int i = 0; i < arraySize; i++) {							// Loop through array
		if(arr[i].invDesc()) invDesc++;								// Increment invDesc if current description is invalid
		if(arr[i].invUnits()) {										// Increment invUnits if current units are invalid and
			invUnits++;												// add negative units to total
			totUnits += arr[i].getUnits();
		}
		if(arr[i].invDay()) invDays++;								// Increment invDay if current description is invalid
	}
}

void hasConflicting(Course *arr, int arraySize, int &confDays, int &maxConflict) {
	int days[] = {0, 0, 0, 0, 0, 0, 0};
	confDays = 0;
	for(int i = 0; i < arraySize; i++) {
		days[(*(arr+i)).getNumDay()]++;
	}
	int max = days[0];
	for(int i = 1; i < 7; i++) {
		if(days[i] > max) max = days[i];
		if(days[i] > 1) confDays++;
	}
	maxConflict = max;
}

void checkEndingWithComma(int argc, char *args[]) {
	for(int i = 0; i < argc; i++) {
		for(int j = 0; j != '\0'; j++) {
			cout << i << ": " << args[i] << ": " << *(args[i] + j) << endl;
		}
	}
}

int main(int argc, char *args[]) {
	// QUESTION 1:
	Course course1("Introduction to C++", 3, 4);
	Course course2("    ", -1, 0);
	Course course3("", 1, 4);
	cout << "QUESTION 1:" << endl;
 	cout << "Course 1: " << course1.toString() << endl;
	cout << "Course 2: " << course2.toString() << endl;
	cout << "Course 3: " << course3.toString() << endl;
	cout << "Course 1 isInvalid(): " << boolalpha << course1.isInvalid() << endl;
	cout << "Course 2 isInvalid(): " << boolalpha << course2.isInvalid() << endl;
	cout << "Course 3 isInvalid(): " << boolalpha << course3.isInvalid() << endl;
	cout << "Course 1 and Course 2 hasTheSameDay(): " << boolalpha << course1.hasTheSameDay(course2) << endl;
	cout << "Course 1 and Course 3 hasTheSameDay(): " << boolalpha << course1.hasTheSameDay(course3) << endl;
	cout << endl;

	// QUESTION 2:
	Course arr[] = {course1, course2, course3};
	int invDesc, invUnits, invDays, totUnits;
	analyzeInvalid(arr, 3, invDesc, invUnits, invDays, totUnits);
	cout << "QUESTION 2:" << endl;
	cout << "Course arr[] = {course1, course2, course3}" << endl;
	cout << "analyzeInvalid(arr, 3, invDesc, invUnits, invDay, totUnits): " << endl;
	cout << "Number of courses with invalid descriptions: " << invDesc << endl;
	cout << "Number of courses with invalid unit counts: " << invUnits << endl;
	cout << "Number of courses with invalid day numbers: " << invDays << endl;
	cout << "Total number of invalid units: " << totUnits << endl;
	cout << endl;

	// QUESTION 3:
	Course *arr2 = arr;
	int confDays, maxConflict;
	hasConflicting(arr2, 3, confDays, maxConflict);
	cout << "QUESTION 3:" << endl;
	cout << "Course arr[] = {course1, course2, course3}" << endl;
	cout << "hasConflicting(arr[], 3, confCourses, maxConflict)" << endl;
	cout << "Number of days with conflicts: " <<  confDays << endl;
	cout << "Day with the most conflict: " << maxConflict << endl;
	cout << endl;

	// QUESTION 4:
	argc = 4;
	args[0] = "bruh";
	args[1] = "bru";
	args[2] = "br";
	args[3] = "b";
	cout << "QUESTION 4:" << endl;
	checkEndingWithComma(argc, args);

    return 0;
}