#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Exam {
    private:
        string examName;
        int score;
    
    public:
		Exam(string examName, int score) :			                // Constructor method
			examName(examName), score(score) {
		}

		bool isPerfect() {										    // Returns true if score is 100 and false otherwise
			return score == 100;
		}

        bool isPassing() {										    // Returns true if score is greater than or equal to
			return score >= 70;                                     // 70 and false otherwise
		}

        string toString() { 										// Converts Exam object data to string
            stringstream out;
            string pass = isPassing() ? "Pass" : "Fail";
            out << "EXAM(" << examName << ") SCORE(" << score << ") RESULT(" << pass << ")";
            return out.str();
        }

        bool isGreater(Exam exam) {						        	// Returns true if current exam has a greater score
		    return score > exam.score;                              // than given exam
        }

		void increment(int n) {                                     // Increments exam score by given amount
            score += n;
        }
};

void getExamListInfo(Exam arr[], int arraySize, int &numPerfect, int &numPassing, int &indexLargest) {
	numPerfect = numPassing = indexLargest = 0;
    if(arr[0].isPerfect()) numPerfect++;
	if(arr[0].isPassing()) numPassing++;
	for(int i = 1; i < arraySize; i++) {
		if(arr[i].isPerfect()) numPerfect++;
		if(arr[i].isPassing()) numPassing++;
        if(arr[i].isGreater(arr[i - 1])) indexLargest++;
	}
}

vector<Exam*> getInfoAfterIncrement(Exam *arr, int arraySize, int impAmount, int &numPassing) {
	numPassing = 0;
	vector<Exam*> vect;
	for(int i = 0; i < arraySize; i++) {
		(*(arr+i)).increment(impAmount); // I ACCIDENTALLY deleted this line between submission 1 and 2
		if((*(arr+i)).isPassing()) {
			numPassing++;
			vect.push_back((arr + i));
		}
	}
	return vect;
}

void getMatchFirstLastCount(int argc, char *argv[], int &firstLast, int &singular) {
    firstLast = singular = 0;
    for(int i = 0; i < argc; i++) {
		int lastIndex = 0;
		for(int j = 0; *(argv[i] + j) != '\0'; j++) {
            lastIndex++;
		}

		lastIndex -= 1;

        if(*(argv[i] + 1) == '\0') singular++;
		if(argv[i] != "") {
			if(*(argv[i]) == *(argv[i] + lastIndex)) firstLast++;
		}
	}
}

int main(int argc, char *argv[]) {
	// QUESTION 1:
	Exam exam1("Midterm Exam", 100);
	Exam exam2("Final Exam", 50);
	cout << "QUESTION 1:" << endl;
 	cout << "Exam 1: " << exam1.toString() << endl;
	cout << "Exam 2: " << exam2.toString() << endl;
	cout << "Exam 1 isPerfect(): " << boolalpha << exam1.isPerfect() << endl;
	cout << "Exam 2 isPerfect(): " << boolalpha << exam2.isPerfect() << endl;
	cout << "Exam 1 isPassing(): " << boolalpha << exam1.isPassing() << endl;
	cout << "Exam 2 isPassing(): " << boolalpha << exam2.isPassing() << endl;
	cout << "Exam 2 increment(20): " << exam2.toString() << endl;
	cout << "Exam 2 isPassing(): " << boolalpha << exam2.isPassing() << endl;
	cout << endl;

	// QUESTION 2:
	Exam exam3("Midterm1 Exam", 90);
	Exam exam4("Final Exam", 50);
	Exam exam5("Midterm2 Exam", 80);
	Exam exam6("Extra Credit", 100);
	Exam exam7("Initial Test", 0);
	Exam exam8("Homework1", 69);

	Exam examList[] = {exam3, exam4, exam5, exam6, exam7, exam8};
	int numPerfect, numPassing, indexLargest;
	getExamListInfo(examList, 6, numPerfect, numPassing, indexLargest);
	cout << "QUESTION 2:" << endl;
	cout << "Exam examList[] = { {\"Midterm1 Exam\", 90}, {\"Midterm2 Exam\", 80}," << endl;
    cout << "                    {\"Final Exam\", 50}, {\"Extra Credit\", 100}," << endl;
    cout << "                    {\"Initial Test\", 0}, {\"Homework1\", 69} } ;" << endl;
	cout << "getExamListInfo(examList, 6, numPerfect, numPassing, indexLargest): " << endl;
	cout << "Number of exams with perfect scores: " << numPerfect << endl;
	cout << "Number of exams with passing scores: " << numPassing << endl;
	cout << "Index of exam with highest score: " << indexLargest << endl;
	cout << endl;

	// QUESTION 3:
	Exam *pExamList[6];
	pExamList[0] = new Exam("Midterm1 Exam", 90);
	pExamList[1] = new Exam("Midterm2 Exam", 80);
	pExamList[2] = new Exam("Final Exam", 50);
	pExamList[3] = new Exam("Extra Credit", 100);
	pExamList[4] = new Exam("Initial Test", 0);
	pExamList[5] = new Exam("Homework1", 69);

	// Exam *pExamList1 = new Exam[6];
	// pExamList[0] = new Exam("Midterm1 Exam", 90);
	// pExamList[1] = new Exam("Midterm2 Exam", 80);
	// pExamList[2] = new Exam("Final Exam", 50);
	// pExamList[3] = new Exam("Extra Credit", 100);
	// pExamList[4] = new Exam("Initial Test", 0);
	// pExamList[5] = new Exam("Homework1", 69);

	int numPassing1;
	vector<Exam*> vect = getInfoAfterIncrement(*pExamList, 6, 10, numPassing1);
	cout << endl;
	cout << "QUESTION 3:" << endl;
	cout << "Number of exams with passing scores after increment: "  << numPassing1 << endl;
	cout << "Vector of passing exams: " << endl;
	for(int i=0; i < vect.size(); i++)
   		cout << "vect[" << i << "]: " << (vect.at(i))->toString() << endl;
	cout << endl;

	// QUESTION 4:
	int firstLast, singular;
	cout << "QUESTION 4:" << endl;
	getMatchFirstLastCount(argc, argv, firstLast, singular);
    cout << "firstLast: " << firstLast << endl;
    cout << "singular: " << singular << endl;
    return 0;
}