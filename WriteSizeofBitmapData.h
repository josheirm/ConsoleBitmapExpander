#pragma once


class WriteSizeofBitmapData
{
public:
    char buffer[3];
    char* pbuf;
    char mystring[12];

    WriteSizeofBitmapData();
    void getstringandsave(char filepath1[], char filepath2[], utilities* util);
};
