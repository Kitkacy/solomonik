//
// Created by marci on 01.06.2024.
//

#ifndef SOLOMONIK_NOISE_H
#define SOLOMONIK_NOISE_H


#include <string>

class noise {
public:

    std::string randnoise(std::string input,int bits);
    std::string infnoise(std::string input,int bits);
    std::string correctnoise(std::string input,int bits);
    bool isIn(int* tab, int n, int key);



};


#endif //SOLOMONIK_NOISE_H
