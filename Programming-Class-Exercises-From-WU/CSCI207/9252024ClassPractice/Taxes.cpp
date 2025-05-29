#include <iostream>
using namespace std;
int main() {
    char taxCode;
    double price = 17.00;
    const double taxRate = 0.005; // 0.5 percent

    cin >> taxCode;

    if (taxCode == 'T') {
        price = price + (price * taxRate);
        cout << "Price after taxes: " << price << endl;
    }
    else {
        cout << "Price without taxes: " << price << endl;
    }

    return 0;
}