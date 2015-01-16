#include <iostream>
#include <string>
#include <ctime>
#include "big.h"
#include "Stopwatch.h"
#include <fstream>
#include "sstring_class.h"

using namespace std;

int main()
{
	
	big x = 10;
	x ^= 79; 

	x.printNum();

	return 0;
}