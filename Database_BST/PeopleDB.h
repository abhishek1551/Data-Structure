#ifndef PEOPLEDB_
#define PEOPLEDB_


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "People.h"
#include "BinarySearchTree.h"

using namespace std;

class PeopleDB {
    public:
        PeopleDB(const std::string& filename);
        //display unsorted and sorted methods use different traversal methods to print the items in sorted or unsorted order

        // @pre: None.
        // @post: Prints the list of people in unsorted order to the console.
        void displayUnsorted () const;

        // @pre: None.
        // @post: Prints the list of people in sorted order to the console.
        void displaySorted () const;

        // @pre: None.
        // @post: Searches for a specified person in the database and returns true if found, false otherwise.
        // @param: person: The person object to search for.
        bool searchPerson (const People& person) const;

        // @pre: None.
        // @post: Adds a new person to the database.
        // @param: person: The person object to add to the database.
        // @return: True if the person was added successfully, false otherwise.
        bool addPerson(const People& person);

        // @pre: None.
        // @post: Removes a specified person from the database.
        // @param: person: The person object to remove from the database.
        // @return: True if the person was removed successfully, false otherwise.
        bool removePerson(const People& person);

        // @pre: None.
        // @post: Modifies an existing person's information in the database.
        // @param: oldPerson: The person object to modify.
        // @param: newPerson: The new person object to replace the old one.
        // @return: True if the person was modified successfully, false otherwise.
        bool modifyPerson (const People& oldPerson, const People& newPerson);


    //save person
        void saveToFile(const std::string& filename) const;

    
    private:
    //To store people in BST
        BinarySearchTree<People> database;
};

#include "PeopleDB.cpp"
#endif



