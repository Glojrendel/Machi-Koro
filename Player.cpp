#include"PLayer.h"

int Player::Show_Coins()
{
    cout << "\nCoins: " << p_balance;
    return p_balance;
}

void Player::Show_My_Cards()
{
    std::cout << "\nCards: ";
    for (const auto& C : cards)
    {
        std::cout << *C.get() << "|";
    }
}

template <typename L>
void Player::BuyLandMarks(std::unique_ptr<L>& land)
{
    LandMarks.push_back(std::move(land));
}

template<typename T>
void Player::CheckLandmarks(const std::unique_ptr<T>& landmark)
{

    std::string trainStation{ "Train Station" };
    for (const auto& Card : LandMarks)
    {
        std::cout << Card->getName() << " | ";
        if (Card->getName() == trainStation)
        {
            cout << trainStation << endl; Card->activate();
        }
    }
}

template <typename T>
void Player::BuyCards(std::unique_ptr<T>& card)
{
    cards.push_back(std::move(card));
}

template <typename L>
bool Player::IsLandMarkPresent()
{
    for (const auto& land : LandMarks)
    {
        if (dynamic_cast<const L*>(land.get()) != nullptr)
        {
            return true;
        }
    }
    return false;
}