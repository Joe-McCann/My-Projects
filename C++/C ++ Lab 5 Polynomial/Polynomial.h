#pragma once
#include <vector>

class Polynomial
{
public:

	Polynomial();
	Polynomial(int size);
	Polynomial operator+ (Polynomial poly);
	Polynomial operator- (Polynomial poly);
	Polynomial operator* (const Polynomial poly);
	Polynomial operator/ (Polynomial binomial);
	Polynomial operator/ (float x);
	void operator+= (const Polynomial poly);
	void operator-= (const Polynomial poly);
	void factor(Polynomial poly);
	void display();
	int greatestNum(int x, int y);
	void getRemainder();


private:
	std::vector <float> polyCoeff;
	float remainder[2];
};

