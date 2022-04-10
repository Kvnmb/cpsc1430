// Header file for Car class

#ifndef CAR_H
#define CAR_H
using namespace std;

class Car
{
 private:
  int yearModel;
  string make;
  int speed;
 public:
  Car(int, string); // constructor
  int getModel() const;
  string getMake() const;
  int getSpeed() const;
  void accelerate();
  void brake();
};

#endif
