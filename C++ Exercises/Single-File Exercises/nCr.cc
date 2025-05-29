#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

unsigned long long nCr(int n, int r) {
    if (r > n) {
        return 0; // Invalid case
    }
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n, r;
    cout << "Enter n and r (n >= r) for nCr calculations: ";
    cin >> n >> r;

    if (n < r || n < 0 || r < 0) {
        cerr << "Invalid input. Ensure you only input non-negative numbers and that n >= r." << endl;
        return 1;
    }

    unsigned long long result = nCr(n, r);

    cout << "nCr = " << result << endl;

    return 0;
}