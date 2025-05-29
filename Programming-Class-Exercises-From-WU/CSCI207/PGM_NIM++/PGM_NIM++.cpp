#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
using namespace std;

// Function to determine if the picked object is orange based on the described method in the prompt about a ratio
bool isOrange(int totalObjects, int orangeCount) {
    if (orangeCount == 0) {
        return false; // No orange objects left
    }
    int ratio = totalObjects / orangeCount;
    int randomNum = rand() % ratio; // Generate a random number based on ratio

    return (randomNum == 0); // Return true if the picked object is orange
}

int main() {
    // Initializing game variables
    int blackCount = 23;
    int orangeCount = 7;
    int totalObjects = blackCount + orangeCount;
    string playerName;

    cout << "Welcome to the Game of NIM++!" << endl;
    cout << "Enter your name: ";
    cin >> playerName;

    srand(time(0)); // Seed the random number generator
    // Allows the random numbers for the computer to use different sequences for each turn, creating a more fully realized game via more variety

    // Game loop
    while (blackCount > 0) {
        // Player's turn
        cout << endl << playerName << "'s turn. Total objects: " << totalObjects << endl;
        cout << "Enter your move (1, 2, or 3): ";
        int playerMove;
        cin >> playerMove;

        // Validate the player's move
        while (playerMove < 1 || playerMove > 3 || playerMove > totalObjects) {
            cout << "Invalid move. Please enter a number between 1 and 3 and not more than the total objects: ";
            cin >> playerMove;
        }

        // Remove objects and determine if they are orange or black
        for (int i = 0; i < playerMove; ++i) {
            if (isOrange(totalObjects, orangeCount)) {
                orangeCount--;
            }
            else {
                blackCount--;
                if (blackCount == 0) {
                    cout << playerName << " picked the last black object. " << playerName << " loses!" << endl;
                    cout << "Computer wins!" << endl;
                    return 0;
                }
            }
            totalObjects--;
        }

        // Check if there are any black objects left
        if (blackCount == 0) {
            cout << playerName << " wins!" << endl;
            return 0;
        }

        // Computer's turn
        cout << endl << "Computer's turn." << endl;
        int computerMove = rand() % 3 + 1; // Generate a move between 1 and 3
        while (computerMove > totalObjects) {
            computerMove = rand() % 3 + 1; // Ensure it's less than total objects
        }
        cout << "Computer removes " << computerMove << " objects." << endl;

        // Remove objects and determine if they are orange or black
        for (int i = 0; i < computerMove; ++i) {
            if (isOrange(totalObjects, orangeCount)) {
                orangeCount--;
            }
            else {
                blackCount--;
                if (blackCount == 0) {
                    cout << "Computer picked the last black object. Computer loses!" << endl;
                    cout << playerName << " wins!" << endl;
                    return 0;
                }
            }
            totalObjects--;
        }

        // Check if there are any black objects left
        if (blackCount == 0) {
            cout << "Computer wins!" << endl;
            return 0;
        }
    }

    return 0;
}