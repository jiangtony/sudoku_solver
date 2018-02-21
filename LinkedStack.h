//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "StackInterface.h"
#include "Node.h"
#include "PreconditionViolatedException.h"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType>
{
private:
    Node<ItemType>* top_ptr_; // Pointer to first node in the chain;
                           // this node contains the stack's top
public:
    // Constructors and destructor:
    LinkedStack();                                   // Default constructor
    LinkedStack(const LinkedStack<ItemType>& a_stack);// Copy constructor
    virtual ~LinkedStack();                          // Destructor

    // Stack operations:
    bool IsEmpty() const;
    bool Push(const ItemType& new_item);
    bool Pop();
    ItemType Peek();

}; // end LinkedStack

#include "LinkedStack.cpp"
#endif // LINKED_STACK_H
