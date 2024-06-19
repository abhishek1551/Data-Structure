
#include "DoublyLinkedBag.h"
#include "BagInterface.h"

#include <cstddef>

template<class ItemType>
DLinkedBag<ItemType>::DLinkedBag() : headPtr(NULL), tailPtr(NULL), itemCount(0)
{
}  // end default constructor

template<class ItemType>
DLinkedBag<ItemType>::DLinkedBag(const DLinkedBag<ItemType>& aBag)
{
    itemCount = aBag.itemCount;
    DNode<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain

    if (origChainPtr == NULL)
        headPtr = NULL;  // Original bag is empty
    else
    {
        // Copy first node
        headPtr = new DNode<ItemType>();
        headPtr->setItem(origChainPtr->getItem());
        tailPtr = headPtr;

        // Copy remaining nodes

        origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer

        while (origChainPtr != NULL)
        {
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();

            // Create a new node containing the next item
            DNode<ItemType>* newNodePtr = new DNode<ItemType>(nextItem);

            // Link new node to end of new chain
            tailPtr->setNext(newNodePtr);
            newNodePtr->setPrevious(tailPtr);
            // Advance pointer to new last node
            tailPtr = tailPtr->getNext();

            // Advance original-chain pointer
            origChainPtr = origChainPtr->getNext();
        }  // end while

        tailPtr->setNext(NULL);              // Flag end of chain
    }  // end if
}  // end copy constructor

template<class ItemType>
DLinkedBag<ItemType>::~DLinkedBag()
{
    clear();
}  // end destructor

template<class ItemType>
bool DLinkedBag<ItemType>::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int DLinkedBag<ItemType>::getCurrentSize() const
{
    return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool DLinkedBag<ItemType>::add(const ItemType& newEntry)
{
    // Create a new node
    DNode<ItemType>* newNodePtr = new DNode<ItemType>(newEntry);

    // Insert the new node at the beginning of the list
    if (headPtr == NULL) {
        // The list is empty, so make the new node the head
        headPtr = newNodePtr;
        tailPtr = newNodePtr;
    } else {
        // The list is not empty, so insert the new node before the head
        newNodePtr->setNext(headPtr);
        headPtr->setPrevious(newNodePtr);
        headPtr = newNodePtr;
    }
   itemCount++;
   
   return true;
}





template<class ItemType>
vector<ItemType> DLinkedBag<ItemType>::toVector() const
{
   vector<ItemType> bagContents;
   DNode<ItemType>* curPtr = headPtr;
   int counter = 0;
	while ((curPtr != NULL) && (counter < itemCount))
   {
		bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }  // end while
   
   return bagContents;
}  // end toVector

template<class ItemType>
bool DLinkedBag<ItemType>::remove(const ItemType& anEntry)
{
   DNode<ItemType>* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != NULL);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());

      // Delete first node
      DNode<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();

      if (headPtr != NULL) { // check if the list is not empty
          headPtr->setPrevious(NULL); // set the previous pointer of the new head node to NULL
      } else {
          tailPtr = NULL; // set the tail pointer to NULL since the list is now empty
      }

      // Return node to the system
      nodeToDeletePtr->setNext(NULL);
      delete nodeToDeletePtr;
      nodeToDeletePtr = NULL;

      itemCount--;
   } // end if

   return canRemoveItem;
}  // end remove

template<class ItemType>
void DLinkedBag<ItemType>::clear()
{
   DNode<ItemType>* nodeToDeletePtr = headPtr;
   while (headPtr != NULL)
   {
      headPtr = headPtr->getNext();

      // Return node to the system
      nodeToDeletePtr->setNext(NULL);
      nodeToDeletePtr->setPrevious(NULL);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is NULL; nodeToDeletePtr is NULL
   	tailPtr= NULL;
	itemCount = 0;
}  // end clear

template<class ItemType>
int DLinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
   int counter = 0;
   DNode<ItemType>* curPtr = headPtr;
   while ((curPtr != NULL) && (counter < itemCount))
   {
      if (anEntry == curPtr->getItem())
      {
         frequency++;
      } // end if
      
      counter++;
      curPtr = curPtr->getNext();
   } // end while
   
	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool DLinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != NULL);
}  // end contains

/* ALTERNATE 1
template<class ItemType>
bool DoublyLinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   return getFrequencyOf(anEntry) > 0;
} 
*/
/* ALTERNATE 2 
template<class ItemType>
bool DoublyLinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   int i = 0;
   while (!found && (curPtr != NULL) && (i < itemCount))
   {
      if (anEntry == curPtr-<getItem())
      {
         found = true;
      }
      else
      {
         i++;
         curPtr = curPtr->getNext();
      }  // end if
   }  // end while

   return found;
}  // end contains
*/

// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
DNode<ItemType>* DLinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
   bool found = false;
   DNode<ItemType>* curPtr = headPtr;
   
   while (!found && (curPtr != NULL))
   {
      if (anEntry == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   } // end while
   
   return curPtr;
} // end getPointerTo


