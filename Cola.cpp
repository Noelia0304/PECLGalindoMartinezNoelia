#include "Cola.hpp"

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}
void Cola::insertar(Pedido p)
{
    pnodoCola nuevo;
    nuevo = new NodoCola(p);
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
        cout << "-> "<< aux->valor;
        aux = aux->siguiente;
    }
    cout << endl;
}
int Cola::eliminar()
{
    pnodoCola nodo;
    Pedido p;
    nodo = primero;
    if(!nodo)
        return 0;
    primero = nodo->siguiente;
    p = nodo->valor;
    delete nodo;
    if(!primero)
        ultimo = NULL;
    longitud--;
    return p;
}
int Cola::verPrimero(){
    return primero->valor;
}
Cola::~Cola()
{
    while(primero)
        eliminar();
}




