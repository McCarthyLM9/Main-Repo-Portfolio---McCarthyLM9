#include <iostream>
using namespace std;

int main()
{
    int count = 0;

    for (count = 0; count <5; count++) {
        cout << count++ << " " ;
    }

    cout << count+2 << endl;

    return 0;
}