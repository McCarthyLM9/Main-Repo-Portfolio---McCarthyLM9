#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin;
    ofstream fout;
    double price, total;
    fin.open("prices.txt");
    fout.open("total.txt");
    if (!fin.is_open() || !fout.is_open()) {
        cout << "Error opening files" << endl;
        return 1;
    }
    while (fin >> price) {
        total += price;
    }
    fout << "$" << total << endl;
    fin.close();
    fout.close();
    return 0;  
}