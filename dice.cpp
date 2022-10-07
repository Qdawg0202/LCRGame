#include "stdafx.h"
#include "Dice.h"
#include <time.h>
#include<iostream>


int Dice::rollDice()
{

    int diceOutcome;

    diceOutcome = (rand() % 6) + 1;
    return diceOutcome;
}
