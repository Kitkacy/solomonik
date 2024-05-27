 //
// Created by marci on 20.05.2024.
//

#ifndef SOLOMONIK_DEKODER_H
#define SOLOMONIK_DEKODER_H


#include "Galois.hpp"

 class Dekoder {
 public:
     Galois generator;

     Dekoder();

     Galois decodepol(const Galois &word);
     Galois syndrom(const Galois &word);
     Galois singlerepair(const Galois &word);

};


#endif //SOLOMONIK_DEKODER_H
