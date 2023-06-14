#include <iostream>

#include <iostream>
#include <thread>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <memory>
#include <random>

using std::cout;
using std::cin;
using std::endl;

void PossibleCardModel();

class Turn_Dice
{
private:
    std::random_device rd;
    std::mt19937 gen;

public:
    Turn_Dice() : gen(rd()) {}

    int Roll_1_Dice()
    {
        auto roll6_or_12 = [](int min = 1, int max = 6)
        {
            std::random_device rd;
            std::mt19937 gen;
            std::uniform_int_distribution<> dis(min, max);
            return dis(gen);
        };
        return roll6_or_12();
    }
    int Roll_2_Dice()
    {
        auto roll6_or_12 = [](int min = 2, int max = 12)
        {
            std::random_device rd;
            std::mt19937 gen;
            std::uniform_int_distribution<> dis(min, max);
            return dis(gen);
        };
        return roll6_or_12();
    }
};

class Card {
protected:
    std::string name{};
    int cost{};

public:
    Card(const std::string& cardName, int cardCost) : name(cardName), cost(cardCost) {}
    virtual void activate() = 0;

    std::string getName() const { return name; }
    int getCost() const { return cost; }

    friend std::ostream& operator<<(std::ostream& os, const Card& c)
    {
        os << c.getName() << "(" << c.getCost() << " coin)";
        return os;
    }
};

class Player
{
private:
    int p_balance{ 10 };
    std::vector<std::unique_ptr<Card>> cards;
    std::vector<std::unique_ptr<Card>> LandMarks;
public:
    Player() {}
    ~Player() {}

    int Show_My_Coins()
    {
        cout << "\nCoins: " << p_balance;
        return p_balance;
    }
    void Show_My_Cards()
    {
        std::cout << "\nCards: ";
        for (const auto& C : cards)
        {
            std::cout << *C.get() << "|";
        }
        cout << endl << "Landmarks: ";

        for (const auto& l : LandMarks)
        {
            cout << *l.get() << "|";
        }
    }

    int GetProfit(int p) { return p_balance += p; }
    int GetLosses(int l) { return p_balance -= l; }

    template <typename T>
    void BuyCards(std::unique_ptr<T>& card)
    {
        cards.push_back(std::move(card));
    }

    template <typename L>
    void BuyLandMarks(std::unique_ptr<L>& land)
    {
        LandMarks.push_back(std::move(land));
    }

    template<typename T>
    void CheckLandmarks(const std::unique_ptr<T>& landmark)
    {

        std::string trainStation{ "Train Station" };
        for (const auto& Card : LandMarks)
        {
            std::cout << Card->getName() << " | ";
            if (Card->getName() == trainStation)
            {
                cout << endl << trainStation << endl;
                Card->activate();
            }
        }
    }

    template <typename L>
    bool IsLandMarkPresent() const
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
};

namespace Landmarks
{
    Player getCoin;
    class Train_Station : public Card
    {
    public:
        Train_Station() : Card("Train Station", 4) {}
        ~Train_Station() {}

        void activate() override
        {
            cout << "You may roll 1 or 2 dice.\n";
        }
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
        void activate() override
        {
            cout << "Get 1 coin from the bank in anyone's turn.\n";
            getCoin.GetProfit(1);
        }
    };

    class WheatField : public Card
    {
    public:
        WheatField() : Card("Wheat Field", 1) {}
        ~WheatField() {}
        void activate() override
        {
            cout << "Get 1 coin from the bank in anyone's turn." << endl;
            getCoin.GetProfit(1);
        }

    };

    class Forest : public Card
    {
    public:
        Forest() : Card("Forest", 3) {}
        ~Forest() {}
        void activate() override
        {
            cout << "Get 1 coin from the bank in anyone's turn." << endl;
            getCoin.GetProfit(1);
        }
    };

    class Mine : public Card
    {
    public:
        Mine() : Card("Mine", 6) {}
        ~Mine() {}
        void activate() override
        {
            cout << "Get 5 coin from the bank in anyone's turn." << endl;
            getCoin.GetProfit(1);
        }
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
        void activate() override
        {
            cout << "Earn 1 coin from the bank for your turn only." << endl;
            getCoin.GetProfit(1);
        }
    }; class ConvStore : public Card
    {
    public:
        ConvStore() : Card("Bakery", 3) {}
        ~ConvStore() {}
        void activate() override
        {
            cout << "Get 3 coin from the bank for your turn only." << endl;
            getCoin.GetProfit(1);
        }
    };
}
struct Card_Options
{
    void Get_new_card()
    {
        using namespace Blue_Cards;
        using namespace Green_Cards;

        Ranch ranch;
        Forest forest;
        Bakery bakery;
        Turn_Dice roll1;
        auto randomNumber = rand() % 6;

        std::map<int, Card*> blue;
        blue[1] = &ranch;
        blue[2] = &bakery;
        blue[5] = &forest;

        for (auto& op : blue)
        {
            if (randomNumber == op.first && op.first == 1)
            {
                cout << "\ndice ->" << randomNumber << "\n";
                cout << *(op.second); ranch.activate(); jeg.GetProfit(1);
            }
            else if (randomNumber == op.first && op.first == 2)
            {
                cout << "\ndice ->" << randomNumber << "\n";
                cout << *(op.second); ranch.activate(); jeg.GetProfit(1);
            }
            else if (randomNumber == op.first && op.first == 5)
            {
                cout << "\ndice ->" << randomNumber << "\n";
                cout << *(op.second); ranch.activate(); jeg.GetProfit(1);
            }
            cout << "\n\n|Wallet|";
            jeg.Show_My_Cards();
        }
    }


protected:
    Player jeg;
};

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

    Turn_Dice roll_6_12;
    int dice6 = roll_6_12.Roll_1_Dice();
    int dice12 = roll_6_12.Roll_2_Dice();
    Player player;

public:

    void Get_Coin_mechanism();

    int ShowMenu()
    {
        cout << "\n-enter option-\n";
        cout << "(1)|Turn 1 dice|\n";

        {
            using namespace Landmarks;
            std::unique_ptr<Train_Station> trainST{ std::make_unique<Train_Station>() };
            player.CheckLandmarks(trainST);
            if (player.IsLandMarkPresent<Train_Station>())
            {
                cout << "(2)|Turn 2 dice|\n";
            }
        }

        cout << "(3)|Check balance|\n";
        cout << "(4)|Buy new Property|\n";

        cout << "|-> "; cin >> choiceMenu;
        switch (choiceMenu)
        {
        case Turn_1_dice:
            cout << "6-sided dice: " << dice6 << endl;
            return dice6;

        case Turn_2_dice:
            using namespace Landmarks;
            if (!player.IsLandMarkPresent<Train_Station>())
            {
                cout << "\nTrain Station landmark is required to turn 2 dice.\n";
                break;
            }
            cout << "12-sided dice: " << dice12 << endl;
            return dice12;

        case Check_balance:
            player.Show_My_Coins();
            player.Show_My_Cards();
            break;

        case Buy_property:
            PossibleCardModel();
            break;

        default:
            if (choiceMenu > 4)
            {
                cout << "\nUnknown command.\n";
            }
            break;
        }
    }

};


void PossibleCardModel()
{
    using namespace Landmarks;
    using namespace Blue_Cards;
    using namespace Green_Cards;
    Player jeg;

    WheatField wheat;
    Mine mine;
    Ranch ranch;
    Forest forest;

    Bakery bakery;

    Turn_Dice roll1;
    auto randomNumber = roll1.Roll_1_Dice();

    std::map<int, std::unique_ptr<Card>> blue;
    std::unique_ptr<Train_Station> l_trainStation;


    blue[1] = std::make_unique<WheatField>();
    blue[2] = std::make_unique<Ranch>();
    blue[3] = std::make_unique<Bakery>();
    blue[5] = std::make_unique<Forest>();
    blue[9] = std::make_unique<Mine>();
    int sel;
    if (jeg.Show_My_Coins() >= 1)
    {
        std::vector<std::unique_ptr<Card>> availableCards;
        availableCards.push_back(std::make_unique<WheatField>());
        availableCards.push_back(std::make_unique<Ranch>());
        availableCards.push_back(std::make_unique<Mine>());
        availableCards.push_back(std::make_unique<Forest>());
        availableCards.push_back(std::make_unique<Bakery>());
        cout << "\n|Available for buying| ";
        for (size_t i = 0; i < availableCards.size(); i++)
        {
            cout << "\n(" << i + 1 << ") - " << availableCards[i]->getName() << " ";
        }
        cout << "\n|-> "; cin >> sel;

        if (sel == 1 && jeg.Show_My_Coins() == 1)
        {
            cout << endl << wheat.getName() << " added to your property.\n";
            jeg.BuyCards(blue[1]);
            jeg.GetLosses(wheat.getCost());
        }
        else if (sel == 2 && jeg.Show_My_Coins() == 1)
        {
            cout << endl << ranch.getName() << " added to your property.\n";
            jeg.BuyCards(blue[2]);
            jeg.GetLosses(ranch.getCost());
        }
        else if (sel == 3 && jeg.Show_My_Coins() <= 5)
        {
            cout << endl << mine.getName() << " added to your property.\n";
            jeg.BuyCards(blue[3]);
            jeg.GetLosses(mine.getCost());
        }
        else if (sel == 4 && jeg.Show_My_Coins() <= 3)
        {
            cout << endl << forest.getName() << " added to your property.\n";
            jeg.BuyCards(blue[4]);
            jeg.GetLosses(forest.getCost());
        }
        else if (sel == 5)
        {
            cout << endl << bakery.getName() << " added to your property.\n";
            jeg.BuyCards(blue[5]);
            jeg.GetLosses(bakery.getCost());
        }
        else
        {
            cout << "\nNot enought coins.\n";
        }
        jeg.Show_My_Coins();
        jeg.Show_My_Cards();
    }
}

void landmarkDevelop()
{
    using namespace Blue_Cards;
    using namespace Landmarks;
    Player han;

    std::unique_ptr<Train_Station> trainST{ std::make_unique<Train_Station>() };

    han.BuyLandMarks(trainST);
    han.Show_My_Cards();

    cout << endl;
    han.CheckLandmarks(trainST);

}

void StartMenu()
{
    GameProcess start; start.ShowMenu();
}

int main()
{
    StartMenu();
    //landmarkDevelop();
    //PossibleCardModel();

    cout << endl << endl; return 0;
}
