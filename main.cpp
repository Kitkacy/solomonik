#include <iostream>
#include "Galois.hpp"
#include "Koder.h"
#include "Dekoder.h"
#include <vector>

int main() {


    Galois msg = Galois(std::vector<int>{1, 2, 3, 4, 5}, 4);
    Koder code;
    Dekoder decode;
    if(false)
    {


    std::cout << "Wiadomosc" << std::endl;
    msg.wyswietl();


    Galois coded = code.codePolynomial(msg);
    std::cout << std::endl;
    std::cout << "Zakodowana wiadomosc" << std::endl;
    coded.wyswietl();
    std::cout << std::endl;

    Galois received = coded;
    received.wspolczynniki[8] = 255;

    received.wspolczynniki[6] = 255;

    Galois syndrom = decode.syndrom(received);

    std::cout << "Syndrom" << std::endl;
    syndrom.wyswietl();

    Galois repaired = decode.singlerepair(received);

    std::cout << std::endl;
    std::cout << "Naprawiony" << std::endl;
    repaired.wyswietl();

    repaired.Xdodaj(coded);

    std::cout << std::endl;
    std::cout << "XOR" << std::endl;
    repaired.wyswietl();
}


std::string aa = code.code("Carabus coriaceus is a species of beetle widespread in Europe, where it is primarily found in deciduous forests and mixed forests.");
    std::string bb=decode.decode(aa);

    std::cout<<aa<<std::endl;
    std::cout<<bb<<std::endl;


    return 0;
}
