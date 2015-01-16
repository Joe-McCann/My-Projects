#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class sstring
{
public:
	//constructors
	sstring();
	sstring(string);
	sstring(string, unsigned int);
	sstring(int);
	sstring(float);
	sstring(double);

	//operator overloads
	void operator= (int x);
	void operator= (float x);
	void operator= (double x);
	void operator= (const string);
	void set(string);
	void operator= (const sstring newstr);
	void operator+= (const string newstr);
	void operator+= (const sstring newstr);
	char& operator[] (unsigned int);
	const sstring operator+ (const string);
	const sstring operator+ (const sstring&);

	//string functions
	void push_back(char);
	void erase();
	void erase(unsigned int, unsigned int);
	unsigned int size();
	unsigned int length();
	unsigned int max_size();
	void resize(unsigned int);
	void resize(unsigned int, char);
	unsigned int capacity();
	void reserve(unsigned int);
	void clear();
	bool empty();
	void shrink_to_fit();
	char& at(unsigned int);
	char& back();
	char& front();
	void append(const string&);
	void append(const string&, unsigned int, unsigned int);
	void append(const char*);
	void append(const char*, unsigned int);
	void append(unsigned int, char);
	void assign(const string&);
	void assign(const string&, unsigned int, unsigned int);
	void assign(const char*);
	void assign(const char*, unsigned int);
	void assign(unsigned int, char);
	void insert(unsigned int, const string&);
	void insert(unsigned int, const string&, unsigned int, unsigned int);
	void insert(unsigned int, const char*);
	void insert(unsigned int, const char*, unsigned int);
	void insert(unsigned int, unsigned int, char);
	void replace(unsigned int, unsigned int, const string&);
	void replace(unsigned int, unsigned int, const string&, unsigned int, unsigned int);
	void replace(unsigned int, unsigned int, const char*);
	void replace(unsigned int, unsigned int, const char*, unsigned int);
	void replace(unsigned int, unsigned int, unsigned int, char);
	void swap(string&);
	void pop_back();
	const char* c_str();
	const char* data();
	unsigned int copy(char*, unsigned int, unsigned int);
	unsigned int find(const string&, unsigned int);
	unsigned int find(const char*, unsigned int);
	unsigned int find(const char*, unsigned int, unsigned int);
	unsigned int find(char c, unsigned int);
	unsigned int rfind(const string&, unsigned int);
	unsigned int rfind(const char*, unsigned int);
	unsigned int rfind(const char*, unsigned int, unsigned int);
	unsigned int rfind(char c, unsigned int);
	unsigned int find_first_of(const string&, unsigned int);
	unsigned int find_first_of(const char*, unsigned int);
	unsigned int find_first_of(const char*, unsigned int, unsigned int);
	unsigned int find_first_of(char c, unsigned int);
	unsigned int find_last_of(const string&, unsigned int);
	unsigned int find_last_of(const char*, unsigned int);
	unsigned int find_last_of(const char*, unsigned int, unsigned int);
	unsigned int find_last_of(char c, unsigned int);
	unsigned int find_first_not_of(const string&, unsigned int);
	unsigned int find_first_not_of(const char*, unsigned int);
	unsigned int find_first_not_of(const char*, unsigned int, unsigned int);
	unsigned int find_first_not_of(char c, unsigned int);
	unsigned int find_last_not_of(const string&, unsigned int);
	unsigned int find_last_not_of(const char*, unsigned int);
	unsigned int find_last_not_of(const char*, unsigned int, unsigned int);
	unsigned int find_last_not_of(char c, unsigned int);
	string substr(unsigned int, unsigned int);
	int compare(const string&);
	int compare(unsigned int, unsigned int, const string&);
	int compare(unsigned int, unsigned int, const string&, unsigned int, unsigned int);
	int compare(const char*);
	int compare(unsigned int, unsigned int, const char*);
	int compare(unsigned int, unsigned int, const char*, unsigned int);

	int to_int();
	float to_float();
	double to_double();
	void to_sstring(int);
	void to_sstring(double);
	void to_sstring(float);

	//new functions
	void split(int, vector<sstring>*);
	void split(char, vector<sstring>*);

	void forceLower();
	void forceUpper();

	bool isAlpha();
	bool isNum();

	void reverse();

	unsigned int rep_char(char);

	void to_vec(vector<char>*);
	//void to_vec(vector<char>*, unsigned int);

	bool made_of(sstring);
	bool made_of(string);

	//agorithm class adaptations
	void fill(char*, char*, char);
	void fill(unsigned int, unsigned int, char);

	char* adjacent_find(char*, char*);
	unsigned int adjacent_find(unsigned int, unsigned int);

	//cin and cout 
	friend ostream &operator<<(ostream&, const sstring&);
	friend istream &operator>>(istream&, sstring &);
	string get();
	void enter();
	void getline();
	void display();

private:
	string str;
};