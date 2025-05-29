#include <iostream>
using namespace std;

int main() {
    int day;
    cout << "Enter the day (1-12): ";
    cin >> day;

    switch(day) {
        case 1:
            cout << "A partridge in a pear tree" << endl;
            break;
        case 2:
            cout << "Two turtle doves" << endl;
            break;
        case 3:
            cout << "Three French hens" << endl;
            break;
        case 4:
            cout << "Four calling birds" << endl;
            break;
        case 5:
            cout << "Five gold rings" << endl;
            break;
        case 6:
            cout << "Six geese a-laying" << endl;
            break;
        case 7:
            cout << "Seven swans a-swimming" << endl;
            break;
        case 8:
            cout << "Eight maids a-milking" << endl;
            break;
        case 9:
            cout << "Nine ladies dancing" << endl;
            break;
        case 10:
            cout << "Ten lords a-leaping" << endl;
            break;
        case 11:
            cout << "Eleven pipers piping" << endl;
            break;
        case 12:
            cout << "Twelve drummers drumming" << endl;
            break;
        default:
            cout << "Invalid" << endl;
            break;
    }

    return 0;
}