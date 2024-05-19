#include <iostream>
#include "Galois.hpp"
#include "Koder.h"
#include <vector>

int main() {




    Galois a(std::vector<int>{0,1},1);

Koder code;
a=code.codePolynomial(a);
a.wyswietl();






    return 0;
}
