#include "Polynomial.h"
#include <iostream>
#include <vector>

using namespace std;

Polynomial::Polynomial()
{
	int terms = 0;

	cout << "Enter the amount of terms in the polynomial: ";
	cin >> terms;

	polyCoeff.resize(terms, 0);

	cout << "\nEnter the first polynomial coeffieciants from x^N -> x^0: ";
	
	for (int i = terms - 1; i >= 0; --i)
	{
		cin >> polyCoeff[i];
	}

	for (int i = 0; i < 2; ++i)
		remainder[i] = 0;

	system("Cls");

}

Polynomial::Polynomial(int size)
{
	polyCoeff.resize(size, 0);

	for (int i = 0; i < 2; ++i)
		remainder[i] = 0;
}

Polynomial Polynomial::operator+(Polynomial poly)
{
	Polynomial endPoly(greatestNum(poly.polyCoeff.size(), this->polyCoeff.size()));

	poly.polyCoeff.resize(greatestNum(poly.polyCoeff.size(), this->polyCoeff.size()), 0);

	this->polyCoeff.resize(greatestNum(poly.polyCoeff.size(), this->polyCoeff.size()), 0);

	for (int i = 0; i < endPoly.polyCoeff.size(); ++i)
	{
		endPoly.polyCoeff[i] = this->polyCoeff[i] + poly.polyCoeff[i];
	}

	return endPoly;
}

void Polynomial::operator+=(const Polynomial poly)
{
	this->polyCoeff.resize(greatestNum(poly.polyCoeff.size(), this->polyCoeff.size()), 0);

	for (int i = 0; i < poly.polyCoeff.size(); ++i)
	{
		this->polyCoeff[i] += poly.polyCoeff[i];
	}
}

void Polynomial::operator-=(const Polynomial poly)
{
	this->polyCoeff.resize(greatestNum(poly.polyCoeff.size(), this->polyCoeff.size()), 0);

	for (int i = 0; i < poly.polyCoeff.size(); ++i)
	{
		this->polyCoeff[i] -= poly.polyCoeff[i];
	}
}

Polynomial Polynomial::operator-(Polynomial poly)
{
	Polynomial endPoly(greatestNum(poly.polyCoeff.size(), this->polyCoeff.size()));

	poly.polyCoeff.resize(greatestNum(poly.polyCoeff.size(), this->polyCoeff.size()), 0);

	this->polyCoeff.resize(greatestNum(poly.polyCoeff.size(), this->polyCoeff.size()), 0);

	for (int i = 0; i < endPoly.polyCoeff.size(); ++i)
	{
		endPoly.polyCoeff[i] = this->polyCoeff[i] - poly.polyCoeff[i];
	}

	return endPoly;
}

Polynomial Polynomial::operator*(const Polynomial poly)
{
	Polynomial endPoly((poly.polyCoeff.size() - 1) + (this->polyCoeff.size()));

	for (int i = 0; i < poly.polyCoeff.size(); ++i)
	{
		for (int j = 0; j < this->polyCoeff.size(); ++j)
		{
			endPoly.polyCoeff[i + j] += poly.polyCoeff[i] * this->polyCoeff[j];
		}
	}

	return endPoly;

}

Polynomial Polynomial::operator/(Polynomial binomial)
{
	cout << "Warning: When dividing two polynomials, the divisor will be modified into a binomial. Also, the first term must be the first degree." << endl;
	int j = this->polyCoeff[polyCoeff.size() - 1];

	Polynomial endPoly(this->polyCoeff.size() -1);

	if (binomial.polyCoeff.size() > 2)
	{
		while (binomial.polyCoeff.size() > 2)
		{
			binomial.polyCoeff.pop_back();
		}
	}

	else if (binomial.polyCoeff.size() < 2)
	{
		binomial.polyCoeff[0] = 1;
		binomial.polyCoeff[1] = 1;
	}

	binomial.polyCoeff[0] *= -1;
	binomial.polyCoeff[1] = 1;

	endPoly.polyCoeff[endPoly.polyCoeff.size() - 1] = j;

	for (int i = endPoly.polyCoeff.size() - 2; i >= 0; --i)
	{
		j = j * binomial.polyCoeff[0] + this->polyCoeff[i + 1];
		endPoly.polyCoeff[i] = j;
	}

	endPoly.remainder[1] = j * binomial.polyCoeff[0] + this->polyCoeff[0];
	endPoly.remainder[0] = binomial.polyCoeff[0] * -1;

	return endPoly;
}

Polynomial Polynomial::operator/(float x)
{
	float j = this->polyCoeff[polyCoeff.size() - 1];

	Polynomial endPoly(this->polyCoeff.size() - 1);

	x *= -1;

	endPoly.polyCoeff[endPoly.polyCoeff.size() - 1] = j;

	for (int i = endPoly.polyCoeff.size() - 2; i >= 0; --i)
	{
		j = j * x + this->polyCoeff[i + 1];
		endPoly.polyCoeff[i] = j;
	}

	endPoly.remainder[1] = j * x + this->polyCoeff[0];
	endPoly.remainder[0] = x * -1;

	return endPoly;
}

void Polynomial::display()
{
	for (int i = polyCoeff.size() - 1; i >= 0; --i)
	{
		if (i == 0)
		{
			cout << polyCoeff[i];
		}

		else if (polyCoeff[i] == 0)
			continue;

		else
			cout << polyCoeff[i] << "x" << i << " + ";
	}

	cout << endl;
}

int Polynomial::greatestNum(int x, int y)
{
	if (x > y)
	{
		return x;
	}

	else
	{
		return y;
	}
}

void Polynomial::factor(Polynomial poly)
{
	vector<float> pfacts;
	vector<float> qfacts;
	Polynomial testpoly(0);
	int count = 0;

	for (int i = abs(poly.polyCoeff[0]); i > 0; --i)
	{
		if (fmod(poly.polyCoeff[0], i) == 0)
		{
			pfacts.push_back(i);
			pfacts.push_back(i * -1);
		}
	}

	for (int i = abs(poly.polyCoeff[poly.polyCoeff.size() - 1]); i > 0; --i)
	{
		if (fmod(poly.polyCoeff[poly.polyCoeff.size() - 1], i) == 0)
		{
			qfacts.push_back(i);
		}
	}

	cout << "Factors are: ";

	for (int i = 0; i < pfacts.size(); ++i)
	{
		for (int j = 0; j < qfacts.size(); ++j)
		{
			testpoly = poly / (pfacts[i] / qfacts[j]);

			if (testpoly.remainder[1] == 0)
			{
				cout << (pfacts[i] / qfacts[j]) << " ";
				++count;
			}

		}
	}

	if (!count)
	{
		cout << "No Rational Factors";
	}

	return;


}

void Polynomial::getRemainder()
{

	if (remainder[0] >= 0)
		cout << "Remainder: " << remainder[1] << " / ( x + " << remainder[0] << " )" << endl;

	else 
		cout << "Remainder: " << remainder[1] << " / ( x - " << remainder[0] * -1 << " )" << endl;
}





