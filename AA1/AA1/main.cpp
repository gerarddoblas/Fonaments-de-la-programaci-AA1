#include <iostream>
#include <stdlib.h>

bool gameover = false;
bool shipInstance1 = false;
bool shipInstance2 = false;
bool shipInstance3 = false;
bool shipInstance4 = false;

const short numRows = 7;
const short numCols = 9;
const char ship1 = '3';
const char ship2 = '4';
const char ship3 = '5';
const char ship4 = '6';

const char water = '~';

char** mapFirstPlayer = new char* [numRows];


char** mapSecondPlayer = new char* [numRows];

void Ship1()
{
	
		int newShipX;
		int newShipY;
		int direction = rand() % (4 - 1) + 1;

		switch (direction)
		{
		case 1:
			do
			{
				newShipX = rand() % (numRows - 6) + 3;
				newShipY = rand() % (numCols - 6) + 3;

			} while (mapFirstPlayer[newShipX][newShipY] != water && mapFirstPlayer[newShipX + 1][newShipY] != water && mapFirstPlayer[newShipX + 2][newShipY] != water);

			mapFirstPlayer[newShipX][newShipY] = ship1;
			mapFirstPlayer[newShipX + 1][newShipY] = ship1;
			mapFirstPlayer[newShipX + 2][newShipY] = ship1;

			break;

		case 2:
			do
			{
				newShipX = rand() % (numRows - 6) + 3;
				newShipY = rand() % (numCols - 6) + 3;

			} while (mapFirstPlayer[newShipX][newShipY] != water && mapFirstPlayer[newShipX][newShipY + 1] != water && mapFirstPlayer[newShipX][newShipY + 2] != water);

			mapFirstPlayer[newShipX][newShipY] = ship1;
			mapFirstPlayer[newShipX][newShipY + 1] = ship1;
			mapFirstPlayer[newShipX][newShipY + 2] = ship1;

			break;

		case 3:
			do
			{
				newShipX = rand() % (numRows - 6) + 3;
				newShipY = rand() % (numCols - 6) + 3;

			} while (mapFirstPlayer[newShipX][newShipY] != water && mapFirstPlayer[newShipX - 1][newShipY] != water && mapFirstPlayer[newShipX - 2][newShipY] != water);

			mapFirstPlayer[newShipX][newShipY] = ship1;
			mapFirstPlayer[newShipX - 1][newShipY] = ship1;
			mapFirstPlayer[newShipX - 2][newShipY] = ship1;

			break;

		case 4:
			do
			{
				newShipX = rand() % (numRows - 6) + 3;
				newShipY = rand() % (numCols - 6) + 3;

			} while (mapFirstPlayer[newShipX][newShipY] != water && mapFirstPlayer[newShipX][newShipY - 1] != water && mapFirstPlayer[newShipX][newShipY - 2] != water);

			mapFirstPlayer[newShipX][newShipY] = ship1;
			mapFirstPlayer[newShipX][newShipY - 1] = ship1;
			mapFirstPlayer[newShipX][newShipY - 2] = ship1;

			break;
		default:
			std::cout << "No se puede poner un barco";
			break;
		}
		shipInstance1 = true;
}

int main()
{
	srand(time(NULL));



	std::string stop;

	//Inicialización mapFirstPlayer
	

	for (short i = 0; i < numRows; i++)
	{
		mapFirstPlayer[i] = new char[numCols];
	}

	for (short i = 0; i < numRows; i++)
	{
		for (short j = 0; j < numCols; j++)
		{
			mapFirstPlayer[i][j] = water;
		}
	}
	//Inicialización mapSecondPlayer
	

	for (short i = 0; i < numRows; i++)
	{
		mapSecondPlayer[i] = new char[numCols];
	}

	for (short i = 0; i < numRows; i++)
	{

		for (short j = 0; j < numCols; j++)
		{

			mapSecondPlayer[i][j] = water;
		}
	}
	while (!gameover)
	{
		std::cout << "Tablero jugador 1" << std::endl;
		
		////Spaguetti code ship1
		if(!shipInstance1)
			Ship1();

		////Spaguetti Code ship2
		//if (!shipInstance2)
		//{
		//	int newShipX;
		//	int newShipY;

		//	do
		//	{
		//		newShipX = rand() % (numRows - 6) + 3;
		//		newShipY = rand() % (numCols - 6) + 3;


		//	} while (mapFirstPlayer[newShipX][newShipY] != water && (mapFirstPlayer[newShipX + 1][newShipY] != water
		//		&& mapFirstPlayer[newShipX + 2][newShipY] != water && mapFirstPlayer[newShipX + 3][newShipY] != water
		//		|| mapFirstPlayer[newShipX][newShipY + 1] != water && mapFirstPlayer[newShipX][newShipY + 2] != water
		//		&& mapFirstPlayer[newShipX][newShipY + 3] != water || mapFirstPlayer[newShipX - 1][newShipY] != water
		//		&& mapFirstPlayer[newShipX - 2][newShipY] != water && mapFirstPlayer[newShipX - 3][newShipY] != water
		//		|| mapFirstPlayer[newShipX][newShipY - 1] != water && mapFirstPlayer[newShipX][newShipY - 2] != water
		//		&& mapFirstPlayer[newShipX][newShipY - 3] != water));

		//	if (mapFirstPlayer[newShipX][newShipY] == water)
		//	{
		//		mapFirstPlayer[newShipX][newShipY] = ship2;

		//		if (mapFirstPlayer[newShipX + 1][newShipY] == water && mapFirstPlayer[newShipX + 2][newShipY] == water && mapFirstPlayer[newShipX + 3][newShipY] == water)
		//		{
		//			mapFirstPlayer[newShipX + 1][newShipY] = ship2;
		//			mapFirstPlayer[newShipX + 2][newShipY] = ship2;
		//			mapFirstPlayer[newShipX + 3][newShipY] = ship2;
		//		}
		//		else if (mapFirstPlayer[newShipX - 1][newShipY] == water && mapFirstPlayer[newShipX - 2][newShipY] == water && mapFirstPlayer[newShipX - 3][newShipY] == water)
		//		{
		//			mapFirstPlayer[newShipX - 1][newShipY] = ship2;
		//			mapFirstPlayer[newShipX - 2][newShipY] = ship2;
		//			mapFirstPlayer[newShipX - 3][newShipY] = ship2;
		//		}
		//		else if (mapFirstPlayer[newShipX][newShipY + 1] == water && mapFirstPlayer[newShipX][newShipY + 2] == water && mapFirstPlayer[newShipX][newShipY + 3] == water)
		//		{
		//			mapFirstPlayer[newShipX][newShipY + 1] = ship2;
		//			mapFirstPlayer[newShipX][newShipY + 2] = ship2;
		//			mapFirstPlayer[newShipX][newShipY + 3] = ship2;
		//		}
		//		else if (mapFirstPlayer[newShipX][newShipY - 1] == water && mapFirstPlayer[newShipX][newShipY - 2] == water && mapFirstPlayer[newShipX][newShipY - 3] == water)
		//		{
		//			mapFirstPlayer[newShipX][newShipY - 1] = ship2;
		//			mapFirstPlayer[newShipX][newShipY - 2] = ship2;
		//			mapFirstPlayer[newShipX][newShipY - 3] = ship2;
		//		}
		//	}
		//	shipInstance2 = true;
		//}

		////Spaguetti Code ship3
		//if (!shipInstance3)
		//{
		//	int newShipX;
		//	int newShipY;

		//	do
		//	{
		//		newShipX = rand() % (numRows - 6) + 3;
		//		newShipY = rand() % (numCols - 6) + 3;


		//	} while (mapFirstPlayer[newShipX][newShipY] != water && (mapFirstPlayer[newShipX + 1][newShipY] != water
		//		&& mapFirstPlayer[newShipX + 2][newShipY] != water && mapFirstPlayer[newShipX + 3][newShipY] != water
		//		&& mapFirstPlayer[newShipX + 4][newShipY] != water || mapFirstPlayer[newShipX][newShipY + 1] != water

		//		&& mapFirstPlayer[newShipX][newShipY + 2] != water && mapFirstPlayer[newShipX][newShipY + 3] != water
		//		&& mapFirstPlayer[newShipX][newShipY + 4] != water || mapFirstPlayer[newShipX - 1][newShipY] != water

		//		&& mapFirstPlayer[newShipX - 2][newShipY] != water && mapFirstPlayer[newShipX - 3][newShipY] != water
		//		&& mapFirstPlayer[newShipX - 4][newShipY] != water || mapFirstPlayer[newShipX][newShipY - 1] != water

		//		&& mapFirstPlayer[newShipX][newShipY - 2] != water && mapFirstPlayer[newShipX][newShipY - 3] != water
		//		&& mapFirstPlayer[newShipX][newShipY - 4] != water));

		//	if (mapFirstPlayer[newShipX][newShipY] == water)
		//	{
		//		mapFirstPlayer[newShipX][newShipY] = ship3;

		//		if (mapFirstPlayer[newShipX + 1][newShipY] == water && mapFirstPlayer[newShipX + 2][newShipY] == water
		//			&& mapFirstPlayer[newShipX + 3][newShipY] == water && mapFirstPlayer[newShipX + 4][newShipY] == water)
		//		{
		//			mapFirstPlayer[newShipX + 1][newShipY] = ship3;
		//			mapFirstPlayer[newShipX + 2][newShipY] = ship3;
		//			mapFirstPlayer[newShipX + 3][newShipY] = ship3;
		//			mapFirstPlayer[newShipX + 4][newShipY] = ship3;
		//		}
		//		else if (mapFirstPlayer[newShipX - 1][newShipY] == water && mapFirstPlayer[newShipX - 2][newShipY] == water
		//				&& mapFirstPlayer[newShipX - 3][newShipY] == water && mapFirstPlayer[newShipX - 4][newShipY] == water)
		//		{
		//			mapFirstPlayer[newShipX - 1][newShipY] = ship3;
		//			mapFirstPlayer[newShipX - 2][newShipY] = ship3;
		//			mapFirstPlayer[newShipX - 3][newShipY] = ship3;
		//			mapFirstPlayer[newShipX - 4][newShipY] = ship3;
		//		}
		//		else if (mapFirstPlayer[newShipX][newShipY + 1] == water && mapFirstPlayer[newShipX][newShipY + 2] == water
		//				&& mapFirstPlayer[newShipX][newShipY + 3] == water && mapFirstPlayer[newShipX][newShipY + 4] == water)
		//		{
		//			mapFirstPlayer[newShipX][newShipY + 1] = ship3;
		//			mapFirstPlayer[newShipX][newShipY + 2] = ship3;
		//			mapFirstPlayer[newShipX][newShipY + 3] = ship3;
		//			mapFirstPlayer[newShipX][newShipY + 4] = ship3;
		//		}
		//		else if (mapFirstPlayer[newShipX][newShipY - 1] == water && mapFirstPlayer[newShipX][newShipY - 2] == water
		//				&& mapFirstPlayer[newShipX][newShipY - 3] == water && mapFirstPlayer[newShipX][newShipY - 4] == water)
		//		{
		//			mapFirstPlayer[newShipX][newShipY - 1] = ship3;
		//			mapFirstPlayer[newShipX][newShipY - 2] = ship3;
		//			mapFirstPlayer[newShipX][newShipY - 3] = ship3;
		//			mapFirstPlayer[newShipX][newShipY - 4] = ship3;
		//		}
		//	}
		//	shipInstance3 = true;
		//}

		//Dibujo de mapFirstPlayer
		for (short i = 0; i < numRows; i++)
		{
			std::cout << "  ";

			for (short j = 0; j < numCols; j++)
			{
				std::cout << mapFirstPlayer[i][j];
				std::cout << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;

		//Dibujo de mapSecondPlayer
		printf("Tablero jugador 2\n");

		for (short i = 0; i < numRows; i++)
		{
			std::cout << "  ";

			for (short j = 0; j < numCols; j++)
			{
				std::cout << mapSecondPlayer[i][j];
				std::cout << " ";
			}
			std::cout << std::endl;
		}
		std::cin >> stop;

		system("cls");
		
		

		
		/*
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

