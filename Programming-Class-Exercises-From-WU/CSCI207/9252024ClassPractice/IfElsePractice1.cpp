#include <iostream>
using namespace std;
int main() {
    int num1, num2, num3;

    cin >> num1 >> num2 >> num3;

    if ((num1 > num2) && (num1 > num3)) {
        cout << "The largest number is: " << num1 << endl;
    }
    if ((num2 > num1) && (num2 > num3)) {
        cout << "The largest number is: " << num2 << endl;
    }
    if ((num3 > num1) && (num3 > num2)) {
        cout << "The largest number is: " << num3 << endl;
    }
    if ((num1 == num2) || (num1 == num3) || (num2 == num3)) {
        cout << "Two or all three of the numbers you inputted must be equal, so please re-enter input without any two numbers being equal." << endl;
    }

    return 0;
}