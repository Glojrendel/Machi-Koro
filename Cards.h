#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"PLayer.h"
#include"DiceTurn.h"

class Card 
{
protected:
    std::string name{};
    int cost{};

public:
    Card(const std::string& cardName, int cardCost) : name(cardName), cost(cardCost) {}

    std::string getName() const { return name; }
    int getCost() const { return cost; }
    virtual void activate() = 0;

    friend std::ostream& operator<<(std::ostream& os, const Card& c)
    {
        os << c.getName() << "(" << c.getCost() << " coin)\n";
        return os;
    }
};

namespace LANDMARKS
{
    Player getCoin;
    class L_Train_Station : public Card
    {
    public:
        L_Train_Station() : Card("Train Station", 4) {}
        ~L_Train_Station(){}

        void activate() override; 
    };
}
namespace Blue_Cards
{
    Player getCoin;
    class Ranch : public Card
    {
    public:
        Ranch() : Card("Ranch", 1) {}
        ~Ranch() {}
        void activate() override;
    };
    class WheatField : public Card
    {
    public:
        WheatField() : Card("Wheat Field", 1) {}
        ~WheatField() {}
        void activate() override;

    };
    class Forest : public Card
    {
    public:
        Forest() : Card("Forest", 1) {}
        ~Forest() {}
        void activate() override;
    };
    class Mine : public Card
    {
    public:
        Mine() : Card("Mine", 5) {}
        ~Mine() {}
        void activate() override;
    };
    class Apple_Orchard : public Card
    {
    public:
        Apple_Orchard() : Card("Ranch", 3) {}
        ~Apple_Orchard() {}
        void activate() override;
    };
}
namespace Green_Cards
{
    Player getCoin;
    class Bakery : public Card
    {
    public:
        Bakery() : Card("Bakery", 1) {}
        ~Bakery() {}
        void activate() override;
    };
    class ConvStore : public Card
    {
    public:
        ConvStore() : Card("Bakery", 3) {}
        ~ConvStore() {}
        void activate() override;   
    };
    class Cheese_Factory : public Card
    {
    public:
        Cheese_Factory() : Card("Cheese Factory", 5) {}
        ~Cheese_Factory(){}
        void activate() override;
    };
    class Furniture_Factory : public Card
    {
    public:
        Furniture_Factory() : Card("Furniture Factory", 3) {}
        ~Furniture_Factory(){}
        void activate() override;
    };
}
namespace Red_Cards
{
    //Add red cards
}