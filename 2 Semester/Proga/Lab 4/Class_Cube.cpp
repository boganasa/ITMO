#include "Class_Cube.h"


void PrintOfCage(char cage)
{
	char square = -2;
	if (cage == 'R')
	{
		std::cout << termcolor::bright_red << square << " ";
		std::cout << termcolor::reset;
	}
	else if (cage == 'W')
	{
		std::cout << termcolor::bright_white << square << " ";
		std::cout << termcolor::reset;
	}
	else if (cage == 'B')
	{
		std::cout << termcolor::bright_blue << square << " ";
		std::cout << termcolor::reset;
	}
	else if (cage == 'Y')
	{
		std::cout << termcolor::bright_yellow << square << " ";
		std::cout << termcolor::reset;
	}
	else if (cage == 'G')
	{
		std::cout << termcolor::bright_green << square << " ";
		std::cout << termcolor::reset;
	}
	else if (cage == 'O')
	{
		std::cout << termcolor::magenta << square << " ";
		std::cout << termcolor::reset;
	}
}

Cube::Cube(char U[9], char L[9], char F[9], char R[9], char B[9], char D[9])
{
	if (accuracy(U, L, F, R, B, D))
	{
		memcpy(surfaceU, U, 9);
		memcpy(surfaceL, L, 9);
		memcpy(surfaceF, F, 9);
		memcpy(surfaceR, R, 9);
		memcpy(surfaceB, B, 9);
		memcpy(surfaceD, D, 9);
	}
}

void Cube::Generation()
{
	srand(time(NULL));
	for (int i = 0; i < 9; i++)
	{
		surfaceU[i] = 'W';
		surfaceL[i] = 'B';
		surfaceF[i] = 'O';
		surfaceR[i] = 'G';
		surfaceB[i] = 'R';
		surfaceD[i] = 'Y';
	}
	int numberOfMove = rand() % 20;
	int done;
	int turn;
	int move;
	for (int i = 0; i < numberOfMove; i++)
	{
		done = rand() % 2;
		if (done == 0)
		{
			turn = rand() % 4;
			switch (turn)
			{
			case 0:
				TurnDown();
				system("cls");
			case 1:
				TurnLeft();
				system("cls");
			case 2:
				TurnRight();
				system("cls");
			case 3:
				TurnUp();
				system("cls");
			}
		}
		else
		{
			move = rand() % 10;
			switch (move)
			{
			case 0:
				U();
				system("cls");
			case 1:
				F_();
				system("cls");
			case 2:
				R();
				system("cls");
			case 3:
				D_();
				system("cls");
			case 4:
				U_();
				system("cls");
			case 5:
				L_();
				system("cls");
			case 6:
				D();
				system("cls");
			case 7:
				R_();
				system("cls");
			case 8:
				F();
				system("cls");
			case 9:
				L();
				system("cls");
			}
		}
	}
	writeToFile();
	std::cout << termcolor::bright_cyan << "Now Your Generate cub looks like this:" << std::endl;
	print();
	std::cout << "This posession is writen to FinalPos.txt file" << std::endl;

}

int colorCode(char color)
{
	switch (color)
	{
	case 'W':
			return 0;
	case 'R':
			return 1;
	case 'G':
		return 2;
	case 'Y':
		return 3;
	case 'B':
		return 4;
	case 'O':
		return 5;

	default:
		return -1;
	}
}

bool Cube::accuracy(char U[9], char L[9], char F[9], char R[9], char B[9], char D[9])
{
	int countOfColors[6] = {0};
	int ch;
	for (int i = 0; i < 9; i++)
	{
		ch = colorCode(U[i]);
		if (ch == -1)
		{
			std::cout << "Error with input data";
			return false;
		}
		countOfColors[ch]++;
	}
	for (int i = 0; i < 9; i++)
	{
		ch = colorCode(L[i]);
		if (ch == -1)
		{
			std::cout << "Error with input data";
			return false;
		}
		countOfColors[ch]++;
	}
	for (int i = 0; i < 9; i++)
	{
		ch = colorCode(F[i]);
		if (ch == -1)
		{
			std::cout << "Error with input data";
			return false;
		}
		countOfColors[ch]++;
	}
	for (int i = 0; i < 9; i++)
	{
		ch = colorCode(R[i]);
		if (ch == -1)
		{
			std::cout << "Error with input data";
			return false;
		}
		countOfColors[ch]++;
	}
	for (int i = 0; i < 9; i++)
	{
		ch = colorCode(B[i]);
		if (ch == -1)
		{
			std::cout << "Error with input data";
			return false;
		}
		countOfColors[ch]++;
	}
	for (int i = 0; i < 9; i++)
	{
		ch = colorCode(D[i]);
		if (ch == -1)
		{
			std::cout << "Error with input data";
			return false;
		}
		countOfColors[ch]++;
	}

	for (int i = 0; i < 6; i++)
	{
		if (countOfColors[i] != 9)
		{
			std::cout << "Error with number of colors. Sorry, I can't do anything";
			return false;
		}
	}
	return true;
}

void Cube::print()
{
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
		{
			std::cout << "      ";
		}
		PrintOfCage(surfaceU[i]);
		if ((i + 1) % 3 == 0)
		{
			std::cout << std::endl;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			PrintOfCage(surfaceL[3*i + j]);
		}
		for (int j = 0; j < 3; j++)
		{
			PrintOfCage(surfaceF[3 * i + j]);
		}
		for (int j = 0; j < 3; j++)
		{
			PrintOfCage(surfaceR[3 * i + j]);
		}
		for (int j = 0; j < 3; j++)
		{
			PrintOfCage(surfaceB[3 * i + j]);
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
		{
			std::cout << "      ";
		}
		PrintOfCage(surfaceD[i]);
		if ((i + 1) % 3 == 0)
		{
			std::cout << std::endl;
		}
	}
}

void Cube::writeToFile()
{
	std::ofstream fout("FinalPos.txt");
	for (int i = 0; i < 9; i++)
	{
		fout << surfaceU[i] << " ";
		if ((i + 1) % 3 == 0)
			fout << std::endl;
	}
	for (int i = 0; i < 9; i++)
	{
		fout << surfaceL[i] << " ";
		if ((i + 1) % 3 == 0)
			fout << std::endl;
	}
	for (int i = 0; i < 9; i++)
	{
		fout << surfaceF[i] << " ";
		if ((i + 1) % 3 == 0)
			fout << std::endl;
	}
	for (int i = 0; i < 9; i++)
	{
		fout << surfaceR[i] << " ";
		if ((i + 1) % 3 == 0)
			fout << std::endl;
	}
	for (int i = 0; i < 9; i++)
	{
		fout << surfaceB[i] << " ";
		if ((i + 1) % 3 == 0)
			fout << std::endl;
	}
	for (int i = 0; i < 9; i++)
	{
		fout << surfaceD[i] << " ";
		if ((i + 1) % 3 == 0)
			fout << std::endl;
	}
	fout.close();
	return;
}

void Cube::TurnUp()
{
	std::cout << "Turn Up" << std::endl;
	char AdditionalSurface[9];
	memcpy(AdditionalSurface, surfaceU, 9);
	memcpy(surfaceU, surfaceF, 9);
	memcpy(surfaceF, surfaceD, 9);
	for (int i = 0; i < 9; i++)
	{
		surfaceD[i] = surfaceB[8 - i];
	}
	for (int i = 0; i < 9; i++)
	{
		surfaceB[i] = AdditionalSurface[8 - i];
	}

	AdditionalSurface[0] = surfaceR[6];
	AdditionalSurface[1] = surfaceR[3];
	AdditionalSurface[2] = surfaceR[0];
	AdditionalSurface[3] = surfaceR[7];
	AdditionalSurface[4] = surfaceR[4];
	AdditionalSurface[5] = surfaceR[1];
	AdditionalSurface[6] = surfaceR[8];
	AdditionalSurface[7] = surfaceR[5];
	AdditionalSurface[8] = surfaceR[2];
	memcpy(surfaceR, AdditionalSurface, 9);

	AdditionalSurface[0] = surfaceL[2];
	AdditionalSurface[1] = surfaceL[5];
	AdditionalSurface[2] = surfaceL[8];
	AdditionalSurface[3] = surfaceL[1];
	AdditionalSurface[4] = surfaceL[4];
	AdditionalSurface[5] = surfaceL[7];
	AdditionalSurface[6] = surfaceL[0];
	AdditionalSurface[7] = surfaceL[3];
	AdditionalSurface[8] = surfaceL[6];
	memcpy(surfaceL, AdditionalSurface, 9);
}

void Cube::TurnDown()
{
	std::cout << "Turn Down" << std::endl;
	char AdditionalSurface[9];
	memcpy(AdditionalSurface, surfaceU, 9);
	for (int i = 0; i < 9; i++)
	{
		surfaceU[i] = surfaceB[8 - i];
	}
	for (int i = 0; i < 9; i++)
	{
		surfaceB[i] = surfaceD[8 - i];
	}
	memcpy(surfaceD, surfaceF, 9);
	memcpy(surfaceF, AdditionalSurface, 9);

	AdditionalSurface[0] = surfaceL[6];
	AdditionalSurface[1] = surfaceL[3];
	AdditionalSurface[2] = surfaceL[0];
	AdditionalSurface[3] = surfaceL[7];
	AdditionalSurface[4] = surfaceL[4];
	AdditionalSurface[5] = surfaceL[1];
	AdditionalSurface[6] = surfaceL[8];
	AdditionalSurface[7] = surfaceL[5];
	AdditionalSurface[8] = surfaceL[2];
	memcpy(surfaceL, AdditionalSurface, 9);

	AdditionalSurface[0] = surfaceR[2];
	AdditionalSurface[1] = surfaceR[5];
	AdditionalSurface[2] = surfaceR[8];
	AdditionalSurface[3] = surfaceR[1];
	AdditionalSurface[4] = surfaceR[4];
	AdditionalSurface[5] = surfaceR[7];
	AdditionalSurface[6] = surfaceR[0];
	AdditionalSurface[7] = surfaceR[3];
	AdditionalSurface[8] = surfaceR[6];
	memcpy(surfaceR, AdditionalSurface, 9);
}

void Cube::TurnRight()
{
	std::cout << "Turn Right" << std::endl;
	char AdditionalSurface[9];
	memcpy(AdditionalSurface, surfaceF, 9);
	memcpy(surfaceF, surfaceL, 9);
	memcpy(surfaceL, surfaceB, 9);
	memcpy(surfaceB, surfaceR, 9);
	memcpy(surfaceR, AdditionalSurface, 9);

	AdditionalSurface[0] = surfaceD[6];
	AdditionalSurface[1] = surfaceD[3];
	AdditionalSurface[2] = surfaceD[0];
	AdditionalSurface[3] = surfaceD[7];
	AdditionalSurface[4] = surfaceD[4];
	AdditionalSurface[5] = surfaceD[1];
	AdditionalSurface[6] = surfaceD[8];
	AdditionalSurface[7] = surfaceD[5];
	AdditionalSurface[8] = surfaceD[2];
	memcpy(surfaceD, AdditionalSurface, 9);

	AdditionalSurface[0] = surfaceU[2];
	AdditionalSurface[1] = surfaceU[5];
	AdditionalSurface[2] = surfaceU[8];
	AdditionalSurface[3] = surfaceU[1];
	AdditionalSurface[4] = surfaceU[4];
	AdditionalSurface[5] = surfaceU[7];
	AdditionalSurface[6] = surfaceU[0];
	AdditionalSurface[7] = surfaceU[3];
	AdditionalSurface[8] = surfaceU[6];
	memcpy(surfaceU, AdditionalSurface, 9);
}

void Cube::TurnLeft()
{
	std::cout << "Turn Left" << std::endl;
	char AdditionalSurface[9];
	memcpy(AdditionalSurface, surfaceF, 9);
	memcpy(surfaceF, surfaceR, 9);
	memcpy(surfaceR, surfaceB, 9);
	memcpy(surfaceB, surfaceL, 9);
	memcpy(surfaceL, AdditionalSurface, 9);

	AdditionalSurface[0] = surfaceU[6];
	AdditionalSurface[1] = surfaceU[3];
	AdditionalSurface[2] = surfaceU[0];
	AdditionalSurface[3] = surfaceU[7];
	AdditionalSurface[4] = surfaceU[4];
	AdditionalSurface[5] = surfaceU[1];
	AdditionalSurface[6] = surfaceU[8];
	AdditionalSurface[7] = surfaceU[5];
	AdditionalSurface[8] = surfaceU[2];
	memcpy(surfaceU, AdditionalSurface, 9);

	AdditionalSurface[0] = surfaceD[2];
	AdditionalSurface[1] = surfaceD[5];
	AdditionalSurface[2] = surfaceD[8];
	AdditionalSurface[3] = surfaceD[1];
	AdditionalSurface[4] = surfaceD[4];
	AdditionalSurface[5] = surfaceD[7];
	AdditionalSurface[6] = surfaceD[0];
	AdditionalSurface[7] = surfaceD[3];
	AdditionalSurface[8] = surfaceD[6];
	memcpy(surfaceD, AdditionalSurface, 9);
}

void Cube::F()
{
	std::cout << "F" << std::endl;
	char AdditionalSurface1[9];
	int I, J;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			I = j;
			J = (2 * (i + 1)) % 3;
			AdditionalSurface1[3 * I + J] = surfaceF[3 * i + j];
		}
	}
	memcpy(surfaceF, AdditionalSurface1, 9);
	char Additional1, Additional2, Additional3;
	Additional1 = surfaceL[2];
	Additional2 = surfaceL[5];
	Additional3 = surfaceL[8];
	surfaceL[2] = surfaceD[0];
	surfaceL[5] = surfaceD[1];
	surfaceL[8] = surfaceD[2];
	surfaceD[0] = surfaceR[6];
	surfaceD[1] = surfaceR[3];
	surfaceD[2] = surfaceR[0];
	surfaceR[6] = surfaceU[8];
	surfaceR[3] = surfaceU[7];
	surfaceR[0] = surfaceU[6];
	surfaceU[8] = Additional1;
	surfaceU[7] = Additional2;
	surfaceU[6] = Additional3;
}

void Cube::R()
{
	std::cout << "R" << std::endl;
	char AdditionalSurface1[9];
	int I, J;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			I = j;
			J = (2 * (i + 1)) % 3;
			AdditionalSurface1[3 * I + J] = surfaceR[3 * i + j];
		}
	}
	memcpy(surfaceR, AdditionalSurface1, 9);

	char Additional1, Additional2, Additional3;
	Additional1 = surfaceF[2];
	Additional2 = surfaceF[5];
	Additional3 = surfaceF[8];
	surfaceF[2] = surfaceD[2];
	surfaceF[5] = surfaceD[5];
	surfaceF[8] = surfaceD[8];
	surfaceD[2] = surfaceB[6];
	surfaceD[5] = surfaceB[3];
	surfaceD[8] = surfaceB[0];
	surfaceB[6] = surfaceU[2];
	surfaceB[3] = surfaceU[5];
	surfaceB[0] = surfaceU[8];
	surfaceU[2] = Additional1;
	surfaceU[5] = Additional2;
	surfaceU[8] = Additional3;
}

void Cube::L()
{
	std::cout << "L" << std::endl;
	char AdditionalSurface1[9];
	int I, J;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			I = j;
			J = (2 * (i + 1)) % 3;
			AdditionalSurface1[3 * I + J] = surfaceL[3 * i + j];
		}
	}
	memcpy(surfaceL, AdditionalSurface1, 9);

	char Additional1, Additional2, Additional3;
	Additional1 = surfaceB[2];
	Additional2 = surfaceB[5];
	Additional3 = surfaceB[8];
	surfaceB[2] = surfaceD[6];
	surfaceB[5] = surfaceD[3];
	surfaceB[8] = surfaceD[0];
	surfaceD[6] = surfaceF[6];
	surfaceD[3] = surfaceF[3];
	surfaceD[0] = surfaceF[0];
	surfaceF[6] = surfaceU[6];
	surfaceF[3] = surfaceU[3];
	surfaceF[0] = surfaceU[0];
	surfaceU[6] = Additional1;
	surfaceU[3] = Additional2;
	surfaceU[0] = Additional3;
}

void Cube::U()
{
	std::cout << "U" << std::endl;
	char AdditionalSurface1[9];
	int I, J;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			I = j;
			J = (2 * (i + 1)) % 3;
			AdditionalSurface1[3 * I + J] = surfaceU[3 * i + j];
		}
	}
	memcpy(surfaceU, AdditionalSurface1, 9);

	char Additional1, Additional2, Additional3;
	Additional1 = surfaceL[0];
	Additional2 = surfaceL[1];
	Additional3 = surfaceL[2];
	surfaceL[0] = surfaceF[0];
	surfaceL[1] = surfaceF[1];
	surfaceL[2] = surfaceF[2];
	surfaceF[0] = surfaceR[0];
	surfaceF[1] = surfaceR[1];
	surfaceF[2] = surfaceR[2];
	surfaceR[0] = surfaceB[0];
	surfaceR[1] = surfaceB[1];
	surfaceR[2] = surfaceB[2];
	surfaceB[0] = Additional1;
	surfaceB[1] = Additional2;
	surfaceB[2] = Additional3;
}

void Cube::D()
{
	std::cout << "D" << std::endl;
	char AdditionalSurface1[9];
	int I, J;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			I = j;
			J = (2 * (i + 1)) % 3;
			AdditionalSurface1[3 * I + J] = surfaceD[3 * i + j];
		}
	}
	memcpy(surfaceD, AdditionalSurface1, 9);

	char Additional1, Additional2, Additional3;
	Additional1 = surfaceL[6];
	Additional2 = surfaceL[7];
	Additional3 = surfaceL[8];
	surfaceL[6] = surfaceB[6];
	surfaceL[7] = surfaceB[7];
	surfaceL[8] = surfaceB[8];
	surfaceB[6] = surfaceR[6];
	surfaceB[7] = surfaceR[7];
	surfaceB[8] = surfaceR[8];
	surfaceR[6] = surfaceF[6];
	surfaceR[7] = surfaceF[7];
	surfaceR[8] = surfaceF[8];
	surfaceF[6] = Additional1;
	surfaceF[7] = Additional2;
	surfaceF[8] = Additional3;
}

void Cube::W()
{
	std::cout << "W" << std::endl;
	char Additional1, Additional2, Additional3;
	Additional1 = surfaceL[3];
	Additional2 = surfaceL[4];
	Additional3 = surfaceL[5];
	surfaceL[3] = surfaceB[3];
	surfaceL[4] = surfaceB[4];
	surfaceL[5] = surfaceB[5];
	surfaceB[3] = surfaceR[3];
	surfaceB[4] = surfaceR[4];
	surfaceB[5] = surfaceR[5];
	surfaceR[3] = surfaceF[3];
	surfaceR[4] = surfaceF[4];
	surfaceR[5] = surfaceF[5];
	surfaceF[3] = Additional1;
	surfaceF[4] = Additional2;
	surfaceF[5] = Additional3;
}

void Cube::F_()
{
	std::cout << "F'" << std::endl;
	char AdditionalSurface1[9];
	int I, J;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			I = j;
			J = (2 * (i + 4)) % 3;
			AdditionalSurface1[3 * i + j] = surfaceF[3 * I + J];
		}
	}
	memcpy(surfaceF, AdditionalSurface1, 9);
	char Additional1, Additional2, Additional3;
	Additional1 = surfaceL[2];
	Additional2 = surfaceL[5];
	Additional3 = surfaceL[8];
	surfaceL[2] = surfaceU[8];
	surfaceL[5] = surfaceU[7];
	surfaceL[8] = surfaceU[6];
	surfaceU[8] = surfaceR[6];
	surfaceU[7] = surfaceR[3];
	surfaceU[6] = surfaceR[0];
	surfaceR[6] = surfaceD[0];
	surfaceR[3] = surfaceD[1];
	surfaceR[0] = surfaceD[2];
	surfaceD[0] = Additional1;
	surfaceD[1] = Additional2;
	surfaceD[2] = Additional3;
}

void Cube::R_()
{
	std::cout << "R'" << std::endl;
	char AdditionalSurface1[9];
	int I, J;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			I = j;
			J = (2 * (i + 4)) % 3;
			AdditionalSurface1[3 * i + j] = surfaceR[3 * I + J];
		}
	}
	memcpy(surfaceR, AdditionalSurface1, 9);
	
	char Additional1, Additional2, Additional3;
	Additional1 = surfaceF[2];
	Additional2 = surfaceF[5];
	Additional3 = surfaceF[8];
	surfaceF[2] = surfaceU[2];
	surfaceF[5] = surfaceU[5];
	surfaceF[8] = surfaceU[8];
	surfaceU[2] = surfaceB[6];
	surfaceU[5] = surfaceB[3];
	surfaceU[8] = surfaceB[0];
	surfaceB[6] = surfaceD[2];
	surfaceB[3] = surfaceD[5];
	surfaceB[0] = surfaceD[8];
	surfaceD[2] = Additional1;
	surfaceD[5] = Additional2;
	surfaceD[8] = Additional3;
}

void Cube::L_()
{
	std::cout << "L'" << std::endl;
	char AdditionalSurface1[9];
	int I, J;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			I = j;
			J = (2 * (i + 4)) % 3;
			AdditionalSurface1[3 * i + j] = surfaceL[3 * I + J];
		}
	}
	memcpy(surfaceL, AdditionalSurface1, 9);

	char Additional1, Additional2, Additional3;
	Additional1 = surfaceB[2];
	Additional2 = surfaceB[5];
	Additional3 = surfaceB[8];
	surfaceB[2] = surfaceU[6];
	surfaceB[5] = surfaceU[3];
	surfaceB[8] = surfaceU[0];
	surfaceU[6] = surfaceF[6];
	surfaceU[3] = surfaceF[3];
	surfaceU[0] = surfaceF[0];
	surfaceF[6] = surfaceD[6];
	surfaceF[3] = surfaceD[3];
	surfaceF[0] = surfaceD[0];
	surfaceD[6] = Additional1;
	surfaceD[3] = Additional2;
	surfaceD[0] = Additional3;
}

void Cube::U_()
{
	std::cout << "U'" << std::endl;
	char AdditionalSurface1[9];
	int I, J;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			I = j;
			J = (2 * (i + 4)) % 3;
			AdditionalSurface1[3 * i + j] = surfaceU[3 * I + J];
		}
	}
	memcpy(surfaceU, AdditionalSurface1, 9);

	char Additional1, Additional2, Additional3;
	Additional1 = surfaceL[0];
	Additional2 = surfaceL[1];
	Additional3 = surfaceL[2];
	surfaceL[0] = surfaceB[0];
	surfaceL[1] = surfaceB[1];
	surfaceL[2] = surfaceB[2];
	surfaceB[0] = surfaceR[0];
	surfaceB[1] = surfaceR[1];
	surfaceB[2] = surfaceR[2];
	surfaceR[0] = surfaceF[0];
	surfaceR[1] = surfaceF[1];
	surfaceR[2] = surfaceF[2];
	surfaceF[0] = Additional1;
	surfaceF[1] = Additional2;
	surfaceF[2] = Additional3;
}

void Cube::D_()
{
	std::cout << "D'" << std::endl;
	char AdditionalSurface1[9];
	int I, J;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			I = j;
			J = (2 * (i + 4)) % 3;
			AdditionalSurface1[3 * i + j] = surfaceD[3 * I + J];
		}
	}
	memcpy(surfaceD, AdditionalSurface1, 9);

	char Additional1, Additional2, Additional3;
	Additional1 = surfaceL[6];
	Additional2 = surfaceL[7];
	Additional3 = surfaceL[8];
	surfaceL[6] = surfaceF[6];
	surfaceL[7] = surfaceF[7];
	surfaceL[8] = surfaceF[8];
	surfaceF[6] = surfaceR[6];
	surfaceF[7] = surfaceR[7];
	surfaceF[8] = surfaceR[8];
	surfaceR[6] = surfaceB[6];
	surfaceR[7] = surfaceB[7];
	surfaceR[8] = surfaceB[8];
	surfaceB[6] = Additional1;
	surfaceB[7] = Additional2;
	surfaceB[8] = Additional3;
}

void Cube::W_()
{
	std::cout << "W'" << std::endl;
	char Additional1, Additional2, Additional3;
	Additional1 = surfaceL[3];
	Additional2 = surfaceL[4];
	Additional3 = surfaceL[5];
	surfaceL[3] = surfaceF[3];
	surfaceL[4] = surfaceF[4];
	surfaceL[5] = surfaceF[5];
	surfaceF[3] = surfaceR[3];
	surfaceF[4] = surfaceR[4];
	surfaceF[5] = surfaceR[5];
	surfaceR[3] = surfaceB[3];
	surfaceR[4] = surfaceB[4];
	surfaceR[5] = surfaceB[5];
	surfaceB[3] = Additional1;
	surfaceB[4] = Additional2;
	surfaceB[5] = Additional3;
}

bool Cube::IsCubeAssembled()
{
	for (int i = 0; i < 9; i++)
	{
		if ((surfaceB[i] != surfaceB[4]) || (surfaceR[i] != surfaceR[4]) || (surfaceF[i] != surfaceF[4]) || 
			(surfaceL[i] != surfaceL[4]) || (surfaceD[i] != surfaceD[4]) || (surfaceU[i] != surfaceU[4]))
			return false;
	}
	return true;
}

void Cube::Cross()
{
	if (IsCubeAssembled())
		return;
	bool key = false;
	if ((surfaceU[1] == 'W') && (surfaceU[3] == 'W') && (surfaceU[5] == 'W') && (surfaceU[7] == 'W') && (surfaceU[4] == 'W'))
	{
		key = true;
	}
	if (surfaceU[4] != 'W')
	{
		if (surfaceD[4] == 'W')
		{
			TurnUp();
			TurnUp();
		}
		else if (surfaceB[4] == 'W')
		{
			TurnDown();
		}
		else if (surfaceL[4] == 'W')
		{
			TurnRight();
			TurnUp();
		}
		else if (surfaceR[4] == 'W')
		{
			TurnLeft();
			TurnUp();
		}
		else if (surfaceF[4] == 'W')
		{
			TurnUp();
		}
	}
	while ((key == false) && ((surfaceU[1] != 'W') || (surfaceU[3] != 'W') || (surfaceU[5] != 'W') || (surfaceU[7] != 'W')))
	{
		for (int i = 0; i < 4; i++)
		{
			if (surfaceF[5] == 'W')
			{
				while (surfaceU[5] == 'W')
				{
					U();
				}
				R();
			}
			if (surfaceF[3] == 'W')
			{
				while (surfaceU[3] == 'W')
				{
					U();
				}
				L_();
			}
			if (surfaceF[1] == 'W')
			{
				F();
				while (surfaceU[5] == 'W')
				{
					U();
				}
				R();
			}
			if (surfaceF[7] == 'W')
			{
				while (surfaceU[5] == 'W')
				{
					U();
				}
				F_();
				R();
				F();
			}
			if (surfaceD[1] == 'W')
			{
				while (surfaceU[7] == 'W')
				{
					U();
				}
				F_();
				F_();
			}
			TurnLeft();
		}
	}
	int numberOfMatch = 0;
	numberOfMatch = (surfaceF[1] == surfaceF[4]) + (surfaceR[1] == surfaceR[4]) +
		+(surfaceB[1] == surfaceB[4]) + (surfaceL[1] == surfaceL[4]);
	
	if (numberOfMatch == 0)
	{
		while (surfaceF[1] != surfaceF[4])
			U();
		numberOfMatch = (surfaceF[1] == surfaceF[4]) + (surfaceR[1] == surfaceR[4]) +
			+(surfaceB[1] == surfaceB[4]) + (surfaceL[1] == surfaceL[4]);
	}
	if (numberOfMatch == 1)
	{
		while (surfaceF[1] != surfaceF[4])
		{
			TurnLeft();
		}
		R();
		U();
		R_();
		U_();
		R();
	}
	
	numberOfMatch = (surfaceF[1] == surfaceF[4]) + (surfaceR[1] == surfaceR[4]) +
		+(surfaceB[1] == surfaceB[4]) + (surfaceL[1] == surfaceL[4]);
	if (numberOfMatch == 2)
	{
		while (surfaceF[1] != surfaceF[4])
		{
			TurnLeft();
		}
		if ((surfaceB[4] == surfaceB[1]))
		{
			R();
			U();
			R_();
			U_();
			R();
			U();
			R();
			U();
			R_();
			U_();
			R();
			U_();
			R();
			U();
			R_();
			U_();
			R();

		}
		else if (surfaceL[4] != surfaceL[1])
		{
			TurnLeft();
			R();
			U();
			R_();
			U_();
			R();
		}
		else
		{
			R();
			U();
			R_();
			U_();
			R();
		}
	}
}

void Cube::FirstLayer()
{
	if (IsCubeAssembled())
		return;
	TurnDown();
	TurnDown();
	int numberOfCorner = 0;
	numberOfCorner = ((surfaceF[8] == surfaceF[4]) && (surfaceR[6] == surfaceR[4]) && (surfaceD[2] == 'W'))
		+ ((surfaceR[8] == surfaceR[4]) && (surfaceB[6] == surfaceB[4]) && (surfaceD[8] == 'W'))
		+ ((surfaceB[8] == surfaceB[4]) && (surfaceL[6] == surfaceL[4]) && (surfaceD[6] == 'W'))
		+ ((surfaceF[6] == surfaceF[4]) && (surfaceL[8] == surfaceL[4]) && (surfaceD[0] == 'W'));

	while (numberOfCorner != 4)
	{
		if ((surfaceF[8] == surfaceF[4]) && (surfaceR[6] == surfaceR[4]) && (surfaceD[2] == 'W'))
			TurnLeft();
		else
		{
			if ((surfaceF[8] == 'W') || (surfaceR[6] == 'W') || (surfaceD[2] == 'W'))
			{
				if ((surfaceD[2] == surfaceR[4] && (surfaceR[6] == surfaceF[0])) ||
					(surfaceD[2] == surfaceF[4] && (surfaceF[6] == surfaceR[0])))
				{
					while (!((surfaceF[8] == surfaceF[4]) && (surfaceR[6] == surfaceR[4]) && (surfaceD[2] == 'W')))
					{
						R();
						U();
						R_();
						U_();
					}
				}
				else
				{
					R();
					U();
					R_();
					U_();
				}
			}
			if (!((surfaceF[8] == surfaceF[4]) && (surfaceR[6] == surfaceR[4]) && (surfaceD[2] == 'W')))
			{
				for (int j = 0; j < 4; j++) {
					for (int i = 0; i < 4; i++)
					{
						char u = surfaceU[8], f = surfaceF[2], r = surfaceR[0];
						if (((u == 'W') + (u == surfaceF[4]) + (u == surfaceR[4]) +
							(f == 'W') + (f == surfaceF[4]) + (f == surfaceR[4]) +
							(r == 'W') + (r == surfaceF[4]) + (r == surfaceR[4])) == 3)
						{
							while (!((surfaceF[8] == surfaceF[4]) && (surfaceR[6] == surfaceR[4]) && (surfaceD[2] == 'W')))
							{
								R();
								U();
								R_();
								U_();
							}
							break;
						}
						else
						{
							U();
						}
					}
					TurnLeft();
				}
			}
		}
		numberOfCorner = ((surfaceF[8] == surfaceF[4]) && (surfaceR[6] == surfaceR[4]) && (surfaceD[2] == 'W'))
			+ ((surfaceR[8] == surfaceR[4]) && (surfaceB[6] == surfaceB[4]) && (surfaceD[8] == 'W'))
			+ ((surfaceB[8] == surfaceB[4]) && (surfaceL[6] == surfaceL[4]) && (surfaceD[6] == 'W'))
			+ ((surfaceF[6] == surfaceF[4]) && (surfaceL[8] == surfaceL[4]) && (surfaceD[0] == 'W'));
	}
}

void Cube::SecondLayer()
{
	if (IsCubeAssembled())
		return;
	int numberOfEdge = 0;
	numberOfEdge = (surfaceF[3] == surfaceF[5]) + (surfaceF[5] == surfaceF[4]) +
		(surfaceR[3] == surfaceR[5]) + (surfaceR[5] == surfaceR[4]) +
		(surfaceB[3] == surfaceB[5]) + (surfaceB[5] == surfaceB[4]) +
		(surfaceL[3] == surfaceL[5]) + (surfaceL[5] == surfaceL[4]);
	while (numberOfEdge < 8)
	{
		while ((surfaceF[3] == surfaceF[5]) && (surfaceF[5] == surfaceF[4]))
			TurnLeft();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if ((surfaceF[1] == surfaceF[4]) && ((surfaceU[7] == surfaceL[4]) || (surfaceU[7] == surfaceR[4])))
				{
					break;
				}
				else
				{
					U();
				}
			}
			if ((surfaceF[5] != surfaceF[4]) || (surfaceR[3] != surfaceR[4])
				&& (surfaceF[5] != 'Y') && (surfaceR[3] != 'Y'))
			{
				for (int w = 0; w < 4; w++)
				{
					if ((surfaceU[3] == 'Y') || (surfaceL[1] == 'Y') || (w == 3))
					{
						R();
						U();
						R_();
						U_();
						TurnLeft();
						L_();
						U_();
						L();
						U();
						TurnRight();
						break;
					}
					else
					{
						U();
					}
				}
			}
			for (int ii = 0; ii < 4; ii++)
			{
				for (int jj = 0; jj < 4; jj++)
				{
					if ((surfaceF[1] == surfaceF[4]) && ((surfaceU[7] == surfaceL[4]) || (surfaceU[7] == surfaceR[4])))
					{
						break;
					}
					else
					{
						U();
					}
				}
			}
			if (surfaceF[1] == surfaceF[4])
			{
				if (surfaceU[7] == surfaceL[4])
				{
					U_();
					L_();
					U_();
					L();
					U();
					TurnRight();
					R();
					U();
					R_();
					U_();
					TurnLeft();
				}
				if (surfaceU[7] == surfaceR[4])
				{
					U();
					R();
					U();
					R_();
					U_();
					TurnLeft();
					L_();
					U_();
					L();
					U();
					TurnRight();
				}
			}
			numberOfEdge = (surfaceF[3] == surfaceF[5]) + (surfaceF[5] == surfaceF[4]) +
				(surfaceR[3] == surfaceR[5]) + (surfaceR[5] == surfaceR[4]) +
				(surfaceB[3] == surfaceB[5]) + (surfaceB[5] == surfaceB[4]) +
				(surfaceL[3] == surfaceL[5]) + (surfaceL[5] == surfaceL[4]);
			if (numberOfEdge == 8)
				break;
			TurnLeft();
		}
		numberOfEdge = (surfaceF[3] == surfaceF[5]) + (surfaceF[5] == surfaceF[4]) +
			(surfaceR[3] == surfaceR[5]) + (surfaceR[5] == surfaceR[4]) +
			(surfaceB[3] == surfaceB[5]) + (surfaceB[5] == surfaceB[4]) +
			(surfaceL[3] == surfaceL[5]) + (surfaceL[5] == surfaceL[4]);
	}
	return;
}

void Cube::CrossUp()
{
	if (IsCubeAssembled())
		return;
	if (!((surfaceU[1] == surfaceU[4]) && (surfaceU[3] == surfaceU[4])
		&& (surfaceU[5] == surfaceU[4]) && (surfaceU[7] == surfaceU[4])))
	{
		if (((surfaceU[1] == surfaceU[4]) && (surfaceU[7] == surfaceU[4]))
			|| ((surfaceU[3] == surfaceU[4]) && (surfaceU[5] == surfaceU[4])))
		{
			if ((surfaceU[1] == surfaceU[4]) && (surfaceU[7] == surfaceU[4]))
			{
				U();
			}
			F();
			R();
			U();
			R_();
			U_();
			F_();
		}
		else if (((!(surfaceU[1] == surfaceU[4])) && (!(surfaceU[3] == surfaceU[4]))
			&& (!(surfaceU[5] == surfaceU[4])) && (!(surfaceU[7] == surfaceU[4]))))
		{
			F();
			R();
			U();
			R_();
			U_();
			F_();
			U();
			U();
			F();
			R();
			U();
			R_();
			U_();
			R();
			U();
			R_();
			U_();
			F_();
		}
		else
		{
			while ((surfaceU[1] != surfaceU[4]) || (surfaceU[3] != surfaceU[4]))
			{
				U();
			}
			F();
			R();
			U();
			R_();
			U_();
			R();
			U();
			R_();
			U_();
			F_();
		}
	}
}

void Cube::TopFacet()
{
	if (IsCubeAssembled())
		return;
	TurnDown();
	TurnLeft();
	for (int i = 0; i < 4; i++)
	{
		while (surfaceL[0] != surfaceL[4])
		{
			R();
			U();
			R_();
			U_();
		}
		L_();
	}
	TurnRight();
	TurnUp();
}

void Cube::ThirdLayer()
{
	if (IsCubeAssembled())
		return;
	for (int i = 0; i < 4; i++)
	{
		if (((surfaceB[1] == surfaceB[4]) + (surfaceR[1] == surfaceR[4]) +
			(surfaceF[1] == surfaceF[4]) + (surfaceL[1] == surfaceL[4])) >= 2)
		{
			while (surfaceB[1] != surfaceB[4])
				TurnLeft();
			break;
		}
		U();
	}
	
	if (!((surfaceB[1] == surfaceB[4]) && (surfaceF[1] == surfaceF[4])
		&& (surfaceR[1] == surfaceR[4]) && (surfaceL[1] == surfaceL[4])))
	{
		if (surfaceL[1] == surfaceL[4])
		{
			R();
			U();
			R_();
			F_();
			R();
			U();
			R_();
			U_();
			R_();
			F();
			R();
			R();
			U_();
			R_();
			U_();
		}
		else if (surfaceR[1] == surfaceR[4])
		{
			U_();
			R();
			U();
			R_();
			F_();
			R();
			U();
			R_();
			U_();
			R_();
			F();
			R();
			R();
			U_();
			R_();
			U_();
		}
		else
		{
			R();
			U();
			R_();
			F_();
			R();
			U();
			R_();
			U_();
			R_();
			F();
			R();
			R();
			U_();
			R_();
			U_();
			U();
			U();
			R();
			U();
			R_();
			F_();
			R();
			U();
			R_();
			U_();
			R_();
			F();
			R();
			R();
			U_();
			R_();
			U_();
			U_();
		}
	}
	
	while (surfaceF[1] != surfaceF[4]) {
		U();
	}
	
	bool key = false;
	while (!(IsCubeAssembled()))
	{
		for (int i = 0; i < 4; i++)
		{
			if ((surfaceF[0] == surfaceF[4]) && (surfaceL[2] == surfaceL[4]))
			{
				TurnLeft();
				if (IsCubeAssembled())
				{
					return;
				}
				key = true;
				break;
			}
			else
			{
				TurnLeft();
				if (IsCubeAssembled())
				{
					return;
				}
			}
		}
		TurnDown();
		TurnLeft();
		TurnUp();

		U();
		U();
		R();
		U();
		U();
		R_();
		F();
		F();
		U();
		U();
		L_();
		U();
		U();
		L();
		F();
		F();
		if ((surfaceU[0] == surfaceU[4]) && (surfaceU[6] == surfaceU[4]) && (surfaceB[2] == surfaceB[4]) &&
			(surfaceF[0] == surfaceF[4]) && (surfaceF[6] == surfaceF[4]) && (surfaceD[0] == surfaceD[4]))
		{
			
			break;
		}
		else
		{
			if (key == true)
			{
				U();
				U();
				R();
				U();
				U();
				R_();
				F();
				F();
				U();
				U();
				L_();
				U();
				U();
				L();
				F();
				F();
				TurnRight();
				TurnUp();
			}
			else {
				TurnRight();
				TurnUp();
			}
		}
	}
	TurnLeft();
	TurnUp();
}

void Cube::AssemblingCube()
{
	if (IsCubeAssembled())
		return;
	if (!accuracy(surfaceB, surfaceD, surfaceF, surfaceL, surfaceR, surfaceU))
	{
		return;
	}
	std::cout << termcolor::underline << termcolor::bright_cyan << "Do you want to see intermediate build results?" << std::endl;
	std::cout << termcolor::reset;
	std::cout << termcolor::bright_cyan << "1 - Yes" << std::endl << "2 - No" << std::endl;
	std::cout << termcolor::reset;
	int keyPrint;
	std::cin >> keyPrint;

	if (keyPrint == 1)
	{
		std::cout << termcolor::bright_cyan << "Now your cube looks like this:" << std::endl;
		print();
	}
	std::cout << termcolor::bright_cyan << "You should do the following:" << std::endl;
	std::cout << termcolor::reset;
	Cross();

	if (keyPrint == 1)
	{
		std::cout << termcolor::bright_cyan << "Your cube after assembling the cross:" << std::endl;
		print();
	}
	std::cout << termcolor::bright_cyan << "You should do the following:" << std::endl;
	std::cout << termcolor::reset;
	FirstLayer();

	if (keyPrint == 1)
	{
		std::cout << termcolor::bright_cyan  << "Congratulations! The first layer is assembled!" << std::endl;
		print();
	}
	std::cout << termcolor::bright_cyan << "You should do the following:" << std::endl;
	std::cout << termcolor::reset;
	SecondLayer();

	if (keyPrint == 1)
	{
		std::cout << termcolor::bright_cyan << "WOW! Look two layers already assembled!" << std::endl;
		print();
	}
	std::cout << termcolor::bright_cyan << "You should do the following:" << std::endl;
	std::cout << termcolor::reset;
	CrossUp();

	if (keyPrint == 1)
	{
		std::cout << termcolor::bright_cyan << "Assembled the cross at the top))" << std::endl;
		print();
	}
	std::cout << termcolor::bright_cyan << "You should do the following:" << std::endl;
	std::cout << termcolor::reset;
	TopFacet();

	if (keyPrint == 1)
	{
		std::cout << termcolor::bright_cyan << "It seems that there is only a little bit left" << std::endl;
		print();
	}
	std::cout << termcolor::bright_cyan << "You should do the following:" << std::endl;
	std::cout << termcolor::reset;
	ThirdLayer();

	if (keyPrint == 1)
	{
		std::cout << termcolor::bright_cyan << "Well, that's it. The cube is assembled, we are all great)" << std::endl;
		print();
	}
	return;
}

void Cube::play()
{
	std::fill(surfaceU, surfaceU + 9, 'W');
	std::fill(surfaceL, surfaceL + 9, 'O');
	std::fill(surfaceF, surfaceF + 9, 'G');
	std::fill(surfaceR, surfaceR + 9, 'R');
	std::fill(surfaceB, surfaceB + 9, 'B');
	std::fill(surfaceD, surfaceD + 9, 'Y');

	std::cout << "Welcome to the virtual cube) Initially, you are given a collected Rubik's Cube." <<
		std::endl << "The following commands are available to you" << std::endl
		<< "U          - Rotate the top surface of the cube clockwise" << std::endl << "U'         - Rotate the top surface of the cube Counterclockwise" << std::endl 
		<< "R          - Rotate the right surface of the cube clockwise" << std::endl << "R'         - Rotate the right surface of the cube Counterclockwise" << std::endl
		<< "L          - Rotate the left surface of the cube clockwise" << std::endl << "L'         - Rotate the left surface of the cube Counterclockwise" << std::endl
		<< "D          - Rotate the down surface of the cube clockwise" << std::endl << "D'         - Rotate the down surface of the cube Counterclockwise" << std::endl
		<< "F          - Rotate the front surface of the cube clockwise" << std::endl << "F'         - Rotate the front surface of the cube Counterclockwise" << std::endl
		<< "print      - show current status to console" << std::endl << "Assembling - Assemble the cube you just entagled" << std::endl
		<< "return     - stop playing" << std::endl << std::endl << "Now your cube looks like this:" << std::endl;

	print();
	char command[20];
	std::cin >> command;
	while (strcmp(command, "return") != 0)
	{
		if (strcmp(command, "U") == 0)
		{
			std::cout <<termcolor::green << char(16);
			std::cout << termcolor::reset;
			U();

		}
		else if (strcmp(command, "U'") == 0)
		{
			std::cout << termcolor::green << char(16);
			std::cout << termcolor::reset;
			U_();
		}
		else if (strcmp(command, "R") == 0)
		{
			std::cout << termcolor::green << char(16);
			std::cout << termcolor::reset;
			R();
		}
		else if (strcmp(command, "R'") == 0)
		{
			std::cout << termcolor::green << char(16);
			std::cout << termcolor::reset;
			R_();
		}
		else if (strcmp(command, "L") == 0)
		{
			std::cout << termcolor::green << char(16);
			std::cout << termcolor::reset;
			L();
		}
		else if (strcmp(command, "L'") == 0)
		{
			std::cout << termcolor::green << char(16);
			std::cout << termcolor::reset;
			L_();
		}
		else if (strcmp(command, "D") == 0)
		{
			std::cout << termcolor::green << char(16);
			std::cout << termcolor::reset;
			D();
		}
		else if (strcmp(command, "D'") == 0)
		{
			std::cout << termcolor::green << char(16);
			std::cout << termcolor::reset;
			D_();
		}
		else if (strcmp(command, "F") == 0)
		{
			std::cout << termcolor::green << char(16);
			std::cout << termcolor::reset;
			F();
		}
		else if (strcmp(command, "F'") == 0)
		{
			std::cout << termcolor::green << char(16);
			std::cout << termcolor::reset;
			F_();
		}
		else if (strcmp(command, "TurnLeft") == 0)
		{
			std::cout << termcolor::green << char(16);
			std::cout << termcolor::reset;
			TurnLeft();
		}
		else if (strcmp(command, "TurnRight") == 0)
		{
			std::cout << termcolor::green << char(16);
			std::cout << termcolor::reset;
			TurnRight();
		}
		else if (strcmp(command, "TurnUp") == 0)
		{
			std::cout << termcolor::green << char(16);
			std::cout << termcolor::reset;
			TurnUp();
		}
		else if (strcmp(command, "TurnDown") == 0)
		{
			std::cout << termcolor::green << char(16);
			std::cout << termcolor::reset;
			TurnDown();
		}
		else if (strcmp(command, "print") == 0)
		{
			print();
		}
		else if (strcmp(command, "Assembling") == 0)
		{
			writeToFile();
			AssemblingCube();
		}
		std::cin >> command;
	}
}