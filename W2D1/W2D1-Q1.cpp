// QUESTION 1:
#include <iostream>

using namespace std;

int findTheSmallest(int arr[], int size, bool &lastNum, int &count) {
    int smallest = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] == smallest) {        // If current element is equal to the smallest,
            count += 1;                 // increment count
        }
        else if(arr[i] < smallest) {    // Assign smallest to current element if 
            smallest = arr[i];          // it is less than the smallest
        }
    }
    lastNum = arr[size-1] == smallest;
    return smallest;
}

int main() {
    int array[] = {50, 20, 30, 40, 10}; // PLEASE CHANGE [Array to be tested]
    int size = 5;                       // PLEASE CHANGE [Size of array to be tested]
    int count;                          // Number of times the smallest element occurred in the array
    bool lastNum;                       // Is the last array element equal to the smallest?
    int smallest = findTheSmallest(array, size, lastNum, count); // Smallest number in the array
    cout << "The smallest number in the array is " << smallest 
         << " which was repeated " << count 
         << " time(s) and was it the last number in the array?: " 
         << boolalpha << lastNum;       // Print result
    return 0;
}