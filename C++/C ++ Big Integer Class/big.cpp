#include "big.h"
#include <string>
#include <vector>
#include <iostream>
#include "Stopwatch.h"

//#define debug

using namespace std;

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////// CONSTRUCTORS ////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

//Generic default construct. Requires no parameters
big::big()
{	
	sign = 1;
}

//Constructor to initilize the number. Takes an integer
big::big(int num)
{
	setNumber(num);
}

//Constructor to initilize the number. Takes a string
big::big(string num)
{
	setNumber(num);
}

///////////////////////////////////////////////////////////////////////////////////
////////////////////////// ACCESS FUNCTIONS ///////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

//Will set the number with a string as an input
void big::setNumber(string num)
{
	number.resize(0);

	sign = 1;

	if (num.substr(0, 1) == "-")
	{
		sign = -1;
		num = num.substr(1, num.length() - 1);
	}

	for (int i = num.length() - 1; i >= 0; --i)
	{
		if (isNumerical((num.substr(i, 1))))
			number.push_back(stoi(num.substr(i, 1).c_str()));

		if ((num.substr(i, 1) == "."))
			number.resize(0);
	}
}

//Will set the number with a int as an input
void big::setNumber(int copy)
{
	setNumber(to_string(copy));
}

//Will output the number, formatted with commas
void big::printNum()
{
	if (sign == -1)
		cout << "-";
	
	for (int i = number.size() - 1; i >= 0; --i)
	{
		cout << (short)number[i];

		if (i % 3 == 0 && i != 0)
			cout << ",";

	}

	cout << endl;
}

//Will output the amount of digits in the number
int big::size()
{
	return number.size();
}

///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// OPERATORS ////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

//Assigns to a string
void big::operator=(string num)
{
	setNumber(num);
}

//Assigns to integer
void big::operator=(int num)
{
	setNumber(num);
}

//Assigns to big
void big::operator=(const big& copy)
{
	this->number.resize(0);

	for (int i = 0; i < copy.number.size(); ++i)
	{
		this->number.push_back(copy.number[i]);
	}

	sign = copy.sign;
}

//Subtracts and reassigns the number
void big::operator-=(const big& num)
{

	if (sign == -1 && num.sign == 1 || sign == 1 && num.sign == -1)
	{
		addition(num);
		cleanNum();
		return;
	}

	else
	{
		subtraction(num);
		cleanNum();
		return;
	}

}

//Adds and reassigns the number
void big::operator+= (const big& num)
{
	if (sign == -1 && num.sign == 1 || sign == 1 && num.sign == -1)
	{
		subtraction(num);
		cleanNum();
		return;
	}

	else
	{
		addition(num);
		cleanNum();
		return;
	}

}

//Divides and reassigns the number
void big::operator/= (const big& num)
{
	big endBig;
	copy(endBig);
	big returnBig;

	returnBig = endBig / num;

	operator=(returnBig);
}

//Mod and reassigns the number
void big::operator%= (const big& num)
{
	big endBig;
	copy(endBig);
	big returnBig;

	returnBig = endBig % num;

	operator=(returnBig);
}

//Multiplies and reassigns
void big::operator*= (big& num)
{
	big copy;
	big end;
	int holdsign1 = sign;
	int holdsign2 = num.sign;

	sign = 1;
	num.sign = 1;

	end = multiply(num);
	operator=(end);

	/*for (int i = 0; i < number.size(); ++i)
	{
		copy.number.push_back(number[i]);
	}

	number.resize(0);

	for (int i = num.number.size() - 1; i > 0; --i)
	{
		addItself(num.number[i], copy);

		this->shiftRight();
	}

	addItself(num.number[0], copy);*/

	sign = holdsign1;
	num.sign = holdsign2;

	sign *= num.sign;
	
}

//Exponents and reassigns
void big::operator^= (big& num)
{
	expo(num);
	return;
}

//Subtracts and reassigns an integer
void big::operator-= (int num)
{
	big set;
	set = num;
	operator-=(set);
}

//Adds and reassigns an integer
void big::operator+= (int num)
{
	big set;
	set = num;
	operator+=(set);
}

//Divides and reassigns an integer
void big::operator/= (int num)
{
	big set;
	set = num;
	operator/=(set);
}

//Mods and reassigns an integer
void big::operator%= (int num)
{
	big set;
	set = num;
	operator%=(set);
}

//Multiplies and reassigns an integer
void big::operator*= (int num)
{
	big set;
	set = num;
	operator*=(set);
}

//Exponents and reassigns an integer
void big::operator^= (int num)
{
	big cops = num;
	expo(cops);
	return;
}

void big::operator+= (string str)
{
	big x(str);
	operator+=(x);
}

void big::operator-= (string str)
{
	big x(str);
	operator-=(x);
}

void big::operator*= (string str)
{
	big x(str);
	operator*=(x);
}

void big::operator^= (string str)
{
	big x(str);
	operator^=(x);
}

void big::operator/= (string str)
{
	big x(str);
	operator/=(x);
}

void big::operator%= (string str)
{
	big x(str);
	operator%=(x);
}

//Adds one to the number
void big::operator++()
{
	operator+=(1);
}

//Subtracts one for the number
void big::operator--()
{
	operator-=(1);
}

//Sets the number to the factorial of the number
void big::operator! ()
{
	big cops;
	copy(cops);
	cops -= 1;
	for (cops; cops > 1; --cops)
	{
		operator*= (cops);
	}

}

//Multiplies two numbers and returns the product
big big::operator* (big& num)
{
	big endBig;
	copy(endBig);
	endBig *= num;

	return endBig;
}

//Adds two numbers and returns the sum
big big::operator+ (const big& num)
{
	big endBig;
	copy(endBig);
	endBig += num;

	return endBig;
}

//Subtracts then returns the difference
big big::operator- (const big& num)
{
	big endBig;
	copy(endBig);
	endBig -= num;

	return endBig;
}

big big::operator^ (big& num)
{
	big endBig;
	copy(endBig);
	endBig ^= num;

	return endBig;
}

big big::operator/ (const big& num)
{
	big divisor = num;
	big quotiant(0);
	big numerator;
	copy(numerator);
	int holdsign1 = numerator.sign;
	int holdsign2 = divisor.sign;

	numerator.sign = 1;
	divisor.sign = 1;

	while (numerator.number.size() > divisor.number.size())
	{
		divisor.shiftRight();
		quotiant.shiftRight();
	}

	for (int i = quotiant.number.size() - 1; i >= 0; --i)
	{
		while (numerator >= divisor)
		{
			numerator -= divisor;
			++quotiant.number[i];
		}

		divisor.shiftLeft();

	}

	if (holdsign1 == -1 && holdsign2 == 1 || holdsign1 == 1 && holdsign2 == -1)
	{
		quotiant.sign = -1;
	}

	quotiant.cleanNum();
	return quotiant;

}

big big::operator% (const big& num)
{
	big divisor = num;
	big quotiant(0);
	big numerator;
	copy(numerator);

	numerator.sign = 1;
	divisor.sign = 1;

	while (numerator.number.size() > divisor.number.size())
	{
		divisor.shiftRight();
		quotiant.shiftRight();
	}

	for (int i = quotiant.number.size() - 1; i >= 0; --i)
	{
		while (numerator >= divisor)
		{
			numerator -= divisor;
		}

		divisor.shiftLeft();

	}

	return numerator;
}

big big::operator+ (int num)
{
	big endBig;
	copy(endBig);
	endBig += num;

	return endBig;
}

big big::operator- (int num)
{
	big endBig;
	copy(endBig);
	endBig -= num;

	return endBig;
}

big big::operator* (int num)
{
	big endBig;
	copy(endBig);
	endBig *= num;

	return endBig;
}

big big::operator^ (int num)
{
	big endBig;
	copy(endBig);
	endBig ^= num;

	return endBig;
}

big big::operator/ (int num)
{
	big endBig;
	copy(endBig);
	endBig /= num;

	return endBig;
}

big big::operator% (int num)
{
	big endBig;
	copy(endBig);
	endBig %= num;

	return endBig;
}

big big::operator* (string copy)
{
	big x(copy);
	return operator*(x);
}

big big::operator+ (string copy) 
{
	big x(copy);
	return operator+(x);
}

big big::operator- (string copy) 
{
	big x(copy);
	return operator-(x);
}

big big::operator/ (string copy) 
{
	big x(copy);
	return operator/(x);
}

big big::operator% (string copy)
{
	big x(copy);
	return operator%(x);
}

big big::operator^ (string copy)
{
	big x(copy);
	return operator^(x);
}

int big::compare (const big& input)
{
	big num = input;
	cleanNum();
	num.cleanNum();

	if (sign == 1 && num.sign == -1)
		return 1;

	else if (sign == -1 && num.sign == 1)
		return -1;

	else
	{
		if (this->number.size() > num.number.size())
			return 1 * sign;

		else if (this->number.size() == num.number.size())
		{
			for (int i = this->number.size() - 1; i >= 0; --i)
			{
				if (number[i] == num.number[i])
					continue;

				else if (number[i] < num.number[i])
					return -1 * sign;

				else
					return 1 * sign;

			}

			return 0;
		}

		else
			return -1 * sign;
	}
}

bool big::operator>(const big& num)
{
	return (compare(num) == 1) ? true : false;
}

bool big::operator>=(const big& num)
{
	return (compare(num) != -1) ? true : false;
}

bool big::operator<(const big& num)
{
	return (compare(num) == -1) ? true : false;
}

bool big::operator<=(const big& num)
{
	return (compare(num) != 1) ? true : false;
}

bool big::operator==(const big& num)
{
	return (compare(num) == 0) ? true : false;
}

bool big::operator!=(const big& num)
{
	return (compare(num) != 0) ? true : false;
}

bool big::operator> (int num)
{
	big copy(num);
	return operator>(copy);
}

bool big::operator>= (int num)
{
	big copy(num);
	return operator>=(copy);
}

bool big::operator< (int num)
{
	big copy(num);
	return operator<(copy);
}

bool big::operator<= (int num)
{
	big copy(num);
	return operator<=(copy);
}

bool big::operator== (int num)
{
	big copy(num);
	return operator==(copy);
}

bool big::operator!= (int num)
{
	big copy(num);
	return operator!=(copy);
}

bool big::operator> (string copy)
{
	big x(copy);
	return operator>(copy);
}

bool big::operator< (string copy)
{
	big x(copy);
	return operator<(copy);
}

bool big::operator>= (string copy)
{
	big x(copy);
	return operator>=(copy);
}

bool big::operator<= (string copy)
{
	big x(copy);
	return operator<=(copy);
}

bool big::operator== (string copy)
{
	big x(copy);
	return operator==(copy);
}

bool big::operator!= (string copy)
{
	big x(copy);
	return operator!=(copy);
}

string big::_toString()
{
	string end = "";

	if (sign == -1)
		end += "-";

	for (int i = number.size() - 1; i >= 0; --i)
	{
		end += to_string(number[i]);
	}

	return end;

}

//Credit to Microsoft for basic code. Allows input for functionality with cout
ostream &operator<<(ostream &output, const big& num)
{
	if (num.sign == -1)
	{
		output << "-";
	}

	for (int i = num.number.size() - 1; i >= 0; --i)
	{
		output << (int)num.number[i];
	}

	return output;
} 

//Credit to Microsoft for basic code. Allows for functionality with cin
istream &operator>>(istream  &input, big & num)
{
	string in;
	input >> in;
	num.setNumber(in);
	return input;
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// FUNCTIONS ///////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

big big::digitSum()
{
	big endBig(0);

	for (int i = 0; i < number.size(); ++i)
	{
		endBig += number[i];
	}

	return endBig;

}

//Credit to Babalonyians for the algorithm
big big::longSqrt()
{
	big cops;
	copy(cops);

	big end;
	copy(end);

	big hold;
	hold = end.size() * end.size() * size() + 20;

	end /= hold;

	big backEnd(1);
	float accuracy = .5;

	while ((end - backEnd) > accuracy)
	{
		end = (end + backEnd) / 2;
		backEnd = cops / end;
	}

	return end;

}

big big::sqrt()
{
	big dropDown(0);
	big solution;
	big helpers;

	if (number.size() % 2 == 1)
	{
		number.push_back(0);
	}

	dropDown.number.push_back(number[number.size() - 1]);
	dropDown.number[0] = number[number.size() - 2];



	if (dropDown >= 81)
	{
		solution.number.push_back(9);
	}


	else
	{
		for (int i = 0; i < 10; ++i)
		{
			if (dropDown < (i * i))
			{
				solution.number.push_back(i - 1);
				break;
			}
		}
	}

	dropDown -= (solution * solution);

	for (int i = number.size() - 3; i > 0; i -= 2)
	{

		
		dropDown.shiftRight();
		dropDown.shiftRight();

		dropDown.number[1] = number[i];
		dropDown.number[0] = number[i - 1];

		helpers = solution * 2;
		helpers.shiftRight();



		for (int i = 0; i < 10; ++i)
		{
			helpers.number[0] = i;

			if ((helpers * i) > dropDown)
			{
				helpers.number[0] = i - 1;
				break;
			}
		}

		solution.shiftRight();
		solution.number[0] = helpers.number[0];

		dropDown -= (helpers * helpers.number[0]);

	}
	
	return solution;
}
 
void big::pop_back()
{
	number.pop_back();
}

void big::append(int x)
{
	do
	{
		number.push_back(x % 10);
		x /= 10;
	}while (x != 0);
}

void big::append(string num)
{
	append(stoi(num.c_str()));
}

void big::append(const big& num)
{
	for (int i = 0; i < num.number.size(); ++i)
		number.push_back(num.number[i]);
}

int big::find(int x)
{
	return find_first_of(x);
}

int big::find(string num)
{
	return find_first_of(num);
}

int big::find_first_of(int x)
{
	big num = x;
	bool result = true;

	for (int i = 0; i <= number.size() - num.size(); ++i)
	{
		result = true;

		for (int j = 0; j < num.number.size(); ++j)
		{
			if (num.number[j] != number[i + j])
			{
				result = false;
				break;
			}
		}

		if (result)
			return i;
	}

	return -1;

}

int big::find(int x, int time)
{
	return find(to_string(x), time);
}

int big::find(string num, int time)
{
	big x = num;
	int count = 0;
	bool hold;

	for (int i = 0; i < number.size() - num.size() + 1; ++i)
	{
		hold = true;
		if (x.number[0] == number[i])
		{
			for (int j = 0; j < num.size(); ++j)
			{
				if (x.number[j] != number[i + j])
				{
					hold = false;
					break;
				}
			}

			if (hold)
			{
				--time;
			}
		}

		if (time == 0)
		{
			return i;
		}
	}

	return -1;
}

int big::find_first_of(string num)
{
	return find_first_of(stoi(num.c_str()));
}

int big::find_first_not_of(int x)
{
	big num(x);
	bool result = true;

	for (int i = 0; i <= number.size() - num.size(); ++i)
	{
		result = true;

		for (int j = 0; j < num.number.size(); ++j)
		{
			if (num.number[j] == number[i + j])
			{
				result = false;
				continue;
			}

			else if (num.number[j] != number[i + j])
			{
				result = true;
				break;
			}
		}

		if (result)
			return i;
	}

	return -1;

}

int big::find_first_not_of(string num)
{
	return find_first_not_of(stoi(num.c_str()));
}

int big::find_last_of(int x)
{
	big num (x);
	bool result = true;

	for (int i = number.size() - 1; i >= num.size() - 1; --i)
	{
		result = true;

		for (int j = 0; j <= num.number.size() - 1; ++j)
		{
			if (num.number[num.number.size() - (j + 1)] != number[i - j])
			{
				result = false;
				break;
			}
		}

		if (result)
			return i;
	}

	return -1;
}

int big::find_last_of(string num)
{
	return find_last_of(stoi(num.c_str()));
}

int big::find_last_not_of(int x)
{
	big num(x);
	bool result = true;

	for (int i = number.size() - 1; i > num.number.size() - 1; --i)
	{
		result = true;

		for (int j = 0; j <= num.number.size() - 1; ++j)
		{
			if (num.number[num.number.size() - (j + 1)] == number[i - j])
			{
				result = false;
				continue;
			}

			else if (num.number[num.number.size() - (j + 1)] != number[i - j])
			{
				result = true;
				break;
			}
		}

		if (result)
			return i;
	}

	return -1;

}

int big::find_last_not_of(string num)
{
	return find_last_not_of(stoi(num.c_str()));
}

big big::subbig(int pos, int length)
{
	big endBig;

	for (int i = pos; i < (length + pos) && i < number.size(); ++i)
	{
		endBig.number.push_back(number[i]);
	}

	return endBig;

}

///////////////////////////////////////////////////////////////////////////////////
////////////////////////// SSTRING FUNCTIONS //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

big::big(sstring str)
{
	big x(str.get());
}

void big::setNumber(sstring str)
{
	setNumber(str.get());
}

void big::operator+= (sstring str)
{
	operator+=(str.get());
}

void big::operator-= (sstring str)
{
	operator-=(str.get());
}

void big::operator*= (sstring str)
{
	operator*=(str.get());
}

void big::operator^= (sstring str)
{
	operator^=(str.get());
}

void big::operator/= (sstring str)
{
	operator/=(str.get());
}

void big::operator%= (sstring str)
{
	operator%=(str.get());
}

void big::operator= (sstring str)
{
	operator=(str.get());
}

big big::operator* (sstring copy)
{
	big x(copy);
	return operator*(x);
}

big big::operator+ (sstring copy)
{
	big x(copy);
	return operator+(x);
}

big big::operator- (sstring copy)
{
	big x(copy);
	return operator-(x);
}

big big::operator/ (sstring copy)
{
	big x(copy);
	return operator/(x);
}

big big::operator% (sstring copy)
{
	big x(copy);
	return operator%(x);
}

big big::operator^ (sstring copy)
{
	big x(copy);
	return operator^(x);
}

bool big::operator> (sstring copy)
{
	big x(copy);
	return operator>(x);
}

bool big::operator< (sstring copy)
{
	big x(copy);
	return operator<(x);
}

bool big::operator>= (sstring copy)
{
	big x(copy);
	return operator>=(x);
}

bool big::operator<= (sstring copy)
{
	big x(copy);
	return operator<=(x);
}

bool big::operator== (sstring copy)
{
	big x(copy);
	return operator==(x);
}

bool big::operator!= (sstring copy)
{
	big x(copy);
	return operator!=(x);
}

void big::append(sstring str)
{
	append(str.get());
}

int big::find(sstring str)
{
	return find(str.get());
}

int big::find(sstring str, int time)
{
	return find(str.get(), time);
}

int big::find_first_of(sstring str)
{
	return find_first_of(str.get());
}

int big::find_first_not_of(sstring str)
{
	return find_first_not_of(str.get());
}

int big::find_last_of(sstring str)
{
	return find_last_of(str.get());
}

int big::find_last_not_of(sstring str)
{
	return find_last_not_of(str.get());
}

sstring big::_toSString()
{
	sstring str = _toString();
	return str;
}

///////////////////////////////////////////////////////////////////////////////////
////////////////////////// UTILITY FUNCTIONS //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

//Credit to Jacob Fattakov for coming up with a faster prime exponent algoritm
void big::expo(big num)
{
	if (num == 0)
	{
		operator=(1);
		return;
	}

	vector<big> factors;
	big cop;

	copy(cop);
	factors = primeFactor(num, factors);

	if (factors.size() == 1)
	{
		if (factors[0] != 2 || factors[0] != 3 || factors[0] != 5)
		{
			big thing = cop;
			expo(num - 1);
			operator*=(thing);
			return;
		}
	}
#ifdef debug
	Stopwatch watch;
#endif

	for (int i = (factors.size()) - 1; i >= 0; --i)
	{

#ifdef debug
		watch.startWatch();
#endif
		for (int j = 1; factors[i] > j; ++j)
		{
			operator*=(cop);
		}

#ifdef debug
		watch.endWatch();
		cout << factors[i] << " " << i << " " << watch.getTime() << endl;
#endif
		cop.number.resize(0);
		copy(cop);
	}

}

int big::greaterNumber(int x, int y)
{
	if (x > y)
		return x;

	else
		return y;
}

void big::shiftRight()
{
	number.push_back(0);

	for (int i = number.size() - 1; i > 0; --i)
	{
		number[i] = number[i - 1];
	}

	number[0] = 0;
}

void big::shiftLeft()
{
	for (int i = 0; i < number.size() - 1; ++i)
	{
		number[i] = number[i + 1];
	}

	number.pop_back();

}

void big::addItself(int x, const big& copy)
{

	for (int i = 0;  i < x; ++i)
	{
		addition(copy);
	}
}

void big::copy(big& copy)
{
	for (int i = 0; i < this->number.size(); ++i)
	{
		copy.number.push_back(this->number[i]);
	}

	copy.sign = sign;
}

void big::addition(const big& num)
{

	int carry = 0;
	int count = 0;

	if (num.number.size() > this->number.size())
	{
		this->number.resize(num.number.size(), 0);
	}

	for (int i = 0; i < num.number.size(); ++i)
	{
		this->number[i] += num.number[i] + carry;
		carry = this->number[i] / 10;
		this->number[i] = this->number[i] % 10;
	}

	while (carry >= 1)
	{

		if (num.number.size() + count == this->number.size())
		{
			this->number.push_back(carry);
			carry = 0;
		}

		else
		{
			this->number[num.number.size() + count] += carry;
			carry = this->number[num.number.size() + count] / 10;
			this->number[num.number.size() + count] = this->number[num.number.size() + count] % 10;
		}

		++count;

	};
}

void big::subtraction(const big& place)
{
	big num = place;
	num.cleanNum();
	cleanNum();

	int borrow = 0;
	int count = 0;
	bool hold = false;

	if (operator>(num) || (operator<(num) && (sign == -1 && num.sign == -1)))
	{
		for (int i = 0; i < num.number.size(); ++i)
		{
			if (this->number[i] < num.number[i] + borrow)
			{
				number[i] += 10;
				hold = true;
			}

			this->number[i] -= (num.number[i] + borrow);
			borrow = 0;

			if (hold)
				borrow = 1;

			hold = false;
		}

		while (borrow == 1)
		{

			if (this->number[num.number.size() + count] == 0)
			{
				this->number[num.number.size() + count] += 10;
				hold = true;
			}

			this->number[num.number.size() + count] -= 1;

			borrow = 0;

			if (hold)
				borrow = 1;

			hold = false;

			++count;

		};

	}

	else
	{

		big cop;
		copy(cop);
		operator=(num);

		for (int i = 0; i < cop.number.size(); ++i)
		{
			if (this->number[i] < cop.number[i] + borrow)
			{
				number[i] += 10;
				hold = true;
			}

			this->number[i] -= (cop.number[i] + borrow);
			borrow = 0;

			if (hold)
				borrow = 1;

			hold = false;
		}

		while (borrow == 1)
		{

			if (this->number[cop.number.size() + count] == 0)
			{
				this->number[cop.number.size() + count] += 10;
				hold = true;
			}

			this->number[cop.number.size() + count] -= 1;

			borrow = 0;

			if (hold)
				borrow = 1;

			hold = false;

			++count;

		};

		sign *= -1;

	}
}

void big::swapSign()
{
	sign *= -1;
}

void big::cleanNum()
{
	for (int i = this->number.size() - 1; i > 0; --i)
	{
		if (number[i] == 0)
		{
			number.pop_back();
		}

		else
			break;
	}

	if (number.size() == 1 && number[0] == 0)
		sign = 1;

	return;
}

bool big::isNumerical(string str)
{
	if (str == "0" || str == "1" || str == "2" || str == "3" || str == "4" || str == "5" || str == "6" || str == "7" || str == "8" || str == "9")
		return true;

	return false;
}

vector<big> big::primeFactor(big num, vector<big> vec)
{
	big copy = num;
	big j = copy.sqrt() + 1;
	vec.resize(0);
	bool tf = true;

	while (copy % 2 == 0)
	{
		copy /= 2;
		vec.push_back(2);
	}
	
	do
	{

		for (int i = 3; j > i; i += 2)
		{
			if (copy % i == 0)
			{
				copy /= i;
				vec.push_back(i);
				tf = true;
				break;
			}

			else
				tf = false;
		}

		j = copy.sqrt() + 3;

	} while (tf);

	if (copy != 1)
		vec.push_back(copy);

	return vec;

}

big big::multiply(big num1)
{
	big ans = 0;
	big hold;

	hold.number.resize(num1.size());
	
	for (int i = size() - 1; i > 0; --i)
	{
		for (int j = 0; j < num1.size(); ++j)
		{
			hold.number[j] = number[i] * num1.number[j];
		}

		ans += hold;
		ans.shiftRight();

	}

	for (int j = 0; j < num1.size(); ++j)
	{
		hold.number[j] = number[0] * num1.number[j];
	}

	ans += hold;

	return ans;

}