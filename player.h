#pragma once
#include "stdafx.h"
#include "Dice.h"
#include <iostream>

class Player
{
public:
    int numPlayers;
    int playerChips;
    std::string playerName = ""; //tells which player to give to

    Player() = default;

    void getChips();
    void getName();
    int checkChipTotals();
    static void gameRules();



};