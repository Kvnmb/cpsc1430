#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;

class Player
{
    private:
    string name;
    int *ptr = nullptr;
    int games;
    public:
    void setNum();
    void getNum();
    Player(string, int);
    void winner(Player &);
    ~Player();
};

#endif