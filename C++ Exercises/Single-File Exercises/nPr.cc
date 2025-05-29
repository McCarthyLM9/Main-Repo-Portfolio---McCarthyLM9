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

unsigned long long nPr(int n, int r) {
    return factorial(n) / (factorial(n - r));
}

int main() {
    int n, r;
    cout << "Enter n and r (n >= r) for nPr calculations: ";
    cin >> n >> r;

    if (n < r || n < 0 || r < 0) {
        cerr << "Invalid input. Ensure you only input non-negative numbers and that n >= r." << endl;
        return 1;
    }

    unsigned long long result = nPr(n, r);

    cout << "nPr = " << result << endl;

    return 0;
}