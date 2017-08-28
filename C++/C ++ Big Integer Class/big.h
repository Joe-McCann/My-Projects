#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "sstring_class.h"
using namespace std;



class big
{
public:

	big();
	big(string num);
	big(int copy);

	void setNumber(string copy); 
	void setNumber(int copy);
	void printNum();
	int size();

	void operator+= (const big& copy);
	void operator-= (const big& copy);
	void operator/= (const big& copy);
	void operator%= (const big& copy); 
	void operator*= (big& copy);
	void operator^= (big& copy); 
	void operator+= (int copy); 
	void operator-= (int copy); 
	void operator*= (int copy);  
	void operator^= (int copy); 
	void operator/= (int copy);  
	void operator%= (int copy);  
	void operator+= (string str); 
	void operator-= (string str); 
	void operator*= (string str);  
	void operator^= (string str); 
	void operator/= (string str); 
	void operator%= (string str); 
	void operator++ (); 
	void operator-- (); 
	void operator! ();
	void operator= (string copy);
	void operator= (int copy); 
	void operator= (const big& copy);
	big operator* (big& copy);
	big operator+ (const big& copy);
	big operator- (const big& copy);
	big operator/ (const big& copy);
	big operator% (const big& copy);
	big operator^ (big& copy); 
	big operator* (int copy); 
	big operator+ (int copy);  
	big operator- (int copy); 
	big operator/ (int copy); 
	big operator% (int copy); 
	big operator^ (int copy); 
	big operator* (string copy); 
	big operator+ (string copy); 
	big operator- (string copy); 
	big operator/ (string copy); 
	big operator% (string copy); 
	big operator^ (string copy); 
	bool operator> (const big& copy);
	bool operator< (const big& copy);
	bool operator>= (const big& copy);
	bool operator<= (const big& copy);
	bool operator== (const big& copy);
	bool operator!= (const big& copy);
	bool operator> (int copy);
	bool operator< (int copy);
	bool operator>= (int copy);
	bool operator<= (int copy);
	bool operator== (int copy);
	bool operator!= (int copy);
	bool operator> (string copy); 
	bool operator< (string copy); 
	bool operator>= (string copy); 
	bool operator<= (string copy); 
	bool operator== (string copy); 
	bool operator!= (string copy); 
	int compare(const big& copy);

	big digitSum ();
	big sqrt ();
	big longSqrt ();
	void pop_back ();
	void append (int x);
	void append (string num);
	void append (const big& num);
	int find (int x); 
	int find (string x);
	int find (int x, int time); 
	int find (string num, int time); 
	int find_first_of (int x);
	int find_first_of (string x);
	int find_first_not_of (int x); 
	int find_first_not_of (string x); 
	int find_last_of (int x);
	int find_last_of (string x);
	int find_last_not_of (int x); 
	int find_last_not_of (string x); 
	big subbig(int pos, int lentgh);

	string _toString();

	friend ostream &operator<<(ostream &output, const big& D);
	friend istream &operator>>(istream &input, big& num);

	big(sstring str); 
	void setNumber(sstring str); 
	void operator+= (sstring str); 
	void operator-= (sstring str); 
	void operator*= (sstring str); 
	void operator^= (sstring str); 
	void operator/= (sstring str); 
	void operator%= (sstring str); 
	void operator= (sstring str); 
	big operator* (sstring copy); 
	big operator+ (sstring copy); 
	big operator- (sstring copy); 
	big operator/ (sstring copy); 
	big operator% (sstring copy); 
	big operator^ (sstring copy); 
	bool operator> (sstring copy); 
	bool operator< (sstring copy); 
	bool operator>= (sstring copy); 
	bool operator<= (sstring copy); 
	bool operator== (sstring copy); 
	bool operator!= (sstring copy); 
	void append(sstring str); 
	int find(sstring str); 
	int find(sstring str, int time); 
	int find_first_of(sstring str); 
	int find_first_not_of(sstring str); 
	int find_last_of(sstring str); 
	int find_last_not_of(sstring str); 
	sstring _toSString();  

private:
	
	int greaterNumber(int x, int y);
	void expo(big num);
	void shiftRight();
	void shiftLeft();
	void addItself(int x, const big& copy);
	void copy(big& num);
	void addition(const big& num);
	void subtraction(const big& num);
	void swapSign();
	void cleanNum();
	bool isNumerical(std::string str);
	big multiply(big num);
	vector<big> primeFactor(big num, vector<big> vec);

	std::vector<char> number;
	short sign;
	
};