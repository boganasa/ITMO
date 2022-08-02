#include <iostream>
#include <fstream>
#include "Class_Cube.h"

using namespace std;

int main()
{
	ifstream fcin("StartPos.txt");
	char surfaceU[9], surfaceL[9], surfaceF[9], surfaceR[9], surfaceB[9], surfaceD[9];
	for (int i = 0; i < 9; i++)
	{
		fcin >> surfaceU[i];
	}
	for (int i = 0; i < 9; i++)
	{
		fcin >> surfaceL[i];
	}
	for (int i = 0; i < 9; i++)
	{
		fcin >> surfaceF[i];
	}
	for (int i = 0; i < 9; i++)
	{
		fcin >> surfaceR[i];
	}
	for (int i = 0; i < 9; i++)
	{
		fcin >> surfaceB[i];
	}
	for (int i = 0; i < 9; i++)
	{
		fcin >> surfaceD[i];
	}

	Cube cub(surfaceU, surfaceL, surfaceF, surfaceR, surfaceB, surfaceD);
	cub.play();
	//cub.AssemblingCube();
	/*for (int i = 0; i < 20; i++)
	{
		cub.Generation();
		cub.AssemblingCube();
		int t;
		std::cin >> t;
	}*/
}