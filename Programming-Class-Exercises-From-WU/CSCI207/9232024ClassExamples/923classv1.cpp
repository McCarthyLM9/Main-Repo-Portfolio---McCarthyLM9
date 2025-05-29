#include <iostream>
using namespace std;
int main() {
    char oper;
    double n1, n2;
    cin >> oper >> n1 >> n2;

    if (oper == '+') {
        cout << n1 << " + " << n2 << " = " << n1 + n2 << endl;
    }
    else if (oper == '-') {
        cout << n1 << " - " << n2 << " = " << n1 - n2 << endl;
    }
    else {
        cout << "Error" << endl;
    }
}