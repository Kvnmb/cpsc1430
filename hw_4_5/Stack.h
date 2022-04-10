#ifndef STACK_H
#define STACK_H

class Stack
{
    private:
    struct Node
    {
        int value;
        Node *next;
    };
    Node *top;

    public:
    Stack();
    ~Stack();
    void push(int);
    void pop(int &);
    bool isEmpty();
};

#endif