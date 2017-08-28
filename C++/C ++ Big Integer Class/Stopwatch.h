#pragma once
class Stopwatch
{
public:
	Stopwatch();
	
	void startWatch();
	void endWatch();

	double getTime();
	double getTime(double currentTime);

private:

	double startTime;
	double endTime;
};

