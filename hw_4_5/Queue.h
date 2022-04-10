#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
    private:
    struct Node
    {
        int value;
        Node *next;
    };
    Node *front;
    Node *rear;
    int numItems;
    public:
    Queue();
    ~Queue();
    void enqueue(int);
    void dequeue(int &);
    bool isEmpty() const;
    void clear();
    int total();
};

#endif