//
// Created by marci on 01.06.2024.
//

#include <ctime>
#include <iostream>
#include "noise.h"

std::string noise::randnoise(std::string input, int bits){

    std::string output = input;
    int len = input.length();
    int* list = new int[bits];

    srand( time( NULL ) );

    for(int i=0;i<bits;i++)
    {
        int r = rand()%len;
        list[i]=r;

        while(isIn(list,i,r))
        {
            r = rand()%len;
            list[i]=r;
        }

        if(output[r]=='1')
        {
            output[r]='0';
        }
        if(output[r]=='1')
        {
            output[r]='0';
        }

    }


return output;
};

std::string noise::infnoise(std::string input, int bits){

    std::string output = input;
    int len = input.length();
    int* list = new int[bits];

    srand( time( NULL ) );

    for(int i=0;i<bits;i++)
    {
        int r = rand()%20;
        list[i]=r;

        while(isIn(list,i,r))
        {
            r = rand()%20;
            list[i]=r;
        }
        if(output[r]=='1')
        {
            output[r]='0';
        }
        if(output[r]=='1')
        {
            output[r]='0';
        }

    }


    return output;
};

std::string noise::correctnoise(std::string input, int bits){

    std::string output = input;
    int len = input.length();
    int* list = new int[bits];

    srand( time( NULL ) );

    for(int i=0;i<bits;i++)
    {
        int r = rand()%40+20;
        list[i]=r;

        while(isIn(list,i,r))
        {
            r = rand()%40+20;
            list[i]=r;
        }
        if(output[r]=='1')
        {
            output[r]='0';
        }
        if(output[r]=='1')
        {
            output[r]='0';
        }

    }


    return output;
};

bool noise::isIn(int *tab, int n, int key) {

    bool is = false;

    for(int i=0;i<n;i++)
    {
        if(tab[i]==key)
        {
            is=true;
        }
    }

    return is;
}
