#include <iostream>
using namespace std;
int main() {
    int number;
    int sum;
    sum = 0;
    cin >> number;

    while ((number >= 0) && (number <= 100)) {
        sum = sum + number;
        cin >> number;
    }
    cout << "The sum of integers between 0 and 100 inclusive is: " << sum << endl;
    return 0;
}