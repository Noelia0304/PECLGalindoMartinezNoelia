#ifndef LISTA_HPP
#define LISTA_HPP
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
    void mostrar();
    int getLongitud();
private:
    pnodoLista ultimo;
    int longitud;
    pnodoLista primero;
};

#endif // LISTA_HPP
