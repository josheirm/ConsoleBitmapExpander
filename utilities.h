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
	void readinfile(void);
	int hexadecimalToDecimal(char hexVal[]);
	int cal(char c);
	int GetSizeImageData();
	void reversestring(void);
};

#endif