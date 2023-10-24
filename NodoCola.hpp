#include <iostream>
#include "Pedido.hpp"
using namespace std;

class NodoCola
{
public:
    NodoCola(Pedido (p), NodoCola* sig = NULL);
    ~NodoCola();

private:
    Pedido pedido;
    NodoCola* siguiente;
    
    friend class Cola;
};

typedef NodoCola* pnodoCola;
