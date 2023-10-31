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
    nuevo = new NodoLista(pedido);
    
    if(!primero || pedido.ID < primero->valor.ID){
        nuevo->siguiente = primero;
        primero = nuevo;
    }else{
        pnodoLista actual = primero;
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
    pnodoLista aux = primero;
    if(aux->valor.esUrgente() == 1){
        cout << "\t" << setw(10) << "El contenido de la lista Urgente es: " << endl;
    }else{
        cout << "\t" << setw(10) << "El contenido de la lista Estandar es: " << endl;
    }
    
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

Pedido Lista::mostrarMenor()
{
    return primero->valor;
}

Pedido Lista::mostrarMayor()
{
    pnodoLista aux = primero;
    while(aux->siguiente != NULL){
        primero->siguiente = aux;
        primero = aux;
    }
    return ultimo->valor;
}

void Lista::eliminar()
{
    while (ultimo){
    pnodoLista nodo = ultimo;
    ultimo = ultimo->siguiente;
    delete nodo;
    longitud--;
    }
    return pedido
}

Lista::~Lista()
{
}

