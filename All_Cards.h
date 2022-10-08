#ifndef ALL_CARDS_H
#define ALL_CARDS_H

#include<iostream>
#include "TurnDice.h"
using std::cout;
using std::cin;
using std::endl;


class Player
{
private:
public:
	Player(){}
	int m_wallet{ 3 };
	
};

class Blue_cards
{
public:
	Player player;

	int WheatField(int dice = 1)
	{
		int Wprice{1};
		cout << "Wheat Field.\nGet 1 coin from the bank in anyone's turn.\n\n";
		return Wprice;
	}
	int Ranch(int Rdice = 2)
	{
		int Rprice{ 1 };
		cout << "Ranch.\nGet 1 coin from the bank in anyone's turn.\n\n";
		return Rprice;
	}

	void showResult()
	{
		cout << "Enter one/two dice:\n";
		cout << "1.Turn one dice \n";
		cout << "2.Turn two dice\n";
		cout << "3.Show wallet and cards\n";
		cout << "4.Buy properties\n";

		int dice; cin >> dice;
		int a = turnDice(dice);
		switch (dice)
		{
		case 1:
			if (a == 1)
				cout << "Wheat Field\n";
				WheatField();
				player.m_wallet += 1;
			break;
		case 2:
			if (a == 2)
				Ranch();
				player.m_wallet += 1;
			break;
		case 3:
			cout << "You have " << player.m_wallet << " coins\n\n";
			break;
		case 4:
			cout << "Available properties: \n\n";
			break;

		default:
			break;
		}
	}
};

#endif

