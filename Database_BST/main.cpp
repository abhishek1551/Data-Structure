#include <iostream>
#include <string>
#include "PeopleDB.h"

using namespace std;

int main () {
    int menu;
    string filename;
    
    // asks for a filename
    cout << "Please enter filename: ";
    cin >> filename;
    
    // Loads data from file
    PeopleDB database(filename);
    
    // shows menu
    while (menu != 7 and menu != 8) {
        cout << endl << "Please choose an option below:" << endl
            << "1. Add" << endl
            << "2. Remove" << endl
            << "3. Edit" << endl
            << "4. Search" << endl
            << "5. Display unsorted data" << endl
            << "6. Display sorted data" << endl
            << "7. Save & quit" << endl
            << "8. Exit without saving" << endl
            << "--> ";
        cin >> menu;
        cout << endl;
        
        // executes menu actions
        switch (menu) {
            // Add
            case 1:
            {
                string name;
                Date bday;
                
                cout << "Please enter person's name: ";
                cin >> name;
                
                cout << "Please enter person's birthday (dd/mm/yyyy): ";
                cin >> bday;
                
                People person(name, bday);
                
                if (database.addPerson(person)) {
                    cout << "Person added successfully!" << endl;
                } else {
                    cout << "Failed to add person. Person already exists!" << endl;
                }
                break;
            }
            
            // Remove
            case 2:
            {
                string name;
                Date bday;
                
                cout << "Please enter person's name: ";
                cin >> name;
                
                cout << "Please enter person's birthday (dd/mm/yyyy): ";
                cin >> bday;
                
                People person(name, bday);
                
                if (database.removePerson(person)) {
                    cout << "Person removed successfully!" << endl;
                } else {
                    cout << "Failed to remove person. Person does not exist!" << endl;
                }
                break;
            }
            
            // Edit
            case 3:
            {
                string oldName, newName;
                Date oldBday, newBday;
                
                cout << "Please enter person's name to be modified: ";
                cin >> oldName;
                
                cout << "Please enter person's birthday (dd/mm/yyyy): ";
                cin >> oldBday;
                
                cout << "Please enter new person's name: ";
                cin >> newName;
                
                cout << "Please enter new person's birthday (dd/mm/yyyy): ";
                cin >> newBday;
                
                People oldPerson(oldName, oldBday);
                People newPerson(newName, newBday);
                
                if (database.modifyPerson(oldPerson, newPerson)) {
                    cout << "Person modified successfully!" << endl;
                } else {
                    cout << "Failed to modify person. Person does not exist!" << endl;
                }
                break;
            }
            
            // Search
            case 4:
            {
                string name;
                Date bday;
                
                cout << "Please enter person's name: ";
                cin >> name;
                
                cout << "Please enter person's birthday (dd/mm/yyyy): ";
                cin >> bday;
                
                People person(name, bday);
                
                if (database.searchPerson(person)) {
                    cout << "Person exists in database!" << endl;
                } else {
                    cout << "Person does not exist in database!" << endl;
                }
                break;
            }

               // Display unsorted data
            case 5: 
            {
                cout << "Displaying unsorted data:" << endl << endl;
                    database.displayUnsorted();
                    break;
            }

            case 6:
            {
                cout << "Displaying sorted data:" << endl << endl;
                    database.displaySorted();
                    break;
                    /*
                // Retrieve sorted data from database
                vector<People> sortedData = database.getSortedData();
                
                // Print sorted data
                for (const auto& person : sortedData) {
                    cout << person << endl;
                }
                */
                break;
            }


            // Save & quit
            case 7:
            {
                database.saveToFile("output.txt");
                cout << "Exiting program..." << endl;
                return 0;
            }

            case 8:
            {
                cout << "Exiting without saving changes..." << endl;
                return 0; // exit the program
                break;
            }

            // Invalid input
            default:
                cout << "Invalid input!" << endl;
            break;
    }   }

    return 0;
}


