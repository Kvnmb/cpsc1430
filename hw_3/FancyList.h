// Header file

#ifndef FANCYLIST_H
#define FANCYLIST_H

#include <iostream>
using namespace std;

class FancyList
{
    private:
    struct Node{ // doubly linked list
        int value;
        Node *prev; // points to previous pointer
        Node *next;
    };
    Node *head;

    public:
    FancyList(); // constructor
    void appendNode(int); // appends new nodes to end of list
    void printList(); // prints list from start to end
    void reverseList(); // reverses the list
    void deleteNode(int); // deletes nth node from end of list
    ~FancyList(); // destructor
};
#endif