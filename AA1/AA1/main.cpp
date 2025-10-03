#include <iostream>


int main()
{

	bool Over = false;
	const short numRows = 10;
	const short numCols = 10;
	const char water = '~';
	const short shipSize1 = 3;
	const short shipSize2 = 4;
	const short shipSize3 = 5;
	const short shipSize4 = 6;
	char ship1[shipSize1];
	char ship2[shipSize1];
	char ship3[shipSize1];
	char ship4[shipSize1];
	const char water = '~';
	const char water = '~';
	std::string stop;
	while (!Over)
	{

		std::cout << "Tablero jugador 1" << std::endl;

		char** mapFirstPlayer = new char*[numRows];
		for (int i = 0; i < numRows; i++)
		{
			mapFirstPlayer[i] = new char[numCols];
		}

		for (int i = 0; i < numRows; i++)
		{
			std::cout << "  ";

			for (int j = 0; j < numCols; j++)
			{

				mapFirstPlayer[i][j] = '~';
				std::cout << mapFirstPlayer[i][j];
				std::cout << " ";
			}
			printf("\n");
		}

		std::cout << "Tablero jugador 2" << std::endl;

		char** mapSecondPlayer = new char* [numRows];

		for (int i = 0; i < numRows; i++)
		{
			mapSecondPlayer[i] = new char[numCols];
		}

		for (int i = 0; i < numRows; i++)
		{
			std::cout << "  ";

			for (int j = 0; j < numCols; j++)
			{

				mapSecondPlayer[i][j] = '~';
				std::cout << mapSecondPlayer[i][j];
				std::cout << " ";
			}
			printf("\n");
		}

		for (int i = 0; i < numRows; i++)
		{
			delete[] mapFirstPlayer[i];
		}
		delete[] mapFirstPlayer;

		for (int i = 0; i < numRows; i++)
		{
			delete[] mapSecondPlayer[i];
		}
		delete[] mapSecondPlayer;
		system("cls");
	}
/*
	for (int i = 0; i < numRows; i++)
	{
		delete[] map[i];
	}
	delete[] map;
	*/
}