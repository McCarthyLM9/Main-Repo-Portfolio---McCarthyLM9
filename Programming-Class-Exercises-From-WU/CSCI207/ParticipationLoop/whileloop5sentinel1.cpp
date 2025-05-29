#include <iostream>
using namespace std;
int main() {
    char letter;
    int count = 0;
    cin.get(letter);
    while (isspace(letter)==false) {
        count++;
        cin.get(letter);
    }
    cout << count << endl;
    return 0;
}