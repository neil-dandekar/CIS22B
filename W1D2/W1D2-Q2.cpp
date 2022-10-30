// QUESTION 2:
#include <iostream>

using namespace std;

bool repeatPasscode(int password, int &count) {
    int currentPassword;
    for(int i = 0; i < 3; i++) { // Prompt the user 3 times for the correct password
        count = i+1; // Track number of attempts and assign it to count
        cout << "Enter the password: ";
        cin >> currentPassword;
        if(currentPassword == password) { // Return true if correct password was entered
            return true;
        }
        cout << "Incorrect. Try again." << endl;
    }
    return false; // Return false if the correct password wasn't entered in 3 attempts
}

int main() {
    int correctPassword;
    int count;
    cout << "Set your password: "; // Ask user for their password
    cin >> correctPassword;
    bool success = repeatPasscode(correctPassword, count); // Call function

    cout << "\nYou attempted the password " << count 
         << " time(s) and were you correct?: " << boolalpha << success; // Print result

    return 0;
}