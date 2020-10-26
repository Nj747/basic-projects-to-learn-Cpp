// ==============================
// T.P. Esc. Técnica 35: TA-TE-TI
// Autor: Nahuel Armando
// ==============================

#include <iostream>
#include <string>
using namespace std;
 
class Game {
private:
	const int n = 3; 
	const int totalRounds = 9; // Total de turnos
	string board[3][3];
	bool charSwift = false;

	void FillBoard() 
	{
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < n; j++) 
			{
				board[i][j] = " ";
			}
		}
	}
	
	// Se relaciona a "X" con un +1 y a "O" con un -1
	// Jugador 1 suma +3 y Jugador 2 suma -3
	bool DidAnybodyWon() {

		int sumRows = 0, dp = 0, ds = 0, sumColums = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				// verif. filas
				if (board[i][j] == "X")
					sumRows++;
				else if (board[j][i] == "O")
					sumRows--;

				// diagonal principal
				if (i == j) 
				{
					if (board[i][j] == "X")
						dp++;
					else if (board[j][i] == "O")
						dp--;
				}

				// diagonal secundaria
				if ((i + j) == 2) 
				{
					if (board[i][j] == "X")
						ds++;
					else if (board[j][i] == "O")
						ds--;
				}

				// verif. columnas
				if (board[j][i] == "X")
					sumColums++;
				else if (board[j][i] == "O")
					sumColums--;
			}

			if (abs(sumRows) == n || abs(sumColums) == n)
				return true;
			sumRows = 0;
			sumColums = 0;
		}

		// resultados de diagonal principal y secundaria
		if (abs(ds) == n || abs(dp) == n) {
			return true;
		}

		return false;
	}
public:
	Game()
	{
		FillBoard();
		PrintBoard();
	}

	void PrintBoard()
	{
		cout << " ============= " << endl;
		for (int i = 0; i < n; i++) {
			cout << " | ";
			for (int j = 0; j < n; j++) {
				cout << board[i][j] << " | ";
			}
			cout << endl;
		}
		cout << " ============= " << endl;
	}

	// Inserta el elemento "X" u "O" según corresponda 
	// en la posicion deseada (fila,columna)
	void InsertarElemento(int row, int col)
	{
		if (!charSwift) {
			board[row][col] = "X";
			charSwift = true;
		}
		else {
			board[row][col] = "O";
			charSwift = false;
		}
	}

	bool IsTheGameOver(int currentTurn)
	{
		if (DidAnybodyWon() && currentTurn >= 3) 
		{
			cout << endl;
			// Mostrar que jugador gano
			int playerNum = currentTurn % 2;
			cout << " ========================== " << endl;
			cout << " Particpante de 'X' es el 1 " << endl;
			cout << " Particpante de 'O' es el 0 " << endl;
			cout << " ========================== " << endl;
			cout << "Ha Ganado! el participante "<< playerNum << endl;
			return true;
		}

		if (currentTurn <= totalRounds)
		{
			return false;
		}
		else
		{
			cout << "Se ha terminado el tiempo" << endl;
			cout << "EMPATE" << endl;
			return true;
		}
	}
};

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

		GM.InsertarElemento(x, y);
		GM.PrintBoard();
		currentTurn++;
		
		gameOver = GM.IsTheGameOver(currentTurn);
	}

	return 0;
}