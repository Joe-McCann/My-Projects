#include "Stopwatch.h"
#include <ctime>


Stopwatch::Stopwatch()
{
	startTime = clock();
	endTime = clock();
}

void Stopwatch::startWatch()
{
	startTime = clock();
}

void Stopwatch::endWatch()
{
	endTime = clock();
}

double Stopwatch::getTime()
{
	return (endTime - startTime) / CLOCKS_PER_SEC;
}


