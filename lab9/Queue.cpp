#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue(int s)
{
    queueArray = new int[s];
    queueSize = s;
    front = -1;
    rear = -1;
    numItems = 0;
}

Queue::~Queue()
{
    delete [] queueArray;
}

void Queue::enqueue(int num)
{
    if(isFull())
    {
        cout << "The queue is full.\n";
    }else{
        rear = (rear + 1) % queueSize;
        queueArray[rear] = num;
        numItems++;
    }
}

void Queue::dequeue(int &num)
{
    if(isEmpty()){
        cout << "The queue is empty.\n";
    }else{
        front = (front + 1) % queueSize;
        num = queueArray[front];
        numItems--;
    }
}

bool Queue::isEmpty() const
{
    bool status;

    if(numItems){
        status = false;
    }else{
        status = true;
    }
    return status;
}

bool Queue::isFull() const
{
    bool status;

    if(numItems < queueSize){
        status = false;
    }else{
        status = true;
    }
    return status;
}

void Queue::display()
{
    int num;
    cout << "[";
    while(!isEmpty()){
        dequeue(num);
        
        cout << num << ", ";
    }
    cout << "]";
}