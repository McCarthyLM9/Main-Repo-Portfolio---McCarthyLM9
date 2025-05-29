#include <iostream>
using namespace std;

void swap_floats(float &x, float &y);  // Pass by reference

int main() {
    float x, y;
    cout << "Enter two float number values: ";
    cin >> x >> y;
    swap_floats(x, y);
    cout << endl << x << " " << y << endl;
}

void swap_floats(float &x, float &y) {  // Use references to modify original values
    float temp = x;
    x = y;
    y = temp;
}