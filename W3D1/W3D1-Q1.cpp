// QUESTION 1:
#include <iostream>

using namespace std;

void checkBoundedList(int *arr, int size, int lowBound, int uppBound, int &numLower, int &numUpper, int &numEqual)  {
    numLower = numUpper = numEqual = 0;         // Reset all counters
    for(int i = 0; i < size; i++) {             // Loop through array
        if(*(arr + i) < lowBound) numLower++;   // Increment numLower if current int is less than lowBound
        if(*(arr + i) > uppBound) numUpper++;   // Increment numUpper if current int is less than uppBound
        if(*(arr + i) == lowBound               // Increment numEqual if current int is equal to either
        || *(arr + i) == uppBound) numEqual++;  // lowBound or uppBound
    }
}

int main() {
    // TEST DATA:
    int numList0[] = {10};
    int numList1[] = {10, 20, 30, 40};
    int numList2[] = {0, 40, 30, 20, 10, 5};
    int numList3[] = {10, 30, 20};
    int numLower, numUpper, numEqual;           // Counters for number of integers less than the lower bound, 
                                                // greater than the upper bound, or equal to either bound

    // OUTPUT:
    cout << "| numList | #numLower | #numUpper | #numEqual |" << endl;
    checkBoundedList(numList0, 1, 10, 30, numLower, numUpper, numEqual);
    cout << "|    1    |     " << numLower << "     |      " << numUpper << "    |     " << numEqual << "     |" << endl;
    checkBoundedList(numList1, 4, 10, 30, numLower, numUpper, numEqual);
    cout << "|    2    |     " << numLower << "     |      " << numUpper << "    |     " << numEqual << "     |" << endl;
    checkBoundedList(numList2, 6, 10, 30, numLower, numUpper, numEqual);
    cout << "|    3    |     " << numLower << "     |      " << numUpper << "    |     " << numEqual << "     |" << endl;
    checkBoundedList(numList3, 3, 10, 30, numLower, numUpper, numEqual);
    cout << "|    4    |     " << numLower << "     |      " << numUpper << "    |     " << numEqual << "     |" << endl;
}