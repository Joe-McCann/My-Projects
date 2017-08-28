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
	
	big x = 2; 
	big y = x ^ 6400;
	cout << y << endl;

	return 0;
}