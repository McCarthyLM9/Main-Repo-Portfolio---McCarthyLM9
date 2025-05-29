#include <iostream>
using namespace std;

long long int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    else return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter the number n for n!: ";
    cin >> n;
    cout << "\nYou are requesting the calculation for " << n << "!.\n";
    cout << "\nThe factorial calculation result is " << factorial(n) << ".\n";
    return 0;
}