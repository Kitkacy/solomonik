//
// Created by marci on 01.06.2024.
//

#include <iostream>
#include "Tester.h"
#include "Koder.h"
#include "Dekoder.h"
#include "noise.h"

void Tester::testrand(int bits, int n,std::string msg) {

    Koder code;
    Dekoder decode;
    noise noise;
    int errors=0;
    float percent;

    for(int i=0;i<n;i++)
    {
        std::string input = code.code(msg);
        input = noise.randnoise(input,bits);
        std::string output = decode.decode(input);

        if(output!=msg)
        {
            errors++;
        //    std::cout<<"Blad w iteracji "<<i<<std::endl;
         //   std::cout<<output<<std::endl;
        }


    }

    percent = (float)(n-errors)/(float)n;
    std::cout<<"Bledy:"<<errors<<std::endl;
    std::cout<<"Procent poprawnych transmisji:"<<percent*100<<"%"<<std::endl;



}
void Tester::testinf(int bits, int n,std::string msg) {

    Koder code;
    Dekoder decode;
    noise noise;
    int errors=0;
    float percent;

    for(int i=0;i<n;i++)
    {
        std::string input = code.code(msg);
        input = noise.infnoise(input,bits);
        std::string output = decode.decode(input);

        if(output!=msg)
        {
            errors++;
            //    std::cout<<"Blad w iteracji "<<i<<std::endl;
            //   std::cout<<output<<std::endl;
        }


    }

    percent = (float)(n-errors)/(float)n;
    std::cout<<"Bledy:"<<errors<<std::endl;
    std::cout<<"Procent poprawnych transmisji:"<<percent*100<<"%"<<std::endl;



}
void Tester::testcorrect(int bits, int n, std::string msg) {

    Koder code;
    Dekoder decode;
    noise noise;
    int errors=0;
    float percent;

    for(int i=0;i<n;i++)
    {
        std::string input = code.code(msg);
        input = noise.correctnoise(input,bits);
        std::string output = decode.decode(input);

        if(output!=msg)
        {
            errors++;
            //    std::cout<<"Blad w iteracji "<<i<<std::endl;
            //   std::cout<<output<<std::endl;
        }


    }

    percent = (float)(n-errors)/(float)n;
    std::cout<<"Bledy:"<<errors<<std::endl;
    std::cout<<"Procent poprawnych transmisji:"<<percent*100<<"%"<<std::endl;



}

void Tester::testrandS(int symbols, int n, std::string msg) {

    int errors=0;
    noise noise;

    srand( time( NULL ) );
    Koder code;
    Dekoder decode;
    int* list = new int[symbols];

    for(int j=0;j<n;j++) {

        std::string coded = code.code(msg);

        Galois codedpoly = decode.stringtopol(coded);
        Galois original = codedpoly;
        //  codedpoly.wyswietl();

        for (int i = 0; i < symbols; i++) {

            int r = rand() % 15;
            list[i]=r;
            while(noise.isIn(list,i,r))
            {
                r = rand() % 15;
                list[i]=r;
            }


            codedpoly.wspolczynniki[r] = codedpoly.wspolczynniki[r]+1;
        }



        // decoded.wyswietl();

        std::string in = code.codetostring(codedpoly);

        std::string out = decode.decode(in);

        if (msg != out) {
            errors++;
        }

    }

    float percent = (float)(n-errors)/(float)n;
    std::cout<<"Bledy:"<<errors<<std::endl;
    std::cout<<"Procent poprawnych transmisji:"<<percent*100<<"%"<<std::endl;


}

void Tester::testinfS(int symbols, int n, std::string msg) {

    int errors=0;
    noise noise;

    srand( time( NULL ) );
    Koder code;
    Dekoder decode;
    int* list = new int[symbols];

    for(int j=0;j<n;j++) {

        std::string coded = code.code(msg);

        Galois codedpoly = decode.stringtopol(coded);
        Galois original = codedpoly;
        //  codedpoly.wyswietl();

        for (int i = 0; i < symbols; i++) {

            int r = rand() % 5;
            list[i]=r;
            while(noise.isIn(list,i,r))
            {
                r = rand() % 5;
                list[i]=r;
            }


            codedpoly.wspolczynniki[r] = codedpoly.wspolczynniki[r]+1;
        }



        // decoded.wyswietl();

        std::string in = code.codetostring(codedpoly);

        std::string out = decode.decode(in);

        if (msg != out) {
            errors++;
        }

    }

    float percent = (float)(n-errors)/(float)n;
    std::cout<<"Bledy:"<<errors<<std::endl;
    std::cout<<"Procent poprawnych transmisji:"<<percent*100<<"%"<<std::endl;


}
void Tester::testcorrectS(int symbols, int n, std::string msg) {

    int errors=0;
    noise noise;

    srand( time( NULL ) );
    Koder code;
    Dekoder decode;
    int* list = new int[symbols];

    for(int j=0;j<n;j++) {

        std::string coded = code.code(msg);

        Galois codedpoly = decode.stringtopol(coded);
        Galois original = codedpoly;
        //  codedpoly.wyswietl();

        for (int i = 0; i < symbols; i++) {

            int r = rand() % 10 +5;
            list[i]=r;
            while(noise.isIn(list,i,r))
            {
                r = rand() % 10 + 5;
                list[i]=r;
            }


            codedpoly.wspolczynniki[r] = codedpoly.wspolczynniki[r]+1;
        }



        // decoded.wyswietl();

        std::string in = code.codetostring(codedpoly);

        std::string out = decode.decode(in);

        if (msg != out) {
            errors++;
        }

    }

    float percent = (float)(n-errors)/(float)n;
    std::cout<<"Bledy:"<<errors<<std::endl;
    std::cout<<"Procent poprawnych transmisji:"<<percent*100<<"%"<<std::endl;


}