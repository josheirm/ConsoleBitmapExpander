#define _CRT_SECURE_NO_DEPRECATE
#include<iostream> 
#include<string.h> 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <fstream>
#include<sstream>
#include<iomanip>
//#include <bits/stdc++.h> 
using namespace std;

int globallength = 0;
char hexaDeciNum[100];
#include <string>
#include <cstring>
using namespace std;
int hexadecimalToDecimal(char hexVal[]);
int grabfourhexdoubleit();
int GetSizeImageData();
void checkforfourhexdouble();
int cal(char c);

int main()
{
    grabfourhexdoubleit();
    GetSizeImageData();
}


void grabfourhexsaveit()
{

}

int grabfourhexdoubleit() {
   
    FILE* file;
    int index = 0;
    int count = 0;
    int counter = 0;
    char mystring[12];
    mystring[2] = '\0';
    std::string hex1;
    std::string hex2;
    //holds final hex that needs to be reversed
    std::string result;
    //holds characters for reading in the hex file
    char buffer[3] = "";
    buffer[2] = '\0';
    char* pbuf = buffer;
    
    file = fopen("file7z.bmp", "r");
    fseek(file, 0, SEEK_SET);

    //results in hex with spaces saved to mystring, ie : 2 0 0 D0
    do {
       
        int var3 = fgetc(file);
        if (feof(file)) {
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
    int len = strlen(mystring) - 1;
    if (mystring[len] == ' ')
    {
        mystring[len] = '\0';
        len--;
    }
    else
    {
        mystring[len + 1] = '\0';
    }
    // creates hex one an hex two strings - reverses mystring
    // hex one has no spaces, hex 2 has spaces
    int flag = 0;
    for (int i = len; i > -10; i--)
    {
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
        //////////////

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
    
        //josh: check these two : does string take care of this elsewhere?
        int len2 = hex2.length();
        len2 = len2 - 1;
        hex2.resize(len2 - 1);
        hex2 = hex2 + '\0';

        len2 = hex1.length();
        //len2 = len2 - 2;
        hex1.resize(len2 - 1);
        hex1 = hex1 + '\0';

        fclose(file);
        
        char* cstr = new char[hex2.length() + 1];
        std::strcpy(cstr, hex2.c_str());
        int decimal = hexadecimalToDecimal(cstr);
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
            final[i] = result[j-1];
            final[i+1] = result[j];
            i++;
            j--;
        }
        final[8] = '\0';

        //////////////////
        ///exception being called in here, this is for trying to create
        ///this function in c - global funnctions declerations removed
        /////////////////
        //count = 4;
       
        //////////////////////////////////
        ////reverse each element first.
        ////////////////////////////////
        //int count2 = 0;
        //
        //char hexaDeciNum1[100];
        //int i = 0;
        ////consider
        //for ( i = 0; i < hex2.length()-1 ; i++)
        //{
        //    hexaDeciNum[i] = *(&hex2[i]);
        //}
        //hexaDeciNum[i] = '\0';
        //hexaDeciNum1[i] = '\0';
        //for (int i = 0, k = len2-1 ; k>=0 ; )

        //{
        //    //single element 0 - F
        //    if (hexaDeciNum[i] == ' ')
        //    {
        //        hexaDeciNum1[k-1] = hexaDeciNum[i + 1];
        //        hexaDeciNum1[k] = ' ';
        //        
        //        k = k - 2;
        //        i = i + 2;
        //    }
        //    //double digit
        //    else
        //    {
        //        hexaDeciNum1[k-1] = hexaDeciNum[i];
        //        hexaDeciNum1[k] = hexaDeciNum[i+1];
        //        hexaDeciNum1[k - 2] = ' ';
        //        k = k - 2;
        //        i = i + 2;
        //    }
        //    
        //}
        /////how many zeros needed
        /////////////////////////
        //int lastpos = 0;
        //int mycount = 0;
        //for (int i = 0; i < 100; i++)
        //{
        //    if (hexaDeciNum1[i] == '\0')
        //    {
        //        lastpos = i;
        //        break;
        //    }
        //    else if(hexaDeciNum[i] == ' ')
        //    {
        //        mycount++;
        //    }
        //}
        //int numzerosneeded = 3 - mycount;

        //////////////////////////////
        //// add zeros
        ////////////////////////////
        //for (int i = 0; i < numzerosneeded; i++)
        //{
        //    hexaDeciNum1[lastpos] = '0';
        //    lastpos++;
        //}
        //hexaDeciNum1[lastpos] = '\0';

        //char hexaDeciNum2[9] = { 0,0,0,0,0,0,0,0 };
        //hexaDeciNum2[8] = '\0';
        //
        ////remove spaces
        //for (int i = 0, j = 0; i < 100; )
        //{
        //    if (hexaDeciNum1[i] == ' ')
        //    {
        //        i++;
        //      
        //    }
        //    else if (hexaDeciNum1[i] == '\0')
        //    {
        //        break;
        //    }
        //    else
        //    {   
        //        hexaDeciNum2[j] = hexaDeciNum1[i];
        //        j++;
        //        i++;
        //    }
        //}
        //
        //char hexaDeciNum3[9] = { 0,0,0,0,0,0,0,0 };
        //hexaDeciNum3[8] = '\0';
        //
        ////double the zeros
        //int count3 = 0;
        //
        //for (int i = 0, j = 0; i < 100;)
        //{
        //    hexaDeciNum3[i] = hexaDeciNum2[j];
        //    if (hexaDeciNum3[i] == '0')
        //    {
        //        hexaDeciNum3[i + 1] = '0';
        //        i = i + 1;
        //    }
        //    
        //    else if (hexaDeciNum2[i] == '\0')
        //    {
        //        break;
        //    }
        //    j++;
        //    i++;
        //}

        //value = 1;
        //char* cstr1 = new char[result.length() + 1];
        //std::strcpy(cstr1, result.c_str());
        //char holder[9] = "";
        //for (int i = 0; i < 8; i++)
        //{
        //    holder[i] = cstr1[i];
        //}
        char r;
        //writes to file
        ofstream myfile;
        myfile.open("C:/Users/joshe/file7a.bmp", ios::binary);  
        for (int i = 0; i < 8; i++)
        {
            //calculates 
            r = cal(final[i]) * 16 + cal(final[i+1]);
            myfile << r;
            i++;
         }
        
        myfile.close();
        return(1);
 }

/////////////////////////////
int hexadecimalToDecimal(char hexVal[])
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

//utility, displays hex and size. 
int GetSizeImageData()
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


int cal(char c)
{
    int h = 0;
    if (c <= '9' && c >= '0') return c - '0';
    if (c <= 'f' && c >= 'a') return c - 'a' + 10;
    if (c <= 'F' && c >= 'A') return c - 'A' + 10;
    return(1);
}

