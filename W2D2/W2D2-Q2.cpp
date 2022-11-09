// QUESTION 2:
#include <iostream>

using namespace std;

int analyzeSurvey(char twoD[][4], int arraySize, int (&questionY)[]) {
    int numY, numNeutral = 0;            // numY: number of 'Y' responses
    questionY[0] = 0;                    // numNeutral: number of neutral surveys
    questionY[1] = 0;
    questionY[2] = 0;
    questionY[3] = 0;
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
        // cout << "numY: " << numY << endl;
        if(numY == 2) numNeutral++;      // Increment neutral if exactly two 'Y'
            numY = 0;                    // Reset numY counter before next person
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
    int questionY[4] = {0, 0, 0, 0};         // Question-corresponding 'Y' counts
    // int numNeutral1, numNeutral2, numNeutral3, numNeutral4, numNeutral5, numNeutral6;
    // cout << "|     6     |     " << analyzeSurvey(survey6, 5, questionY) << "     |   " << questionY[0] << "   |   " << questionY[1] << "   |   " << questionY[2] << "   |   " << questionY[3] << "   |" << endl;
    // cout << analyzeSurvey(survey6, 5, questionY);
    cout << "|  Survey#  |  Neutral  |  #questionY[0]  |  #questionY[1]  |  #questionY[2]  |  #questionY[3]  |" << endl;
    questionY[0] = questionY[1] = questionY[2] = questionY[3] = 0;
    int numNeutral1 = analyzeSurvey(survey1, 1, questionY);
    cout << "|     1     |     " << numNeutral1 << "     |   " << questionY[0] << "   |   " << questionY[1] << "   |   " << questionY[2] << "   |   " << questionY[3] << "   |" << endl;
    questionY[0] = questionY[1] = questionY[2] = questionY[3] = 0;
    int numNeutral2 = analyzeSurvey(survey2, 1, questionY);
    cout << "|     2     |     " << numNeutral2 << "     |   " << questionY[0] << "   |   " << questionY[1] << "   |   " << questionY[2] << "   |   " << questionY[3] << "   |" << endl;
    questionY[0] = questionY[1] = questionY[2] = questionY[3] = 0;
    int numNeutral3 = analyzeSurvey(survey3, 1, questionY);
    cout << "|     3     |     " << numNeutral3 << "     |   " << questionY[0] << "   |   " << questionY[1] << "   |   " << questionY[2] << "   |   " << questionY[3] << "   |" << endl;
    questionY[0] = questionY[1] = questionY[2] = questionY[3] = 0;
    int numNeutral4 = analyzeSurvey(survey4, 2, questionY);
    cout << "|     4     |     " << numNeutral4 << "     |   " << questionY[0] << "   |   " << questionY[1] << "   |   " << questionY[2] << "   |   " << questionY[3] << "   |" << endl;
    questionY[0] = questionY[1] = questionY[2] = questionY[3] = 0;
    int numNeutral5 = analyzeSurvey(survey5, 4, questionY);
    cout << "|     5     |     " << numNeutral5 << "     |   " << questionY[0] << "   |   " << questionY[1] << "   |   " << questionY[2] << "   |   " << questionY[3] << "   |" << endl;
    questionY[0] = questionY[1] = questionY[2] = questionY[3] = 0;
    int numNeutral6 = analyzeSurvey(survey6, 5, questionY);
    cout << "|     6     |     " << numNeutral6 << "     |   " << questionY[0] << "   |   " << questionY[1] << "   |   " << questionY[2] << "   |   " << questionY[3] << "   |" << endl;
    return 0;
}