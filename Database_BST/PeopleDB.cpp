#include "PeopleDB.h"
#include <cstdlib>

ofstream of;

void toFile (People& p) {
	of << p << endl;
}

void toScreen (People& p) {
	cout << p << endl;
}

// Constructor
PeopleDB::PeopleDB(const std::string& filename) {
    // Open input file stream
    std::ifstream inputFile;
    inputFile.open(filename.c_str());


    // Check if file was opened successfully
    if (!inputFile) {
        std::cerr << "Error opening file" << filename << std::endl;
        //exit(1);
    }

    // Read data from file and add to BST
    while (inputFile) {
        std::string name;
        Date bday;
        inputFile >> name >> bday;
        if (name != "") {
            People person(name, bday);
            addPerson(person);
        }
    }

    // Close input file stream
    inputFile.close();
}

// Display unsorted list of people
void PeopleDB::displayUnsorted() const {
    std::cout << "People in database (unsorted):" << std::endl;
    database.preorderTraverse(toScreen);
}

// Display sorted list of people
void PeopleDB::displaySorted() const {
    std::cout << "People in database (sorted):" << std::endl;
    database.inorderTraverse(toScreen);
}

// Search for a person in the database
bool PeopleDB::searchPerson(const People& person) const {
    return database.contains(person);
}

// Add a person to the database
bool PeopleDB::addPerson(const People& person) {
    if (database.contains(person)) {
        return false; // person already exists in database
    }
    database.add(person);
    return true;
}

// Remove a person from the database
bool PeopleDB::removePerson(const People& person) {
    if (!database.contains(person)) {
        return false; // person not found in database
    }
    database.remove(person);
    return true;
}

// Modify a person's information in the database
bool PeopleDB::modifyPerson(const People& oldPerson, const People& newPerson) {
    if (!database.contains(oldPerson)) {
        return false; // old person not found in database
    }
    if (database.contains(newPerson)) {
        return false; // new person already exists in database
    }
    database.remove(oldPerson);
    database.add(newPerson);
    return true;
}

// Save database to file
void PeopleDB::saveToFile(const std::string& filename) const {
    // Open output file stream
    of.open(filename.c_str());

    // Check if file was opened successfully
    if (!of) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }

    // Write each person in database to file
    database.preorderTraverse(toFile);

    // Close output file stream
    of.close();
}