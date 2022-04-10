// Kevin Bui
// order.cpp
// 1/25/22
// Purpose: This program demonstrates the use of a class, along with
// its accessor and mutator functions
// Input: none
// Processing: functions
// Output: displays changes to the object through member functions

#include <iostream>
#include <string>

using namespace std;

class Order // class declarations
{
private:
  // member variables
  string name;
  int itemID;
  double total;
  bool status;
public:
  // setter functions
  void setName(string);
  void setID(int);
  void setTotal(double);
  void setStatus(bool);

  // getter functions
  string getName() const
  {return name; }

  int getID() const
  {return itemID; }

  double getTotal() const
  {return total; }

  bool getStatus() const
  {return status; }

  Order(); // constructor
};


// FUNCTIONS                                                                                                                                                                                                                     

Order::Order() // default constructor
{
  // default arguments
  name = "";
  itemID = 0;
  total = 0.0;
  status = false;

  // displays values upon object creation
  cout << "\n\nYou have opened an order! Current contents of the order:\n\n" ;
  cout << "Name: " << name << "\nItem ID: " << itemID << "\nTotal: " << total
       << "\nStatus: " << status << endl;
}

void Order::setName(string input) // changes name of customer
{
  name = input;
  cout << "\nThe customer's name has been changed." ;
}

void Order::setID(int input) // changes item ID of order
{
  itemID = input;
  cout << "\nThe item ID has been changed." ;
}

void Order::setTotal(double input) // changes total amount of order
{
  total = input;
  cout << "\nThe total amount has been changed." ;
}

void Order::setStatus(bool input) // changes status of the order
{
  status = input;
  cout << "\nThe order status has been changed." ;
}


int main()
{
  Order newCustomer; // creates an object

  // Sets new values into the object
  newCustomer.setName("William");
  newCustomer.setID(22);
  newCustomer.setTotal(27.4);
  newCustomer.setStatus(true);

  // Prints out the new values stored in the object
  cout << "\n\nThe customer's name is " << newCustomer.getName();
  cout << "\nThe item ID is " << newCustomer.getID();
  cout << "\nThe order total is " << newCustomer.getTotal();
  cout << "\nThe status of the order is " << newCustomer.getStatus() << endl;
  
  return 0;
}
