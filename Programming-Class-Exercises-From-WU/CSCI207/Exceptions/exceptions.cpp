//****************************************************************
//*  FILE NAME: exceptions.cpp
//*
//*   AUTHOR: Leonard McCarthy
//*
//*  DESCRIPTION: This program gets a number as integer input and checks whether it's valid.
//*               If the input provided is not an integer, error 99 occurs.
//*               If the input is out of the range parameters, error 98 occurs.
//*               Rethrow is used, so a nested try-catch statement approach was used to accomodate the errors and the rethrow.
//****************************************************************
#include <iostream> // input/output and basic code structure for c++
using namespace std; // using the standard namespace

int getNum(int startRange, int endRange); // declare getNum as an int with two int parameters

//the main function
int main()
{
    int num1; // the number that'll be processed
    int startRange = 1; // minimum of range
    int endRange = 7; // maximum of range

    // I did a nested try-catch approach to accomodate the rethrow because I was getting exception errors/crashes otherwise. This let me
    // keep the rethrow and not have crashes/error, no matter the test case or input provided.
    try {
        cout << "Enter NUMBER in range " << startRange << " - " << endRange << endl; // tell user to have input be in-range i.e 1-7

        // inner try-catch approach for calling getNum and saying whether input is valid or invalid, utilizing int error as the erro value storage for errors 98 and 99
        // try statement sets num1 to the calling of getNum with the range parameters as the used parameters - will say input is valid if no errors are detected
        try {
            num1 = getNum(startRange, endRange);
            cout << "You entered a valid number: " << num1 << endl;
        }
        // if errors are detected, they're caught here via int error as 98 (invalid input (incorrect data type)) or 99 (out of range parameters for valid input)
        catch (int error) {
            if (error == 99) {
                cout << "Error: Invalid input. Please enter an integer." << endl;
            }
            else if (error == 98) {
                cout << "Error: Number out of range. Please enter a number between " << startRange << " and " << endRange << "." << endl;
            }
            throw; // rethrow
        }
    }
    // outer catch statement for accomodating the rethrow statement in the inner catch statement - says there was an unhandled error and which erro it was as code 98 or code 99
    catch (int error) {
        cout << "Unhandled exception occured. Code: " << error << endl;
    }
    return 0; // return 0 to end main function successfully
}

// define getNum with range parameters for input gathering, processing, and error checking as throw 99 and throw 98
int getNum(int startRange, int endRange) {
    int num; // declare int num variable
    cout << "Enter a number: "; // ask for number
    cin >> num; // input num

    if(!cin) { // if cin fails or is invalid (incorrect data type - not an integer)
        throw 99; // throw 99 - aligns with nested try-catch statement in main function
    }
    if (num < startRange || num > endRange) { // if cin is out of range parameters
        throw 98; // throw 98 - aligns with nested try-catch statement in main function
    }
    return num; // returns num to complete the getNum function
}