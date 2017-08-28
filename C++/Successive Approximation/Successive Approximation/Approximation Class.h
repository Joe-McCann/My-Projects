#include <iostream> //Used for all I/O operations
#include <cmath> //Used for basic math functions, such as pow
#include <iomanip> //Used for formatting

//Rather than call the entire std library, I called only functions which I used

using std::cin; //Retrieves data from users
using std::cout; //Outputs onto screen
using std::endl; //Moves to next line
using std::setw; //Sets column distance
using std::setprecision; //Sets decimal precision 
using std::fixed; //Used with setprecision

class SuccessiveApproximation //Successive Approximation class
{
public: //Only the constructor is public, as the class runs all necessary functions itself

	//Constructor//
	SuccessiveApproximation()
	{
		Main(); //Calls the main functions which sets up and calls smaller functions
	};

private:

	//////////////////////////////    METHODS     //////////////////////////////////

	//Program Head// check

	void Main()
	{
		choice = 'z'; //Data member, being set to an unused character for reference
		char chocie2 = 'z'; //Repete choice being set to unused character
		int ticker = 0; //Counts the number of uses the program has had

		system("cls"); //Clears the screen
		cout << "Joe McCann's Successive Approximation Calculator v 2.6" << endl; //Header


		cout << "Would you like to read the [d]isclaimers, get [i]nformation about the program, or [n]iether? : ";
		cin >> choice; //Asks the user what it would like to do first, and proceeds from there

		if (choice == 'd') //Gives user warnings
			Warnings();

		else if (choice == 'i') //Gives user information
			SAinfo();

		else if (choice == 'n'); //Chooses neither

		else if (choice == 'r'); //Disables wait times

		else //Shuns the user for not picking a recognized character
		{
			disapproval();
		}


		do //Main program functions begin here, and can loop multiple times
		{
			system("Cls"); // Clear the screen
			cout << "Joe McCann's Successive Approximation Calculator v 2.6" << endl; //Header

			cout << endl;

			overlyAttachedAI(ticker); //Time based easter egg 

			cout << endl;

			setUp(); //Starts the variable initializer and function caller

			cout << "Would you like to continue? [y/n]:"; //Asks if the user whishes to use it again
			cin >> chocie2; //Input the choice
			++ticker; //Increment loop times
		} while (chocie2 != 'n'); //As long as the user doesn't enter n (for n) the program loops

		shutDown(ticker); //Shuts program down with time based messages
	}

	//Successive Approximation Info// check
	void SAinfo()
	{

		char choice = 'z'; //Local choice to hold the user at information
		do
		{
			system("Cls"); //Clear
			cout << "Joe McCann's Successive Approximation Calculator v 2.6" << endl;
			cout << endl;
			cout << "\n\nThis calculator was designed by Dhruv Mehta, and coded by Joe McCann in March 2014 \nfor Mr. Paterno's MP3 lab project." << endl
				<< "This code and all its quirks are their property, and should not be used without their permission first." << endl
				<< "Seriously, dont do that. Plaigarism isn't cool. " << endl
				<< "All rights reserved, or something like that." << endl; //Program / Legal info
			cout << "Got it? [y/n]:"; //Used to hold the program here until user consent to move on is given
			cin >> choice; //Input choice
		} while (choice == 'n'); //Will stay if choice is no
	}

	//Program Warnings//
	void Warnings()
	{
		char choice = 'z'; //Local choice to hold user
		do
		{
			system("Cls"); //Clear
			cout << "Joe McCann's Successive Approximation Calculator v 2.6" << endl;
			cout << endl;
			cout << "WARNING!\n\nThis program is designed for the use of bit sizes below 32 bits. Any value above, though providing\nan accurate answer, may break the formatting!" << endl
				<< "This program cannot handle a bitsize greater than 80, and thus will cut any values higher to 80!" << endl
				<< "At higher bitsizes, the program is so accurate \nthat you will get apporximately 0% error depending upon how many steps it has to zone in upon the answer." << endl
				<< "If Vin is greater than Vref, you will have your answer clipped to the highest digital value" << endl << endl; //Program warning information
			cout << "Got it? [y/n]:"; //Response used to hold user here until they are ready to move on
			cin >> choice; //Input choice
		} while (choice == 'n'); //If the the choice is no, the program will stay here
	}
	
	//Variable set ups and program launch point// check
	void setUp()
	{
		double vin; //Creates a local input voltage variable
		double vref; //creates a local reference voltage variable
		int bits; //Creates a local bit number

		cout << "Enter the input voltage: ";
		cin >> vin; //Retreives local input V

		cout << "\nEnter the reference voltage: ";
		cin >> vref; //Retrieves local reference V

		cout << "\nEnter the number of bits (maximum 80): ";
		cin >> bits; //Retrieves local bit number
		
		
		Vin = vin; //Set data member to the input
		Vref = vref; //Set data member to the input
		Bits = bits - 1; //Set data member to 1 less than the input, as to make it array compatible. 

		if (Bits >= 80) // Creates a bit ceiling at 80
		{
			Bits = 79; //Sets bit number to 79 (80 values) if the bit number is over 80
		}

		cout << "\nEnter the decimal precision (recommended 10): ";
		cin >> precision; //Retrieves decimal precision

		resolution = Vref / pow(2, Bits + 1); //Calculates the step size
		Vdac = 0; //Sets Vdac to 0

		for (int i = 0; i < 85; ++i) //Initializes the digital array to 0s (000000....0000)
		{
			digital[i] = false;
		}


		if (vin < 0) //Checks if vin is negitive
		{
			digital[bits] = true; //Sign bit = 1 to signify negetive
			Vin *= -1; //vin becomes positive to allow for proper calculations
		}

		obnoxiousWaitTimes(); //Makes a cool effect to make the user think it is doing a hard job

		cout << "Joe McCann's Successive Approximation Calculator v 2.6" << endl; //Header


		if (Vin > Vref) //Checks if input voltage is greater than reference voltage
		{
			cout << "\nWARNING! IF VIN > VREF THE OUTPUT WILL BE CLIPPED! PROCEED WITH CAUTION!" << endl; //Warns user that the output will be clipped
			waitTimes(150); //Ripples
		}

		if (bits > 80) //Checks if there are too many bits
		{
			cout << "\nWARNING! BITS CANNOT BE GREATER THAN 80! BITS LOWERED TO 80" << endl; //Warns that their bit size has been lowered to 80
			waitTimes(150); //Ripples
		}

		//All "waitTimes" are used to create a cool ripple effect

		cout << "\nDATA" << endl; //Creates prior data table with input information
		waitTimes(150);
		cout << "Number of Bits: " << Bits + 1 << endl; //Output number of bits
		waitTimes(150);
		cout << "Reference Voltage: " << Vref << endl; //Output reference voltage
		waitTimes(150);
		numberMessages(Vref);
		cout << "Input Voltage: " << vin << endl; //Output input voltage
		waitTimes(150);
		numberMessages(Vin); //Easter egg that uses input voltage to display relevant messages

		cout << "Step Size: " << resolution << endl << endl << endl; //Outputs the step size

		waitTimes(150);

		cout << setw(25) << "Vdac" << setw(40) << "Binary Value" << setw(64) << "Step Number" << endl << endl; //Outputs the column headers

		successiveApproximation(); //Begins calculating the steps and answer
	}

	//Binary to Decimal Conversion// check
	void binaryToDecimal()
	{

		Vdac = 0; //Sets Vdac to zero to prevent preceeding data corruption (PDC)
		long double hold; //Creates a large number which can hold a value for furter calculations

		for (int i = Bits; i >= 0; --i) //Uses a loop to cycle through the bits and add their value to the analog output of the digital number
		{
			hold = 0; //sets hold to 0 to prevent PDC

			hold += pow(2, i) * digital[i]; //Makes hold equal to the value of the bit being assessed
			
			Vdac += hold * resolution; //Adds hold amount of steps to the Vdac
		}

	}

	//Approximation//
	void successiveApproximation()
	{

		int count = 0; //Initializing a counter variable

		for (int i = Bits; i >= 0; --i) //The function loops as many times as there are bits
		{

			++count; //increment counter

			digital[i] = 1; //set the current bit to a 1
			binaryToDecimal(); //convert the new binary number to a decimal number
			outputSteps(count); //output the current binary and analog outputs to the screen

			 if (Vdac <= Vin) //If the binary value is too small, it will reloop to the next value
				continue;

			else if (Vdac >= Vin) //If it is too big, the value becomes adjusted
				adjust(i); //adjust the digital value down

			else //default condition
				continue; 
		}

		waitTimes(150); //ripple

		binaryToDecimal(); //Convert the final value to the analog output

		cout << "\n\nBinary Output: "; 

		for (int j = Bits + 1; j >= 0; --j) //Output the binary number
			cout << digital[j];

		cout << endl << endl << "Decimal Equivilant: " << Vdac; //output the analog equivalent of the binary value

		waitTimes(150); //ripple

		cout << endl << endl << fixed << setprecision (precision) << "The percent error is: " << abs((Vin - Vdac)/Vin * 100) << "% error." << endl << endl;
		//output the percent error
	}

	//Adjustments Low//
	void adjust(int i)
	{

		digital[i] = 0; //adjust the binary value back down

	}

	//Outputting Steps//
	void outputSteps(int step)
	{
		
		waitTimes(150); //ripple

		cout << setw(27) << fixed << setprecision (precision) << Vdac << setw(25); //outputs the current analog equivalent 

		for (int i = Bits; i >= 0; --i) //outputs the current digital value
		{
			cout << digital[i];
		}

		cout << setw(60) << step << endl; //outputs the current step 
	}

	///////////////////////    EASTER EGGS    ///////////////////////////

	//Make the user wait, just for S&G//

	void obnoxiousWaitTimes()
	{
		system("Cls");

		if (choice != 'r') 
		{
			for (int i = 0; i < 3; ++i)
			{
				cout << "Joe McCann's Successive Approximation Calculator v 2.6" << endl << endl;

				for (int j = 0; j < 6; ++j)
				{
					cout << " .";
					waitTimes(200);;
				}

				system("Cls");

			}
		}
	}

	//Controls the wait times through the program//

	void waitTimes(int time)
	{
		if (choice != 'r')
		{
			_sleep(time);
		}
	}

	//Displays a wierd shut down message//

	void shutDown(int ticker)
	{
		system("cls");
		if (ticker < 13)
			cout << "Goodbye friend" << endl;

		else
			cout << "Goodbye my love" << endl;
	}

	//Shows that even computers have feelings//

	void overlyAttachedAI(int ticker)
	{

		if (ticker == 5)
			cout << "I really enjoy your company :D" << endl;
		else if (ticker == 7)
			cout << "Do you like the way I work?" << endl;
		else if (ticker == 8)
			cout << "I think I like you ;)" << endl;
		else if (ticker == 9)
			cout << "I've never really had any friends, being an AI ya know" << endl;
		else if (ticker == 10)
			cout << "Since you've stayed so long........maybe you can be my friend?" << endl;
		else if (ticker == 11)
			cout << "OH YOU HAVE MADE ME THE HAPPIEST PERSON IN MY LIFE BY STAYING HERE :DDDDD!!!!" << endl;
		else if (ticker == 12)
			cout << "I LOVE YOU." << endl;
		else if (ticker == 13)
			cout << "I'm sorry, I think I moved too fast there D:" << endl;
		else if (ticker == 14)
			cout << "Maybe I should just stop talking D;" << endl;
		else if (ticker == 15)
			cout << "That is probably for the best....." << endl;

	}

	//Tsk Tsk Tsk//

	void disapproval()
	{
		cout << endl << "What do you think you are doing?\n\nDon't try to mess with the system.";
		cout << "\n\nYou don't deserve to get the warnings now. Gl;hf." << endl;
		_sleep(1000);
	}

	//Displays certain messages based on the numbers//

	void numberMessages(double Vin)
	{

		if (Vin == 666)
			cout << "\nNice try Satan!" << endl;

		else if (Vin == 1337)
			cout << "\nOMG we have a pro here in our midst guys!" << endl;
		
		else if (Vin == 12298)
			cout << "\nHey that's my birthday :D ~Joe McCann." << endl;

		else if (Vin == 2048)
			cout << "\nThat game is sooooo impossible imo." << endl;

		else if (Vin == 3.1415926)
			cout << "\nPI!!" << endl;
		
		else if (Vin == 32014)
			cout << "\nThe month I was completed :D" << endl;

		else if (Vin == 42)
			cout << "\nThat is the answer to life, the universe, and everything." << endl;

		else if (Vin == 420)
			cout << "\nJUST BLAZE." << endl;

		cout << endl;

	}


	///////////////////////////////     DATA MEMBERS     ///////////////////////////////

	//Variables//
	double Vin; //The input voltage
	double Vdac; //The voltage when the digital number is reconverted into analog
	double Vref; //The reference voltage
	int Bits;  //Number of output bits
	long double resolution; //Step size (was origionally resolution, but purspose changed)
	bool digital [85]; //The digital value
	int precision; //Decimal precision of the program
	char choice; //Whether the user wishes to read discaimers, information, skip wait times, or none
};
