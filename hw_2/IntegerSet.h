// Header file for IntegerSets class
#ifndef INTEGERSET_H
#define INTEGERSET_H

class IntegerSet
{
 private:
  int arr[100];
 public:
  void inputSet(int);
  IntegerSet unionOfsets(IntegerSet);
  IntegerSet intersectionOfsets(IntegerSet);
  void insertElement();
  void deleteElement(int);
  void printSet();
  void isEqualTo(IntegerSet);
  void emptySet();
  bool validEntry(int);
  IntegerSet();
  IntegerSet(int, int[]);
};

#endif
