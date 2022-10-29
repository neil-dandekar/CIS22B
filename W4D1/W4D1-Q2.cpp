// QUESTION 2:
#include <iostream>
#include <string>

using namespace std;

double* getDynamicPointerToMaxAndMin(int size, double arr[]) {
    double *pNumList = new double[2]; // Create new dynamically allocated memory to store min and max
    pNumList[0] = arr[0]; // Save first element of arr as min
    pNumList[1] = arr[0]; // Save first element of arr as max

    for(int i = 1; i < size; i++) { // Loop through remainind elemnts of arr
        if(arr[i] < arr[0]) {
            pNumList[0] = arr[i]; // Save element as min if it is less than current min
        }
        else if(arr[i] > arr[0]) {
            pNumList[1] = arr[i]; // Save element as max if it is greater than current max
        }
    }
    return pNumList;
}

int main() {
    double array[4] = {10.1, 30.3, 40.4, 20.2}; // Input array
    cout << "Min: " << *getDynamicPointerToMaxAndMin(4, array) << ", Max: " << *(getDynamicPointerToMaxAndMin(4, array) + 1) << endl;
}