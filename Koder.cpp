//
// Created by marci on 13.05.2024.
//

#include <string>
#include <bitset>
#include <iostream>
#include "Koder.h"
#include "Galois.hpp"

Koder::Koder() {
    generator =Galois(std::vector<int>{10 ,1 ,6, 1, 2, 14, 6 ,9, 3, 2, 0},10);

}

Galois Koder::codePolynomial( const Galois &msg) {


    Galois C;
    Galois M = msg;


    M.scale(10);
    M.XXpodziel(generator);

    C=msg;
    C.scale(10);
    C.Xdodaj(M);




return C;

}


Galois Koder::ASCIItoPolynomial(char a){


    Galois g;
    g.wspolczynniki.resize(5);

    int b = int(a);

    std::string s=std::bitset<8>(a).to_string();
   //////////


    return g;
}