#ifndef LISTA_HPP
#define LISTA_HPP
#include "NodoLista.hpp"

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
    void generarNSeguimiento(Pedido pedido);

private:
    pnodoLista primero, ultimo;
    int longitud;
    int posicion;
};

#endif // LISTA_HPP
