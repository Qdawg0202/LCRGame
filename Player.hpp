//
// Created by Yungs on 11/6/2022.
//

#ifndef LCRFINAL_PLAYER_HPP
#define LCRFINAL_PLAYER_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Player
{
private:
    int chips;
    bool isOut;
public:
    Player();
    void setChips();
    int getChips();
    int takeTurn(); //return 0 for left, 1 for right, 2 for center, 3-5 for nothing call however times
    //bool out();
};

Player::Player()
{
    chips = 3;
    isOut = false;
}
void Player::setChips()
{
    chips++;
}
int Player::getChips()
{
    return chips;
}
int Player::takeTurn()
{

    int ret = 0;
    int dice = rand()%6; //gets a roll 0-5
    if(!isOut)
    {
        if (dice == 0) {
            chips--;
            //out();
            return dice;
        } else if (dice == 1) {
            chips--;
            //out();
            return dice;
        } else if (dice == 2) {
            chips--;
            //out();
            return dice;
        } else {
            return dice;
        }
    }
    else
        return -1;
}
//bool Player::out()
//{
//    if(chips <= 0)
//    {
//        isOut = true;
//    }
//    return isOut;
//}

#endif //LCRFINAL_PLAYER_HPP
