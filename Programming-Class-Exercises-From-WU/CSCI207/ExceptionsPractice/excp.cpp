#include <iostream>
using namespace std;
void ageTest(int sonAge, int momAge);
int main() {
    int sonAge = 22;
    int momAge = 15;
    try {
        ageTest(sonAge, momAge);
    }
    catch (int x) {
        if (x == 99) {
            cout << "Can't have son's age greater than mom's" << endl;
        }
    }
    return 0;
}
void ageTest(int sonAge, int momAge) {
    if (sonAge > momAge) {
        throw 99;
    }
}