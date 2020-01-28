#pragma once
#ifndef utils
#define utils

#include <string>
class utilities
{
	public:

	char buffer[3];
	char * pbuf;
	char mystring[12];
	std::string hex1;
	std::string hex2;
	int len;

	utilities(void);
	void readinfile(int, char file[] );
	int hexadecimalToDecimal(char hexVal[]);
	int cal(char c);
	int Printdata(char []);
	void reversestring(int , char[]);
};

#endif