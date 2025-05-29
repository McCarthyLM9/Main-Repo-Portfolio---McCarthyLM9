//****************************************************************
//*  FILE NAME: statistics.cpp
//*
//*   AUTHOR: Leonard McCarthy
//*
//*  DESCRIPTION: Takes four scores as input (data types are all doubles) and calculates the mean and standard deviation.
//*               It will take inputs and perform calculations as many times as the user requests.
//*
//* 
//*
//****************************************************************
#include <iostream> // input output (io) stream/library
#include <cmath> // for calculations
using namespace std; // use the standard namespace

// declaring the four functions
void calculateStats(double score1, double score2, double score3, double score4, double& mean, double& stdDev); // overall function that has smaller functions embedded for calculating stats
double calculateMean(double score1, double score2, double score3, double score4); // takes 4 scores and returns mean
double calculateStandardDeviation(double score1, double score2, double score3, double score4, double mean); // takes 4 scores and mean of those scores and returns standard deviation
bool isValidInput(double score); // input validation function

// the main function
int main() {
    double score1, score2, score3, score4, mean, stdDev; // the variables declared
    char choice = 'y'; // the choice variable declared and initialized - used for determining how many times inputs should be taken and calculations should occur
    
    // the program continues while choice is y, which will be seen after first time taking inputs and performing calculations - also allows for capital Y if user uses a capital letter
    while (choice == 'y' || choice == 'Y') {
        // get score 1
        cout << "Enter four scores:" << endl;
        cout << "Score 1: ";
        cin >> score1;
        // checks score 1 validity and repeats while loop until a valid input is provided
        while (!isValidInput(score1)) {
            cout << "Invalid input. Please enter a valid score." << endl;
            cout << "Score 1: ";
            cin >> score1;
        }
        // get score 2
        cout << "Score 2: ";
        cin >> score2;
        // checks score 2 validity and repeats while loop until a valid input is provided
        while (!isValidInput(score2)) {
            cout << "Invalid input. Please enter a valid score." << endl;
            cout << "Score 2: ";
            cin >> score2;
        }
        // get score 3
        cout << "Score 3: ";
        cin >> score3;
        // checks score 3 validity and repeats while loop until a valid input is provided
        while (!isValidInput(score3)) {
            cout << "Invalid input. Please enter a valid score." << endl;
            cout << "Score 3: ";
            cin >> score3;
        }
        // get score 4
        cout << "Score 4: ";
        cin >> score4;
        // checks score 4 validity and repeats while loop until a valid input is provided
        while (!isValidInput(score4)) {
            cout << "Invalid input. Please enter a valid score." << endl;
            cout << "Score 4: ";
            cin >> score4;
        }
        
        // calling for the use of the larger function for calculating all stats, which includes the mean and standard deviation embedded calculation functions
        calculateStats(score1, score2, score3, score4, mean, stdDev);

        // prints the calculated stats - mean and standard deviation
        cout << "Mean: " << mean << endl;
        cout << "Standard Deviation: " << stdDev << endl;

        // here is where the choice variable is used for determing if new inputs should be taken for new calculations
        cout << "Do you want to calculate for another set of scores? (y/n): ";
        cin >> choice;
        cout << endl;
    }

    // prints that the program has ended and ends the program with the return 0
    cout << "Program ended." << endl;
    return 0;
}

// Here is where all of the previously declared functions are defined

// defines the larger stats calculation function, which has reference variables that are based off of smaller embedded calculation functions for mean and standard deviation
void calculateStats(double score1, double score2, double score3, double score4, double& mean, double& stdDev) {
    mean = calculateMean(score1, score2, score3, score4);
    stdDev = calculateStandardDeviation(score1, score2, score3, score4, mean);
}

// calculates mean
double calculateMean(double score1, double score2, double score3, double score4) {
    return (score1 + score2 + score3 + score4) / 4.0;
}

// calculates standard deviation
double calculateStandardDeviation(double score1, double score2, double score3, double score4, double mean) {
    double sumSquaredDifferences = pow(score1 - mean, 2) + pow(score2 - mean, 2) + pow(score3 - mean, 2) + pow(score4 - mean, 2);
    return sqrt(sumSquaredDifferences / 4.0);
}

// checks for input validity
bool isValidInput(double score) {
    return score >= 0;
}