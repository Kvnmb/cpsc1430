// Implementation file for OrderedList

#include <iostream>
#include "OrderedList.h"

using namespace std;

OrderedList::OrderedList() // default constructor
{
    head = nullptr;
}

// copy constructor 
OrderedList::OrderedList(OrderedList &obj)
{
    Node *newNode;
    Node *nodePtr;
    Node *objPtr;

    objPtr = obj.head; // sets ptr equal to object's node head

    newNode = new Node; // creates a new node and sets it to the head
    head = newNode;
    newNode->value = objPtr->value;
    objPtr = objPtr->next; // points to the referenced object's next node

    while(objPtr != nullptr){ // loop to create new copy nodes
    nodePtr = newNode; // sets nodePtr to newNode for linking
    newNode = new Node;
    nodePtr->next = newNode;
    newNode->value = objPtr->value; // copies values into newNode
    objPtr = objPtr->next;
    }
    
    newNode->next = nullptr; // sets the last node to nullptr
}

OrderedList::~OrderedList() // destructor
{
    Node *nodePtr;
    Node *nextNode;

    nodePtr = head; // sets nodePtr to the start of list

    cout << "\n\nDeallocating...\n";

    while(nodePtr != nullptr){ // until end of list, deletes the notes in order
        nextNode = nodePtr->next;
        cout << "\nDeleting " << nodePtr->value << "\n\n";
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void OrderedList::insert(int num) // function to insert nodes into list
{
    Node *newNode;
    Node *nodePtr;
    Node *prevNode = nullptr;

    newNode = new Node; // node with value created
    newNode->value = num;

    if(!head){ // if list is empty newNode becomes the head
        head = newNode;
        newNode->next = nullptr;
    }else{
        nodePtr = head; // sets node search to start at head
        prevNode = nullptr;

        // searches for the correct spot to put the inserted node
        while(nodePtr != nullptr && nodePtr->value < num){ 
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if(prevNode == nullptr){ // if the node is the first in the set
            head = newNode;
            newNode->next = nodePtr;
        }else{ // puts node in the correct position
            prevNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

void OrderedList::printList() // cycles through linked list to print values
{
    Node *nodePtr;

    nodePtr = head;

    while(nodePtr){ // until nodePtr = nullptr
        cout << nodePtr->value << " ";

        nodePtr = nodePtr->next;
    }
}