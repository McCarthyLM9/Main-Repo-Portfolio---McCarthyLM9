#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main() {
    ifstream fin;
    stringstream ssline;
    string strline;
    string word;
    int total = 0;
    fin.open("line.dat");
    if (!fin.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }
    while (getline(fin, strline)) {
        ssline.clear();
        ssline << strline;
        while (ssline >> word) {
            if (word == "holiday") {
                total = total + 1;
            }
        }
    }
    cout << "Total times the word 'holiday' was used: " << total << endl;
    fin.close();
    return 0;
}