#include "NodoCola.hpp"
#include "Pedido.hpp"

NodoCola::NodoCola(Pedido p, NodoCola* sig)
{
    valor = p;
    siguiente = sig;
}

NodoCola::~NodoCola()
{
}


