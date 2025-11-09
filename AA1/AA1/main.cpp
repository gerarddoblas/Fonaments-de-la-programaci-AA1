#include <iostream>
#include <stdlib.h>

bool gameover = false;



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

const short players = 2;

char (*map)[numCols];

char mapFirstPlayer[numRows][numCols];


char mapSecondPlayer[numRows][numCols];

bool shipsInstanciate = false;

bool endFirstTurn = false;

short posX;
short posY;

char shootFail = 'X';
char shootRight = 'O';

void Ships()
{
	
	for (short player = 0; player < players; player++)
	{
		map = (player == 0) ? mapFirstPlayer : mapSecondPlayer;

		bool firstShipPlace = false;
		bool secondShipPlace = false;
		bool thirdShipPlace = false;
		bool fourthShipPlace = false;

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

						if (newShipX + (firstShipLenght - 1) >= numRows)
							continue;

						for (short i = 0; i < firstShipLenght; i++)
						{
							if (map[newShipX + i][newShipY] == water) freeBoxes++;
							else
								break;
						}

						if (freeBoxes == firstShipLenght) canPlace = true;

					} while (!canPlace);

					for (short i = 0; i < firstShipLenght; i++)
					{
						map[newShipX + i][newShipY] = ship;
					}
					break;

				case 2:
					do
					{
						newShipX = rand() % numRows;
						newShipY = rand() % numCols;

						short freeBoxes = 0;

						if (newShipY + (firstShipLenght - 1) >= numCols)
							continue;

						for (short i = 0; i < firstShipLenght; i++)
						{
							if (map[newShipX][newShipY + i] == water) freeBoxes++;
							else
								break;
						}

						if (freeBoxes == firstShipLenght) canPlace = true;

					} while (!canPlace);

					for (short i = 0; i < firstShipLenght; i++)
					{
						map[newShipX][newShipY + i] = ship;
					}

					break;

				case 3:
					do
					{
						newShipX = rand() % numRows;
						newShipY = rand() % numCols;

						short freeBoxes = 0;

						if (newShipX - (firstShipLenght - 1) < 0)
							continue;


						for (short i = 0; i < firstShipLenght; i++)
						{
							if (map[newShipX - i][newShipY] == water) freeBoxes++;
							else
								break;
						}

						if (freeBoxes == firstShipLenght) canPlace = true;

					} while (!canPlace);

					for (short i = 0; i < firstShipLenght; i++)
					{
						map[newShipX - i][newShipY] = ship;
					}

					break;

				case 4:
					do
					{
						newShipX = rand() % numRows;
						newShipY = rand() % numCols;

						short freeBoxes = 0;

						if (newShipY - (firstShipLenght - 1) < 0)
							continue;

						for (short i = 0; i < firstShipLenght; i++)
						{
							if (map[newShipX][newShipY - i] == water) freeBoxes++;
							else
								break;
						}

						if (freeBoxes == firstShipLenght) canPlace = true;

					} while (!canPlace);

					for (short i = 0; i < firstShipLenght; i++)
					{
						map[newShipX][newShipY - i] = ship;
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

						if (newShipX + (secondShipLenght - 1) >= numRows)
							continue;

						for (short i = 0; i < secondShipLenght; i++)
						{
							if (map[newShipX + i][newShipY] == water) freeBoxes++;
							else
								break;
						}

						if (freeBoxes == secondShipLenght) canPlace = true;

					} while (!canPlace);

					for (short i = 0; i < secondShipLenght; i++)
					{
						map[newShipX + i][newShipY] = ship;
					}
					break;

				case 2:
					do
					{
						newShipX = rand() % numRows;
						newShipY = rand() % numCols;

						short freeBoxes = 0;

						if (newShipY + (secondShipLenght - 1) >= numCols)
							continue;

						for (short i = 0; i < secondShipLenght; i++)
						{
							if (map[newShipX][newShipY + i] == water) freeBoxes++;
							else
								break;
						}

						if (freeBoxes == secondShipLenght) canPlace = true;

					} while (!canPlace);

					for (short i = 0; i < secondShipLenght; i++)
					{
						map[newShipX][newShipY + i] = ship;
					}

					break;

				case 3:
					do
					{
						newShipX = rand() % numRows;
						newShipY = rand() % numCols;

						short freeBoxes = 0;

						if (newShipX - (secondShipLenght - 1) < 0)
							continue;


						for (short i = 0; i < secondShipLenght; i++)
						{
							if (map[newShipX - i][newShipY] == water) freeBoxes++;
							else
								break;
						}

						if (freeBoxes == secondShipLenght) canPlace = true;

					} while (!canPlace);

					for (short i = 0; i < secondShipLenght; i++)
					{
						map[newShipX - i][newShipY] = ship;
					}

					break;

				case 4:
					do
					{
						newShipX = rand() % numRows;
						newShipY = rand() % numCols;

						short freeBoxes = 0;

						if (newShipY - (secondShipLenght - 1) < 0)
							continue;

						for (short i = 0; i < secondShipLenght; i++)
						{
							if (map[newShipX][newShipY - i] == water) freeBoxes++;
							else
								break;
						}

						if (freeBoxes == secondShipLenght) canPlace = true;

					} while (!canPlace);

					for (short i = 0; i < secondShipLenght; i++)
					{
						map[newShipX][newShipY - i] = ship;
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

						if (newShipX + (thirdShipLenght - 1) >= numRows)
							continue;

						for (short i = 0; i < thirdShipLenght; i++)
						{
							if (map[newShipX + i][newShipY] == water) freeBoxes++;
							else
								break;
						}

						if (freeBoxes == thirdShipLenght) canPlace = true;

					} while (!canPlace);

					for (short i = 0; i < thirdShipLenght; i++)
					{
						map[newShipX + i][newShipY] = ship;
					}
					break;

				case 2:
					do
					{
						newShipX = rand() % numRows;
						newShipY = rand() % numCols;

						short freeBoxes = 0;

						if (newShipY + (thirdShipLenght - 1) >= numCols)
							continue;

						for (short i = 0; i < thirdShipLenght; i++)
						{
							if (map[newShipX][newShipY + i] == water) freeBoxes++;
							else
								break;
						}

						if (freeBoxes == thirdShipLenght) canPlace = true;

					} while (!canPlace);

					for (short i = 0; i < thirdShipLenght; i++)
					{
						map[newShipX][newShipY + i] = ship;
					}

					break;

				case 3:
					do
					{
						newShipX = rand() % numRows;
						newShipY = rand() % numCols;

						short freeBoxes = 0;

						if (newShipX - (thirdShipLenght - 1) < 0)
							continue;


						for (short i = 0; i < thirdShipLenght; i++)
						{
							if (map[newShipX - i][newShipY] == water) freeBoxes++;
							else
								break;
						}

						if (freeBoxes == thirdShipLenght) canPlace = true;

					} while (!canPlace);

					for (short i = 0; i < thirdShipLenght; i++)
					{
						map[newShipX - i][newShipY] = ship;
					}

					break;

				case 4:
					do
					{
						newShipX = rand() % numRows;
						newShipY = rand() % numCols;

						short freeBoxes = 0;

						if (newShipY - (thirdShipLenght - 1) < 0)
							continue;

						for (short i = 0; i < thirdShipLenght; i++)
						{
							if (map[newShipX][newShipY - i] == water) freeBoxes++;
							else
								break;
						}

						if (freeBoxes == thirdShipLenght) canPlace = true;

					} while (!canPlace);

					for (short i = 0; i < thirdShipLenght; i++)
					{
						map[newShipX][newShipY - i] = ship;
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
							if (map[newShipX + i][newShipY] == water) freeBoxes++;
							else
								break;
						}

						if (freeBoxes == fourthShipLenght) canPlace = true;

					} while (!canPlace);

					for (short i = 0; i < fourthShipLenght; i++)
					{
						map[newShipX + i][newShipY] = ship;
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
							if (map[newShipX][newShipY + i] == water) freeBoxes++;
							else
								break;
						}

						if (freeBoxes == fourthShipLenght) canPlace = true;

					} while (!canPlace);

					for (short i = 0; i < fourthShipLenght; i++)
					{
						map[newShipX][newShipY + i] = ship;
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
							if (map[newShipX - i][newShipY] == water) freeBoxes++;
							else
								break;
						}

						if (freeBoxes == fourthShipLenght) canPlace = true;

					} while (!canPlace);

					for (short i = 0; i < fourthShipLenght; i++)
					{
						map[newShipX - i][newShipY] = ship;
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
							if (map[newShipX][newShipY - i] == water) freeBoxes++;
							else
								break;
						}

						if (freeBoxes == fourthShipLenght) canPlace = true;

					} while (!canPlace);

					for (short i = 0; i < fourthShipLenght; i++)
					{
						map[newShipX][newShipY - i] = ship;
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
	
}

int main()
{
	srand(time(NULL));

	for (short i = 0; i < numRows; i++)
	{
		for (short j = 0; j < numCols; j++)
		{
			mapFirstPlayer[i][j] = water;
			mapSecondPlayer[i][j] = water;
		}
	}

	while (!gameover)
	{
		if (!shipsInstanciate)
		{
			Ships();

			shipsInstanciate = true;
		}

		std::cout << "Tablero jugador 1" << std::endl;
		if (!endFirstTurn)
		{
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

			std::cout << "Tablero jugador 2" << std::endl;

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
		}
		else
		{
			for (short i = 0; i < numRows; i++)
			{
				std::cout << "  ";

				for (short j = 0; j < numCols; j++)
				{
					std::cout << water;
					std::cout << " ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;

			std::cout << "Tablero jugador 2" << std::endl;

			for (short i = 0; i < numRows; i++)
			{
				std::cout << "  ";

				for (short j = 0; j < numCols; j++)
				{
					std::cout << water;
					std::cout << " ";
				}
				std::cout << std::endl;
			}
		}


		std::cout << "Turn first Player. Choose when you want attack: " << std::endl;
		std::cout << "Position X: ";
		std::cin >> posX;
		std::cout << "Position Y: ";
		std::cin >> posY;
		std::cout << std::endl;

		if (mapSecondPlayer[posX - 1][posY - 1] != water)
			mapSecondPlayer[posX - 1][posY - 1] = shootRight;
		else
			mapSecondPlayer[posX - 1][posY - 1] = shootFail;

		std::cout << "Turn second Player. Choose when you want attack: " << std::endl;
		std::cout << "Position X: ";
		std::cin >> posX;
		std::cout << "Position Y: ";
		std::cin >> posY;
		std::cout << std::endl;

		system("cls");
	}
}

