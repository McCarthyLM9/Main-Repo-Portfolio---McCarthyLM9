//****************************************************************
//*  FILE NAME: MissileGame.cpp
//*
//*   AUTHOR: Leonard McCarthy
//*
//*  DESCRIPTION: Calculate the range of a projectile fired at an angle and 
//*  fire up to 5 shots to see if you can get within 0.1% tolerance of the target (very close to the necessary target distance).
//* 
//*
//****************************************************************
#include <iostream> // input/output stream and basic code
#define _USE_MATH_DEFINES // I had to look this up and apparently, it's needed for microsoft products like VS Code to actual use the math defines from cmath
#include <cmath> // for math defines like M_PI and sin
using namespace std; // using the standard namespace

// Gets the target distance in feet by asking for double distance until a value that's > 0 is given.
double GetTargetDistance() {
    double distance; // declare variable
    cout << "The distance to the target (in feet) must be > zero." << endl; // first ask
    cout << "Enter target distance: "; // first ask
    cin >> distance; // input variable
    // For next asks if a value > 0 wasn't already provided
    while (distance <= 0) {
        cout << "The distance must be greater than zero. Try again." << endl; // next asks
        cout << "Enter target distance: "; // next asks
        cin >> distance; // next variable inputs
    }
    return distance; // return inputted variable value that's > 0
}

// Gets the launcher angle in degrees by asking for double angle between 0 and 90, exclusive.
double GetLauncherAngle() {
    double angle; // declare variable
    cout << "The launcher angle (in degrees) must be in-between zero and ninety." << endl; // first ask
    cout << "Enter launcher angle: "; // first ask
    cin >> angle; // input variable
    // For next asks if a value between 0 and 90, exclusive, wasn't already provided
    while (angle <= 0 || angle >= 90) {
        cout << "The angle must be between zero and ninety degrees. Try again." << endl; // next asks
        cout << "Enter launcher angle: "; // next asks
        cin >> angle; // next variable inputs
    }
    return angle; // return the inputted variable that's between 0 and 90, exclusive
}

// converts degrees to radians by multiple degrees by pi/180.
double DegreesToRadians(double degrees) {
    return degrees * M_PI / 180.0; // returns the value of radians
}

// Gets the missile velocity in ft/sec by asking for double velocity that's > 0.
double GetMissileVelocity() {
    double velocity; // declare variable
    cout << "The missile velocity (in feet per second) must be greater than zero." << endl; // first ask
    cout << "Enter missile velocity: "; // first ask
    cin >> velocity; // input variable
    // For next asks if a value > 0 wasn't already provided
    while (velocity <= 0) {
        cout << "The velocity must be greater than zero. Try again." << endl; // next asks
        cout << "Enter missile velocity: "; // next asks
        cin >> velocity; // next variable inputs
    }
    return velocity; // return the inputted variable that's > 0
}

// calculates missile distance via equation: (velocity * velocity * sin(2 * angleRadians)) / 32.2;
double CalculateMissileDistance(double velocity, double angleRadians) {
    return (velocity * velocity * sin(2 * angleRadians)) / 32.2; // return missile distance value
}

// calculates whether it's a winning range
bool CalculateWinningRange(double missileDistance, double targetDistance) {
    double tolerance = 0.001 * targetDistance; // calculate tolerance (accepted margin of error distance to target)
    return abs(missileDistance - targetDistance) <= tolerance; // returns true/false depending on adherence to value of equation result compared to tolerance
}

// Prints the values
void PrintSummary(int shotNumber, double targetDistance, double angle, double velocity, double missileDistance) {
    cout << "****************************************************************************" << endl;
    cout << "Shot Number: " << shotNumber << endl; // output shot number
    cout << "Target Distance: " << targetDistance << endl; // output target distance
    cout << "Launcher Angle: " << angle << endl; // output launcher angle
    cout << "Missile Velocity: " << velocity << endl; // output missile velocity
    cout << "Missile Distance: " << missileDistance << endl; // output missile distance
    cout << endl;

    double difference = missileDistance - targetDistance; // declare and initialize variable
    // for if target is overshot
    if (difference > 0) {
        cout << "The missile landed " << difference << " feet past the target." << endl;
    }
    // for if target is undershot
    else {
        cout << "The missile landed " << abs(difference) << " feet short of the target." << endl;
    }
    cout << "**********************************************************" << endl;
}

// main function
int main() {
    double targetDistance; // declare variable target distance
    int maxTries = 5; // declare and initialize max number of tries variable

    targetDistance = GetTargetDistance(); // equate target distance variable to the function that gets its value

    // goes through the code until max tries is reached
    for (int shot = 1; shot <= maxTries; ++shot) {
        double angleDegrees = GetLauncherAngle(); // equate angle degrees variable to the function that gets it
        double velocity = GetMissileVelocity(); // equate velocity variable to the function that gets it
        double angleRadians = DegreesToRadians(angleDegrees); // equate angle radians variable to the function that gets it

        double missileDistance = CalculateMissileDistance(velocity, angleRadians); // equate missile distance to the function that gets it using parameters velocity and angle radians

        PrintSummary(shot, targetDistance, angleDegrees, velocity, missileDistance); // use the print summary function to print the values

        // for if calculate winning range function returns true
        if (CalculateWinningRange(missileDistance, targetDistance)) {
            cout << "Hit! You win the game!" << endl; // hit and game won
            return 0; // return 0 to end code/program
        }
    }

    cout << "Game Over. Play again." << endl; // game over
    return 0; // return 0 to end code/program
}