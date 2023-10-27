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
    nuevo = new NodoLista(pedido, nullptr);
    
    if(!ultimo || pedido.idPedido < ultimo->valor.idPedido){
        nuevo->siguiente = ultimo;
        ultimo = nuevo;
    }else{
        
    }
        
    
    /*if(primero)
        primero->siguiente = nuevo;
        
    primero = nuevo;
    if(!ultimo)
        ultimo = nuevo;
    longitud++;*/
}

void Lista::mostrar()
{
    pnodoLista aux = ultimo;
    cout << "\t" << setw(10) << "El contenido de la lista es: " << endl;
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

