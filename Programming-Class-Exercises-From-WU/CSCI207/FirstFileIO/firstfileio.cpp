#include <fstream>
#include <iostream>
using namespace std;
int main() {
    ifstream fin;
    ofstream fout;

    int num1, num2, num3;
    int sum;

    fin.open("addends.dat");
    if(fin.fail()) {
        cout << "Input file opening failed" << endl;
        return EXIT_FAILURE;
    }
    fout.open("sum.dat");
    if(fout.fail()) {
        cout << "Output file opening failed" << endl;
        return EXIT_FAILURE;
    }
    fin >> num1 >> num2 >> num3;
    sum = num1 + num2 + num3;
    fout << sum;
    fin.close();
    fout.close();
    return EXIT_SUCCESS;
}