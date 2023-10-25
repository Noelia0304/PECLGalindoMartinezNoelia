#include "NodoLista.hpp"
#include "Pedido.hpp"

NodoLista::NodoLista(Pedido p, NodoLista* sig)
{
    valor = p;
    siguiente = sig;
}

NodoLista::~NodoLista()
{
}

