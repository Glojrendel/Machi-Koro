#include"DiceTurn.h"

int Turn_Dice::Roll_1_Dice()
{
    auto roll1_to_6 = [](int min = 1, int max = 6)
    {
        std::random_device rd;
        std::mt19937 gen;
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    };
    return roll1_to_6();
}

int Turn_Dice::Roll_2_Dice()
{
    auto roll6_to_12 = [](int min = 2, int max = 12)
    {
        std::random_device rd;
        std::mt19937 gen;
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    };
    return roll6_to_12();
}