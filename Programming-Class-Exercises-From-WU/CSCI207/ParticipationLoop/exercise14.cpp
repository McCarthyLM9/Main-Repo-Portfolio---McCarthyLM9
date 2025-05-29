#include <iostream>
using namespace std;

int main() {
    int i = 10; // Initialize row counter (for stars)

    // Outer loop for each row
    while (i > 0) {
        int spaces = 10 - i; // Calculate spaces to print before stars
        int stars = i;       // Number of stars to print in each row

        // Inner loop to print spaces
        int j = 0;
        while (j < spaces) {
            cout << " ";
            j++;
        }

        // Inner loop to print stars
        int k = 0;
        while (k < stars) {
            cout << "*";
            k++;
        }

        // Move to the next line after printing a row
        cout << endl;

        // Decrement the row counter
        i--;
    }

    return 0;
}