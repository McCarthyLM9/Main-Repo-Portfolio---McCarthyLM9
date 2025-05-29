#include <iostream>
#include <fstream>
using namespace std;
int main() {
    string fileName;
    ifstream fin;
    string line;

    cout << "Enter file name to open: ";
    cin >> fileName;

    fin.open(fileName);
    if (fin.fail()) {
        cout << "File did not open" << endl;
        throw 99;
    }

    getline(fin, line);
    while (!fin.eof()) {
        cout << line << endl;
        getline(fin, line);
    }

    fin.close();

    return 0;
}