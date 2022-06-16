// ==============================
// T.P. Esc. Técnica 35: TA-TE-TI
// Autor: Nahuel Armando
// ==============================

#include <iostream>
#include "Game.hpp"
using namespace std;

int main()
{
	Game GM; // Game Manager

	int currentTurn = 0;
	int x, y;

	bool gameOver = false;

	while (!gameOver)
	{
		cout << " - Fila: ";
		cin >> x;
		cout << " - Columna: ";
		cin >> y;

		GM.InsertElement(x, y);
		GM.PrintBoard();
		currentTurn++;
		
		gameOver = GM.IsTheGameOver(currentTurn);
	}

	return 0;
}