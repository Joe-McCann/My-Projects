#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

class TripT
{

public:

	TripT()
	{
		int count = 1;
		TC = 0; 
		winner = 0;

		cout << "Input Player 1 name: "; 

		cin >> p1; //Input player 1 and player 2 names

		cout << "Input Player 2 name: ";

		cin >> p2; 

		for (int i = 0; i < 3; ++i) //Multidimenional array initializer
		{
			for (int j = 0; j < 3; ++j)
			{
				char hold = '\0';

				switch (count)
				{
				case 1:
					hold = '1';
					break;
				case 2:
					hold = '2';
					break;
				case 3: 
					hold = '3';
					break;
				case 4:
					hold = '4';
					break;
				case 5:
					hold = '5';
					break;
				case 6:
					hold = '6';
					break;
				case 7:
					hold = '7';
					break;
				case 8:
					hold = '8';
					break;
				case 9:
					hold = '9';
					break;
				default:
					hold = '0';
					break;
				}

				grid[i][j] = { hold }; //Initializes the array to have all spaces. 

				++count;

			}
		}

		displayGrid();

	}

	void getInput()
	{
		++TC;
		int space;

		while (1)
		{
			(TC % 2 == 1) ? cout << (getP1()) : cout << (getP2());
			cout << " enter what space you will fill next:";

			cin >> space;

			if (!(space > 0) || !(space < 10))
			{
				for (int i = 0; i < 3; ++i)
				{
					for (int j = 0; j < 3; ++j)
					{
						if (checkAvailable(i, j))
						{
							space = (i * 3) + j + 1;
							goto loopEnd;
						}

						else
							continue;
					}
				}

				loopEnd:
				cout << "Invalid input. Defaulting to space: " << space << endl;
				_sleep(500);

			}

			--space;

			int j = space % 3;
			space -= j;

			int i = (space / 3);

			if (!checkAvailable(i, j))
				continue;

			(TC % 2 == 1) ? grid[i][j] = 'X' : grid[i][j] = 'O';
			break; 
		}
	}

	void displayGrid()
	{
		system("Cls"); 

		cout << "CURRENT BOARD" << endl << endl;

		for (int i = 0; i < 3; ++i)
		{

			cout << "     |     |     " << endl;
			cout  << "  " << grid[i][0] << "  |  " << grid[i][1] << "  |  " << grid[i][2] << "  " << endl;

			if (i != 2)
				cout  << "_____|_____|_____" << endl;

			else
			{
				cout << "     |     |     " << endl << endl;
					
			}
		}
	}

	bool isThereAWinner()
	{
		
		if (grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2])
		{
			if (grid[0][0] == 'X')
				winner = 1;
			else if (grid[0][0] == 'O')
				winner = 2; 
		}

		else if (grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2])
		{
			if (grid[1][0] == 'X')
				winner = 1;
			else if (grid[1][0] == 'O')
				winner = 2;
		}

		else if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2])
		{
			if (grid[2][0] == 'X')
				winner = 1;
			else if (grid[2][0] == 'O')
				winner = 2;
		}

		else if (grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0])
		{
			if (grid[0][0] == 'X')
				winner = 1;
			else if (grid[0][0] == 'O')
				winner = 2;
		}

		else if (grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1])
		{
			if (grid[0][1] == 'X')
				winner = 1;
			else if (grid[0][1] == 'O')
				winner = 2;
		}

		else if (grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2])
		{
			if (grid[0][2] == 'X')
				winner = 1;
			else if (grid[0][2] == 'O')
				winner = 2;
		}

		else if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
		{
			if (grid[0][0] == 'X')
				winner = 1;
			else if (grid[0][0] == 'O')
				winner = 2;
		}

		else if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
		{
			if (grid[0][2] == 'X')
				winner = 1;
			else if (grid[0][2] == 'O')
				winner = 2;
		}

		else
			winner = 0; 

		if (winner == 0)
			return false;

		else
			return true; 
	}

	void getWinner()
	{
		
		cleanArray();

		displayGrid(); 
		
		if (winner == 1)
		{
			cout << getP1() << " wins!" << endl;
		}

		else if (winner == 2)
			cout << getP2() << " wins!" << endl;

		else
			cout << "No winner!" << endl; 

		cout << endl; 
	}

private: 

	void cleanArray()
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (grid[i][j] == 'X' || grid[i][j] == 'O')
					continue;

				else
					grid[i][j] = ' '; 

			}
		}
	}
	
	void checkWinner()
	{


	}

	bool checkAvailable(int i, int j)
	{
		if (grid[i][j] != 'X' && grid[i][j] != 'O')
			return true;

		else
		{
			system("Cls");
			displayGrid();
			cout << "\nSpace already claimed. Choose again.\n" << endl;
			return false;
		}
	}
	
	string getP1()
	{
		return p1;
	}

	string getP2()
	{
		return p2;
	}

	char grid[3][3]; 
	string p1;
	string p2;
	short int winner; 
	int TC; 

};