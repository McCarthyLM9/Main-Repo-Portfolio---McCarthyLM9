#include <iostream>
using namespace std;

class Base {
    public:
        Base() {cout << "A created" << endl;}
        ~Base() {cout << "A destroyed" << endl;}
};

class Child : public Base {
    public:
        Child() {cout << "B created" << endl;}
        ~Child() {cout << "B destroyed" << endl;}
};

int main() {
    cout << "LIFO is used for chain of destruction" << endl;
    cout << "     Top-Bottom for construction     " << endl;
    cout << "     Bottom-Top for destruction      " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    Child child;
    return 0;
}