#ifndef __Galois_H__
#define __Galois_H__

#include <vector>

class Galois
{
public:
    std::vector<int> wspolczynniki;
    std::vector<int> wartosci;
    int stopien;


    Galois(const std::vector<int> &wspolczynniki, int stopien); // Konstruktor
    Galois(); // Konstruktor domyślny, inicjalizuje współczynniki zerami
    ~Galois();
    Galois& operator=(const Galois &g);
    void wypisz();
    void wyswietl();             // Wyświetla wielomian
    void Xpomnoz(const Galois &g);
    void dodaj(const Galois &w);
    void Xdodaj(const Galois &g);   // Dodaje dwa wielomiany
    void odejmij(const Galois &w); // Odejmuje dwa wielomiany
    void pomnoz(const Galois &w); // Mnoży dwa wielomiany, wynik zapisuje w obiekcie wywołującym
    void podziel(const Galois &dzielnik, Galois &reszta); // Dzieli dwa wielomiany, wynik zapisuje w obiekcie wywołującym, resztę w obiekcie przekazanym jako argument

    void scale(int k);
    void singlemul(int w, int k);


    Galois Xpodziel(const Galois &g);

    Galois XXpodziel(const Galois &g);

    void minimalize();


};

#endif // __Galois_H__