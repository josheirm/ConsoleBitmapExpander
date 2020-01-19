#define _CRT_SECURE_NO_DEPRECATE
#include<iostream> 
#include<string.h> 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <fstream>
//#include <bits/stdc++.h> 
using namespace std;

int globallength = 0;
char hexaDeciNum[100];
#include <string>
#include <cstring>
using namespace std;

char* decToHexa(int n);
int hexadecimalToDecimal(char hexVal[]);
int grabfourhexdoubleit();
int GetSizeImageData();
void checkforfourhexdouble();
int cal(char c);

//must be : (needs second digit)
//01, 02, 03, 04, 05 , 06, 07 , 08, 09, A B C D E F
char s[] = "FFFFFFFF\0";
char r;
string tester = "FF01";
int main()
{
   

    //file = fopen("C:/Users/joshe/file7", "r");
   
   
    //char buffer7[BUFF] =
    //{ 0x4D,0x54,0x68,0x64,0x00,0x00,0x00,0x06,0x00,0x01,0x00,0x01,0x00,0x80,0x4D,0x54,0x72,0x6B,0x00,0x00,0x00,0x16,0x80,0x00,0x90,0x3C,0x60,0x81,0x00,0x3E,0x60,0x81,0x00,0x40,0x60,0x81,0x00,0xB0,0x7B,0x00,0x00,0xFF,0x2F,0x00 };


    //char s[] = "FE";
    //char r;
    //FILE * file;
    //freopen("C:/Users/joshe/file7", "wb+", file);// every thing you output to stdout will be outout to x.dat.
    //r = cal(s[0]) * 16 + cal(s[1]);
    ////print2(r);the binary code of r is　"1111 1110"
    //cout << r;//Then you can open the x.dat with any hex editor, you can see it is "0xFE" in binary
    ////freopen("CON", "w", stdout); // back to normal
    ////cout << 1;// you can see '1' in the stdout.
    ////return(1);
    //fclose(stdout);

    //return(1);
    grabfourhexdoubleit();
    GetSizeImageData();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

void grabfourhexsaveit()
{

}

int grabfourhexdoubleit() {
   

    
    FILE* file;
   
    int index = 0;
    int count = 0;
    char mystring[100];
    mystring[2] = '\0';
    std::string hex1;
    //std::string hex2;
    std::string newhex;
    std::string hexbuffer;
    char* hexbuffer2;
    char bufferb[100];
    char buffer_1[100];
    //hexbuffer[4] = '\0';
    
    int counter = 0;
    char buffer[50] = "";
    //char hexbuffer[50] = "";
    char* pbuf = buffer;

    //std::ofstream myfile;
    //myfile.open("C:/Users/joshe/file7", std::ios::binary);
    file = fopen("b.bmp", "r");
    fseek(file, 18, SEEK_SET);
    //if (fgetc(mystring, 100, file) != NULL)
    
    do {
        //hex with spaces saved to mystring : 2 0 0 D0
        int var3 = fgetc(file);
        if (feof(file)) {
            break;
        }
        //to make a generic function
        if (counter == 4)
        {
            break;
        }
        counter++;
        //char pbuf;
        //saves all as hex to mystring from pbuf->buffer
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
    
    //removes all zeros so that I can double its decimal
    for (int i = 0; i < 100; i++)
    {
        //seperate zero
        if (mystring[i] == '0' && mystring[i+1] == ' ')
        {
            
                //hex2 = hex2 + "  ";
                //hex1 = hex1 + "0 ";
                count++;
                i++;
            
        }

        //one character
        else if (mystring[i+1] == ' ')
        {

            hex1 = hex1 + mystring[i];
            //hex2 = hex1 = hex1 + ' ';
            i++;
            count++;
           
            
        }
        // double digit
        else
        {
            count++;
            hex1 = hex1 + mystring[i] + mystring[i + 1] ;
            i = i + 2;
        }
            


            
            if (count == 4)
            {
                break;
            }
            
        }
    
         
        fclose(file);
        char* cstr = new char[hex1.length() + 1];
        std::strcpy(cstr, hex1.c_str());

        //finds decimal input doesn't have zeros 
        int decimal = hexadecimalToDecimal(cstr);
        //new decimal value now get the hex
        decimal = decimal * 2;
        
        int amountofcharacters;
        char* pnewhex; 
        //sets hexaDeciNum without trailing zeros
        decToHexa(decimal);
        
        count = 4;


        //// 
        //adds trailing zeros to hex so that next function
        //can make buffer of 0x values for bitmap stream
        for (int i = 0; i <= 10; i++)
        {
           
            if (count == 0)
            {
                break;
            }

            //next element
            if (hexaDeciNum[i] == ' ')
            {   
                count--;
                
            }
            //set memset
            else if (hexaDeciNum[i] == '\0' && hexaDeciNum[i + 1 == '\0'])
            {
                for (int i = 0; i < count-1; i++)
                {
                    newhex = newhex + "0 ";
                }
                //count++;
                //i++;
                break;
            }
            else
            {
                newhex = newhex + hexaDeciNum[i] + " ";
               
            }
            

        }
        //put this pointer into an indexed array for usage
       // int len = newhex.length();
       // for (int i = 0; i < (len - 1); i++)
       // {
       //     hexaDeciNum[i] = *(&newhex[i]);
       // }

        ////

        ////////////////////////////////////////
        //fill hex buffer with hex myfile<< stream values for streaming to bitmap file like : FF0A0FF
        ////////////////////////////////////////
        index = 0;
        count = 0;
        for (int i = 0; i <= 100; i++)
        {
            if (count == 4)
            {
                break;
            }
            //write to bitmap file (has zeros 0x ...)
            if (newhex[i] == '0' && newhex[i + 1] == ' ')
            {
               
                //std::string value1 = "0x";
                hexbuffer = hexbuffer + "00";
                index++;
                i++;
                count++;
               
            }

            //////
            //singal digit
            else if (newhex[i + 1] == ' ')
            {


                hexbuffer = hexbuffer + "0" + newhex[i];
                
                index++;
                i++;
                count++;
                

            }
            //double digit
            else
            {
                /////////
                hexbuffer = hexbuffer + newhex[i] + newhex[i+1];
                
                index++;
                i = i + 2;
                count++;
            }
        
            
        }
        

        //string hexbuffer
        char str[20 + 1];
        ////char 
        //strcpy(s, tester.c_str());
        int leng = strlen(s);
        str[leng] = '\0';
        //cout << hex<< str << '\n';

        
        char* cstr1 = new char[hexbuffer.length() + 1];
        std::strcpy(cstr1, hexbuffer.c_str());
        
        ofstream myfile;
        myfile.open("C:/Users/joshe/file7", ios::binary);  
        //myfile<<"4D";
        
        for (int i = 0; i < 8; i++)
        {
            r = cal(hexbuffer[i]) * 16 + cal(hexbuffer[i+1]);
            myfile << r;
            i++;
            //r = cal(s[2]) * 16 + cal(s[3]);
            //myfile << r;
        }
        
        myfile.close();
        return(1);

      

     }
        

/////////////////////////////
/////////////////////////////

// function to convert decimal to hexadecimal 
char* decToHexa(int n)
{
    // char array to store hexadecimal number 
    //char hexaDeciNum[100];
    //char* hexaDeciNum = new char[100];

    // counter for hexadecimal number array 
    int i = 0;
    while (n != 0)
    {
        // temporary variable to store remainder 
        int temp = 0;

        // storing remainder in temp variable. 
        temp = n % 16;

        // check if temp < 10 
        if (temp < 10)
        {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else
        {
            hexaDeciNum[i] = temp + 55;
            i++;
        }

        n = n / 16;
    }


    globallength = i;
    char* stringA;

    // printing hexadecimal number array in reverse order 
    int k = 0;
    for (int j = i - 1; j >= 0; j--, k++)
    {
        hexaDeciNum[k] = hexaDeciNum[j];
    }

    ///
    //hexaDeciNum[k] = ' ';
   
    hexaDeciNum[k] = '\0';
    ///
    return (hexaDeciNum);
}

int hexadecimalToDecimal(char hexVal[])
{
    int len = strlen(hexVal);

    // Initializing base value to 1, i.e 16^0 
    int base = 1;

    int dec_val = 0;

    // Extracting characters as digits from last character 
    //for (int i = len - 1 ; i >= 0; i--)
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


int GetSizeImageData()
{
    FILE* file;
    int i;
    int counter = 0;
    //char buf[27];
    file = fopen("C:/Users/joshe/file7", "r");
    //for (i = 0; i < 1478; i++)
    //fseek(file, 0, SEEK_SET);
    do {



        i = fgetc(file);
        if (feof(file)) {
            fclose(file);
            break;
        }
        counter++;
        //4 bytes * 54 = 
        printf("%x ", i);

    } while (1);

    int check = sizeof(unsigned int);
    printf("size is: %d", counter);
    //fclose(file);
    int ans = remove("C:/Users/joshe/file7");
    return(counter);
}


int cal(char c)// cal the coresponding value in hex of ascii char c
{
    int h = 0;
    if (c <= '9' && c >= '0') return c - '0';
    if (c <= 'f' && c >= 'a') return c - 'a' + 10;
    if (c <= 'F' && c >= 'A') return c - 'A' + 10;
    return(1);
}

