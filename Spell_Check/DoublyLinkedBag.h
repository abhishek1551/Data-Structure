
#ifndef DOUBLY_LINKED_BAG_
#define DOUBLY_LINKED_BAG_
#include "BagInterface.h"
#include "DNode.h"

template<class ItemType>
class DLinkedBag : public BagInterface<ItemType>
{
private:
   DNode<ItemType>* headPtr; // Pointer to first node
   DNode<ItemType>*tailPtr; //Pointer to last node
   int itemCount;           // Current count of bag items
   
   // Returns either a pointer to the node containing a given entry
   // or the null pointer if the entry is not in the bag.
   DNode<ItemType>* getPointerTo(const ItemType& target) const;
   
public:
   DLinkedBag();
   DLinkedBag(const DLinkedBag<ItemType>& aBag); // Copy constructor
   virtual ~DLinkedBag();                       // Destructor should be virtual
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool remove(const ItemType& anEntry);
   void clear();
   bool contains(const ItemType& anEntry) const;
   int getFrequencyOf(const ItemType& anEntry) const;
   std::vector<ItemType> toVector() const;
}; // end LinkedBag

//#include "DoublyLinkedBag.cpp"
#endif
