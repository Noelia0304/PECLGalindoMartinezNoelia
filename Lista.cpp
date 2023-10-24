#include "Lista.hpp"

Lista::Lista()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}
void Lista::insertar(Pedido pedido)
{
    pnodoPila nuevo;
    nuevo = new NodoPila(pedido, ultimo);
    if(ultimo)
        ultimo->siguiente = nuevo;
        
    ultimo = nuevo;
    
    if(!primero)
        primero = nuevo;
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
void Lista::mostrar()
{
    pnodoLista aux = ultimo;
    cout << "\tEl contenido de la lista es: ";
    while(aux){
        cout << "-> "<< aux->valor;
        aux = aux->siguiente;
    }
    cout << endl;
}
int Lista::getLongitud()
{
    return this->longitud;
}

Lista::~Lista()
{
}

