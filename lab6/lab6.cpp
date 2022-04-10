// Kevin Bui
// lab6.cpp
// 2/11/22
// Purpose: to test out nodes by creating linked lists
// Input: numbers for the list and x to stop
// Processing: dynamic allocation and linking ptrs of nodes
// Output: numbers stored inside linked lists and deallocation

#include <iostream>
#include "OrderedList.h"
#include <string>

using namespace std;

void input(OrderedList &); // function to get user inputs, parameter is object

int main(int argc, char *argv[])
{
    cout << "\n\nAsking user to type and create listA...\n\n" ;

    OrderedList A;

    input(A);

    cout << "\n\nlistA is: ";
    A.printList(); 

    OrderedList B(A); // copy constructor

    cout << "\n\nlistB is copied from listA: ";
    B.printList();

    cout << "\n\nAsking user to type and add more to listB..." ;
    input(B);

    cout << "\nlistA now is: ";
    A.printList();

    cout << "\nlistB now is: ";
    B.printList();


    return 0;
}

void input(OrderedList &obj)
{
    string input = "";
    int num = 0;
    bool isNum = true;

    while(true){
        cout << "\n\nType a number for insertion (type x to stop): ";
        cin >> input;
        if(input == "x"){// stops when input is x
            break;
        }
        if(isNum){
            num = stoi(input); // string to int
            obj.insert(num); // inserts the number into the object
        }
    }
}
