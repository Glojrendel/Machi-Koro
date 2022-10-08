#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int turnDice(int valueD)
{
	srand(time(NULL));

	int num = 1 + rand() % (6 - 1 + 1);

	if (valueD == 1)
	{
		srand(time(NULL));

		int num = 1 + rand() % (6 - 1 + 1);
		cout << num << endl;
		return num;
	}
	else if (valueD == 2)
	{
		srand(time(NULL));

		int num = 2 + rand() % (12 - 2 + 2);
		cout << num << endl;
		return num;
	}
}
