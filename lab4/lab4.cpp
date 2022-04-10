// Kevin Bui
// lab4.cpp
// 2/1/22
// Purpose: to create a car object through header and implementation files
// and access the functions
// Input: none
// Processing: function calls
// Output: describes car and the speed variable increases and decreases

#include <iostream>
#include "Car.h" // header file

using namespace std;

int main()
{
  Car test(2020, "Honda Civic"); // creates object and inputs argument to
  // constructor

  // tests functions
  cout << "\n\nThe car is a " << test.getModel() << " "
       << test.getMake() << " and the current speed is " << test.getSpeed();

  // increases speed variable 5 times and displays speed
  for(int x = 1; x <= 5; x++){
    test.accelerate();
    cout << "\nThe speed is now " << test.getSpeed();
  }

  // decreases speed variable 5 times and displays speed
  for(int x = 1; x <= 5; x++){
    test.brake();
    cout << "\nThe speed is now " << test.getSpeed();
  }

  cout << endl;
  
  return 0;
}
