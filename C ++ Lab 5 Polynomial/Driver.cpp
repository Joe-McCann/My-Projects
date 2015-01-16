#include "Polynomial.h"
#include <iostream>

using namespace std;

int main()
{
	Polynomial poly;

	/*Polynomial poly2;
	Polynomial poly3(0);

	cout << "P1: ";
	poly.display();

	cout << "\nP2: ";
	poly2.display();

	cout << "\nP1 + P2: ";
	poly3 = poly + poly2;
	poly3.display();

	cout << "\nP1 - P2: ";
	poly3 = poly - poly2;
	poly3.display();

	cout << "\nP1 * P2: ";
	poly3 = poly * poly2;
	poly3.display();

	cout << "\nP3 += P1: ";
	poly3 += poly;
	poly3.display();

	cout << "\nP3 -= P2: ";
	poly3 -= poly;
	poly3.display();

	cout << endl << endl << endl;

	*/Polynomial poly4(0);/*
	Polynomial poly5;
	Polynomial poly6 = poly4 / poly5;

	poly6.display();
	poly6.getRemainder();*/

	poly.factor(poly);

	cout << endl;

	return 0;
}