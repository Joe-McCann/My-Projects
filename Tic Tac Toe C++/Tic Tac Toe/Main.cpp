#include "TripleT.h"

int main()
{
	TripT(trips);


	for (int i = 0; i < 9; ++i)
	{

		trips.getInput();

		trips.displayGrid();

		trips.displayGrid();

		if (trips.isThereAWinner() || i == 9)
			break; 
	}

	trips.getWinner();

	return 0; 
}