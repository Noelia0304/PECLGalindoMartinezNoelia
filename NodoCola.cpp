#include "NodoCola.hpp"

NodoCola::NodoCola(Pedido p, NodoCola* sig)
{
    valor = p;
    siguiente = sig;
}

NodoCola::~NodoCola()
{
}


