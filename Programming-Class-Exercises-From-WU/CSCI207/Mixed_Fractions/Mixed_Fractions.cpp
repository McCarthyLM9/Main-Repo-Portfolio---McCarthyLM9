#include <iostream>
#include <iomanip>
using namespace std;

//****************************************************************

//*  FILE NAME: Mixed_Fractions.cpp

//*

//*   AUTHOR: Leonard McCarthy

//*

//*  DESCRIPTION: Converts any two integers in order of numerator then denominator into mixed fractions.

//*

//* 

//*

//****************************************************************
int main() {
    int numerator;
    int denominator;

    // Read the first line of input
    cin >> numerator >> denominator;

    // Process the input and handle each line
    if ((numerator != 0) || (denominator != 0)) {
        // Calculate the whole number part and the remainder
        int wholeNumber = numerator / denominator;
        int remainder = numerator % denominator;

        // Output the result in the required format
        cout << wholeNumber << " " << remainder << "/" << denominator << endl;

    }
    return 0;
}