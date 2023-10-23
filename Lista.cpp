#include "Lista.hpp"

Lista::Lista()
{
    primero = NULL;
    longitud = 0;
}
void Lista::insertar(Pedido pedido)
{
    pnodoPila nuevo;
    nuevo = new NodoPila(pedido, ultimo);
    ultimo = nuevo;
    longitud++;
}
int Lista::extraer()
{
    pnodoPila nodo;
    Pedido pedido;
    if(!ultimo)
        return 0;
    nodo = ultimo;
    ultimo = nodo->siguiente;
    pedido = nodo->valor;
    longitud--;
    delete nodo;
    return pedido;
}

Lista::~Lista()
{
}

