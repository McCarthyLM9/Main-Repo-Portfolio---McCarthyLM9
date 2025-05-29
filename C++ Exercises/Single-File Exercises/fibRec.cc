#include <iostream>
using namespace std;

long long int fib(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fib(n-1) + fib(n-2);
    }
}

int main() {
    int n;
    cout << "Enter n fib position: ";
    cin >> n;
    cout << endl;
    cout << fib(n) << endl;
    return 0;
}