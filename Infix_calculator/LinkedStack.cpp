#include "LinkedStack.h"

// Constructor: Initializes the stack with an empty top pointer
template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(NULL) {}

// Destructor: Deletes all nodes to free memory
template<class ItemType>
LinkedStack<ItemType>::~LinkedStack() {
    while (!isEmpty()) {
        pop();
    }
}

// Checks if the stack is empty by verifying if the top pointer is NULL
template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const {
    return topPtr == NULL;
}

// Pushes a new item onto the stack
template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem) {
    // Create a new node with newItem and set its next pointer to the current top
    Node* newNodePtr = new Node(newItem, topPtr);
    // Update the top pointer to the new node
    topPtr = newNodePtr;
    return true;
}

// Pops the top item from the stack
template<class ItemType>
bool LinkedStack<ItemType>::pop() {
    bool result = false;
    if (!isEmpty()) {
        // Pointer to the node to delete
        Node* nodeToDeletePtr = topPtr;
        // Update the top pointer to the next node
        topPtr = topPtr->next;
        // Clear the next pointer of the node to delete
        nodeToDeletePtr->next = NULL;
        // Delete the node to free memory
        delete nodeToDeletePtr;
        // Nullify the pointer
        nodeToDeletePtr = NULL;
        result = true;
    }
    return result;
}

// Peeks at the top item of the stack without removing it
template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const throw(PrecondViolatedException) {
    if (isEmpty()) {
        // Throw an exception if the stack is empty
        throw PrecondViolatedException("peek() called with empty stack");
    }
    // Return the item at the top of the stack
    return topPtr->item;
}
