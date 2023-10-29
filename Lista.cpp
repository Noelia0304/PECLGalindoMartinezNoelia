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
    nuevo = new NodoLista(pedido, NULL);
    
    if(!ultimo || pedido.ID < ultimo->valor.ID){
        nuevo->siguiente = ultimo;
        ultimo = nuevo;
    }else{
        NodoLista* actual = ultimo;
        while (actual->siguiente != NULL && pedido.ID >= actual->siguiente->valor.ID){
            actual = actual->siguiente;
        }
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
    }
    longitud++;
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

