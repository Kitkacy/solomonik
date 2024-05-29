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


     Galois syndrom(const Galois &word);
     Galois singlerepair(const Galois &word);

     Galois decodepol(const Galois &word);
     Galois getmsg(const Galois &word);
     std::string msgtoASCII(const Galois &word);
     Galois stringtopol(std::string msg);

     std::string decode(std::string msg);


};


#endif //SOLOMONIK_DEKODER_H
