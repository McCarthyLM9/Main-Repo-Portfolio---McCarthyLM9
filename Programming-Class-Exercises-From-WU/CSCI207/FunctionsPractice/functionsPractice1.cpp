#include <iostream>
#include <iomanip>
using namespace std;
double appleCost(int, double);
int main() {
    int appleCount;
    double pricePerApple;
    double price;
    cout << "How many apples? ";
    cin >> appleCount;
    cout << "\nUnit price? ";
    cin >> pricePerApple;
    price = appleCost(appleCount, pricePerApple);
    cout << setprecision(2) << fixed << "\nTotal cost: " <<  price << endl;
    return 0;
}
double appleCost(int numApples, double priceApples) {
    double totalPrice;
    totalPrice = numApples * priceApples;
    return totalPrice;
}