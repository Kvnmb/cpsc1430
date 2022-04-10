// Implementation file

#include <iostream>
#include "FancyList.h"

using namespace std;

FancyList::FancyList() // default constructor
{
    head = nullptr;
}

void FancyList::appendNode(int num) // takes input to create and append node
{
    Node *newNode;
    Node *nodePtr;

    newNode = new Node; // dynamic allocation
    newNode->value = num; // stores num into the new node
    newNode->next = nullptr; // node will be at the end of list so null

    if(!head){ // sets node to the head if list is empty
        head = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
    }else{
        nodePtr = head; // sets nodePtr to head for traversing

        while(nodePtr->next){ // loop iterates until nodePtr's next is null
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode; // sets last node in list's ptr to newNode
        newNode->prev = nodePtr; // sets the previous ptr to the last node
    }
}

void FancyList::printList() // prints out the values in the linked list
{
    Node *nodePtr;

    nodePtr = head; // starts at head to traverse

    while(nodePtr){ // until nodePtr = nullptr,
        cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}

void FancyList::reverseList() // reverses the list
{
    Node *nextNode;
    Node *prevNode;
    Node *nodePtr;

     if(!head){ // checks for empty list
        cout << "\nEmpty list\n" ;
        return;
    }else{
        nodePtr = head; // sets nodePtr to head to traverse
        prevNode = nullptr;
        nextNode = nullptr;

        // loop to reverse the list
        while(nodePtr != nullptr){// until nodePtr hits end of list
            nextNode = nodePtr->next; // nextNode holds the next pointer
            prevNode = nodePtr->prev; // prevNode holds the previous one
            nodePtr->next = prevNode; // nodePtr's next points to prevNode
            nodePtr->prev = nextNode; // nodePtr's prev points to nextNode
            nodePtr = nextNode; // nodePtr moves on in list
        }

        head = prevNode->prev; // head is now the "last" node in list
    }
}

void FancyList::deleteNode(int num) // takes input from user to delete node
{
    int count = 0;
    Node *nodePtr;
    Node *prevNode;

    if(!head){ // checks for empty list
        cout << "\nEmpty list\n" ;
        return;
    }else{ // if negative, returns
        if(num <= 0){
            cout << "\nInvalid input\n" ;
            return;
        }

        nodePtr = head; // sets nodePtr to head
        prevNode = nullptr;
        while(nodePtr != nullptr){ // until nodePtr reaches end of list
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
            count++; // counter counts how many nodes in list
        }

        if(num > count){ // checks if the number is outside range
            cout << "\nNot enough nodes in the list\n" ;
            return;
        }else{
            if(num == 1){ // if user wants to delete end of list
                if(count == 1){ // checks if there is only one node in list
                    delete prevNode;
                    head = nullptr;
                    return;
                }else{ // only deletes last node in list
                    nodePtr = prevNode;
                    prevNode = prevNode->prev;
                    prevNode->next = nullptr;
                    delete nodePtr;
                }
            }else{
                // starts from end of list and counts back
                for(int x = 1; x < num; x++){
                    nodePtr = prevNode;
                    prevNode = prevNode->prev; // prevNode will be deleted
                }
                if(prevNode == head){ // if the deleted node is the head
                    head = nodePtr; // sets head to node after the head
                    nodePtr->prev = nullptr;
                    delete prevNode;
                    return;
                }else{ // deletes the node like normal, setting the
                // next ptr of previous node to the one after deleted node
                // and the prev node of the next node to the one before
                // the deleted node
                    prevNode->prev->next = nodePtr;
                    nodePtr->prev = prevNode->prev;
                    delete prevNode;
                }
            }
        }
    }
}

FancyList::~FancyList() // destructor
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
