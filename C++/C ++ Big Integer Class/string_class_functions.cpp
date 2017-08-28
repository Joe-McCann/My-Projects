#include "sstring_class.h"

//This file contains functions from the original string class and functions that already exist
//It also contains code to make cin and cout work

void sstring::push_back(char p)
{
	str.push_back(p);
	return;
}

void sstring::erase()
{
	str.erase();
	return;
}
void sstring::erase(unsigned int len, unsigned int pos)
{
	str.erase(len, pos);
	return;
}

unsigned int sstring::size()
{
	return str.size();
}

unsigned int sstring::length()
{
	return str.length();
}

unsigned int sstring::max_size()
{
	return str.max_size();
}

void sstring::resize(unsigned int n)
{
	str.resize(n);
	return;
}
void sstring::resize(unsigned int n, char ch)
{
	str.resize(n, ch);
	return;
}

unsigned int sstring::capacity()
{
	return str.capacity();
}

void sstring::reserve(unsigned int n)
{
	str.reserve(n);
	return;
}

void sstring::clear()
{
	str.clear();
	return;
}

bool sstring::empty()
{
	return str.empty();
}

void sstring::shrink_to_fit()
{
	str.shrink_to_fit();
	return;
}

char& sstring::operator[](unsigned int n)
{
	return str[n];
}

char& sstring::at(unsigned int n)
{
	return str.at(n);
}

char& sstring::back()
{
	return str.back();
}

char& sstring::front()
{
	return str.front();
}

void sstring::append(const string& s)
{
	str.append(s);
	return;
}
void sstring::append(const string& s, unsigned int subpos, unsigned int sublen)
{
	str.append(s, subpos, sublen);
	return;
}
void sstring::append(const char* s)
{
	str.append(s);
	return;
}
void sstring::append(const char* s, unsigned int n)
{
	str.append(s, n);
	return;
}
void sstring::append(unsigned int n, char c)
{
	str.append(n, c);
	return;
}

void sstring::assign(const string& s)
{
	str.assign(s);
	return;
}
void sstring::assign(const string& s, unsigned int subpos, unsigned int sublen)
{
	str.assign(s, subpos, sublen);
	return;
}
void sstring::assign(const char* s)
{
	str.assign(s);
	return;
}
void sstring::assign(const char* s, unsigned int n)
{
	str.assign(s, n);
	return;
}
void sstring::assign(unsigned int n, char c)
{
	str.assign(n, c);
	return;
}

void sstring::insert(unsigned int pos, const string& s)
{
	str.insert(pos, s);
	return;
}
void sstring::insert(unsigned int pos, const string& s, unsigned int subpos, unsigned int sublen)
{
	str.insert(pos, s, subpos, sublen);
	return;
}
void sstring::insert(unsigned int pos, const char* s)
{
	str.insert(pos, s);
	return;
}
void sstring::insert(unsigned int pos, const char* s, unsigned int n)
{
	str.insert(pos, s, n);
	return;
}
void sstring::insert(unsigned int pos, unsigned int n, char c)
{
	str.insert(pos, n, c);
	return;
}

void sstring::replace(unsigned int pos, unsigned int len, const string& s)
{
	str.replace(pos, len, s);
	return;
}
void sstring::replace(unsigned int pos, unsigned int len, const string& s, unsigned int subpos, unsigned int sublen)
{
	str.replace(pos, len, s, subpos, sublen);
	return;
}
void sstring::replace(unsigned int pos, unsigned int len, const char* s)
{
	str.replace(pos, len, s);
	return;
}
void sstring::replace(unsigned int pos, unsigned int len, const char* s, unsigned int n)
{
	str.replace(pos, len, s, n);
	return;
}
void sstring::replace(unsigned int pos, unsigned int len, unsigned int n, char c)
{
	str.replace(pos, len, n, c);
	return;
}

void sstring::swap(string& s)
{
	str.swap(s);
	return;
}

void sstring::pop_back()
{
	str.pop_back();
	return;
}

const char* sstring::c_str()
{
	return str.c_str();
}

const char* sstring::data()
{
	return str.data();
}

unsigned int sstring::copy(char* s, unsigned int pos, unsigned int len)
{
	return str.copy(s, pos, len);
}

unsigned int sstring::find(const string& s, unsigned int pos)
{
	return str.find(s, pos);
}
unsigned int sstring::find(const char* s, unsigned int pos)
{
	return str.find(s, pos);
}
unsigned int sstring::find(const char* s, unsigned int pos, unsigned int n)
{
	return str.find(s, pos, n);
}
unsigned int sstring::find(char c, unsigned int pos)
{
	return str.find(c, pos);
}

unsigned int sstring::rfind(const string& s, unsigned int pos)
{
	return str.rfind(s, pos);
}
unsigned int sstring::rfind(const char* s, unsigned int pos)
{
	return str.rfind(s, pos);
}
unsigned int sstring::rfind(const char* s, unsigned int pos, unsigned int n)
{
	return str.rfind(s, pos, n);
}
unsigned int sstring::rfind(char c, unsigned int pos)
{
	return str.rfind(c, pos);
}

unsigned int sstring::find_first_of(const string& s, unsigned int pos)
{
	return str.find_first_of(s, pos);
}
unsigned int sstring::find_first_of(const char* s, unsigned int pos)
{
	return str.find_first_of(s, pos);
}
unsigned int sstring::find_first_of(const char* s, unsigned int pos, unsigned int n)
{
	return str.find_first_of(s, pos, n);
}
unsigned int sstring::find_first_of(char c, unsigned int pos)
{
	return str.find_first_of(c, pos);
}

unsigned int sstring::find_last_of(const string& s, unsigned int pos)
{
	return str.find_last_of(s, pos);
}
unsigned int sstring::find_last_of(const char* s, unsigned int pos)
{
	return str.find_last_of(s, pos);
}
unsigned int sstring::find_last_of(const char* s, unsigned int pos, unsigned int n)
{
	return str.find_last_of(s, pos, n);
}
unsigned int sstring::find_last_of(char c, unsigned int pos)
{
	return str.find_last_of(c, pos);
}

unsigned int sstring::find_first_not_of(const string& s, unsigned int pos)
{
	return str.find_first_not_of(s, pos);
}
unsigned int sstring::find_first_not_of(const char* s, unsigned int pos)
{
	return str.find_first_not_of(s, pos);
}
unsigned int sstring::find_first_not_of(const char* s, unsigned int pos, unsigned int n)
{
	return str.find_first_not_of(s, pos, n);
}
unsigned int sstring::find_first_not_of(char c, unsigned int pos)
{
	return str.find_first_not_of(c, pos);
}

unsigned int sstring::find_last_not_of(const string& s, unsigned int pos)
{
	return str.find_last_not_of(s, pos);
}
unsigned int sstring::find_last_not_of(const char* s, unsigned int pos)
{
	return str.find_last_not_of(s, pos);
}
unsigned int sstring::find_last_not_of(const char* s, unsigned int pos, unsigned int n)
{
	return str.find_last_not_of(s, pos, n);
}
unsigned int sstring::find_last_not_of(char c, unsigned int pos)
{
	return str.find_last_not_of(c, pos);
}

string sstring::substr(unsigned int pos, unsigned int len)
{
	return str.substr(pos, len);
}

int sstring::compare(const string& s)
{
	return str.compare(s);
}
int sstring::compare(unsigned int pos, unsigned int len, const string& s)
{
	return str.compare(pos, len, s);
}
int sstring::compare(unsigned int pos, unsigned int len, const string& s, unsigned int subpos, unsigned int sublen)
{
	return str.compare(pos, len, s, subpos, sublen);
}
int sstring::compare(const char* s)
{
	return str.compare(s);
}
int sstring::compare(unsigned int pos, unsigned int len, const char* s)
{
	return str.compare(pos, len, s);
}
int sstring::compare(unsigned int pos, unsigned int len, const char* s, unsigned int n)
{
	return str.compare(pos, len, s, n);
}

ostream &operator<<(ostream &output, const sstring &newstr)
{
	output << newstr.str;

	return output;
}

istream &operator>>(istream  &input, sstring & newstr)
{
	string in;
	input >> in;
	newstr.set(in);
	return input;
}