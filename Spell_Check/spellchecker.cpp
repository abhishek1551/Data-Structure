#include <iostream>
#include <fstream>
#include <string>
#include "DoublyLinkedBag.h"
#include "DoublyLinkedBag.cpp"

using namespace std;

int main() {
    // Step 1: Read the list of correctly spelled words from a file and insert into dictionary
    DLinkedBag<string> dictionary;
    string word;
    ifstream dictionaryFile("dictionary.txt");

    if (dictionaryFile.is_open()) {
        while (dictionaryFile >> word) {
            dictionary.add(word);
        }
        dictionaryFile.close();
    } else {
        cerr << "Failed to open dictionary file." << endl;
        return 1;
    }

    // Step 2: Read the input file containing words to check for spelling errors
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Failed to open input file." << endl;
        return 1;
    }

    // Step 3 and 4: Check each word in the input file for spelling errors
    
    DLinkedBag<string> misspelledWords;

    while (inputFile >> word) {
        if (!dictionary.contains(word)) {
            misspelledWords.add(word);
        }
    }

    // Step 5: Print the list of misspelled words
    if (misspelledWords.getCurrentSize() == 0) {
        cout << "No misspelled words found in the input file." << endl;
    } 
	else {
        cout << "Misspelled words found in the input file: " << endl;
        vector<string> misspelledWordsVector = misspelledWords.toVector();
        for (int i = 0; i < misspelledWordsVector.size(); i++) {
        cout << misspelledWordsVector[i] << endl;
    	}
    }
    return 0;
    }

    


