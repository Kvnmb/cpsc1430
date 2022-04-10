#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack(int size)
{
    stackArray = new int[size];
    stackSize = size;
    top = -1;
}

Stack::~Stack()
{
    delete [] stackArray;
}

void Stack::push(int num)
{
    if(isFull()){
        cout << "The stack is full.\n";
    }else{
        top++;
        stackArray[top] = num;
    }
}

void Stack::pop(int &num)
{
    if(isEmpty()){
        cout << "The stack is empty.\n";
    }else{
        num = stackArray[top];
        top--;
    }
}

bool Stack::isFull() const
{
    bool status;

    if(top == stackSize - 1){
        status = true;
    }else{
        status = false;
    }
    return status;
}

bool Stack::isEmpty() const
{
    bool status;

    if(top == -1){
        status = true;
    }else{
        status = false;
    }
    
    return status;
}

void Stack::display()
{
    int num;
    cout << "[";
    while(!isEmpty()){
        pop(num);
        
        cout << num << ", ";
    }
    cout << "]";
}