#ifndef PILA_HPP
#define PILA_HPP
#include <iostream>
#include "NodoLista.hpp"
#include "Pedido.hpp"
using namespace std;
class Lista
{
public:
    Lista();
    ~Lista();
    void insertar(Pedido pedido);
    int extraer();
    int cima();
    void mostrar();
    int getLongitud();
private:
    pnodoLista ultimo;
    int longitud;
};

#endif // PILA_HPP
