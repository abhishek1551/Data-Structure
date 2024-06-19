#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "StackInterface.h"
#include "PrecondViolatedException.h"

// Template class definition for LinkedStack
template<class ItemType>
class LinkedStack : public StackInterface<ItemType> {
private:
    // Nested Node class to represent each element in the stack
    class Node {
    public:
        ItemType item; // Data stored in the node
        Node* next;    // Pointer to the next node

        // Node constructor
        Node(const ItemType& anItem, Node* nextNodePtr = NULL) :
            item(anItem), next(nextNodePtr) {}
    };
    
    Node* topPtr; // Pointer to the top of the stack

public:
    // Default constructor
    LinkedStack();

    // Destructor
    ~LinkedStack();

    // Check if the stack is empty
    bool isEmpty() const;

    // Push a new item onto the stack
    bool push(const ItemType& newItem);

    // Pop the top item from the stack
    bool pop();

    // Peek at the top item of the stack without removing it
    ItemType peek() const throw(PrecondViolatedException);
};

//#include "LinkedStack.cpp"

#endif
