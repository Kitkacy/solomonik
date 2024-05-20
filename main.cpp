#include <iostream>
#include "Galois.hpp"
#include "Koder.h"
#include <vector>

int main() {




    Galois a(std::vector<int>{0,1},1);

Koder code;
a=code.codePolynomial(a);
a.wyswietl();
std::string s = code.codetostring(a);
std::cout<<s<<std::endl;
std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;

    int i = code.ASCIItoint03('A');
    int j = code.ASCIItoint48('A');
    std::cout<<i<<std::endl;
    std::cout<<j<<std::endl;

     i = code.ASCIItoint03('B');
     j = code.ASCIItoint48('B');
    std::cout<<i<<std::endl;
    std::cout<<j<<std::endl;

    a=code.ASCIIpairtoPolynomial('A','B');

    a.wyswietl();
    a=code.codePolynomial(a);
    a.wyswietl();
    std::string pol = code.codetostring(a);
    std::cout<<pol<<std::endl;







    return 0;
}
