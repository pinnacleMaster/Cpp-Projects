#include <iostream>
#include "englishRuler.hpp"

int main()
{
    int nlen; std::cout << "Enter ruler length (in inches): "; cin >> nlen;
    int mlen; std::cout << "Enter ruler major tick length: "; cin >> mlen;
    drawRuler(nlen, mlen);
    
    return 0;
}
