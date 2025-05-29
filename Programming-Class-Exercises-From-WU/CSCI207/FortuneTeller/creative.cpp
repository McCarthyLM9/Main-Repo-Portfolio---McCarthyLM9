//****************************************************************
//*  FILE NAME: creative.cpp
//*
//*   AUTHOR: Leonard McCarthy
//*
//*  DESCRIPTION: This is the creative version of the PGM Fortune 
//*  Teller assignment that takes a favorite number and disliked number
//*  as input, checks equality/inequality, calculates a lucky number,
//*  and interprets the meaning of the calculated lucky number.
//* 
//****************************************************************
#include <iostream>
using namespace std;
int main() {
    
    // create two numbers as int variables
    int favoriteNum;
    int dislikedNum;

    // get inputs
    cout << "Enter a favorite number: ";
    cin >> favoriteNum;

    cout << "Enter a disliked number: ";
    cin >> dislikedNum;

    // Compare two numbers, favorite number and disliked number, to check for inequality or equality.
    if (favoriteNum == dislikedNum) {
        cout << "Oddly enough, you have your numbers set to be equal, hahaha." << endl;
    }
    else {
        cout << "It makes sense that your favorite number and disliked number are different." << endl;
    }

    // Get lucky number, output lucky number, say you'll decide what lucky number means - Creative changes #1 to creative.cpp for lucky number is modulus 9 instead of modulus 10.
    cout << "Now I'll calculate your lucky number based on the two numbers you gave me." << endl;
    int luckyNum = (favoriteNum * dislikedNum) % 9;
    cout << "Your lucky number is " << luckyNum << endl;
    cout << "Based on your lucky number, here is what I've gathered: ";

    // get different outputs depending on value of lucky number
    // Creative change #2 - output messages for lucky number
    if (luckyNum == 0) {
        cout << "Hahaha, too small, please try again. Sorry." << endl;
    }
    if ((luckyNum > 0) && (luckyNum <= 4)) {
        cout << "Still tooooo small." << endl;
    }
    if ((luckyNum >= 5) && (luckyNum < 9)) {
        cout << "Try to be more tech-savvy, please just try again hahaha." << endl;
    }
    if (luckyNum >= 9) {
        cout << "Now you get it. Today is definitely your lucky day, hahaha." << endl;
    }
    
    // Added farewell message for creative change #3
    cout << "Farewell" << endl;

    // return 0
    return 0;
}