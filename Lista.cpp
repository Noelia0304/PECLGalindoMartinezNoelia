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
    pnodoLista nuevo;
    nuevo = new NodoLista(pedido, ultimo);
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
    cout << "\t" << setw(10) << "\tEl contenido de la lista es: " << endl;
    while(aux){
        aux->valor.mostrar();
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

