#include <iostream>
using namespace std;

void MatrixMult(int, int, int, int, int, int, int, int);

int main() {
    int a, b, c, d, e, f, g, h;
    cout << "Enter the elements of the first 2x2 matrix (a, b, c, d): ";
    cin >> a >> b >> c >> d;
    cout << "\nEnter the elements of the second 2x2 matrix (e, f, g, h): ";
    cin >> e >> f >> g >> h;
    cout << "The first matrix is: (" << a << " " << b << ")\n"
         << "                     (" << c << " " << d << ")\n";
    cout << "The second matrix is: (" << e << " " << f << ")\n"
         << "                      (" << g << " " << h << ")\n";
    cout << "The product of the two matrices is: ";
    MatrixMult(a, b, c, d, e, f, g, h);
    return 0;
}

void MatrixMult(int a, int b, int c, int d, int e, int f, int g, int h) {
    int topLeft = a * e + b * g;
    int bottomLeft = c * e + d * g;
    int topRight = a * f + b * h;
    int bottomRight = c * f + d * h;
    cout << "(" << topLeft << " " << topRight << ")\n"
         << "                                    (" << bottomLeft << " " << bottomRight << ")\n";
}