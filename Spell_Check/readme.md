Spelling Checker Program:
The goal of this program is to check a given input file for spelling errors by comparing each word in the file to a dictionary of correctly spelled words.
The program outputs a list of any misspelled words found in the input file.

Input
Dictionary File: Contains a list of correctly spelled words.
Input File: Contains a list of words to check for spelling errors.

Output
A list of any misspelled words found in the input file.

Approach
Data Structure: Uses a DLinkedBag data structure to store words from the dictionary and any misspelled words.

Reading Files:
Reads the dictionary file and adds each word to the DLinkedBag.
Reads the input file and checks each word for spelling errors.

Checking Words:
Compares each word from the input file with the dictionary.
If a word is not found in the dictionary, it is added to the misspelledWords DLinkedBag.


Output: Prints the list of misspelled words to the console.
Words are separated by whitespace (spaces, tabs, newlines).

Note:
The program does not consider capitalization or punctuation (e.g., "Apple" and "apple!" are different words).
The output is a list of misspelled words without suggestions for corrections.
