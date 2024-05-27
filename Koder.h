//
// Created by marci on 13.05.2024.
//

#ifndef SOLOMONIK_KODER_H
#define SOLOMONIK_KODER_H


#include "Galois.hpp"
#include <vector>

class Koder {

public:
    Galois generator;
    Koder();

    Galois codePolynomial( const Galois &msg);
    std::string codetostring(const Galois &msg);
    int ASCIItoint03(char a);
    int ASCIItoint48(char a);
    Galois ASCIIpairtoPolynomial(char a, char b);

   std::string code(std::string msg);




};


#endif //SOLOMONIK_KODER_H
