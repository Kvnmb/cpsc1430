// Kevin Bui
// lab9.cpp
// 3/6/22
// Purpose: to rearrange the order of an array using a queue and a stack
// Input: the first k integers to reverse in the array
// Processing: enqueuing and pushing
// Output: array with reversed orders

#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

const int SIZE = 10;

int main()
{
    int array[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    Queue queue(SIZE);
    Stack stack(SIZE);
    int k = 0; // integer to store user input of how many integers to reverse
    int num;
    
    cin >> k;

    if(k < 0 || k > SIZE){ // checks validity
        cout << "\n\nInvalid input.\n";
    }else{
        cout << "\nOriginal array: [";
        for(int x = 0; x < SIZE; x++){ // outputs original array
            cout << array[x];
            if(x != SIZE - 1){
                cout << ", ";
            }
        }
        cout << "]";

        for(int x = 0; x < k; x++){ // stores the first k integers into stack
            stack.push(array[x]);
        }

        for(int x = k; x < SIZE; x++){// stores the rest into queue
            queue.enqueue(array[x]);
        }

        cout << "\nReversed first " << k << ": [";

        while(!stack.isEmpty()){ // prints values in stack
            stack.pop(num);
            cout << num << ", ";
        }

        while(!queue.isEmpty()){ // prints values in queue
            queue.dequeue(num);
            cout << num;
            if(!queue.isEmpty()){
                cout << ", ";
            }
        }
        cout << "]\n\n";
    }

    return 0;
}