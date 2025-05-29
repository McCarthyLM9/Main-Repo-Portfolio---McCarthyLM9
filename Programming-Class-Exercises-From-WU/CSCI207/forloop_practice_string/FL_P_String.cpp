#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main () {
    string line;

    getline(cin, line);

    for (int i = 0; i <= line.length() - 1; i++) {
        line.at(i) = toupper(line.at(i));
    }

    cout << endl << line << endl;

    return 0;
}