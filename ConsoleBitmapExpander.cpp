#include"utilities.h"
#include"DoubleString.h"
#include"WriteSizeofBitmap.h"
#include"WriteSizeofBitmapData.h"
#include <string>
#include <sstream>
#include <fstream>
#include<iomanip>
 
void writestringtofile(int indexstart, int indexend);   
void main()
{
	//writestringtofile(0, 3);
	char filen2[] = { "C:/Users/joshe/file7a.bmp" };
	WriteSizeofBitmapData bmpdatasize;
	WriteSizeofBitmap size;
	DoubleString finalobject;
	utilities * utili = new  utilities;
	char filen[] = {"file7z.bmp"};
	//read, write
	bmpdatasize.getstringandsave(filen, filen2, utili);

	//read, write
	//size.getstringandsave(filen,filen2, utili);
	//saves to mystring
	//utili->readinfile(4, filen);
	//saves to hex2
	//utili->reversestring(4, utili->mystring);
	
	
	////saves to file
	//char filen2[] = {"C:/Users/joshe/file7a.bmp"};
	////also reverses pairs
	//finalobject.doublestringandsave(filen2, utili->hex2, utili);
	////"C:/Users/joshe/file7a.bmp"
	//utili->Printdata(filen2);

}

void writestringtofile(int indexstart, int indexend)
{
	char data1[2];
	std::string result;
	char data[100] = { '4', '2' , '4', 'D', 'F' };
	char* pdata = data1;
	utilities util;

	std::stringstream sstream;
	std::ofstream myfile;
	char final[3];
	char r;

	myfile.open("test1000", std::ios::binary);

	for (int i = indexstart; i <= indexend; i++)
	{
		data1[0] = data[i];
		data1[1] = data[i + 1];


		int decimal = util.hexadecimalToDecimal(pdata);

		sstream << std::setfill('0') << std::setw(2) << std::hex << decimal;
		result = sstream.str();

		final[0] = result[i];
		final[1] = result[i + 1];
		final[2] = '\0';
		r = util.cal(final[0]) * 16 + util.cal(final[1]);
		//i++;
		myfile << r;
		i++;



	}

	myfile.close();

}