#include <iostream>
using namespace std;

int main() {
    int i = 10; // Initialize row counter

    // Outer loop for each row
    while (i > 0) {
        int j = 0; // Initialize star counter

        // Inner loop to print '*' i times
        while (j < i) {
            cout << "*";
            j++;
        }

        // Move to the next line after printing a row
        cout << endl;

        // Decrement the row counter
        i--;
    }

    return 0;
}