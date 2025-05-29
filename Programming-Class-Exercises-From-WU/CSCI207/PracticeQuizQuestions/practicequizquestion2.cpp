#include <iostream>
#include <iomanip>
using namespace std;
void addTax(double& taxRate, double& cost);
int main() {
    double taxRate, cost;
    cout << "Enter the tax rate (x%) and cost ($x.xx): ";
    cin >> taxRate >> cost;
    addTax(taxRate, cost);
    return 0;
}
void addTax(double& taxRate, double& cost) {
    cost += (cost * (taxRate/100));
    cout << fixed << setprecision(2) << "Cost with sales tax added: $" << cost << endl;
}