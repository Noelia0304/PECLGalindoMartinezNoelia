#ifndef LISTA_HPP
#define LISTA_HPP
#include "NodoLista.hpp"

class Lista
{
public:
    Lista();
    ~Lista();
    void insertar(Pedido pedido);
    void insertarOrdenNumSeg(Pedido pedido);
    void mostrar();
    Pedido extraer();
    Pedido getMenor();
    Pedido getMayor();
    void eliminar();
    int getLongitud();

private:
    pnodoLista primero, ultimo;
    int longitud;
    int posicion;
};

#endif // LISTA_HPP
