#include "utilities.h"
#include <fstream>
#include <sstream>
#include<iomanip>
#include<string>

#include "WriteSizeofBitmap.h"

using namespace std;



WriteSizeofBitmap::WriteSizeofBitmap()
{

}
//at this point hex2 is four elements i.e.:    FF 3 0 1
void WriteSizeofBitmap::getstringandsave(char filepath[], std::string hex2, utilities* utili)
{
    /////////////
    //THIS IS ALL THE OTHER DOUBLESTRINGCODE TO ADJUST FOR THIS FUNCTION
    ////////////

    std::string result;
    char* cstr = new char[hex2.length() + 1];
    std::strcpy(cstr, hex2.c_str());
    int decimal = utili->hexadecimalToDecimal(cstr);
    //new decimal value afer get the hex
    decimal = decimal * 2;

    std::stringstream sstream;
    //gets stream with complete zeros and one digits and puts in result.
    sstream << std::setfill('0') << std::setw(sizeof(int) * 2)
        << std::hex << decimal;
    result = sstream.str();

    //reverses pairs of hex - (endian)
    char final[9];
    for (int i = 0, j = 7; i < 7; i++, j--)
    {
        final[i] = result[j - 1];
        final[i + 1] = result[j];
        i++;
        j--;
    }


    final[8] = '\0';

    char r;
    //writes to file
    std::ofstream myfile;
    //myfile.open("C:/Users/joshe/file7a.bmp", std::ios::binary);
    myfile.open(filepath, std::ios::binary);
    for (int i = 0; i < 8; i++)
    {
        //calculates 
        r = utili->cal(final[i]) * 16 + utili->cal(final[i + 1]);
        myfile << r;
        i++;
    }

    myfile.close();
    //return(1);
}


