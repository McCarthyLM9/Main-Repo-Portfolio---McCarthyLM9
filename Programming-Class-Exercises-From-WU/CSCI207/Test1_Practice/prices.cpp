#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream inputFile;
    inputFile.open("prices.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }
    double price, sum = 0.0;
    while (inputFile >> price) {
        sum += price;
    }
    cout << "Sum of movie rental prices is: " << sum << endl;
    inputFile.close();
    return 0;
}