//****************************************************************
//*  FILE NAME: Project_CountWordsPoems.cpp
//*
//*   AUTHOR: Leonard McCarthy
//*
//*  DESCRIPTION: Write a program that reads in a poem, counts the number of words in the line.
//*               Then, output the poem in a new file with the word count for each line written to the left of each line.
//*               Output with format "wordCount: line" for each line.
//*
//****************************************************************
#include <iostream>   // Include the input-output stream library
#include <fstream>    // Include the file stream library for file handling
#include <sstream>    // Include the string stream library for manipulating strings
#include <string>     // Include the string library for using the string data type

using namespace std;  // Use the standard namespace

int countWords(string line) {
    istringstream stream(line);  // Create a string stream from the input line to extract words
    int wordCount = 0;            // Initialize a counter for the number of words
    string word;                  // Variable to hold each extracted word

    // Loop to extract words from the stream
    while (stream >> word) {
        wordCount++;               // Increment the word count for each word extracted
    }
    
    return wordCount;             // Return the total word count for the line
}

int main() {
    string inputFileName, outputFileName;  // Variables to hold the names of the input and output files
    ifstream inputFile;                     // Input file stream for reading the poem
    ofstream outputFile;                    // Output file stream for writing the formatted output

    // Prompt the user for the input file name
    cout << "Enter the input file name: ";
    getline(cin, inputFileName);           // Read the input file name from the user

    // Prompt the user for the output file name
    cout << "Enter the output file name: ";
    getline(cin, outputFileName);          // Read the output file name from the user

    // Open the input and output files
    inputFile.open(inputFileName);
    outputFile.open(outputFileName);

    // Check if the files opened successfully
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error opening file." << endl;  // Error message if files cannot be opened
        return 1;  // Exit the program with an error code
    }

    string line;  // Variable to hold each line read from the input file

    // Process each line in the input file
    while (getline(inputFile, line)) {           // Read a line from the input file
        int wordCount = countWords(line);        // Count the words in the current line
        outputFile << wordCount << ": " << line << endl; // Write the word count and line to the output file
    }

    // Close the input and output files after processing
    inputFile.close();
    outputFile.close();

    // Inform the user that the poem has been processed
    cout << "Poem has been processed and written to " << outputFileName << endl;

    return 0;  // Exit the program successfully
}