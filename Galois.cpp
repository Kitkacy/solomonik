#include "Galois.hpp"
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

Galois::Galois(const std::vector<int> &wspolczynniki, int stopien)
        : wspolczynniki(wspolczynniki), stopien(stopien) {}

Galois::Galois() : wspolczynniki({255}), stopien(0) {}

Galois& Galois::operator=(const Galois &g) {
    if (this != &g) { // protect against invalid self-assignment
        this->wspolczynniki = g.wspolczynniki;
        this->stopien = g.stopien;
    }
    // by convention, always return *this
    return *this;
}

void Galois::wyswietl()
{
    stringstream ss;
    for (int i = stopien; i >= 0; --i)
    {

        ss << "a^" << wspolczynniki[i] << "*x^" << i; // Wyświetl "a^", współczynnik i x do potęgi i

        if (i > 0)
        {
            ss << " + "; // Dodaj znak plus, jeśli stopień jest większy od zera
        }
    }
    cout << ss.str() << endl; // Wyświetl wynik
}

void Galois::Xpomnoz(const Galois &g)
{
    Galois wynik;
    wynik.stopien = stopien + g.stopien;
    wynik.wspolczynniki.resize(wynik.stopien + 1, 255);

    for (int i = 0; i <= stopien; i++)
    {
        Galois pojedynczy_wynik;
        pojedynczy_wynik.stopien = i + g.stopien;
        pojedynczy_wynik.wspolczynniki.resize(pojedynczy_wynik.stopien + 1, 255);

        for (int j = 0; j <= g.stopien; j++)
        {
            if (wspolczynniki[i] == 255 && g.wspolczynniki[j] == 255)
            {
                pojedynczy_wynik.wspolczynniki[i + j] = 255;
            }
            else if (wspolczynniki[i] == 255 || g.wspolczynniki[j] == 255)
            {
                pojedynczy_wynik.wspolczynniki[i + j] = 255;
            }
            else
            {
                pojedynczy_wynik.wspolczynniki[i + j] = wspolczynniki[i] + g.wspolczynniki[j];
            }
        }
  ///      pojedynczy_wynik.wyswietl();
        wynik.Xdodaj(pojedynczy_wynik);
    }

    *this = wynik;
}

void Galois::dodaj(const Galois &w)
{
    int maxStopien = max(stopien, w.stopien);                 // Znajdź stopień wielomianu będącego sumą dwóch wielomianów
    std::vector<double> noweWspolczynniki(maxStopien + 1, 0); // Utwórz wektor, w którym będą przechowywane nowe współczynniki

    // Dodaj współczynniki wielomianów
    for (int i = 0; i <= maxStopien; ++i)
    {
        if (i <= stopien)
            noweWspolczynniki[i] += wspolczynniki[i]; // Dodaj współczynnik z pierwszego wielomianu, jeśli istnieje
        if (i <= w.stopien)
            noweWspolczynniki[i] += w.wspolczynniki[i]; // Dodaj współczynnik z drugiego wielomianu, jeśli istnieje
    }

    std::copy(noweWspolczynniki.begin(), noweWspolczynniki.end(), wspolczynniki.begin()); // Skopiuj nowe współczynniki do wektora współczynników

    stopien = maxStopien; // Ustaw nowy stopień
}

void Galois::Xdodaj(const Galois &g)
{
    int maxStopien = max(stopien, g.stopien);
    if (g.stopien > stopien)
    {
        wspolczynniki.resize(g.stopien + 1, 255);
        stopien = g.stopien;
    }

    std::map<int, int> bin_map = {{0, 0b0001}, {1, 0b0010}, {2, 0b0100}, {3, 0b1000}, {4, 0b0011}, {5, 0b0110}, {6, 0b1100}, {7, 0b1011}, {8, 0b0101}, {9, 0b1010}, {10, 0b0111}, {11, 0b1110}, {12, 0b1111}, {13, 0b1101}, {14, 0b1001}, {255, 0b0000}};
    std::map<int, int> rev_bin_map = {{0b0001, 0}, {0b0010, 1}, {0b0100, 2}, {0b1000, 3}, {0b0011, 4}, {0b0110, 5}, {0b1100, 6}, {0b1011, 7}, {0b0101, 8}, {0b1010, 9}, {0b0111, 10}, {0b1110, 11}, {0b1111, 12}, {0b1101, 13}, {0b1001, 14}, {0b0000, 255}};

    for (int i = 0; i <= maxStopien; i++)
    {
        int bin1 = 0, bin2 = 0;

        if (i <= stopien)
        {
            if (wspolczynniki[i] >= 15 && wspolczynniki[i] != 255)
            {
                bin1 = bin_map[wspolczynniki[i] % 15];
            }
            else if (wspolczynniki[i] < 15)
            {
                bin1 = bin_map[wspolczynniki[i]];
            }
            else if (wspolczynniki[i] == 255)
            {
                bin1 = bin_map[255];
            }
        }
        if (i <= g.stopien)
        {
            if (g.wspolczynniki[i] >= 15 && g.wspolczynniki[i] != 255)
            {
                bin2 = bin_map[g.wspolczynniki[i] % 15];
            }
            else if (g.wspolczynniki[i] < 15)
            {
                bin2 = bin_map[g.wspolczynniki[i]];
            }
            else if (g.wspolczynniki[i] == 255)
            {
                bin2 = bin_map[255];
            }
        }

        int xor_result = bin1 ^ bin2;
        wspolczynniki[i] = rev_bin_map[xor_result];
    }
    stopien = maxStopien;

}

void Galois::odejmij(const Galois &w)
{
    int maxStopien = max(stopien, w.stopien);              // Znajdź stopień wielomianu będącego różnicą dwóch wielomianów
    std::vector<int> noweWspolczynniki(maxStopien + 1, 0); // Stwórz wektor, w którym będą przechowywane nowe współczynniki

    // Odejmij współczynniki wielomianów
    for (int i = 0; i <= maxStopien; ++i)
    {
        if (i <= stopien)
            noweWspolczynniki[i] += wspolczynniki[i]; // Dodaj współczynnik z pierwszego wielomianu, jeśli istnieje
        if (i <= w.stopien)
            noweWspolczynniki[i] -= w.wspolczynniki[i]; // Odejmij współczynnik z drugiego wielomianu, jeśli istnieje
    }

    std::copy(noweWspolczynniki.begin(), noweWspolczynniki.end(), wspolczynniki.begin()); // Skopiuj nowe współczynniki do wektora współczynników

    stopien = maxStopien; // Ustaw nowy stopień
}

void Galois::pomnoz(const Galois &w)
{
    int nowyStopien = stopien + w.stopien;                  // Oblicz nowy stopień wynikowego wielomianu
    std::vector<int> noweWspolczynniki(nowyStopien + 1, 0); // Utwórz wektor, w którym będą przechowywane nowe współczynniki

    // Pomnóż współczynniki wielomianów
    for (int i = 0; i <= stopien; ++i)
    {
        for (int j = 0; j <= w.stopien; ++j)
        {
            noweWspolczynniki[i + j] += wspolczynniki[i] * w.wspolczynniki[j]; // Dodaj iloczyn współczynników do odpowiedniego indeksu wektora nowych współczynników
        }
    }

    // Skopiuj nowe współczynniki do wektora współczynników
    for (int i = 0; i <= nowyStopien; ++i)
    {
        wspolczynniki[i] = noweWspolczynniki[i];
    }

    stopien = nowyStopien; // Ustaw nowy stopień
}

void Galois::podziel(const Galois &dzielnik, Galois &reszta)
{
    /// Sprawdź, czy stopień dzielnika jest większy od stopnia dzielonego wielomianu
    if (dzielnik.stopien > stopien)
    {
        /// Jeśli tak, przypisz dzielony wielomian do reszty
        reszta = *this;
        /// Utwórz nowy wielomian o stopniu 0, który jest równy 0
        *this = Galois(std::vector<int>(1, 0.0), 0);
        return;
    }

    /// Utwórz wektor ilorazów o odpowiednim rozmiarze
    std::vector<int> iloraz(stopien - dzielnik.stopien + 1, 0.0);
    /// Przypisz dzielony wielomian do reszty
    reszta = *this;

    /// Iteruj od najwyższego stopnia dzielonego wielomianu do 0
    for (int i = stopien - dzielnik.stopien; i >= 0; i--)
    {
        /// Oblicz iloraz dla aktualnego stopnia
        iloraz[i] = reszta.wspolczynniki[i + dzielnik.stopien] / dzielnik.wspolczynniki[dzielnik.stopien];
        /// Zaktualizuj resztę, odejmując iloraz pomnożony przez odpowiednie współczynniki dzielnika
        for (int j = 0; j <= dzielnik.stopien; j++)
        {
            reszta.wspolczynniki[i + j] -= iloraz[i] * dzielnik.wspolczynniki[j];
        }
    }

    // Przypisz wynikowy iloraz do dzielonego wielomianu
    *this = Galois(iloraz, stopien - dzielnik.stopien);
}

void Galois::scale(int k) {

Galois scaled;
scaled.stopien = stopien+k;
    scaled.wspolczynniki.resize(scaled.stopien + 1, 255);
//cout<<"zeroed"<<endl;
for(int i=k;i<=scaled.stopien;i++)
{
  //  cout<<i<<endl;
    scaled.wspolczynniki[i]=wspolczynniki[i-k];
}

*this = scaled;

}

void Galois::singlemul(int w, int k) {

    scale(k);

    for(int i=0;i<stopien;i++)
    {
        if(wspolczynniki[i]==255||k==255)
        {
            wspolczynniki[i]=255;
        }
        else{

            wspolczynniki[i]=(wspolczynniki[i] * k)%15;
        }

    }
}

Galois Galois::Xpodziel(const Galois &g) {

    Galois reszta = *this;

    /// reszta.wyswietl();
    Galois iloraz;
    iloraz.stopien=stopien;
    iloraz.wspolczynniki.resize(iloraz.stopien + 1, 255);
    Galois iloczyn;
    iloczyn.stopien=stopien;
    iloczyn.wspolczynniki.resize(iloczyn.stopien + 1, 255);

    Galois q;
    q.stopien = stopien;
    q.wspolczynniki.resize(q.stopien+1,255);


    for(int i =stopien;i>=0;i--)
    {
//////////////
        while(reszta.wspolczynniki[i]==255&&i>=-1)i--;///przesuwanie
        if(i<0)
        {
            std::cout<<"przewijanie"<<std::endl;
            break;
        }

        if(i<g.stopien)
        {
            std::cout<<"stopien"<<std::endl;
            break;
        }
/////////////

/////////sprawdzenie czy reszta zerowa
        bool zero = true;

        for(int ii=0;ii<=reszta.stopien;ii++)
        {


            if(reszta.wspolczynniki[ii]!=255)
            {

                zero = false;
                std::cout<<"co"<<std::endl;
                break;
            }
        }

//////
        std::cout<<std::endl;
        std::cout<<"i="<<i<<std::endl;
        std::cout<<std::endl;



        if(zero)
        {
            std::cout<<"zero"<<std::endl;
            break;
        }

        std::cout<<"tu1"<<std::endl;

        q.wspolczynniki[i-g.stopien]=reszta.wspolczynniki[i]-g.wspolczynniki[g.stopien];
        if(iloraz.wspolczynniki[i-g.stopien]<0)
        {
            q.wspolczynniki[i-g.stopien]+=15;
        }

        std::cout<<"tu2"<<std::endl;

        iloraz.Xdodaj(q);
        iloczyn = g;
        std::cout<<"tu3"<<std::endl;
        iloczyn.wyswietl();
        q.wyswietl();
        iloczyn.Xpomnoz(q);

        std::cout<<"tu4"<<std::endl;
        // cout<<"iloraz"<<endl;
        //  iloraz.wyswietl();

        // cout<<"reszta przed"<<endl;
        // reszta.wyswietl();

        //  cout<<"iloczyn"<<endl;
        // iloczyn.wyswietl();

        reszta.Xdodaj(iloczyn);
        // cout<<"reszta po"<<endl;
        //  reszta.wyswietl();
        // cout<<endl;

        q.Xdodaj(q);


    }



    *this=iloraz;
    std::cout<<std::endl;
    std::cout<<"koniec"<<std::endl;
    std::cout<<std::endl;
iloraz.wyswietl();
reszta.wyswietl();


    return reszta;
}


Galois Galois::XXpodziel(const Galois &g) {

    int divident = stopien;
    int divisor = g.stopien;
    ///poczatkowe sprawdzenie stopni
    if(divisor>divident)
    {
        return *this;
    }

    ///inicjalizacja ilorazu
    Galois iloraz;
    iloraz.stopien = divident-divisor;
    iloraz.wspolczynniki.resize(iloraz.stopien+1,255);

    ///inicjalizacja reszty
    Galois reszta;
    iloraz.stopien = divisor;
    iloraz.wspolczynniki.resize(iloraz.stopien+1,255);
    reszta = *this;


    for(int i = divident;i>=divisor;i--)
    {








        ////przewijanie
        while(reszta.wspolczynniki[i]==255&&i>=-1)
        {
            i--;

        }


        ////sprawdzenie stopni
        if(i<divisor)
        {
            break;
        }

        /////////////////////////
        Galois q;
        q.stopien = i-divisor;
        q.wspolczynniki.resize(q.stopien+1,255);



        Galois iloczyn;

        iloczyn.stopien = divident;

        iloczyn.wspolczynniki.resize(iloczyn.stopien+1,255);
        /////////////////////////

        q.wspolczynniki[i-divisor]=reszta.wspolczynniki[i] - g.wspolczynniki[divisor];

        if(q.wspolczynniki[i-divisor]<0)
        {
            q.wspolczynniki[i-divisor]=q.wspolczynniki[i-divisor]+15;
        }

        iloraz.Xdodaj(q);


       // cout<<"iloraz"<<endl;
       // q.wyswietl();
        //cout<<endl;

       // cout<<"reszta przed"<<endl;
      //  reszta.wyswietl();
      //  cout<<endl;

        iloczyn.Xdodaj(g);
        iloczyn.Xpomnoz(q);

        //cout<<"iloczyn"<<endl;
        //iloczyn.wyswietl();


        reszta.Xdodaj(iloczyn);

        /*
        cout<<"reszta po"<<endl;
        reszta.wyswietl();
        cout<<endl;
        cout<<endl;
        cout<<endl;
*/



        bool zero = true;

        for(int ii=0;ii<=reszta.stopien;ii++)
        {


            if(reszta.wspolczynniki[ii]!=255)
            {

                zero = false;

                break;
            }
        }

        if(zero)
        {
            break;
        }




    }


*this = iloraz;


    return reszta;

}

Galois::~Galois()
{
    wspolczynniki.clear();

}