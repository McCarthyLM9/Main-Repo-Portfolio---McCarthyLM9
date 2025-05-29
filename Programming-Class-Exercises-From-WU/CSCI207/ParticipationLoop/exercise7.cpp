#include <iostream>
using namespace std;
int main() {
    int sum;
    bool done;
    int number;
    sum = 0;
    done = false;

    while (!done) {
        cin >> number;
        if (number != 0) {
            sum = sum + number;
        }
        else {
            done = true;
        }
    }
    cout << "The sum of non-zero numbers is: " << sum << endl;
    return 0;
}