
#include "DNode.h"
#include <cstddef>

// Constructor
template<class ItemType>
DNode<ItemType>::DNode() {
    next = NULL;
    previous = NULL;
}

// Constructor
template<class ItemType>
DNode<ItemType>::DNode(const ItemType& anItem) {
    item = anItem;
    next = NULL;
    previous = NULL;
}

// Constructor
template<class ItemType>
DNode<ItemType>::DNode(const ItemType& anItem, DNode<ItemType>* nextDNodePtr, DNode<ItemType>* prevDNodePtr) {
    item = anItem;
    next = nextDNodePtr;
    previous = prevDNodePtr;
}

// Setter for item
template<class ItemType>
void DNode<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
}

// Setter for next
template<class ItemType>
void DNode<ItemType>::setNext(DNode<ItemType>* nextDNodePtr) {
    next = nextDNodePtr;
}

// Setter for prev
template<class ItemType>
void DNode<ItemType>::setPrevious(DNode<ItemType>* prevDNodePtr) {
    previous = prevDNodePtr;
}

// Getter for item
template<class ItemType>
ItemType DNode<ItemType>::getItem() const {
    return item;
}

// Getter for next
template<class ItemType>
DNode<ItemType>* DNode<ItemType>::getNext() const {
    return next;
}

// Getter for prev
template<class ItemType>
DNode<ItemType>* DNode<ItemType>::getPrevious() const {
    return previous;
}
