#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP
#include "Pedido.hpp"
#include <iostream>
using namespace std;

class NodoLista
{
public:
    NodoLista(Pedido (p), NodoLista* sig = NULL);
    ~NodoLista();
private:
    Pedido valor;
    NodoLista* siguiente;
    
    friend class Lista;
};

typedef NodoLista* pnodoLista;

#endif // NODOLISTA_HPP