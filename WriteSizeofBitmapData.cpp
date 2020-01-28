#include "utilities.h"
#include "WriteSizeofBitmapData.h"


#include <fstream>
#include <sstream>
#include<iomanip>
#include<string>

using namespace std;



WriteSizeofBitmapData::WriteSizeofBitmapData()
{
    char* pbuf = buffer;

    mystring[11] = '\0';
}
//at this point hex2 is four elements i.e.:    FF 3 0 1
void WriteSizeofBitmapData::getstringandsave(char filepath_r[], char filepath_w[],  utilities* utili)
{
    /////////////

    ////////////
    int element_counter = 0;
    FILE* file;
   char r;


    file = fopen(filepath_r, "r");
    do {


        int var3 = fgetc(file);
        if (feof(file)) {
            fclose(file);
            break;
        }
        element_counter++;



        /*sprintf(pbuf, "%X", var3);
        if (element_counter == 1)
        {
            strcpy(mystring, pbuf);
        }
        else
        {
            strcat(mystring, pbuf);
        }


        strcat(mystring, " ");*/

    } while (1);

    int sizeorigbitmapdata = element_counter - 54;
    int newsizebitmap = sizeorigbitmapdata * 4;
    int decimal = newsizebitmap;
    std::string result;

    std::stringstream sstream;
    //gets stream with complete zeros and one digits and puts in result.
    sstream << std::setfill('0') << std::setw(sizeof(int) * 2)
        << std::hex << decimal;
    result = sstream.str();
    //////////////////////////
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


    //writes to file
    std::ofstream myfile;
    //myfile.open("C:/Users/joshe/file7a.bmp", std::ios::binary);
    myfile.open(filepath_w, std::ios::binary);
    for (int i = 0; i < 8; i++)
    {
        //calculates 
        r = utili->cal(final[i]) * 16 + utili->cal(final[i + 1]);
        myfile << r;
        i++;
    }

    //////////////////////////
    myfile.close();

}


