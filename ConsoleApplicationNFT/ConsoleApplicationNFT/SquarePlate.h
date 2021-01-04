#ifndef SQUAREPLATE_H
#define SQUAREPLATE_H
#pragma once
class SquarePlate
{

private:
	double side; //Side length in meter
	double potPlate; //Potential of the plate in Volt
	double totalCharge; //Total amount of charges on the plate

	int nX; //Number of SmallSquares in x-direction, must be an odd number
	int nY; //must equal to nX,

	int nN; //Total number of Squares

	Vektor<SmallSquare> vPlate;

	RVektor gmVec; //gm-vector of Momentum Method
	RMatrix aMa; // Matrix of Momentum Method

	RVektor chargeDensity; //Charge density vector

public:
	SquarePlate();
	~SquarePlate();

	void CreatePlate(); // Creates all SmallSquares of the Plate
	void CreateGmVektor(); // Creates the gm-Vektor of Momentum method
	void CreateMatrix(); // Creates the matrix of Momentum method
	void FindChargeDistribution(); //Calculates the charge density in each square
	void CalculateTotalCharge();//Sums up all charges
	void SavePlate(); //To save plate in text file 
};
#endif
