#include <string>
#include <iostream>
#include <fstream>
#include "Physicon.h"
using namespace std;

#ifndef RVEKTOR_H
#include "RVektor.h"
#endif

#ifndef RMATRIX_H
#include "RMatrix.h"
#endif

#ifndef	SMALLSQUARE_H
#include "SmallSquare.h"
#endif

#include "SquarePlate.h"



SquarePlate::SquarePlate()
{
	side = 1.; // SquarePlate of 1 meter
	potPlate = 1.; //Potential of the plate 1 Volt

	nX = 7;
	nY = nX;
	nN = nX * nY;
}


SquarePlate::~SquarePlate()
{
}
//--------------------------------------------------------
void SquarePlate::CalculateTotalCharge()
{
	double area = vPlate[0].GetArea();

	totalCharge = chargeDensity.SumupElements();

	totalCharge *= area;

	std::cout << "\n TotalCharge =" << totalCharge << "\n\n";
}
//--------------------------------------------------------
void SquarePlate::FindChargeDistribution()
{
	std::cout << "\n FindChargeDistribution\n\n";

	chargeDensity.SetDim(nN);

	chargeDensity = RealGaussElimination(aMa, gmVec);

	int iN = 0;
	for (int i = 0; i < nX; i++)
	{
		std::cout << i << " ";
		for (int j = 0; j < nY; j++)
		{
			std::cout << chargeDensity[iN] << " ";
			iN++;
		}
		std::cout << "\n";
	}
}
//--------------------------------------------------------
void SquarePlate::CreateMatrix()
{
	std::cout << "\n Function: CreateMatrix() \n\n";

	aMa.SetDimension(nN, nN);

	for (int i = 0; i < nN; i++)
	{
		for (int j = 0; j < nN; j++)
		{
			aMa[i][j] = vPlate[i].CouplingCoefficient(vPlate[j]);
		}
	}

	std::cout << "\n aMa = \n" << aMa;
}
//--------------------------------------------------------
void SquarePlate::CreateGmVektor()
{
	std::cout << "\n Function: CreateGmVektor() \n\n";

	gmVec.SetDim(nN);

	for (int i = 0; i < nN; i++)
	{
		gmVec[i] = potPlate;
	}

	std::cout << "gmVec = " << gmVec << "\n";
}
//--------------------------------------------------------
void SquarePlate::CreatePlate()
{
	std::cout << "\n Function: CreatePlate()\n\n";

	vPlate.SetDim(nN);
	double delX = side / nX;
	double delY = side / nY;

	int iN = 0;

	for (int iX = -nX / 2; iX <= nX / 2; iX++)
	{
		double x = delX * iX;
		for (int iY = -nY / 2; iY <= nY / 2; iY++)
		{
			double y = delY * iY;
			vPlate[iN].MoveTo(x, y);
			vPlate[iN].SetSide(delX);

			std::cout << iN << " " << vPlate[iN] ;
			iN++;
		}
	}
}


//-----------------------------------------------------
//  source code of function SquarePlate::SavePlate()
//-----------------------------------------------------
void SquarePlate::SavePlate()
{
	std::ofstream aFile;
	aFile.open("Group_10_Plate.txt");

	aFile << "BOTTOMLAYER\n";

	aFile << nN << "," << potPlate << "\n";
	for (int i = 0; i < nN; i++)
	{
		aFile << vPlate[i] << "," << chargeDensity[i] << ")" <<"\n";
	}
	aFile.close();
	std::cout << "\nFinally generating 7*7 plate for group_10 in Group_10_Plate.txt \n\n";
}