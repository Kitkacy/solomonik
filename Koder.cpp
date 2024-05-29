//
// Created by marci on 13.05.2024.
//

#include <string>
#include <bitset>
#include <iostream>
#include <vector>
#include "Koder.h"
#include "Galois.hpp"

Koder::Koder() {
    generator =Galois(std::vector<int>{10 ,1 ,6, 1, 2, 14, 6 ,9, 3, 2, 0},10);

}

Galois Koder::codePolynomial( const Galois &msg) {


    Galois C;
    Galois M = msg;


    M.scale(10);
    M=M.XXpodziel(generator);

    C=msg;
    C.scale(10);
    C.Xdodaj(M);

    C.minimalize();


return C;

}

std::string Koder::codetostring(const Galois &msg) {
    Galois m = msg;
    m.wspolczynniki.resize(15,255);

std::string word = std::bitset<4>(m.wspolczynniki[m.stopien]).to_string();
for(int i=msg.stopien-1;i>=0;i--)
{
   // word+=" ";
    word=word+std::bitset<4>(m.wspolczynniki[i]).to_string();
}
while(word.length()<60)
{
    word="1111"+word;
}

return word;
}

int Koder::ASCIItoint03(char a) {

    int b = int(a);
  //  std::cout<<b<<std::endl;

    std::string s=std::bitset<8>(a).to_string();

    std::string a03 = s.substr(0,4);
   // std::cout<<a03<<std::endl;
    int A03 = std::stoi(a03, nullptr, 2);
   // std::cout<<A03<<std::endl;
    return A03;
}

int Koder::ASCIItoint48(char a) {

    int b = int(a);

    std::string s=std::bitset<8>(a).to_string();
    std::string a48 = s.substr(4,8);
    int A48 = std::stoi(a48, nullptr, 2);

    return A48;
}



Galois Koder::ASCIIpairtoPolynomial(char a, char b) {

    Galois g= Galois(std::vector<int>{255,255,255,255,255},4);
    int a03 = ASCIItoint03(a);
    int a48 = ASCIItoint48(a);
    int b03 = ASCIItoint03(b);
    int b48 = ASCIItoint48(b);
    g.wspolczynniki[3]=a03;
    g.wspolczynniki[2]=a48;
    g.wspolczynniki[1]=b03;
    g.wspolczynniki[0]=b48;

    return g;
}


std::string Koder::code(std::string msg) {

    std::string transmision ="";

    int len = msg.length();

if(len>0){




    for(int i =0;i<=len;i=i+2)
    {



            char a;

            if(len-i-1<0)
            {
                a=' ';
            }
            else{
                a=msg[len-i-1];
            }

        char b=msg[len-i];
       // std::cout<<"x"<<std::endl;
        Galois pair = ASCIIpairtoPolynomial(a,b);
        pair= codePolynomial(pair);
       // pair.wyswietl();



        transmision= codetostring(pair) +transmision;



    }
}
    return transmision;
}