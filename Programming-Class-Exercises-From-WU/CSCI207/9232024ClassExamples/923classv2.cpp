#include <iostream>
using namespace std;
int main() {
    char oper;
    double n1, n2;
    cin >> oper >> n1 >> n2;

    switch (oper) {
        case '+':
            cout << n1 << " + " << n2 << " = " << n1 + n2 << endl;
            break;
        case '-':
            cout << n1 << " - " << n2 << " = " << n1 - n2 << endl;
            break;
        default:
            cout << "error" << endl;
    }
}