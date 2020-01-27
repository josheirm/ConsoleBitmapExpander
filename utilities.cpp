#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "utilities.h"
#include "DoubleValueAndSave.h"
#include <fstream>
#include <string>

//using namespace std;

utilities::utilities(void)
{
    mystring[11] = '\0';
    len = 0;
    //object2 = NULL;
    buffer[2] = '\0';
    pbuf = buffer;
    //object2 = object1;
}
/////////////////////////////
int utilities::hexadecimalToDecimal(char hexVal[])
{
    int len = strlen(hexVal);

    // Initializing base value to 1, i.e 16^0 
    int base = 1;

    int dec_val = 0;

    // Extracting characters as digits from last character 
    for (int i = len - 1; i >= 0; i--)

    {
        // if character lies in '0'-'9', converting  
        // it to integral 0-9 by subtracting 48 from 
        // ASCII value. 
        if (hexVal[i] >= '0' && hexVal[i] <= '9')
        {
            dec_val += (hexVal[i] - 48) * base;

            // incrementing base by power 
            base = base * 16;
        }

        // if character lies in 'A'-'F' , converting  
        // it to integral 10 - 15 by subtracting 55  
        // from ASCII value 
        else if (hexVal[i] >= 'A' && hexVal[i] <= 'F')
        {
            dec_val += (hexVal[i] - 55) * base;

            // incrementing base by power 
            base = base * 16;
        }
    }

    return dec_val;
}

int utilities::cal(char c)
{
    int h = 0;
    if (c <= '9' && c >= '0') return c - '0';
    if (c <= 'f' && c >= 'a') return c - 'a' + 10;
    if (c <= 'F' && c >= 'A') return c - 'A' + 10;
    return(1);
}

int utilities::GetSizeImageData()
{
    {
        FILE* file;
        int i;
        int counter = 0;

        file = fopen("C:/Users/joshe/file7a.bmp", "r");

        do {

            i = fgetc(file);
            if (feof(file)) {
                fclose(file);
                break;
            }
            counter++;

            printf("%x ", i);

        } while (1);

        int check = sizeof(unsigned int);
        printf("size is: %d", counter);
        return(counter);
    }

}

void utilities::reversestring(void)
{

    // creates hex one an hex two strings - reverses mystring
    // hex one has no spaces, hex 2 has spaces
    int flag = 0;
    for (int i = len; i > -10; i--)
    {
        //added
        int count = 0;
        int counter = 0;

        //right hand side zero
        if (mystring[i] == '0' && flag == 0)
        {
            i--;
            count++;

        }//left hand side zero 
        else if (mystring[i] == '0')
        {
            hex1 = hex1 + '0';
            hex2 = hex2 + "0 ";
            i--;
            count++;
        }
       
        //one character
        else if (mystring[i - 1] == ' ')
        {
            flag = 1;
            hex1 = hex1 + mystring[i];
            hex2 = hex2 + mystring[i] + ' ';
            i--;
            count++;
        }
        // double digit
        else
        {
            flag = 1;
            count++;
            hex1 = hex1 + mystring[i] + mystring[i - 1];
            hex2 = hex2 + mystring[i] + mystring[i - 1] + " ";
            i = i - 2;
        }

        if (count == 4)
        {
            break;
        }

    }
    int len2 = hex2.length();
    len2 = len2 - 1;
    hex2.resize(len2 - 1);
    hex2 = hex2 + '\0';
    len2 = hex1.length();
    //len2 = len2 - 2;
    hex1.resize(len2 - 1);
    hex1 = hex1 + '\0';
}

/////

/////

    /////
    void utilities::readinfile(void)
    {
        FILE * file;
        file = fopen("file7z.bmp", "r");
        do {
            //added
            int counter = 0;
            int var3 = fgetc(file);
            if (feof(file)) {
                fclose(file);
                break;
            }
            counter++;

            if (counter == 5)
            {
                break;
            }


            sprintf(pbuf, "%X", var3);



            if (counter == 1)
            {
                strcpy(mystring, pbuf);
            }
            else
            {
                strcat(mystring, pbuf);
            }


            strcat(mystring, " ");

        } while (1);

        //adds null terminator
        len = strlen(mystring) - 1;
        if (mystring[len] == ' ')
        {
            mystring[len] = '\0';
            len--;
        }
        else
        {
            mystring[len + 1] = '\0';
        }
    }

    ////
