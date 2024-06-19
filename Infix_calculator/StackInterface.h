#ifndef STACKINTERFACE_H_
#define STACKINTERFACE_H_
#include "PrecondViolatedException.h"

/**
 * The StackInterface class is an abstract base class that defines the
 * operations for a generic stack data structure.
 * 
 * @tparam ItemType the type of the items stored in the stack.
 */
template<class ItemType>
class StackInterface {
public:
    /**
     * Default constructor.
     */
    StackInterface();
    
    /**
     *destructor to ensure proper cleanup of any derived classes.
     */
    virtual ~StackInterface() { }

    /**
     * Returns true if the stack is empty, false otherwise.
     * 
     * @return true if the stack is empty, false otherwise.
     */
    virtual bool isEmpty() const=0;

    /**
     * Pushes a new item onto the top of the stack.
     * 
     * @param newItem the new item to push onto the stack.
     * @return true if the operation was successful, false otherwise.
     */
    virtual bool push(const ItemType& newItem)=0;

    /**
     * Removes the top item from the stack.
     * 
     * @return true if the operation was successful, false otherwise.
     */
    virtual bool pop()=0;

    /**
     * Returns the top item of the stack without removing it.
     * 
     * @return the top item of the stack.
     * @throws PrecondViolatedExcep if the stack is empty.
     */
    virtual ItemType peek() const throw(PrecondViolatedException)=0;


};

#endif
