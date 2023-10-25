#include "Pila.hpp"
#include "Pedido.hpp"

Pila::Pila()
{
    ultimo = NULL;
    longitud = 0;
}
void Pila::insertar(Pedido pedido)
{
    pnodoPila nuevo;
    nuevo = new NodoPila(pedido, ultimo);
    ultimo = nuevo;
    longitud++;
}
Pedido Pila::extraer()
{
    pnodoPila nodo;
    Pedido pedido;
    if(!ultimo)
        return pedido;
    nodo = ultimo;
    ultimo = nodo->siguiente;
    pedido = nodo->valor;
    longitud--;
    delete nodo;
    return pedido;
}
Pedido Pila::cima()
{
    Pedido pedido;
    pnodoPila nodo;
    if(!ultimo)
        return pedido;
    return ultimo->valor;
}
void Pila::mostrar()
{
    pnodoPila aux = ultimo;
    cout <<"\t" << setw(10) << "\tEl contenido de la pila es: " << endl;
    while(aux){
        aux->valor.mostrar();
        aux = aux->siguiente;
    }
    cout << endl;
}
int Pila::getLongitud()
{
    return this->longitud;
}
Pila::~Pila()
{
    pnodoPila aux;
    while(ultimo){
        aux = ultimo;
        ultimo = ultimo->siguiente;
        delete aux;
    }
}
