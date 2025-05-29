#include <iostream>
using namespace std;
void sort_floats(float &a, float &b, float &c);
int main() {
    float a, b, c;
    cout << "Enter three float type numbers: ";
    cin >> a >> b >> c;
    sort_floats(a, b, c);
    return 0;
}
void sort_floats(float &a, float &b, float &c) {
    if (a > b) {
        float temp = a;
        a = b;
        b = temp;
    }
    if (a > c) {
        float temp = a;
        a = c;
        c = temp;
    }
    if (b > c) {
        float temp = b;
        b = c;
        c = temp;
    }

    cout << a << " " << b << " " << c << endl;
}