//
// Created by marci on 20.05.2024.
//

#include <iostream>
#include <bitset>
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

    int weight = syndromx.weight();
    if(weight<=5)
    {
        repaired.Xdodaj(syndromx);
    }


    return repaired;
}

Galois Dekoder::decodepol(const Galois &word) {

    Galois decoded =word;

    int k=word.stopien+1;
    int i =0;

    while(i<k)
    {
       decoded= singlerepair(decoded);
       if(syndrom(decoded).weight()==0)
       {
           break;
       }
        decoded.rotacja("p",1);

        i++;
    }
    for(int j=0;j<i;j++)
    {
        decoded.rotacja("l",1);

    }



    return decoded;
}

 Galois Dekoder::getmsg(const Galois &word) {


    Galois msg = Galois(std::vector<int>{255,255,255,255},4);
    msg.wspolczynniki[0]=word.wspolczynniki[10];
    msg.wspolczynniki[1]=word.wspolczynniki[11];
    msg.wspolczynniki[2]=word.wspolczynniki[12];
     msg.wspolczynniki[3]=word.wspolczynniki[13];
     msg.wspolczynniki[4]=word.wspolczynniki[14];

     return msg;
}

std::string Dekoder::msgtoASCII(const Galois &word) {

    std::string msg="";

    std::string a =std::bitset<4>((int)word.wspolczynniki[3]).to_string();
    a+=std::bitset<4>((int)word.wspolczynniki[2]).to_string();
    std::string b = std::bitset<4>((int)word.wspolczynniki[1]).to_string();
    b += std::bitset<4>((int)word.wspolczynniki[0]).to_string();

    int A = std::stoi(a, nullptr, 2);
    int B = std::stoi(b, nullptr, 2);
    msg+=(char)A;
    msg+=(char)B;

return msg;
}

Galois Dekoder::stringtopol(std::string msg) {
    Galois G=Galois(std::vector<int>{255},0);
    G.scale(14);
    for(int i =0;i<15;i++)
    {
        G.wspolczynniki[i]=std::stoi(msg.substr(56-i*4,4), nullptr, 2);
        if(G.wspolczynniki[i]==15)
        {
            G.wspolczynniki[i]=255;
        }
    }

    return G;
}

std::string Dekoder::decode(std::string msg) {

    std::string out;
    int len = msg.length();


    for(int i=0;i<(len/60);i++)
    {


        std::string poly = msg.substr(len-i*60-60,60);

        Galois part = stringtopol(poly);


        part= decodepol(part);
        part = getmsg(part);

        std::string plus = msgtoASCII(part);



        out= plus+out;



    }



    return out;
}

std::string Dekoder::decodetostring(std::string msg) {
    std::string out;
    int len = msg.length();

}