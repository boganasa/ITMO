#ifndef CLASS_CUBE_H 
#define CLASS_CUBE_H 
#include <iostream>
#define NOMINMAX
#include <termcolor.hpp>
#include <time.h>
#include <fstream>
#include <string.h>
class Cube
{
private:
	char surfaceU[9], surfaceL[9], surfaceF[9], surfaceR[9], surfaceB[9], surfaceD[9];
public:
	Cube(char U[9], char L[9], char F[9], char R[9], char B[9], char D[9]);

	//Доп методы
	void Generation();
	void print();
	void writeToFile();
	bool accuracy(char U[9], char L[9], char F[9], char R[9], char B[9], char D[9]);
	void play();
	bool IsCubeAssembled();

	//Повороты куба
	void TurnUp();
	void TurnDown();
	void TurnLeft();
	void TurnRight();

	//Все повороты которые будут использоваться
	void F();
	void R();
	void L();
	void U();
	void D();
	void W();

	void F_();
	void R_();
	void L_();
	void U_();
	void D_();
	void W_(); 

	//Этапы сборки
	void Cross();
	void FirstLayer();
	void SecondLayer();
	void CrossUp();
	void TopFacet();
	void ThirdLayer();

	//Полная сборка
	void AssemblingCube();
};
#endif