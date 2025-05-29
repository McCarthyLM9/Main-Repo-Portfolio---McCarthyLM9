#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    cout << "Investment of $24.00 in beads" << endl;
    double principal = 24.00;
    int n = 2024 - 1626;

    for (int rate = 1; rate <= 7; rate++) {
        double r = rate / 100.0;

        double amount = principal;

        for (int year = 0; year < n; year++) {
            amount += amount * r;
        }
        cout << fixed << setprecision(2) << "Rate of " << rate << "%" << "      Current Value  $" << amount << endl;
    }

    return 0;
}