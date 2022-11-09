// QUESTION 2:
#include <iostream>

using namespace std;

int analyzeSurvey(char twoD[][4], int arraySize, int &q1, int &q2, int &q3, int &q4) {
    int numY, numNeutral = 0;            // numY: number of 'Y' responses
    q1 = q2 = q3 = q4 = 0;               // numNeutral: number of neutral surveys
    for(int i = 0; i < arraySize; i++) { // Loop through survey
        for(int j = 0; j < 4; j++) {     // Loop through questions
            if(twoD[i][j] == 'Y') {      // If response is 'Y', increment numY and
                numY++;                  // increment the corresponding question count
                switch(j)
                {
                case 0: q1++;
                        break;
                case 1: q2++;
                        break;
                case 2: q3++;
                        break;
                case 3: q4++;
                        break;
                default:
                    break;
                }
            }
        }
        // cout << "numY: " << numY << endl;
        if(numY == 2) numNeutral++;      // Increment neutral if exactly two 'Y'
        numY = 0;                        // Reset numY counter before next person
    }
    // cout << "numNeutral: " << numNeutral << endl;
    return numNeutral;
}

int main() {
    // TESTING DATA:
    char  survey1[][4] = { {'Y', 'Y', 'N', 'N'} } ;
    char  survey2[][4] = { {'Y', 'Y', 'Y', 'Y'} } ;
    char  survey3[][4] = { {'N', 'N', 'N', 'N'} } ;
    char  survey4[][4] = { {'Y', 'Y', 'N', 'N'}, 
                           {'Y', 'N', 'Y', 'N'} } ;
    char  survey5[][4] = { {'Y', 'Y', 'N', 'N'},
                           {'Y', 'N', 'Y', 'N'},
                           {'Y', 'Y', 'Y', 'Y'},
                           {'N', 'N', 'N', 'N'} } ;
    char  survey6[][4] = { {'Y', 'Y', 'N', 'N'},
                           {'Y', 'N', 'Y', 'N'},
                           {'Y', 'Y', 'Y', 'N'},
                           {'Y', 'N', 'N', 'N'},
                           {'Y', 'Y', 'N', 'N'} } ;
    int q1, q2, q3, q4;                  // Question-corresponding 'Y' counts
    // analyzeSurvey(survey6, 5, q1, q2, q3, q4);
    cout << "|  Survey#  |  Neutral  |  #Q1  |  #Q2  |  #Q3  |  #Q4  |" << endl;
    cout << "|     1     |     " << analyzeSurvey(survey1, 1, q1, q2, q3, q4) << "     |   " << q1 << "   |   " << q2 << "   |   " << q3 << "   |   " << q4 << "   |" << endl;
    cout << "|     2     |     " << analyzeSurvey(survey2, 1, q1, q2, q3, q4) << "     |   " << q1 << "   |   " << q2 << "   |   " << q3 << "   |   " << q4 << "   |" << endl;
    cout << "|     3     |     " << analyzeSurvey(survey3, 1, q1, q2, q3, q4) << "     |   " << q1 << "   |   " << q2 << "   |   " << q3 << "   |   " << q4 << "   |" << endl;
    cout << "|     4     |     " << analyzeSurvey(survey4, 2, q1, q2, q3, q4) << "     |   " << q1 << "   |   " << q2 << "   |   " << q3 << "   |   " << q4 << "   |" << endl;
    cout << "|     5     |     " << analyzeSurvey(survey5, 4, q1, q2, q3, q4) << "     |   " << q1 << "   |   " << q2 << "   |   " << q3 << "   |   " << q4 << "   |" << endl;
    cout << "|     6     |     " << analyzeSurvey(survey6, 5, q1, q2, q3, q4) << "     |   " << q1 << "   |   " << q2 << "   |   " << q3 << "   |   " << q4 << "   |" << endl;
    return 0;
}