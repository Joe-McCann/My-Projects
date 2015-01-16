#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
const bool pass = true; 
const bool fail = false;
const int programSize = 128; 

using namespace std; 

class DisAssembler
{
public:

	DisAssembler();
	void parseLine(int lineNum);
	bool testCC();
	bool testStart(int lineNum);
	bool testEOF(int lineNum);
	int hxStrConv(string x);
	void errorMessages(int ecode);
	string setFileName();
	void displayProgram();
	string intStrConv(int hx);
	string OpCodeHub(string Opcode);

private: 
	 
	string line; 
	string lines[20][4]; // 0:BB 1:Address 2:TT 3:LH 4:Correct Instruction 
	string program[128];
	int bytenum; 
	string hx[16];
	bool bankselhelp;
};