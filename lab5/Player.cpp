#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(string player, int num)
{
    name = player;
    games = num;
    ptr = new int[games];
}

void Player::setNum()
{
    for(int x = 0; x < games; x++){
        cout << "\nPlease enter a number at index " << x + 1 << " for player "
        << name << ":";
        cin >> ptr[x];
    }
}

 void Player::getNum()
{
    cout << "\n\nPlayer " << name << " selected the following numbers: ";
    for(int x = 0; x < games; x++){
        cout << ptr[x] << " ";
    }
}

void Player::winner(Player &obj)
{
    int score1 = 0;
    int score2 = 0;

    for(int x = 0; x < games; x++){
        if(this->ptr[x] > obj.ptr[x]){
            score1++;
        }else if(this->ptr[x] < obj.ptr[x]){
            score2++;
        }else{
            continue;
        }
    }

    if(score1 > score2){
        cout << endl << name << " Won\n\n";
        }else if(score1 < score2){
            cout << endl << obj.name << " Won\n\n";
        }else{
            cout << endl << "It's a draw!\n\n";
        }
}

Player::~Player()
{
    delete [] ptr;
    ptr = nullptr;
}