#pragma once

#include"Cards.h"
#include"Player.h"
#include"DiceTurn.h"


class GameProcess
{
private:
    int choiceMenu{};

    enum Menu_Options
    {
        Turn_1_dice = 1,
        Turn_2_dice,
        Check_balance,
        Buy_property
    };

    Player player;
    Turn_Dice roll_6_12;
    int dice6 = roll_6_12.Roll_1_Dice();
    int dice12 = roll_6_12.Roll_2_Dice();
  
public:

    void Get_Coin_mechanism();
    int ShowMenu();

};