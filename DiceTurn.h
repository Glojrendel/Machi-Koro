#pragma once
#include<random>

class Turn_Dice
{
private:
    std::random_device rd;
    std::mt19937 gen;

public:
    Turn_Dice() : gen(rd()) {}
    int Roll_1_Dice();
    int Roll_2_Dice();
};