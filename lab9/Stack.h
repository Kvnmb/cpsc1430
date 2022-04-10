#ifndef STACK_H
#define STACK_H

class Stack
{
    private:
    int *stackArray;
    int stackSize;
    int top;

    public:
    Stack(int);
    ~Stack();
    void push(int);
    void pop(int &);
    bool isFull() const;
    bool isEmpty() const;
    void display();
};

#endif