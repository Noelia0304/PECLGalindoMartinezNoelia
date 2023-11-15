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
    void mostrar();
    Pedido getMenor();
    Pedido getMayor();
    void eliminar();
    int getLongitud();
    int generarNSeguimiento(Pedido pedido);

private:
    pnodoLista primero, ultimo;
    int longitud;
    int posicion;
};

#endif // LISTA_HPP
