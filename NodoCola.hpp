#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP
#include "Pedido.hpp"
#include <stdio.h>
using namespace std;

class NodoCola
{
public:
    NodoCola(Pedido (p), NodoCola* sig = NULL);
    ~NodoCola();

private:
    Pedido valor;
    NodoCola* siguiente;
    
    friend class Cola;
};

typedef NodoCola* pnodoCola;

#endif // NODOCOLA_HPP