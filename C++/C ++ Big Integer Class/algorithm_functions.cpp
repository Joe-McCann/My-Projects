#include "sstring_class.h"

void sstring::fill(char* first, char* last, char val)
{
	while (first <= last)
	{
		*first = val;
		++first;
	}

	return;
}
void sstring::fill(unsigned int first, unsigned int last, char val)
{
	while (first <= last)
	{
		str[first] = val;
		++first;
	}

	return;
}

char* sstring::adjacent_find(char* first, char* last)
{
	while (first != last)
	{
		if (*first == *last)
			break;
		else
			++first;
	}

	return first;
}
unsigned int sstring::adjacent_find(unsigned int first, unsigned int last)
{
	while (first != last)
	{
		if (str[first] == str[first + 1])
			break;
		else
			++first;
	}

	return first;
}