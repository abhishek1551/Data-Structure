# People Database Management System

## Overview
This project implements a console-based application for managing a database of people using a Binary Search Tree (BST) data structure. Users can perform operations such as adding, removing, editing, searching, and displaying both unsorted and sorted data entries. The application allows for efficient management and retrieval of person records using the BST's properties for fast searching and sorting.

## Features
* Add Person: Adds a new person to the database with their name and birthday.

* Remove Person: Deletes a person from the database based on their name and birthday.

* Edit Person: Modifies an existing person's details, including their name and birthday.

* Search Person: Checks if a person exists in the database based on their name and birthday.

* Display Unsorted Data: Lists all people in the database in the order they were added.

* Display Sorted Data: Displays all people in the database sorted alphabetically by name using the BST's properties.

* Save & Quit: Persists the current database state to a file named "output.txt" and exits the program.

* Exit without Saving: Exits the program without saving any changes made during the session.

## Components
* Main Function (main.cpp): Implements the core logic of the program where users interact via a menu-driven interface to perform operations on the PeopleDB database.

* PeopleDB Class (PeopleDB.h, PeopleDB.cpp): Manages the database operations using a Binary Search Tree (BST) to store and retrieve People objects efficiently.

* People Class (People.h, People.cpp): Represents individual people with attributes such as name and birthday.

* Date Class (Date.h, Date.cpp): Assists in handling date-related operations for storing birthdays.

* BinaryNode Class (BinaryNode.h, BinaryNode.cpp): Defines the structure of nodes used in the Binary Search Tree (BST) to hold People objects.

* BinaryNodeTree Class (BinaryNodeTree.h, BinaryNodeTree.cpp): Implements the Binary Search Tree (BST) data structure and operations like insertion, deletion, searching, and traversal.

* BinarySearchTree Class (BinarySearchTree.h, BinarySearchTree.cpp): Provides an interface for interacting with the Binary Search Tree (BST) data structure, including operations specific to a BST.


## Files
* main.cpp: Implements the main program logic, including user interaction and menu-driven operations.

* PeopleDB.h and PeopleDB.cpp: Contains the PeopleDB class implementation for managing the database operations using a BST.

* People.h and People.cpp: Defines the People class representing individual persons with their attributes.

* Date.h and Date.cpp: Provides the Date class for handling date-related operations.

* BinaryNode.h and BinaryNode.cpp: Defines the BinaryNode class representing nodes in the Binary Search Tree (BST).

* BinaryNodeTree.h and BinaryNodeTree.cpp: Implements the BinaryNodeTree class for managing the Binary Search Tree (BST) structure and operations.

* BinarySearchTree.h and BinarySearchTree.cpp: Provides an interface for interacting with the Binary Search Tree (BST) data structure.


## Data Structure

* The project utilizes a Binary Search Tree (BST) to manage and organize the database of people efficiently:

* BST Operations: Enables fast insertion, deletion, searching, and sorting of People objects based on their names.

* Tree Traversal: Supports in-order traversal to display data alphabetically sorted by name.

## Conclusion
This project showcases the use of a Binary Search Tree as a fundamental data structure for efficient management of a database of people. It demonstrates practical implementation of BST operations in a real-world application, offering users a seamless experience for managing and querying person records.

