//
// Created by marci on 20.05.2024.
//

#include <iostream>
#include "Dekoder.h"
Dekoder::Dekoder() {
    generator =Galois(std::vector<int>{10 ,1 ,6, 1, 2, 14, 6 ,9, 3, 2, 0},10);

}

Galois Dekoder::syndrom(const Galois &word) {

Galois r=word;

r=r.XXpodziel(generator);

r.minimalize();

return r;
}

Galois Dekoder::singlerepair(const Galois &word) {

    Galois repaired = word;
    Galois syndromx = syndrom(word);

    int licznik=0;///waga hamminga
    for(int i=0;i<syndromx.stopien+1;i++)
    {
        if(syndromx.wspolczynniki[i]!=255)
        {

            licznik++;
        }
    }
    if(licznik<5)
    {
        repaired.Xdodaj(syndromx);
    }


    return repaired;
}