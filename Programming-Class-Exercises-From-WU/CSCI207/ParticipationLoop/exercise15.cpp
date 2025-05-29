#include <iostream>
using namespace std;

int main() {
    int inputInt;
    int attempts = 0; // Counter for the number of attempts

    cin >> inputInt;
    while (!cin && attempts < 2) {  // Allow 3 total attempts (0, 1, 2)
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Bad input, try again" << endl;
        cin >> inputInt;
        attempts++;  // Increment attempt count each time invalid input is entered
    }

    if (!cin) {
        cout << "Failed to provide valid input after 3 attempts" << endl;
    } else {
        cout << "Valid input received" << endl;
    }

    return 0;
}