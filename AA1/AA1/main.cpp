#include <iostream>
#include <stdlib.h>

bool gameover = false;

bool firstShipPlace = false;
bool secondShipPlace = false;
bool thirdShipPlace = false;
bool fourthShipPlace = false;

const short numRows = 9;
const short numCols = 9;

const short ships = 4;

const char firstShip = '3';
const char secondShip = '4';
const char thirdShip = '5';
const char fourthShip = '6';

const short firstShipLenght = 3;
const short secondShipLenght = 4;
const short thirdShipLenght = 5;
const short fourthShipLenght = 6;

const char water = '~';

char** mapFirstPlayer = new char* [numRows];


char** mapSecondPlayer = new char* [numRows];

void Ship1()
{
	for (short i = 0; i < ships; i++)
	{
		short newShipX;
		short newShipY;
		short direction = rand() % 4 + 1;
		char ship;
		bool canPlace = false;

		if (!firstShipPlace)
		{
			ship = firstShip;

			switch (direction)
			{
			case 1:

				do
				{
					newShipX = rand() % numRows;
					newShipY = rand() % numCols;

					short freeBoxes = 0;

					//Utilizo un for para comprovar los espacios de la dirección donde se pondra el barco y porque la condición del while me queda muy larga
					for (short i = 0; i < firstShipLenght; i++)
					{
						if (newShipX + i >= numRows)
							break;

						if (mapFirstPlayer[newShipX + i][newShipY] == water)
							freeBoxes++;
						else
							break;
					}

					if (freeBoxes == firstShipLenght)
						canPlace = true;

				} while (!canPlace);

				for (short i = 0; i < firstShipLenght; i++)
				{
					mapFirstPlayer[newShipX + i][newShipY] = ship;
				}
				break;

			case 2:
				do
				{
					newShipX = rand() % numRows;
					newShipY = rand() % numCols;

					short freeBoxes = 0;
	
					for (short i = 0; i < firstShipLenght; i++)
					{
						if (newShipY + i >= numCols)
							break;

						if (mapFirstPlayer[newShipX][newShipY + i] == water)
							freeBoxes++;
						else
							break;
					}

					if (freeBoxes == firstShipLenght)
						canPlace = true;

				} while (!canPlace);

				for (short i = 0; i < firstShipLenght; i++)
				{
					mapFirstPlayer[newShipX][newShipY + i] = ship;
				}

				break;

			case 3:
				do
				{
					newShipX = rand() % numRows;
					newShipY = rand() % numCols;

					short freeBoxes = 0;

					for (short i = 0; i < firstShipLenght; i++)
					{
						if (newShipX - i < 0)
							break;

						if (mapFirstPlayer[newShipX - i][newShipY] == water)
							freeBoxes++;
						else
							break;
					}

					if (freeBoxes == firstShipLenght)
						canPlace = true;

				} while (!canPlace);

				for (short i = 0; i < firstShipLenght; i++)
				{
					mapFirstPlayer[newShipX - i][newShipY] = ship;
				}

				break;

			case 4:
				do
				{
					newShipX = rand() % numRows;
					newShipY = rand() % numCols;

					short freeBoxes = 0;

					for (short i = 0; i < firstShipLenght; i++)
					{
						if (newShipY - i < 0)
							break;

						if (mapFirstPlayer[newShipX][newShipY - i] == water)
							freeBoxes++;
						else
							break;
					}

					if (freeBoxes == firstShipLenght)
						canPlace = true;

				} while (!canPlace);

				for (short i = 0; i < firstShipLenght; i++)
				{
					mapFirstPlayer[newShipX][newShipY - i] = ship;
				}

				break;
			default:
				std::cout << "No se puede poner un barco";
				break;
			}

			firstShipPlace = true;
		}
		else if (!secondShipPlace)
		{
			ship = secondShip;

			switch (direction)
			{
			case 1:

				do
				{
					newShipX = rand() % numRows;
					newShipY = rand() % numCols;

					short freeBoxes = 0;

					for (short i = 0; i < secondShipLenght; i++)
					{
						if (newShipX + i >= numRows)
							break;

						if (mapFirstPlayer[newShipX + i][newShipY] == water)
							freeBoxes++;
						else
							break;
					}

					if (freeBoxes == secondShipLenght)
						canPlace = true;

				} while (!canPlace);

				for (short i = 0; i < secondShipLenght; i++)
				{
					mapFirstPlayer[newShipX + i][newShipY] = ship;
				}
				break;

			case 2:
				do
				{
					newShipX = rand() % numRows;
					newShipY = rand() % numCols;

					short freeBoxes = 0;

					for (short i = 0; i < secondShipLenght; i++)
					{
						if (newShipY + i >= numCols)
							break;

						if (mapFirstPlayer[newShipX][newShipY + i] == water)
							freeBoxes++;
						else
							break;
					}

					if (freeBoxes == secondShipLenght)
						canPlace = true;

				} while (!canPlace);

				for (short i = 0; i < secondShipLenght; i++)
				{
					mapFirstPlayer[newShipX][newShipY + i] = ship;
				}

				break;

			case 3:
				do
				{
					newShipX = rand() % numRows;
					newShipY = rand() % numCols;

					short freeBoxes = 0;

					for (short i = 0; i < secondShipLenght; i++)
					{
						if (newShipX - i < 0)
							break;

						if (mapFirstPlayer[newShipX - i][newShipY] == water)
							freeBoxes++;
						else
							break;
					}

					if (freeBoxes == secondShipLenght)
						canPlace = true;

				} while (!canPlace);

				for (short i = 0; i < secondShipLenght; i++)
				{
					mapFirstPlayer[newShipX - i][newShipY] = ship;
				}

				break;

			case 4:
				do
				{
					newShipX = rand() % numRows;
					newShipY = rand() % numCols;

					short freeBoxes = 0;

					for (short i = 0; i < secondShipLenght; i++)
					{
						if (newShipY - i < 0)
							break;

						if (mapFirstPlayer[newShipX][newShipY - i] == water)
							freeBoxes++;
						else
							break;
					}

					if (freeBoxes == secondShipLenght)
						canPlace = true;

				} while (!canPlace);

				for (short i = 0; i < secondShipLenght; i++)
				{
					mapFirstPlayer[newShipX][newShipY - i] = ship;
				}

				break;
			default:
				std::cout << "No se puede poner un barco";
				break;
			}

			secondShipPlace = true;
		}
		else if (!thirdShipPlace)
		{
			ship = thirdShip;

			switch (direction)
			{
			case 1:

				do
				{
					newShipX = rand() % numRows;
					newShipY = rand() % numCols;

					short freeBoxes = 0;

					for (short i = 0; i < thirdShipLenght; i++)
					{
						if (newShipX + i >= numRows)
							break;

						if (mapFirstPlayer[newShipX + i][newShipY] == water)
							freeBoxes++;
						else
							break;
					}

					if (freeBoxes == thirdShipLenght)
						canPlace = true;

				} while (!canPlace);

				for (short i = 0; i < thirdShipLenght; i++)
				{
					mapFirstPlayer[newShipX + i][newShipY] = ship;
				}
				break;

			case 2:
				do
				{
					newShipX = rand() % numRows;
					newShipY = rand() % numCols;

					short freeBoxes = 0;

					for (short i = 0; i < thirdShipLenght; i++)
					{
						if (newShipY + i >= numCols)
							break;

						if (mapFirstPlayer[newShipX][newShipY + i] == water)
							freeBoxes++;
						else
							break;
					}

					if (freeBoxes == thirdShipLenght)
						canPlace = true;

				} while (!canPlace);

				for (short i = 0; i < thirdShipLenght; i++)
				{
					mapFirstPlayer[newShipX][newShipY + i] = ship;
				}

				break;

			case 3:
				do
				{
					newShipX = rand() % numRows;
					newShipY = rand() % numCols;

					short freeBoxes = 0;

					for (short i = 0; i < thirdShipLenght; i++)
					{
						if (newShipX - i < 0)
							break;

						if (mapFirstPlayer[newShipX - i][newShipY] == water)
							freeBoxes++;
						else
							break;
					}

					if (freeBoxes == thirdShipLenght)
						canPlace = true;

				} while (!canPlace);

				for (short i = 0; i < thirdShipLenght; i++)
				{
					mapFirstPlayer[newShipX - i][newShipY] = ship;
				}

				break;

			case 4:
				do
				{
					newShipX = rand() % numRows;
					newShipY = rand() % numCols;

					short freeBoxes = 0;

					for (short i = 0; i < thirdShipLenght; i++)
					{
						if (newShipY - i < 0)
							break;

						if (mapFirstPlayer[newShipX][newShipY - i] == water)
							freeBoxes++;
						else
							break;
					}

					if (freeBoxes == thirdShipLenght)
						canPlace = true;

				} while (!canPlace);

				for (short i = 0; i < thirdShipLenght; i++)
				{
					mapFirstPlayer[newShipX][newShipY - i] = ship;
				}

				break;
			default:
				std::cout << "No se puede poner un barco";
				break;
			}

			thirdShipPlace = true;
		}
		else if (!fourthShipPlace)
		{
			ship = fourthShip;

			switch (direction)
			{
			case 1:

				do
				{
					newShipX = rand() % numRows;
					newShipY = rand() % numCols;

					short freeBoxes = 0;

					if (newShipX + (fourthShipLenght - 1) >= numRows)
						continue;

					for (short i = 0; i < fourthShipLenght; i++)
					{
						if (mapFirstPlayer[newShipX + i][newShipY] == water) freeBoxes++;
						else
							break;
					}

					if (freeBoxes == fourthShipLenght) canPlace = true;

				} while (!canPlace);

				for (short i = 0; i < fourthShipLenght; i++)
				{
					mapFirstPlayer[newShipX + i][newShipY] = ship;
				}
				break;

			case 2:
				do
				{
					newShipX = rand() % numRows;
					newShipY = rand() % numCols;

					short freeBoxes = 0;

					if (newShipY + (fourthShipLenght - 1) >= numCols)
						continue;

					for (short i = 0; i < fourthShipLenght; i++)
					{
						if (mapFirstPlayer[newShipX][newShipY + i] == water) freeBoxes++;
						else
							break;
					}

					if (freeBoxes == fourthShipLenght) canPlace = true;

				} while (!canPlace);

				for (short i = 0; i < fourthShipLenght; i++)
				{
					mapFirstPlayer[newShipX][newShipY + i] = ship;
				}

				break;

			case 3:
				do
				{
					newShipX = rand() % numRows;
					newShipY = rand() % numCols;

					short freeBoxes = 0;

					if (newShipX - (fourthShipLenght - 1) < 0)
						continue;


					for (short i = 0; i < fourthShipLenght; i++)
					{
						if (mapFirstPlayer[newShipX - i][newShipY] == water) freeBoxes++;
						else
							break;
					}

					if (freeBoxes == fourthShipLenght) canPlace = true;

				} while (!canPlace);

				for (short i = 0; i < fourthShipLenght; i++)
				{
					mapFirstPlayer[newShipX - i][newShipY] = ship;
				}

				break;

			case 4:
				do
				{
					newShipX = rand() % numRows;
					newShipY = rand() % numCols;

					short freeBoxes = 0;

					if (newShipY - (fourthShipLenght - 1) < 0)
						continue;

					for (short i = 0; i < fourthShipLenght; i++)
					{
						if (mapFirstPlayer[newShipX][newShipY - i] == water) freeBoxes++;
						else
							break;
					}

					if (freeBoxes == fourthShipLenght) canPlace = true;

				} while (!canPlace);

				for (short i = 0; i < fourthShipLenght; i++)
				{
					mapFirstPlayer[newShipX][newShipY - i] = ship;
				}

				break;
			default:
				std::cout << "No se puede poner un barco";
				break;
			}

			fourthShipPlace = true;
		}
	}
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
		if(!firstShipPlace)
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

