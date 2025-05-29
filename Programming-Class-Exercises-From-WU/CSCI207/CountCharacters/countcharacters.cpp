//****************************************************************
//*  FILE NAME: countcharacters.cpp
//*
//*   AUTHOR: Leonard McCarthy
//*
//*  DESCRIPTION: go through a string and see how many times a character is found within said string
//*
//* 
//*
//****************************************************************
#include <iostream> // input/output and basic code functionality
using namespace std; // using the standard namespace

int CountCharacters(char, string&); // declare function count characters with a char passed by value and a string passed by reference

// main function
int main() {
    // declare variables
    char character;
    string inputString;

    // Input variables as char space string
    cout << "Enter a character to check for, then a space, followed by the word(s) to check for said character: ";
    cin >> character; // get char

    cin.ignore(); // so that getline works properly due to input buffer from previous cin needing to be removed

    getline(cin, inputString); // get line of word(s)

    int occurences = CountCharacters(character, inputString); // declare and initialize occurrences variables as calling the count characters function using char and string

    // if occurrences = 1, don't have plurals - use plurals if occurrences != 1 (0 or more than 1)
    if (occurences == 1) {
        cout << occurences << " " << character << endl;
    }
    else {
        cout << occurences << " " << character << "'s" << endl;
    }
    return 0; // return 0 to end program successfully
}

// count characters function defined
int CountCharacters(char targetCharacter, string& inputString) {
    int count = 0; // set character count to 0
    // a range-based for loop with a temporary variable c to store each character being iteratively assessed as being equal to or not equal to the target character
    for (char c : inputString) {
        // add 1 to count each time the tested character in input string equals the target character
        if (c == targetCharacter) {
            count++;
        }
    }
    return count; // return count
}