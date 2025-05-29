#include <iostream>
using namespace std;
int sum_from_to(int, int);
int main() {
    int x, y;
    cout << "Enter two integers: ";
    cin >> x >> y;
    cout << endl << sum_from_to(x, y) << endl;
    return 0;
}
int sum_from_to(int x, int y) {
    int total = 0;
    if (x <= y) {
        for (int i = x; i <= y; i++) {
            total += i;
        }
    }
    else {
        for (int i = y; i <= x; i++) {
            total += i;
        }
    }
    return total;
}