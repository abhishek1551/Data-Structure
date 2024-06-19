#include <string>
#include <iostream>
#include "DoublyLinkedBag.h" // Include the header for the doubly linked list bag
#include "DoublyLinkedBag.cpp" // Include the implementation file for the doubly linked list bag

using namespace std;

// Function to display the contents of the bag
void displayBag(const DLinkedBag<string>& bag) {
    cout << "The bag contains " << bag.getCurrentSize() << " items:" << endl;
    vector<string> bagItems = bag.toVector(); // Convert the bag contents to a vector
    int numberOfEntries = (int) bagItems.size();
    for (int i = 0; i < numberOfEntries; i++) {
        cout << bagItems[i] << " "; // Print each item in the bag
    }
    cout << endl << endl;
} // end displayBag

// Function to test various operations on the bag
void bagTester(DLinkedBag<string>& bag) {
    // Check if the bag is initially empty
    cout << "isEmpty: returns " << bag.isEmpty() << "; should be 1 (true)" << endl;
    displayBag(bag); // Display the initial contents of the bag (should be empty)

    // Add items to the bag
    string items[] = {"one", "two", "three", "four", "five", "one"};
    cout << "Add 6 items to the bag: " << endl;
    for (int i = 0; i < 6; i++) {
        bag.add(items[i]);
    }
    displayBag(bag); // Display the contents after adding items

    // Perform various checks on the bag
    cout << "isEmpty: returns " << bag.isEmpty() << "; should be 0 (false)" << endl;
    cout << "getCurrentSize: returns " << bag.getCurrentSize() << "; should be 6" << endl;
    cout << "Try to add another entry: add(\"extra\") returns " << bag.add("extra") << endl;
    cout << "contains(\"three\"): returns " << bag.contains("three") << "; should be 1 (true)" << endl;
    cout << "contains(\"ten\"): returns " << bag.contains("ten") << "; should be 0 (false)" << endl;
    cout << "getFrequencyOf(\"one\"): returns " << bag.getFrequencyOf("one") << " should be 2" << endl;

    // Remove items from the bag and check frequencies
    cout << "remove(\"one\"): returns " << bag.remove("one") << "; should be 1 (true)" << endl;
    cout << "getFrequencyOf(\"one\"): returns " << bag.getFrequencyOf("one") << " should be 1" << endl;
    cout << "remove(\"one\"): returns " << bag.remove("one") << "; should be 1 (true)" << endl;
    cout << "remove(\"one\"): returns " << bag.remove("one") << "; should be 0 (false)" << endl;
    cout << endl;

    displayBag(bag); // Display the contents after removals

    // Clear the bag and check if it is empty
    cout << "After clearing the bag, ";
    bag.clear();
    cout << "isEmpty: returns " << bag.isEmpty() << "; should be 1 (true)" << endl;
} // end bagTester

int main() {
    DLinkedBag<string> bag; // Create an instance of the bag
    cout << "Testing the Link-Based Bag:" << endl;
    cout << "The initial bag is empty." << endl;
    bagTester(bag); // Test the bag operations
    cout << "All done!" << endl;
    return 0;
} // end main
