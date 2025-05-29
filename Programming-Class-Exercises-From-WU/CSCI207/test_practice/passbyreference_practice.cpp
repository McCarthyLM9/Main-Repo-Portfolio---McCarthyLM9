#include <iostream>
using namespace std;
void SwapFloats(float& x, float& y);
void SwapFloats(float& x, float& y) {
    float temp;
    temp = x;
    x = y;
    y = temp;
    return;
}