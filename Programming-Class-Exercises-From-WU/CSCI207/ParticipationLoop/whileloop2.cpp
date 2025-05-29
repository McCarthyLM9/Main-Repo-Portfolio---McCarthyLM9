#include <iostream>
using namespace std;

int main() {
    int sum = 0;    // Variable to store the sum, initialized to 0
    int num = 2;    // Start with the first even number

    while (num <= 500) {
        sum += num;  // Add the current even number to the sum
        num += 2;    // Move to the next even number
    }

    cout << "The sum of even integers from 2 to 500 is: " << sum << endl;

    return 0;
}