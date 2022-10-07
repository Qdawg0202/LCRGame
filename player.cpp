#include "stdafx.h"
#include "Player.h"
#include "Dice.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;


void Player::getName()
{
    std::cin >> playerName;
}


void Player::getChips()
{
    switch (Dice::rollDice())
    {
        case 1:
            if (Dice::rollDice() == 1)
            {
                cout << "You rolled L. Move 1 chip left." << endl;
            }
            break;
        case 2:
            if (Dice::rollDice() == 2)
            {
                cout << "You rolled R. Move 1 chip right." << endl;
            }
            break;
        case 3:
            if (Dice::rollDice() == 3)
            {
                cout << "You rolled C. Place chip in center pile." << endl;
            }
            break;
        case 4:
            if (Dice::rollDice() == 4) //in case of *
                cout << "You rolled a 4. Next player turn." << endl;
            break;
        case 5:
            if (Dice::rollDice() == 5) //in case of *
                cout << "You rolled a 5. Next player turn." << endl;
            break;
        case 6:
            if (Dice::rollDice() == 6) //in case of *
                cout << "You rolled a 6. Next player turn." << endl;
            break;
    }
}

int Player::checkChipTotals()
{
    if (playerChips == 0)
    {
        std::cout << "No chips. Skip turn." << endl;
        return 0;
    }
    else return playerChips;
}

void Player::gameRules()
{
    string getcontent;
    ifstream openfile("Rules.txt");

    while (getline(openfile, getcontent))
    {
        cout << getcontent << endl;
    }

}