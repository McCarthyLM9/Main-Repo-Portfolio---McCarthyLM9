#include <iostream>
using namespace std;
void zeroBoth (int& num1, int& num2);
int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    zeroBoth(num1, num2);
}
void zeroBoth(int& num1, int& num2) {
    num1 = 0;
    num2 = 0;
    cout << "Num 1 becomes " << num1 << " and Num 2 becomes " << num2 << "." << endl;
}