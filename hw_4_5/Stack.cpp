#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack()
{
    top = nullptr;
}

Stack::~Stack()
{
    Node *nodePtr = nullptr;
    Node *nextNode = nullptr;

    nodePtr = top;

    while(nodePtr != nullptr){
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void Stack::push(int num)
{
    Node *newNode = nullptr;

    newNode = new Node;
    newNode->value = num;

    if(isEmpty()){
        top = newNode;
        newNode->next = nullptr;
    }else{
        newNode->next = top;
        top = newNode;
    }
}

void Stack::pop(int &num)
{
    Node *temp = nullptr;

    if(isEmpty()){
        cout << "The stack is empty.\n";
    }else{
        num = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
}

bool Stack::isEmpty()
{
    bool status;

    if(!top){
        status = true;
    }else{
        status = false;
    }
    return status;
}