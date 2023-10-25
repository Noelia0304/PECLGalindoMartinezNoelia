#include "NodoPila.hpp"
#include "Pedido.hpp"

NodoPila::NodoPila(Pedido (p), NodoPila* sig )
{
    valor = p;
    siguiente = sig;
}

NodoPila::~NodoPila()
{
}