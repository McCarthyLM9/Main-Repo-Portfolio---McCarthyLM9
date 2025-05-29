#include <iostream>
#include <fstream>
using namespace std;
int main () {
    ifstream fin;
    int count;
    int sum = 0;
    int grade;

    fin.open("grades.dat");
    if (fin.fail()) {
        return 1;
    }

    fin >> count;

    for (int i = 1; i <= count; i++) {
        fin >> grade;
        cout << grade << endl;
        sum += grade;
    }

    cout << "Average is " << sum / count << endl;

    fin.close();
    return 0;
}
