#include "Cola.hpp"

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
    cout << "\tEl contenido de la cola es: ";
    while(aux){
        cout << "-> "<< aux-> valor;
        aux = aux->siguiente;
    }
    cout << endl;
}
int Cola::eliminar()
{
    pnodoCola nodo;
    Pedido pedido;
    nodo = primero;
    if(!nodo)
        return 0;
    primero = nodo->siguiente;
    pedido = nodo->valor;
    delete nodo;
    if(!primero)
        ultimo = NULL;
    longitud--;
    return pedido;
}
int Cola::verPrimero(){
    return primero->valor;
}
Cola::~Cola()
{
    while(primero)
        eliminar();
}




