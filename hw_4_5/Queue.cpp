#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}

Queue::~Queue()
{
    clear();
}

void Queue::enqueue(int num)
{
    Node *newNode = nullptr;

    newNode = new Node;
    newNode->value = num;
    newNode->next = nullptr;

    if(isEmpty()){
        front = newNode;
        rear = newNode;
    }else{
        rear->next = newNode;
        rear = newNode;
    }
    numItems++;
}

void Queue::dequeue(int &num)
{
    Node *temp = nullptr;

    if(isEmpty()){
        cout << "The queue is empty.\n";
    }else{
        num = front->value;

        temp = front;
        front = front->next;
        delete temp;

        numItems--;
    }
}

bool Queue::isEmpty() const
{
    bool status;

    if(numItems > 0){
        status = false;
    }else{
        status = true;
    }
    return status;
}

void Queue::clear()
{
    int value;

    while(!isEmpty()){
        dequeue(value);
    }
}

int Queue::total()
{
    return numItems;
}