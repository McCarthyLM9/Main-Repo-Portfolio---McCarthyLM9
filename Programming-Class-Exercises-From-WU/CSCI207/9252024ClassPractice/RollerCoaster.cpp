#include <iostream>
using namespace std;
int main () {
    bool pregnant;
    int height;

    cin >> pregnant >> height;

    if (height >= 48) {
        if (pregnant == true) {
            cout << "Sorry" << endl;
        }
        else {
            cout << "OK: have fun!" << endl;
        }
    }

    return 0;
}