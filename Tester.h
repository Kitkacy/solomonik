//
// Created by marci on 01.06.2024.
//

#ifndef SOLOMONIK_TESTER_H
#define SOLOMONIK_TESTER_H


#include <string>

class Tester {
public:
    void testrand(int bits, int n,std::string msg);
    void testinf(int bits, int n,std::string msg);
    void testcorrect(int bits, int n,std::string msg);

    void testrandS(int symbols, int n, std::string msg);


};


#endif //SOLOMONIK_TESTER_H
