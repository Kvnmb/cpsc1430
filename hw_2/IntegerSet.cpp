// Implementation file

#include <iostream>
#include "IntegerSet.h"

using namespace std;

// combines both sets, parameter is second object
IntegerSet IntegerSet::unionOfsets(IntegerSet B)
{
  IntegerSet C; // makes a new object

  cout << "\n\nUnion of A and B is:\n" ;
  
  for(int x = 0; x < 100; x++){ // check whole array for values
    if((arr[x] != B.arr[x]) || (arr[x] == 1)){
      C.arr[x] = 1;
    }
  }

  C.printSet();
  return C;
}

// finds similar values between objects, parameter is second object
IntegerSet IntegerSet::intersectionOfsets(IntegerSet B)
{
  IntegerSet C;

  cout << "\n\nIntersection of A and B is:\n" ;
  
  for(int x = 0; x < 100; x++){
    if((arr[x] == B.arr[x]) && (arr[x] == 1)){
      C.arr[x] = 1;
    }
  }
  
  C.printSet();
  return C;
}

// takes input from user to insert an element into the array
void IntegerSet::insertElement()
{
  int x = 0;
  cout << "\n\nWhat element would you like to insert into set A?: ";
  cin >> x;
  inputSet(x);
  cout << "\nSet A is now:\n" ;
  printSet();
}

// deletes value from the array
void IntegerSet::deleteElement(int x)
{
  if(validEntry(x) == true){// confirms valid input
    arr[x-1] = 0;
  cout << "\n\nDeleting " << x << " from set A...\nSet A is now:\n" ;
  printSet();
  }else{
    cout << "\nInvalid insert of " << x << " attempted!\n\n" ;
  }
}

// prints out the values in the array
void IntegerSet::printSet()
{
  bool flag = false; // flag for empty set
  cout << "\n{ ";
  for(int x = 0; x < 100; x++){
    if(arr[x] == 1){
      flag = true;
      cout << (x + 1) << " ";
    }
  }
  if(flag == false)
    cout << "- ";
  cout << "}";
}

// compares values in two arrays
void IntegerSet::isEqualTo(IntegerSet B)
{
  bool flag = true; // flag turns false if arrays are not equal

  for(int x = 0; x < 100; x++){
    if(arr[x] != B.arr[x]){
      flag = false;
      cout << "\nSet A is not equal to set B";
      break;
    }
  }
  if(flag == true)
    cout << "\nSet A is equal to set B";
}

void IntegerSet::emptySet() // sets array values to 0
{
  for(int x = 0; x < 100; x++){
    arr[x] = 0;
  }
}

// checks to confirm if input is between 1 and 100

void IntegerSet::inputSet(int x) 
{
  if(validEntry(x) == true){
    arr[x-1] = 1;
  }else{
    cout << "\nInvalid insert of " << x << " attempted!" ;
  }
}

// constructor that sets array values to 0
IntegerSet::IntegerSet()
{
  emptySet();
}

// constructor that takes parameters to input into array
IntegerSet::IntegerSet(int size, int array[])
{
  emptySet();

  int temp;
  for(int x = 0; x < size; x++){
    temp = array[x];
    inputSet(temp); // validates array values
  }
}

// confirms that inputs are between 1 and 100
bool IntegerSet::validEntry(int x)
{
  if(x > 0 && x <= 100){
    return true;
  }else{return false;
  }
}
