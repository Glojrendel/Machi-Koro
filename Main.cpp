#include<iostream>
#include"PLayer.h"
#include"Game_Process.h"




void StartGame()
{
	GameProcess start;
	start.ShowMenu();
}

int main()
{
	StartGame();

	

	std::cout << std::endl << std::endl; return 0;
}