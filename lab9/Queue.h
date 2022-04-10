#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
    private:
    int *queueArray;
    int queueSize;
    int front;
    int rear;
    int numItems;
    public:
    Queue(int);
    ~Queue();
    void enqueue(int);
    void dequeue(int &);
    bool isEmpty() const;
    bool isFull() const;
    void display();
};

#endif