#include "DisAssembler.h"

DisAssembler::DisAssembler()
{
	bankselhelp = 0;

	ifstream hxfile(setFileName() + ".HEX");
	int count = 0;
	string linetest;
	for (int i = 0; i < 128; ++i)
	{
		program[i] = "\0";
	}
	for (int i = 0; i < 16; ++i)
	{
		hx[i] = intStrConv(i);
	}
	while (getline(hxfile, line))
	{
		parseLine(count);
		++count;
	}
	hxfile.close();
	displayProgram();
}

void DisAssembler::parseLine(int lineNum)
{
	if (testCC())
	{
		int stringAdd = 0;
		int currentAdd = 0;
		string x = "\0";

		lines[lineNum][0] = line.substr(1, 2);
		lines[lineNum][1] = line.substr(3, 4);
		lines[lineNum][2] = line.substr(7, 2);

		if (!testEOF(lineNum) && !testStart(lineNum))
		{

			bytenum = hxStrConv(lines[lineNum][0].substr(0, 1)) * 16 + hxStrConv(lines[lineNum][0].substr(1, 1));
			lines[lineNum][3] = line.substr(9, bytenum * 2);

			for (int i = 0; i < bytenum * 2; i += 4)
			{
				currentAdd = 0;

				for (int i = 0; i < 4; ++i)
				{
					currentAdd += hxStrConv(lines[lineNum][1].substr(3 - i, 1)) * pow(16, i);
				}

				currentAdd += i / 4;
				lines[lineNum][4] = lines[lineNum][3].substr(i + 2, 2) + lines[lineNum][3].substr(i, 2);
				x = OpCodeHub(lines[lineNum][4]);
				//cout << setw (5) << currentAdd << setw(20) << x << endl;
				program[currentAdd] = x;
			}

		}

		else;

	}

	else
	{
		errorMessages(2);
	}
}

bool DisAssembler::testCC()
{
	int dataLength = line.length() - 2;
	int dataSum = 0;
	int checkSum = 0;
	string data = line.substr(0, dataLength);
	string CC = line.substr(dataLength, 2);

	for (int i = 1; i < dataLength; i += 2)
	{
		dataSum += hxStrConv(data.substr(i, 1)) * 16 + hxStrConv(data.substr(i + 1, 1));
	}

	dataSum %= 0x100;

	checkSum = hxStrConv(CC.substr(0, 1)) * 16 + hxStrConv(CC.substr(1, 1));

	if (checkSum + dataSum == 0x100)
		return pass;

	else
		return fail;

}

bool DisAssembler::testStart(int lineNum)
{
	if (lines[lineNum][2] == "04")
		return pass;

	else
		return fail;
}

bool DisAssembler::testEOF(int lineNum)
{
	if (lines[lineNum][2] == "01")
		return pass;

	else
		return fail;
}

int DisAssembler::hxStrConv(string x)
{
	for (int i = 0; i < 16; ++i)
	{
		if (hx[i] == x)
			return i;
		else
			continue;
	}

	errorMessages(1);
} //Works

void DisAssembler::errorMessages(int ecode)
{
	if (ecode == 1)
	{
		cout << "Error Code 0x01: Unrecognized Character" << endl;
		cout << "Possible reasons for this error include: Lowercase hex values, Non-hexidecimal characters" << endl;
	}

	else if (ecode == 2)
	{
		cout << "Error Code 0x02: Corrupted Data" << endl;
		cout << "Possible reasons for this error include: Incorrect data values, Incorrect checksum values" << endl;
	}

	else if (ecode == 3)
	{
		cout << "Error Code 0x03: Unrecognized OpCode" << endl;
		cout << "Possible reasons for this error include: Tampered Data, Unrecognized Keywords" << endl;
	}
} //Works

string DisAssembler::setFileName()
{
	cout << "Enter the file name, without the file extension: ";
	string file;
	getline(cin, file);
	system("Cls");
	return file;
}

void DisAssembler::displayProgram()
{

	cout << setw(10) << "Address" << setw(50) << "Instruction" << endl << endl;

	cout << setw(5) << "ORG 0" << endl << endl;

	for (int i = 0; i < programSize; ++i)
	{
		if (program[i] != "\0")
			cout << setw(10) << i << setw(50) << program[i] << endl;
		else
			continue;
	}

	cout << endl << "END" << endl;

}

string DisAssembler::intStrConv(int hx)
{
	switch (hx)
	{
	case 0:
		return "0";
		break;
	case 1:
		return "1";
		break;
	case 2:
		return "2";
		break;
	case 3:
		return "3";
		break;
	case 4:
		return "4";
		break;
	case 5:
		return "5";
		break;
	case 6:
		return "6";
		break;
	case 7:
		return "7";
		break;
	case 8:
		return "8";
		break;
	case 9:
		return "9";
		break;
	case 10:
		return "A";
		break;
	case 11:
		return "B";
		break;
	case 12:
		return "C";
		break;
	case 13:
		return "D";
		break;
	case 14:
		return "E";
		break;
	case 15:
		return "F";
		break;
	default:
		return "0";
		break;
	}
}

string DisAssembler::OpCodeHub(string Opcode)
{
	if (Opcode == "0064") // CLRWDT
	{
		return "CLRWDT";
	}

	else if (Opcode == "1303")
	{
		if (!bankselhelp)
			return "BANKSEL A";
		else
			return "BANKSEL B";
	}

	else if (Opcode == "1703")
	{
		if (!bankselhelp)
			return "BANKSEL C";
		else
			return "BANKSEL D";
	}

	else if (Opcode == "1283")
	{
		bankselhelp = 0;
		return "\0";
	}

	else if (Opcode == "1683")
	{
		bankselhelp = 1;
		return "\0";
	}

	else if (Opcode.substr(0, 2) == "07") // ADDWF
	{
		if (hxStrConv(Opcode.substr(2, 1)) < 8)
		{
			return "ADDWF 0x" + Opcode.substr(2, 2) + ", 0";
		}

		else
		{
			return "ADDWF 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1) + ", 1";
		}
	}

	else if (Opcode.substr(0, 2) == "05") // ANDWF
	{
		if (hxStrConv(Opcode.substr(2, 1)) < 8)
		{
			return "ANDWF 0x" + Opcode.substr(2, 2) + ", 0";
		}

		else
		{
			return "ANDWF 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1) + ", 1";
		}
	}

	else if (Opcode.substr(0, 2) == "01" && hxStrConv(Opcode.substr(2, 1)) > 7) //CLRF
	{
		return "CLRF 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1);
	}

	else if (Opcode.substr(0, 2) == "01" && hxStrConv(Opcode.substr(2, 1)) < 8) //CLRW
	{
		return "CLRW";
	}

	else if (Opcode.substr(0, 2) == "09") //COMF
	{
		if (hxStrConv(Opcode.substr(2, 1)) < 8)
		{
			return "COMF 0x" + Opcode.substr(2, 2) + ", 0";
		}

		else
		{
			return "COMF 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1) + ", 1";
		}
	}

	else if (Opcode.substr(0, 2) == "03") //DECF
	{
		if (hxStrConv(Opcode.substr(2, 1)) < 8)
		{
			return "DECF 0x" + Opcode.substr(2, 2) + ", 0";
		}

		else
		{
			return "DECF 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1) + ", 1";
		}
	}

	else if (Opcode.substr(0, 2) == "0B") //DECFSZ
	{
		if (hxStrConv(Opcode.substr(2, 1)) < 8)
		{
			return "DECFSZ 0x" + Opcode.substr(2, 2) + ", 0";
		}

		else
		{
			return "DECFSZ 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1) + ", 1";
		}
	}

	else if (Opcode.substr(0, 2) == "0A") //INCF
	{
		if (hxStrConv(Opcode.substr(2, 1)) < 8)
		{
			return "INCF 0x" + Opcode.substr(2, 2) + ", 0";
		}

		else
		{
			return "INCF 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1) + ", 1";
		}
	}

	else if (Opcode.substr(0, 2) == "0F") //INCFSZ
	{
		if (hxStrConv(Opcode.substr(2, 1)) < 8)
		{
			return "INCFSZ 0x" + Opcode.substr(2, 2) + ", 0";
		}

		else
		{
			return "INCFSZ 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1) + ", 1";
		}
	}

	else if (Opcode.substr(0, 2) == "04") //IORWF
	{
		if (hxStrConv(Opcode.substr(2, 1)) < 8)
		{
			return "IORWF 0x" + Opcode.substr(2, 2) + ", 0";
		}

		else
		{
			return "IORWF 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1) + ", 1";
		}
	}

	else if (Opcode.substr(0, 2) == "08") //MOVF
	{
		if (hxStrConv(Opcode.substr(2, 1)) < 8)
		{
			return "MOVF 0x" + Opcode.substr(2, 2) + ", 0";
		}

		else
		{
			return "MOVF 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1) + ", 1";
		}
	}

	else if (Opcode.substr(0, 2) == "00" && hxStrConv(Opcode.substr(2, 1)) > 7) //MOVWF
	{
		return "MOVWF 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1);
	}

	else if (Opcode.substr(0, 2) == "00" && hxStrConv(Opcode.substr(2, 1)) > 7) //MOVF
	{
		return "CLRF 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1);
	}

	else if (Opcode == "0000") //NOP
	{
		return "NOP";
	}

	else if (Opcode.substr(0, 2) == "0D") //RLF
	{
		if (hxStrConv(Opcode.substr(2, 1)) < 8)
		{
			return "RLF 0x" + Opcode.substr(2, 2) + ", 0";
		}

		else
		{
			return "RLF 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1) + ", 1";
		}
	}

	else if (Opcode.substr(0, 2) == "0C") //RRF
	{
		if (hxStrConv(Opcode.substr(2, 1)) < 8)
		{
			return "RRF 0x" + Opcode.substr(2, 2) + ", 0";
		}

		else
		{
			return "RRF 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1) + ", 1";
		}
	}

	else if (Opcode.substr(0, 2) == "02") //SUBWF
	{
		if (hxStrConv(Opcode.substr(2, 1)) < 8)
		{
			return "SUBWF 0x" + Opcode.substr(2, 2) + ", 0";
		}

		else
		{
			return "SUBWF 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1) + ", 1";
		}
	}

	else if (Opcode.substr(0, 2) == "0E") //SWAPF
	{
		if (hxStrConv(Opcode.substr(2, 1)) < 8)
		{
			return "SWAPF 0x" + Opcode.substr(2, 2) + ", 0";
		}

		else
		{
			return "SWAPF 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1) + ", 1";
		}
	}

	else if (Opcode.substr(0, 2) == "06") //XORWF
	{
		if (hxStrConv(Opcode.substr(2, 1)) < 8)
		{
			return "XORWF 0x" + Opcode.substr(2, 2) + ", 0";
		}

		else
		{
			return "XORWF 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1) + ", 1";
		}
	}

	else if (Opcode == "0009") // RETFIE
	{
		return "RETFIE";
	}


	else if (Opcode == "0008") // RETURN
	{
		return "RETURN";
	}

	else if (Opcode == "0003") // SLEEP
	{
		return "SLEEP";
	}

	else if (Opcode.substr(0, 2) == "3E") //ADDLW
	{
		return "ADDLW 0x" + Opcode.substr(2, 2);
	}

	else if (Opcode.substr(0, 2) == "39") //ANDLW
	{
		return "ANDLW 0x" + Opcode.substr(2, 2);
	}

	else if (Opcode.substr(0, 2) == "38") //IORLW
	{
		return "IORLW 0x" + Opcode.substr(2, 2);
	}

	else if (Opcode.substr(0, 2) == "30") //MOVLW
	{
		return "MOVLW 0x" + Opcode.substr(2, 2);
	}

	else if (Opcode.substr(0, 2) == "34") //RETLW
	{
		return "RETLW 0x" + Opcode.substr(2, 2);
	}

	else if (Opcode.substr(0, 2) == "3C") //SUBLW
	{
		return "SUBLW 0x" + Opcode.substr(2, 2);
	}

	else if (Opcode.substr(0, 2) == "39") //XORLW
	{
		return "XORLW 0x" + Opcode.substr(2, 2);
	}

	else if (Opcode.substr(0, 1) == "2" && hxStrConv(Opcode.substr(1, 1)) < 8) //Call
	{
		return "CALL 0x" + Opcode.substr(1, 3);
	}

	else if (Opcode.substr(0, 1) == "2" && hxStrConv(Opcode.substr(1, 1)) > 7) //GOTO
	{
		return "GOTO 0x" + intStrConv(hxStrConv(Opcode.substr(1, 1)) - 8) + Opcode.substr(2, 2);
	}

	else if (Opcode.substr(0, 1) == "1" && hxStrConv(Opcode.substr(1, 1)) < 4) //BCF
	{
		if (hxStrConv(Opcode.substr(2, 1)) < 8)
			return "BCF 0x" + Opcode.substr(2, 2) + ", 0x" + intStrConv(hxStrConv(Opcode.substr(1, 1)) * 2);

		else
			return "BCF 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1) + ", 0x" + intStrConv((hxStrConv(Opcode.substr(1, 1)) * 2) + 1);
	}

	else if (Opcode.substr(0, 1) == "1" && hxStrConv(Opcode.substr(1, 1)) < 8 && hxStrConv(Opcode.substr(1, 1)) > 3) //BSF
	{
		if (hxStrConv(Opcode.substr(2, 1)) < 8)
			return "BSF 0x" + Opcode.substr(2, 2) + ", 0x" + intStrConv((hxStrConv(Opcode.substr(1, 1)) - 4) * 2);

		else
			return "BSF 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1) + ", 0x" + intStrConv(((hxStrConv(Opcode.substr(1, 1)) - 4) * 2) + 1);
	}

	else if (Opcode.substr(0, 1) == "1" && hxStrConv(Opcode.substr(1, 1)) < 12 && hxStrConv(Opcode.substr(1, 1)) > 7) //BTFSC
	{
		if (hxStrConv(Opcode.substr(2, 1)) < 8)
			return "BTFSC 0x" + Opcode.substr(2, 2) + ", 0x" + intStrConv((hxStrConv(Opcode.substr(1, 1)) - 8) * 2);

		else
			return "BTFSC 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1) + ", 0x" + intStrConv(((hxStrConv(Opcode.substr(1, 1)) - 8) * 2) + 1);
	}

	else if (Opcode.substr(0, 1) == "1" && hxStrConv(Opcode.substr(1, 1)) > 11) //BTFSS
	{
		if (hxStrConv(Opcode.substr(2, 1)) < 8)
			return "BTFSS 0x" + Opcode.substr(2, 2) + ", 0x" + intStrConv((hxStrConv(Opcode.substr(1, 1)) - 12) * 2);

		else
			return "BTFSS 0x" + intStrConv(hxStrConv(Opcode.substr(2, 1)) - 8) + Opcode.substr(3, 1) + ", 0x" + intStrConv(((hxStrConv(Opcode.substr(1, 1)) - 12) * 2) + 1);
	}

	else if (Opcode.substr(0, 2) == "3A") //XORLW
	{
		return "XORLW 0x" + Opcode.substr(2, 2);
	}

	else
	{
		errorMessages(3);
		return "\0";
	}
}