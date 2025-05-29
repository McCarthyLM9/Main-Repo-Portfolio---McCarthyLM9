#include <iostream>
using namespace std;
int main() {
    int num;
    cin >> num;

    switch (num) {
        case 1:
            cout << " I " << endl;
            break;
        case 2:
            cout << " II " << endl;
            break;
        case 3:
            cout << " III " << endl;
            break;
        default:
            cout << " I can't count that high " << endl;
    }

    return 0;  // end of main function
}    // end of main function