#pragma once

#include"Cards.h"

using std::cout;
using std::cin;
using std::endl;

class Player
{
private:
    int p_balance{ 3 };
    std::vector<std::unique_ptr<Card>> cards;
    std::vector<std::unique_ptr<Card>> LandMarks;

public:
    Player() {}
    ~Player() {}

    int Show_Coins();
    void Show_My_Cards();

    int GetProfit(int p) { return p_balance += p; }
    int GetLosses(int l) { return p_balance -= l; }

    template <typename T>
    void CheckLandmarks(const std::unique_ptr<T>& landmark);

    template <typename T>
    void BuyCards(std::unique_ptr<T>& card);

    template <typename L>
    void BuyLandMarks(std::unique_ptr<L>& land);
    
    template <typename L>
    bool IsLandMarkPresent();

};