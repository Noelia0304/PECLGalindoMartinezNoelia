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
    
    if(!primero || pedido.getId() < primero->valor.getId()){
        nuevo->siguiente = primero;
        primero = nuevo;
    }
    else{
        pnodoLista actual = primero;
        while (actual->siguiente != NULL && pedido.getId() >= actual->siguiente->valor.getId()){
            actual = actual->siguiente;
        }
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
    }
    pnodoLista ultimo = primero;
    while(ultimo -> siguiente){
        ultimo = ultimo -> siguiente;
    }
    ultimo -> siguiente = nullptr;
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

Pedido Lista::getMenor() 
{
    pnodoLista actual = primero;
    while(actual){
        ultimo = actual;
        actual = actual -> siguiente;
    }
    return ultimo ->valor;
}


Pedido Lista::getMayor()
{
    return primero->valor;
}

void Lista::eliminar()
{
    while (primero) {
        pnodoLista nodo = primero;
        primero = primero->siguiente;
        delete nodo;
        longitud --;
    }
}

Lista::~Lista()
{
}

