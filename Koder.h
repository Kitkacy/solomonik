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

    Galois ASCIItoPolynomial(char a);




};


#endif //SOLOMONIK_KODER_H
