// Kevin Bui
// hw2.cpp
// 2/6/22
// Purpose: to create a class IntegerSet which holds integers from 1-100 and
// create new modified sets
// Input: numbers from 1-100 and x to stop
// Processing: functions accessing the member variable and modifying values
// Output: displays the sets and creates new ones

#include <iostream>
#include "IntegerSet.h"

using namespace std;

int main(int argc, char *argv[])
{
  IntegerSet A, B;
  int num = 0;

  cout << "\n\nEnter Set A:\n" ;
  // inputs values into set A
  while(!cin.fail()){ // stops when value received is not an int
    cout << "\nEnter an element (Type x to stop): ";
    cin >> num;
    if(cin.fail()){
      cout << "\nEntry complete";
      break;
    }else{
      A.inputSet(num);
    }
  }

  cin.clear();// clears the cin inputs
  cin.ignore();
  
  // inputs values from user into set B
  cout << "\n\nEnter set B:" ;
  while(!cin.fail()){
    cout << "\nEnter an element (Type x to stop): ";
    cin >> num;
    if(cin.fail()){
      cout << "\nEntry complete";
      break;
    }else{
      B.inputSet(num);
    }
  }

  cin.clear();
  cin.ignore(); 
  
  A.unionOfsets(B);
  
  A.intersectionOfsets(B);
  
  A.isEqualTo(B);
  
  A.insertElement();
  
  A.deleteElement(77);
  
  cout << "\nNow creating a set of specific values and testing the bounds"
       << " limits.\nCreating array of size 10: {25, 67, 2, 9, 99,"
       << "105, 45, -5, 100, 1}\n\nSet C is:\n";

  int array[10] = {25,67,2,9,99,105,45,-5,100,1};
  IntegerSet C(10, array); // constructor with parameters is called

  C.printSet();

  cout << endl << endl;
  return 0;
}
