#include <iostream>
#include <stdlib.h>


int main()
{
	const short numRows = 9;
	const short numCols = 9;

	const short ships = 4;

	const char water = '~';
	const char firstShip = '3';
	const char secondShip = '4';
	const char thirdShip = '5';
	const char fourthShip = '6';
	const char shootFail = 'X';
	const char shootRight = 'O';

	const short firstShipLenght = 3;
	const short secondShipLenght = 4;
	const short thirdShipLenght = 5;
	const short fourthShipLenght = 6;

	const short players = 2;

	char mapFirstPlayer[numRows][numCols];
	char mapSecondPlayer[numRows][numCols];

	char (*map)[numCols];

	bool shipsInstanciate = false;

	bool endFirstTurn = false;

	bool mapInicialize = false;

	bool gameOver = false;

	bool again = false;

	bool turn = true;

	bool secondPlayerWin = false;
	bool firstPlayerWin = false;

	short posX;
	short posY;

	short shipsToDeepPlayerOne = 0;
	short shipsToDeepPlayerTwo = 0;

	char otherTry;

	srand(time(NULL));

	while (!gameOver)
	{
		//Se inicializa el tablero
		if (!mapInicialize)
		{
			for (short i = 0; i < numRows; i++)
			{
				for (short j = 0; j < numCols; j++)
				{
					mapFirstPlayer[i][j] = water;
					mapSecondPlayer[i][j] = water;
				}
			}
			mapInicialize = true;
		}
		//Se inicializan los barcos
		if (!shipsInstanciate)
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
						//Utilizo ship para hacerlo mas escalable a futuro
						ship = firstShip;

						switch (direction)
						{
						case 1:

							do
							{
								newShipX = rand() % numRows;
								newShipY = rand() % numCols;
								//Utilizo freeboxes como contador para saber que casillas estan disponibles
								//Si alguna de estas no esta disponible para poner el barco simplemente busca otra posición
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
			endFirstTurn = true;
		}
		else
		{
			for (short i = 0; i < numRows; i++)
			{
				std::cout << "  ";

				for (short j = 0; j < numCols; j++)
				{
					switch (mapFirstPlayer[i][j])
					{
					case shootRight:
						std::cout << shootRight;
						break;
					case shootFail:
						std::cout << shootFail;
						break;
					default:
						std::cout << water;
						break;
					}
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
					switch (mapSecondPlayer[i][j])
					{
					case shootRight:
						std::cout << shootRight;
						break;
					case shootFail:
						std::cout << shootFail;
						break;
					default:
						std::cout << water;
						break;
					}
					std::cout << " ";
				}
				std::cout << std::endl;
			}
		}

		if (turn)
		{
			std::cout << "Turn first player. Choose where you want attack: " << std::endl;
			std::cout << "Position X: ";
			std::cin >> posX;
			std::cout << "Position Y: ";
			std::cin >> posY;
			std::cout << std::endl;
			//En cada posX y posY pongo -1, porque el array es de  0 - 9
			if (mapSecondPlayer[posY - 1][posX - 1] != water && mapSecondPlayer[posY - 1][posX - 1] != shootFail)
				mapSecondPlayer[posY - 1][posX - 1] = shootRight;
			else
				mapSecondPlayer[posY - 1][posX - 1] = shootFail;

			turn = false;
		}
		else
		{
			std::cout << "Turn second player. Choose where you want attack: " << std::endl;
			std::cout << "Position X: ";
			std::cin >> posX;
			std::cout << "Position Y: ";
			std::cin >> posY;
			std::cout << std::endl;

			if (mapFirstPlayer[posY - 1][posX - 1] != water && mapFirstPlayer[posY - 1][posX - 1] != shootFail)
				mapFirstPlayer[posY - 1][posX - 1] = shootRight;
			else
				mapFirstPlayer[posY - 1][posX - 1] = shootFail;

			turn = true;
		}

		shipsToDeepPlayerOne = 0;
		shipsToDeepPlayerTwo = 0;

		for (short i = 0; i < numRows; i++)
		{
			for (short j = 0; j < numCols; j++)
			{
				if (mapFirstPlayer[i][j] != water && mapFirstPlayer[i][j] != shootRight && mapFirstPlayer[i][j] != shootFail)
					shipsToDeepPlayerOne++;

				if (mapSecondPlayer[i][j] != water && mapSecondPlayer[i][j] != shootRight && mapSecondPlayer[i][j] != shootFail)
					shipsToDeepPlayerTwo++;
			}
		}
		if (shipsToDeepPlayerOne == 0)
			secondPlayerWin = true;
		if (shipsToDeepPlayerTwo == 0)
			firstPlayerWin = true;


		system("cls");

		if (secondPlayerWin)
		{
			std::cout << "CONGRATULATIONS" << std::endl;
			std::cout << "Player Two WINS" << std::endl;

			secondPlayerWin = false;
			shipsToDeepPlayerOne = false;
			again = true;
		}

		if (firstPlayerWin)
		{
			std::cout << "CONGRATULATIONS" << std::endl;
			std::cout << "Player One WINS" << std::endl;

			firstPlayerWin = false;
			shipsToDeepPlayerTwo = false;
			again = true;
		}

		while (again)
		{
			std::cout << "You wanna try again?" << std::endl;
			std::cout << "'Y' or 'N'?" << std::endl;

			std::cin >> otherTry;

			switch (otherTry)
			{
			case 'Y':
				gameOver = false;
				turn = true;
				endFirstTurn = false;
				shipsInstanciate = false;
				mapInicialize = false;
				again = false;

				system("cls");

				break;
			case 'N':
				again = false;
				gameOver = true;

				break;
			default:
				system("cls");
				std::cout << "Please insert a valid option" << std::endl;
				break;
			}
		}
	}
}

