#include "Pila.hpp"

using namespace std;

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
int Pila::extraer()
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
int Pila::cima()
{
    pnodoPila nodo;
    if(!ultimo)
        return 0;
    return ultimo->pedido;
}
void Pila::mostrar()
{
    pnodoPila aux = ultimo;
    cout << "\tEl contenido de la pila es: ";
    while(aux){
        cout << "-> "<< aux->pedido;
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
