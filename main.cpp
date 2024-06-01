#include <iostream>
#include "Galois.hpp"
#include "Koder.h"
#include "Dekoder.h"
#include "noise.h"
#include "Tester.h"
#include <vector>

int main() {


    Galois msg = Galois(std::vector<int>{1, 2, 3, 4, 5}, 4);
    Koder code;
    Dekoder decode;
    if (false) {


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


    Tester test;
    test.testrandS(5, 100, "AB");
}