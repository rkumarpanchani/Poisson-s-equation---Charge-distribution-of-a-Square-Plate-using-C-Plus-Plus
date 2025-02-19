// ConsoleApplicationNFT.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Cmplx.h"
#include "RVektor.h"
#include "RMatrix.h"
#include "SmallSquare.h"
#include "SquarePlate.h"

int main()
{
 //   std::cout << "Hello World!\n\n\n";

	//Cmplx z = Cmplx(2., 3.);

	//std::cout << "Z = " << z << "\n\n";

	//RVektor aVec(1., 2., 3.);
	//RVektor bVec(4., 5., 6.);

	//std::cout << "aVec = " << aVec << "\n";
	//std::cout << "bVec = " << bVec << "\n";

	//RVektor cVec = aVec + bVec;
	//std::cout << "cVec = " << cVec << "\n";

	//RMatrix aMa(3,3);

	//aMa[0] = aVec;
	//aMa[1] = bVec;
	//aMa[2] = cVec;

	//std::cout << "aMa = \n" << aMa;

	std::cout << "\nNumerical Solution\n";

	//SmallSquare aSq;

	//RVektor aVec(0.5, 0.5, 0.);

	//aSq.SetSide(0.1);
	//aSq.MoveTo(aVec);

	//std::cout << aSq;

	SquarePlate aPlate;

	aPlate.CreatePlate();

	aPlate.CreateGmVektor();

	aPlate.CreateMatrix();

	aPlate.FindChargeDistribution();

	aPlate.CalculateTotalCharge();

	aPlate.SavePlate();


	char aC = getchar();

	//int iN = 5;

	//std::cout << "\niN = " << iN << "\n\n";

	//RVektor gM(iN);

	////Code to create gM
	//for (int i = 0; i < iN; i++)
	//{
	//	int m = i + 1;

	//	double aVal = 1. + (4.*m*m + 1. / 3) / ((iN + 1)*(iN + 1));
	//	aVal = aVal / (iN + 1);
	//	gM[i] = aVal;
	//}

	//std::cout << "gM = " << gM << "\n\n";

	//RMatrix aMa(iN,iN);

	////Code to define the elements
	//for (int m = 0; m < iN; m++)
	//{
	//	for (int n = 0; n < iN; n++)
	//	{
	//		if (m == n)
	//			aMa[m][n] = 2.*(iN + 1);

	//		if (m == n - 1)
	//			aMa[m][n] = -(iN + 1);

	//		if (m == n + 1)
	//			aMa[m][n] = -(iN + 1);
	//	}
	//}
	//std::cout << "aMa =\n" << aMa << "\n\n";

	//RVektor solution = RealGaussElimination(aMa, gM);

	//std::cout << "solution = " << solution << "\n\n";
}

// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
