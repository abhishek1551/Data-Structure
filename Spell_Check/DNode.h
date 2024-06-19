

#ifndef DNODE_
#define DNODE_
/**
 * A node class for a doubly linked list.
 * @param <ItemType> The type of data stored in the node.
 */
template<class ItemType>
class DNode
{
private:
   ItemType item; 
   DNode<ItemType>* next; 
   DNode<ItemType>* previous; 

public:
	 /**
     * Constructs a new node with null data and null pointers.
     */
   DNode();
   /**
     * Constructs a new node with the specified data and null pointers.
     * @param anItem The data to store in the node.
     */
   DNode(const ItemType& anItem);
    /**
     * Constructs a new node with the specified data and pointers.
     * @param anItem The data to store in the node.
     * @param nextNodePtr The next node in the list.
     * @param prevNodePtr The previous node in the list.
     */
   DNode(const ItemType& anItem, DNode<ItemType>* nextNodePtr, DNode<ItemType>* prevNodePtr);
    /**
     * Sets the data stored in the node.
     * @param anItem The new data to store in the node.
     */
   void setItem(const ItemType& anItem);
   /**
     * Sets the next node in the list.
     * @param nextNodePtr The next node in the list.
     */
   void setNext(DNode<ItemType>* nextDNodePtr);
   /**
     * Sets the previous node in the list.
     * @param prevNodePtr The previous node in the list.
     */
   void setPrevious(DNode<ItemType>* prevDNodePtr);
       /**
     * Returns the data stored in the node.
     * @return The data stored in the node.
     */
   ItemType getItem() const ;
     /**
     * Returns the next node in the list.
     * @return The next node in the list.
     */
   DNode<ItemType>* getNext() const ;
   
    /**
     * Returns the previous node in the list.
     * @return The previous node in the list.
     */
   DNode<ItemType>* getPrevious() const ;
}; 

#include "DNode.cpp"
#endif
