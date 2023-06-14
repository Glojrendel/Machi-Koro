#include"Game_Process.h"


void GameProcess::Get_Coin_mechanism()
{
    // In progress
}

int GameProcess::ShowMenu()
{
    using namespace LANDMARKS;
    cout << "\n-enter option-\n";
    cout << "(1)|Turn 1 dice|\n";

    {
        using namespace LANDMARKS;
        std::unique_ptr<L_Train_Station> trainST{ std::make_unique<L_Train_Station>() };
        player.CheckLandmarks(trainST);
        if (player.IsLandMarkPresent<L_Train_Station>())
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
        if (!player.IsLandMarkPresent<L_Train_Station>())
        {
            cout << "\nTrain Station landmark is required to turn 2 dice.\n";
            break;
        }
        cout << "12-sided dice: " << dice12 << endl;
        return dice12;

    case Check_balance:
        player.Show_Coins();
        player.Show_My_Cards();

    case Buy_property:

    default:
        if (choiceMenu > 4)
        {
            cout << "\nUnknown command.\n";
        }
        break;
    }
}