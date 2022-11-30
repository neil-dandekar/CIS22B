// QUESTION 1:
#include <iostream>

using namespace std;


int getScoreInfo(int twoD[][5], int arraySize, int &numPerfect) {
    int numPassing = 0;                  // Number of passing students
    int pass = 0;                        // Tracks how many passing grades each student has
    int perfect = 0;                     // Tracks how many perfect grades each student has
    numPerfect = 0;
    for(int i = 0; i < arraySize; i++) { // Loop through twoD
        for(int j = 0; j < 5; j++) {     // Loop through twoD[]
            if(twoD[i][j] == 100) {      // Increment perfect and pass if grade is 100
                perfect++;
                pass++;
            }
            else if(twoD[i][j] >= 50) {  // Increment pass if grade is 50 or higher
                pass++;
            }
        }
        if(perfect == 5) {               // If student has 5 perfect grades, increment
            numPerfect++;                // numPerfect and numPassing
            numPassing++;
        }
        else if(pass >= 3) {             // If student has 3 or more passing grades,
            numPassing++;                // increment numPassing
        }
        pass = perfect = 0;              // Reset tracking variables before next iteration
    }
    return numPassing;
}

int main() {
    // TESTING DATA:
    int numPerfect = 0;                  // Number of students with all perfect scores
    int studentScoreList1[][5] = { {100, 100, 100, 100, 100 } } ;
    int studentScoreList2[][5] = { {0, 0, 0, 0, 0 }           } ;
    int studentScoreList3[][5] = { {50, 0, 50, 50, 0 }        } ;
    int studentScoreList4[][5] = { {50, 0,  0, 50, 0 }        } ;
    int studentScoreList5[][5] = { {100, 100, 100, 100, 100 },
                                   {50, 0,  0, 50, 0 }        } ;
    int studentScoreList6[][5] = { {30, 50, 70, 90, 100 },
                                   {100, 100, 100, 100, 100},
                                   {10, 20, 50, 60, 80  },
                                   {100, 100, 40, 40, 40},
                                   {100, 100, 100, 100, 100},
                                   {100, 50, 40, 30, 100}     } ;
    int studentScoreList7[][5] = { {30, 50, 70, 90, 100 },
                                   {10, 20, 50, 60, 80  },
                                   {100, 100, 40, 40, 40}     };

    // OUTPUT:
    cout << "  |  studentScoreList  |  " << "Student-Pass-Count" << "  |  " << "Student-Perfect-Score-Count  |" << endl;
    cout << "  |          1         |           " << getScoreInfo(studentScoreList1, 1, numPerfect) << "          |                " << numPerfect << "              |" << endl;
    cout << "  |          2         |           " << getScoreInfo(studentScoreList2, 1, numPerfect) << "          |                " << numPerfect << "              |" << endl;
    cout << "  |          3         |           " << getScoreInfo(studentScoreList3, 1, numPerfect) << "          |                " << numPerfect << "              |" << endl;
    cout << "  |          4         |           " << getScoreInfo(studentScoreList4, 1, numPerfect) << "          |                " << numPerfect << "              |" << endl;
    cout << "  |          5         |           " << getScoreInfo(studentScoreList5, 2, numPerfect) << "          |                " << numPerfect << "              |" << endl;
    cout << "  |          6         |           " << getScoreInfo(studentScoreList6, 6, numPerfect) << "          |                " << numPerfect << "              |" << endl;
    cout << "  |          7         |           " << getScoreInfo(studentScoreList7, 3, numPerfect) << "          |                " << numPerfect << "              |" << endl;
    return 0;
}