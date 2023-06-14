#include"Cards.h"


//Landmarks
void LANDMARKS::L_Train_Station::activate()
{
    cout << "You may roll 1 or 2 dice.\n";
    getCoin.GetLosses(4);
}

//BLUE CARDS Section
void Blue_Cards::Ranch::activate()
{
    cout << "Get 1 coin from the bank in anyone's turn.\n";
    getCoin.GetProfit(1);
}
void Blue_Cards::WheatField::activate()
{
    cout << "Get 1 coin from the bank in anyone's turn." << endl;
    getCoin.GetProfit(1);
}
void Blue_Cards::Forest::activate()
{
    cout << "Get 1 coin from the bank in anyone's turn." << endl;
    getCoin.GetProfit(1);
}
void Blue_Cards::Mine::activate()
{
    cout << "Get 5 coin from the bank in anyone's turn." << endl;
    getCoin.GetProfit(5);
}
void Blue_Cards::Apple_Orchard::activate()
{
    cout << "Get 3 coin from the bank in anyone's turn." << endl;
    getCoin.GetProfit(3);
}


//GREEN CARDS Section
void Green_Cards::Bakery::activate() 
{
    cout << "Earn 1 coin from the bank for your turn only." << endl;
    getCoin.GetProfit(1);
}
void Green_Cards::ConvStore::activate() 
{
    cout << "Get 3 coin from the bank for your turn only." << endl;
    getCoin.GetProfit(3);
}
void Green_Cards::Cheese_Factory::activate()
{
    cout << "Get 5 coins from the bank in your turn only.\n";
    getCoin.GetProfit(5);
}
void Green_Cards::Furniture_Factory::activate()
{
    cout << "Get 3 coins for each establishment that you own.\n";
    // Write algorith for indicating a number of establishments and multiply profit for each one(Mines and Forest) 
    getCoin.GetProfit(3);
}