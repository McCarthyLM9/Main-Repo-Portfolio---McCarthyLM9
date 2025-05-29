#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin;
    int oneCount = 0, twoCount = 0, threeCount = 0, numRead;
    fin.open("numbers.dat");
    if (!fin.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }
    while (fin >> numRead) {
        if (numRead == 1) {
            oneCount++;
        }
        if (numRead == 2) {
            twoCount++;
        }
        if (numRead == 3) {
            threeCount++;
        }
    }
    cout << "Number of ones: " << oneCount << endl;
    cout << "Number of twos: " << twoCount << endl;
    cout << "Number of threes: " << threeCount << endl;
    fin.close();
    return 0;
}