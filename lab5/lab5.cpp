// Kevin Bui
// lab5.cpp
// 2/8/22
// Purpose: to create a game that saves numbers to a dynamic array and compare
// two players' numbers to see which is larger
// Input: Name and numbers
// Processing: comparing the indexes of two arrays, dynamic allocation
// Output: prints name of winner

#include <iostream>
#include "Player.h"

using namespace std;

int main(int argc, char *argv[])
{
    int games;
    string name;

    cout << "\n\nPlease enter the total number of games:" ;
    cin >> games;

    cout << "\nPlease enter the name of the first player:" ;
    cin >> name;

    Player one(name, games);
    one.setNum();
    one.getNum();

    cout << "\nPlease enter the name of the second player:" ;
    cin >> name;

    Player two(name, games);
    two.setNum();
    two.getNum();

    one.winner(two);


    return 0;
}