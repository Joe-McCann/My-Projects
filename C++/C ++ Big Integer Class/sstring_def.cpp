#include "sstring_class.h"

//constructors
sstring::sstring()
{}
sstring::sstring(string input)
{
	str = input;
}
sstring::sstring(string input, unsigned int size)
{
	str = input;
	str.resize(size);
}
sstring::sstring(int input)
{
	str = std::to_string(input);
}
sstring::sstring(float input)
{
	str = std::to_string(input);
}
sstring::sstring(double input)
{
	str = std::to_string(input);
}

//operator overload; same as set function
void sstring::operator= (string input)
{
	str = input;
	return;
}
void sstring::set(string input)
{
	str = input;
	return;
}

//returns the string stored in sstring
string sstring::get()
{
	return str;
}

//determines if every char in a string is alphabetical
bool sstring::isAlpha()
{
	//upper case: 65 - 90
	//lower case: 97 - 122

	bool check;

	for (int n = 0; n < str.size(); ++n)
	{
		if ((str[n] >= 'A' && str[n] <= 'Z') || (str[n] >= 'a' && str[n] <= 'z'))
			check = true;
		else
		{
			check = false;
			break;
		}
	}

	return check;
} 

//determines if every char in a string is numerical
bool sstring::isNum()
{
	bool check;

	for (int n = 0; n < str.size(); ++n)
	{
		if (str[n] >= '0' && str[n] <= '9')
			check = true;
		else
		{
			check = false;
			break;
		}
	}

	return check;
}

//split the string after the pointer position and return a pointer to a vector
void sstring::split(int ptr, vector<sstring>* strVector)
{
	sstring vecPart;

	for (int n = 0; n <= ptr; ++n)
	{
		vecPart.push_back(str[n]);
	}

	(*strVector).push_back(vecPart);
	vecPart.erase();

	for (int n = ptr + 1; n < str.size(); ++n)
	{
		vecPart.push_back(str[n]);
	}

	(*strVector).push_back(vecPart);

	return;
}

//split the string after ever occurence of a character and return a pointer to a vector
void sstring::split(char ch, vector<sstring>* strVector)
{
	sstring vecPart;

	for (int n = 0; n < str.size(); ++n)
	{
		vecPart.push_back(str[n]);

		if (str[n] == ch || n == str.size() - 1)
		{
			(*strVector).push_back(vecPart);
			vecPart.erase();
		}

		else
			;
	}

	return;
}

//convert a string to the int datatype
int sstring::to_int()
{
	return stoi(str.c_str());
}

//convert a string to the double datatype 
double sstring::to_double()
{
	int ptr;
	double mult = 1;
	double ret = 0;
	int temp;
	string ch;
	int start = 0;

	if (str[0] == '-')
		start = 1;
	else
		start = 0;

	for (int n = start; n < str.size(); ++n)
	{
		if (str[n] == '.')
		{
			ptr = n;
			break;
		}
		else
			;
		if (n == str.size() - 1)
			ptr = n;
		else
			;
	}

	for (int n = ptr - 1; n > start; --n)
		mult *= 10;

	for (int n = start; n < str.size(); ++n, mult /= 10)
	{
		if (str[n] == '.')
		{
			mult *= 10;
			continue;
		}
		else
		{
			ch = str[n];
			temp = stoi(ch.c_str());
			ret += temp * mult;
		}
	}

	if (str[0] == '-')
		return ret * -1;
	else
		return ret;
}

//convert a string to the float datatype
float sstring::to_float()
{
	return to_double();
}

//convert int into sstring
void sstring::to_sstring(int input)
{
	str = std::to_string(input);
	return;
}

//convert double to sstring
void sstring::to_sstring(double input)
{
	str = std::to_string(input);
	return;
}

//convert float to sstring
void sstring::to_sstring(float input)
{
	str = std::to_string(input);
	return;
}

//returns the amount of times a character appears
unsigned int sstring::rep_char(char ch)
{
	unsigned int n = 0;
	
	for (int a = 0; a < str.size(); ++a)
	{
		if (str[a] == ch)
			++n;
		else
			;
	}

	return n;
}

//convert sstring into a vector of characters
void sstring::to_vec(vector<char>* vec)
{
	for (int n = 0; n < str.size(); ++n)
		(*vec).push_back(str[n]);
	return;
}
/*void sstring::to_vec(vector <char>* vec, unsigned int num)
{

}*/

//tells the user if the sstring is made up of the characters in the specified sstring
bool sstring::made_of(sstring block)
{
	for (unsigned int n = 0; n < str.size(); ++n)
	{
		for (unsigned int x = 0; x < block.size(); ++x)
		{
			if (str[n] == block[x])
				break;
			else if (x == block.size() - 1)
				return false;
			else
				continue;

		}
	}

	return true;
}
bool sstring::made_of(string block)
{
	for (unsigned int n = 0; n < str.size(); ++n)
	{
		for (unsigned int x = 0; x < block.size(); ++x)
		{
			if (str[n] == block[x])
				break;
			else if (x == block.size() - 1)
				return false;
			else
				continue;

		}
	}

	return true;
}


//cin-esque type of data entry
void sstring::enter()
{
	cin >> str;
	return;
}
void sstring::getline()
{
	std::getline(cin, str);
	return;
}

//cout-esque display function
void sstring::display()
{
	cout << str;
	return;
}

//operator overloads
void sstring::operator= (int x)
{
	str = std::to_string(x);
	return;
}
void sstring::operator= (float x)
{
	str = std::to_string(x);
	return;
}
void sstring::operator= (double x)
{
	str = std::to_string(x);
	return;
}
void sstring::operator= (sstring newstr)
{
	str = newstr.str;
}
void sstring::operator+= (string str)
{
	str.append(str);
}
void sstring::operator+= (sstring newstr)
{
	str.append(newstr.str);
}
const sstring sstring::operator+ (const string input)
{
	sstring result;
	result.str = this->str + input;
	return result;
}
const sstring sstring::operator+ (const sstring &input)
{
	sstring result;
	result.str = this->str + input.str;
	return result;
}

//force lower or upper case
void sstring::forceLower()
{
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		else
			continue;
	}
}
void sstring::forceUpper()
{
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else
			continue;
	}
}

//reverse a string
void sstring::reverse()
{
	string temp;

	for (int i = 0; i < (str.length() / 2); ++i)
	{
		temp = str.substr(i, 1);
		str.replace(i, 1, str.substr((str.length() - i) - 1, 1));
		str.replace((str.length() - i) - 1, 1, temp);
	}
}