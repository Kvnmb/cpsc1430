// Implementation file

#include <iostream>
#include "Car.h"

using namespace std; // needed for string variable

// constructor with default arguments
Car::Car(int model = 0, string style = "")
{
  // sets object to values when created
  yearModel = model;
  make = style;
  speed = 0;
}

int Car::getModel() const // returns year model
{
  return yearModel;
}

string Car::getMake() const // returns make of car
{
  return make;
}

int Car::getSpeed() const // returns speed
{
  return speed;
}

void Car::accelerate() // increases speed variable
{
  cout << "\n\nVroooom!\n" ;
  speed += 5;
}

void Car::brake() // decreases speed variable
{
  cout << "\n\nScreeeech!\n" ;
  speed -= 5;
}
