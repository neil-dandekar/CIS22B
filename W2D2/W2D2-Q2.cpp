// QUESTION 2:
#include <iostream>

using namespace std;

int analyzeSurvey(char twoD[][4], int arraySize, int (&questionY)[4]) {
    questionY[0] = questionY[1] = questionY[2] = questionY[3] = 0; // Reset 'Y' counts
    int numY = 0;                        // numY: number of 'Y' responses
    int numNeutral = 0;                  // numNeutral: number of neutral surveys
    for(int i = 0; i < arraySize; i++) { // Loop through survey
        for(int j = 0; j < 4; j++) {     // Loop through questions
            if(twoD[i][j] == 'Y') {      // If response is 'Y', increment numY and
                numY++;                  // increment the corresponding question count
                switch(j) {
                    case 0: questionY[0]++;
                            break;
                    case 1: questionY[1]++;
                            break;
                    case 2: questionY[2]++;
                            break;
                    case 3: questionY[3]++;
                            break;
                    default:
                            break;
                }
            }
        }
        if(numY == 2) numNeutral++;      // Increment neutral if exactly two 'Y'
            numY = 0;                    // Reset numY counter before next person
    }
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
    int questionY[4];   // Question-corresponding 'Y' counts

    // OUTPUT:
    cout << "|  Survey#  | # Neutral |  #Q1  |  #Q2  |  #Q3  |  #Q4  |" << endl;
    cout << "|     1     |     " << analyzeSurvey(survey1, 1, questionY) << "     |   " << questionY[0] << "   |   " << questionY[1] << "   |   " << questionY[2] << "   |   " << questionY[3] << "   |" << endl;
    cout << "|     2     |     " << analyzeSurvey(survey2, 1, questionY) << "     |   " << questionY[0] << "   |   " << questionY[1] << "   |   " << questionY[2] << "   |   " << questionY[3] << "   |" << endl;
    cout << "|     3     |     " << analyzeSurvey(survey3, 1, questionY) << "     |   " << questionY[0] << "   |   " << questionY[1] << "   |   " << questionY[2] << "   |   " << questionY[3] << "   |" << endl;
    cout << "|     4     |     " << analyzeSurvey(survey4, 2, questionY) << "     |   " << questionY[0] << "   |   " << questionY[1] << "   |   " << questionY[2] << "   |   " << questionY[3] << "   |" << endl;
    cout << "|     5     |     " << analyzeSurvey(survey5, 4, questionY) << "     |   " << questionY[0] << "   |   " << questionY[1] << "   |   " << questionY[2] << "   |   " << questionY[3] << "   |" << endl;
    cout << "|     6     |     " << analyzeSurvey(survey6, 5, questionY) << "     |   " << questionY[0] << "   |   " << questionY[1] << "   |   " << questionY[2] << "   |   " << questionY[3] << "   |" << endl;
    
    return 0;
}