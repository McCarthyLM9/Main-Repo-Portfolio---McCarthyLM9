#include <iostream>
using namespace std;
int main() {
    int sum = 0;
    int iterator = 73;
    while (iterator <= 415) {
        sum = sum + iterator;
        iterator++;
    }
    cout << sum << endl;
    return 0;
}