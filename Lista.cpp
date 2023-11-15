#include "Lista.hpp"
#include "Pedido.hpp"
Lista::Lista()
{
    primero = NULL;
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
    longitud++;
}

void Lista::generarNSeguimiento(Pedido pedido){
    int nSeguimiento;
    if(pedido.esUrgente()){
        nSeguimiento = (rand() % 501) + 499;
        pedido.setNSeguimiento(nSeguimiento);
    } else{
        nSeguimiento = (rand() % 499) + 1;
        pedido.setNSeguimiento(nSeguimiento);
    }
    
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
    pnodoLista aux = primero;
    Pedido menor = aux->valor;

    while (aux != nullptr) {
        if (aux->valor.getId() > menor.getId()) {
            menor = aux->valor;
        }
        aux = aux->siguiente;
    }

    return menor;
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

