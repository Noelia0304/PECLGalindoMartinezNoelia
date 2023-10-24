#include "Lista.hpp"
#include "Pedido.hpp"
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

void Lista::mostrar()
{
    pnodoLista aux = ultimo;
    cout << "\tEl contenido de la lista es: ";
    while(aux){
        cout << "-> "<< aux->pedido;
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

