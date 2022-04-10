// Kevin Bui
// hw3.cpp
// 2/17/21
// Purpose: to create a doubly linked list that can reverse itself and delete
// specified node from end of list
// Input: numbers for menu choice, numbers for the list, x to stop
// Processing: dynamic allocation and while loops to traverse list
// Output: menu displaying linked list and modifying list

#include <iostream>
#include <string>
#include "FancyList.h"

using namespace std;

void input(FancyList &); // takes object as parameter, checks for valid input

int main(int argc, char *argv[])
{
    int choice = 0; // tracks menu choice
    int num; // append number
    FancyList list;

    while(choice != 5){
        cout << "\n********* FancyList Menu *********\n" 
             << "1. Create a list\n2. Display the list\n3. Reverse the list\n" 
             << "4. Delete the n-th node from the end of the list\n"
             << "5. Exit the program\n\nEnter your choice: " ;
    
        cin >> choice;

        if(choice == 1){ // creates a list
            input(list);
        }else if(choice == 2){ // prints the list
            cout << "\nCurrent list is: " ;
            list.printList();
        }else if (choice == 3){ // reverses the list
            list.reverseList();
            cout << "\nCurrent list after reversing is: " ;
            list.printList();
        }else if(choice == 4){ // deletes node
            cout << "\nDelete n-th node from the end of the list, your n is: " ;
            cin >> num;
            list.deleteNode(num);
            cout << "\nCurrent list after deleting the " << num << "-th node"
            << " from the end is: " ;
            list.printList();
        }else if(choice == 5){ // ends program
            break;
        }else{
            cout << "\nInvalid input. Please try again: ";
            cin >> choice;
        }
    }
}

void input(FancyList &obj)
{
    string input = "";
    int num = 0;
    bool isNum = true;

    while(true){
        cout << "\n\nType a number for appending (type x to stop): ";
        cin >> input;
        if(input == "x"){// stops when input is x
            break;
        }
        if(isNum){
            num = stoi(input); // string to int
            obj.appendNode(num); // inserts the number into the object
        }
    }
}
