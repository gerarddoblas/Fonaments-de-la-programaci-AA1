#include <iostream>
#include <stdlib.h>


int main()
{
	srand(time(NULL));

	bool Over = false;
	bool shipInstance1 = false;
	bool shipInstance2 = false;
	bool shipInstance3 = false;
	bool shipInstance4 = false;

	const short numRows = 10;
	const short numCols = 10;
	const char ship1 = '3';
	const char ship2 = '4';
	const char ship3 = '5';
	const char ship4 = '6';

	char water = '~';

	std::string stop;

	char** mapFirstPlayer = new char* [numRows];
	for (int i = 0; i < numRows; i++)
	{
		mapFirstPlayer[i] = new char[numCols];
	}

	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			mapFirstPlayer[i][j] = water;
		}
	}

	while (!Over)
	{
		std::cout << "Tablero jugador 1" << std::endl;
		
		//Spaguetti code ship1
		if (!shipInstance1)
		{
			int newShipX;
			int newShipY;

			do
			{
				newShipX = rand() % (numRows - 6) + 3;
				newShipY = rand() % (numCols - 6) + 3;


			} while (mapFirstPlayer[newShipX][newShipY] != water && (mapFirstPlayer[newShipX + 1][newShipY] != water 
				&& mapFirstPlayer[newShipX + 2][newShipY] != water || mapFirstPlayer[newShipX][newShipY + 1] != water 
				&& mapFirstPlayer[newShipX][newShipY + 2] != water || mapFirstPlayer[newShipX - 1][newShipY] != water 
				&& mapFirstPlayer[newShipX - 2][newShipY] != water || mapFirstPlayer[newShipX][newShipY - 1] != water
				&& mapFirstPlayer[newShipX][newShipY - 2] != water));

			if (mapFirstPlayer[newShipX][newShipY] == water)
			{
				mapFirstPlayer[newShipX][newShipY] = ship1;

				if (mapFirstPlayer[newShipX + 1][newShipY] == water && mapFirstPlayer[newShipX + 2][newShipY] == water)
				{
					mapFirstPlayer[newShipX + 1][newShipY] = ship1;
					mapFirstPlayer[newShipX + 2][newShipY] = ship1;
				}
				else if (mapFirstPlayer[newShipX - 1][newShipY] == water && mapFirstPlayer[newShipX - 2][newShipY] == water)
				{
					mapFirstPlayer[newShipX - 1][newShipY] = ship1;
					mapFirstPlayer[newShipX - 2][newShipY] = ship1;
				}
				else if (mapFirstPlayer[newShipX][newShipY + 1] == water && mapFirstPlayer[newShipX][newShipY + 2] == water)
				{
					mapFirstPlayer[newShipX][newShipY + 1] = ship1;
					mapFirstPlayer[newShipX][newShipY + 2] = ship1;
				}
				else if (mapFirstPlayer[newShipX][newShipY + 1] == water && mapFirstPlayer[newShipX][newShipY + 2] == water)
				{
					mapFirstPlayer[newShipX][newShipY - 1] = ship1;
					mapFirstPlayer[newShipX][newShipY - 2] = ship1;
				}
			}
			shipInstance1 = true;
		}

		//Spaguetti Code ship2
		if (!shipInstance2)
		{
			int newShipX;
			int newShipY;

			do
			{
				newShipX = rand() % (numRows - 6) + 3;
				newShipY = rand() % (numCols - 6) + 3;


			} while (mapFirstPlayer[newShipX][newShipY] != water && (mapFirstPlayer[newShipX + 1][newShipY] != water
				&& mapFirstPlayer[newShipX + 2][newShipY] != water && mapFirstPlayer[newShipX + 3][newShipY] != water
				|| mapFirstPlayer[newShipX][newShipY + 1] != water && mapFirstPlayer[newShipX][newShipY + 2] != water
				&& mapFirstPlayer[newShipX][newShipY + 3] != water || mapFirstPlayer[newShipX - 1][newShipY] != water
				&& mapFirstPlayer[newShipX - 2][newShipY] != water && mapFirstPlayer[newShipX - 3][newShipY] != water
				|| mapFirstPlayer[newShipX][newShipY - 1] != water && mapFirstPlayer[newShipX][newShipY - 2] != water
				&& mapFirstPlayer[newShipX][newShipY - 3] != water));

			if (mapFirstPlayer[newShipX][newShipY] == water)
			{
				mapFirstPlayer[newShipX][newShipY] = ship2;

				if (mapFirstPlayer[newShipX + 1][newShipY] == water && mapFirstPlayer[newShipX + 2][newShipY] == water && mapFirstPlayer[newShipX + 3][newShipY] == water)
				{
					mapFirstPlayer[newShipX + 1][newShipY] = ship2;
					mapFirstPlayer[newShipX + 2][newShipY] = ship2;
					mapFirstPlayer[newShipX + 3][newShipY] = ship2;
				}
				else if (mapFirstPlayer[newShipX - 1][newShipY] == water && mapFirstPlayer[newShipX - 2][newShipY] == water && mapFirstPlayer[newShipX - 3][newShipY] == water)
				{
					mapFirstPlayer[newShipX - 1][newShipY] = ship2;
					mapFirstPlayer[newShipX - 2][newShipY] = ship2;
					mapFirstPlayer[newShipX - 3][newShipY] = ship2;
				}
				else if (mapFirstPlayer[newShipX][newShipY + 1] == water && mapFirstPlayer[newShipX][newShipY + 2] == water && mapFirstPlayer[newShipX][newShipY + 3] == water)
				{
					mapFirstPlayer[newShipX][newShipY + 1] = ship2;
					mapFirstPlayer[newShipX][newShipY + 2] = ship2;
					mapFirstPlayer[newShipX][newShipY + 3] = ship2;
				}
				else if (mapFirstPlayer[newShipX][newShipY - 1] == water && mapFirstPlayer[newShipX][newShipY - 2] == water && mapFirstPlayer[newShipX][newShipY - 3] == water)
				{
					mapFirstPlayer[newShipX][newShipY - 1] = ship2;
					mapFirstPlayer[newShipX][newShipY - 2] = ship2;
					mapFirstPlayer[newShipX][newShipY - 3] = ship2;
				}
			}
			shipInstance2 = true;
		}

		//Spaguetti Code ship3
		if (!shipInstance3)
		{
			int newShipX;
			int newShipY;

			do
			{
				newShipX = rand() % (numRows - 6) + 3;
				newShipY = rand() % (numCols - 6) + 3;


			} while (mapFirstPlayer[newShipX][newShipY] != water && (mapFirstPlayer[newShipX + 1][newShipY] != water
				&& mapFirstPlayer[newShipX + 2][newShipY] != water && mapFirstPlayer[newShipX + 3][newShipY] != water
				&& mapFirstPlayer[newShipX + 4][newShipY] != water || mapFirstPlayer[newShipX][newShipY + 1] != water

				&& mapFirstPlayer[newShipX][newShipY + 2] != water && mapFirstPlayer[newShipX][newShipY + 3] != water
				&& mapFirstPlayer[newShipX][newShipY + 4] != water || mapFirstPlayer[newShipX - 1][newShipY] != water

				&& mapFirstPlayer[newShipX - 2][newShipY] != water && mapFirstPlayer[newShipX - 3][newShipY] != water
				&& mapFirstPlayer[newShipX - 4][newShipY] != water || mapFirstPlayer[newShipX][newShipY - 1] != water

				&& mapFirstPlayer[newShipX][newShipY - 2] != water && mapFirstPlayer[newShipX][newShipY - 3] != water
				&& mapFirstPlayer[newShipX][newShipY - 4] != water));

			if (mapFirstPlayer[newShipX][newShipY] == water)
			{
				mapFirstPlayer[newShipX][newShipY] = ship3;

				if (mapFirstPlayer[newShipX + 1][newShipY] == water && mapFirstPlayer[newShipX + 2][newShipY] == water
					&& mapFirstPlayer[newShipX + 3][newShipY] == water && mapFirstPlayer[newShipX + 4][newShipY] == water)
				{
					mapFirstPlayer[newShipX + 1][newShipY] = ship3;
					mapFirstPlayer[newShipX + 2][newShipY] = ship3;
					mapFirstPlayer[newShipX + 3][newShipY] = ship3;
					mapFirstPlayer[newShipX + 4][newShipY] = ship3;
				}
				else if (mapFirstPlayer[newShipX - 1][newShipY] == water && mapFirstPlayer[newShipX - 2][newShipY] == water
						&& mapFirstPlayer[newShipX - 3][newShipY] == water && mapFirstPlayer[newShipX - 4][newShipY] == water)
				{
					mapFirstPlayer[newShipX - 1][newShipY] = ship3;
					mapFirstPlayer[newShipX - 2][newShipY] = ship3;
					mapFirstPlayer[newShipX - 3][newShipY] = ship3;
					mapFirstPlayer[newShipX - 4][newShipY] = ship3;
				}
				else if (mapFirstPlayer[newShipX][newShipY + 1] == water && mapFirstPlayer[newShipX][newShipY + 2] == water
						&& mapFirstPlayer[newShipX][newShipY + 3] == water && mapFirstPlayer[newShipX][newShipY + 4] == water)
				{
					mapFirstPlayer[newShipX][newShipY + 1] = ship3;
					mapFirstPlayer[newShipX][newShipY + 2] = ship3;
					mapFirstPlayer[newShipX][newShipY + 3] = ship3;
					mapFirstPlayer[newShipX][newShipY + 4] = ship3;
				}
				else if (mapFirstPlayer[newShipX][newShipY - 1] == water && mapFirstPlayer[newShipX][newShipY - 2] == water
						&& mapFirstPlayer[newShipX][newShipY - 3] == water && mapFirstPlayer[newShipX][newShipY - 4] == water)
				{
					mapFirstPlayer[newShipX][newShipY - 1] = ship3;
					mapFirstPlayer[newShipX][newShipY - 2] = ship3;
					mapFirstPlayer[newShipX][newShipY - 3] = ship3;
					mapFirstPlayer[newShipX][newShipY - 4] = ship3;
				}
			}
			shipInstance3 = true;
		}

		//Dibujito del Mapa
		for (int i = 0; i < numRows; i++)
		{
			std::cout << "  ";

			for (int j = 0; j < numCols; j++)
			{
				std::cout << mapFirstPlayer[i][j];
				std::cout << " ";
			}
			printf("\n");
		}
		std::cin >> stop;
		system("cls");
		/*
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
	*/
	/*
		for (int i = 0; i < numRows; i++)
		{
			delete[] map[i];
		}
		delete[] map;
		*/
	}
}