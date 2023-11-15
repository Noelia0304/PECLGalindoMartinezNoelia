#include "Cola.hpp"
#include "Pedido.hpp"
#include <iostream>

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

void Cola::insertar(Pedido pedido)
{
    pnodoCola nuevo;
    nuevo = new NodoCola(pedido);
    if(ultimo)
        ultimo->siguiente = nuevo;
        
    ultimo = nuevo;
    
    if(!primero)
        primero = nuevo;
    longitud++;
}

void Cola::mostrar()
{
    pnodoCola aux = primero;
    cout << "\t" << setw(10) <<"El contenido de la cola es: " << endl;
    while(aux){
        aux-> valor.mostrar();
        aux = aux->siguiente;
    }
    cout << endl;
}

Pedido Cola::eliminar()
{
    pnodoCola nodo;
    Pedido pedido;
    nodo =primero;
    if(!nodo)
        return pedido;
    primero = nodo->siguiente;
    pedido = nodo->valor;
    delete nodo;
    if(!primero)
        ultimo = NULL;
    longitud--;
    return pedido;
}

Pedido Cola::extraer()
{
    pnodoCola nodo;
    Pedido pedido;
    if(!primero)
        return pedido;
    nodo = primero;
    primero = nodo->siguiente;
    pedido = nodo->valor;
    longitud--;
    delete nodo;
    return pedido;
}

Pedido Cola::verPrimero(){
    return primero->valor;
}

int Cola::getLongitud()
{
    return this->longitud;
}

void Pedido::generarID(){
    Pedido pedido;
    if(pedido.esUrgente){
        ID = (rand() % 51) + 49;
    } else{
        ID = (rand() % 50) + 1;
    } 
    if pedido.getId == pedido.generarID{
        ID = pedido.generarID;
    }
}

Cola::~Cola()
{
    while(primero)
        eliminar();
}




