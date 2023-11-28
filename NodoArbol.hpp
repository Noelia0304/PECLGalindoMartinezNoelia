#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP
#include <iostream>
#include "Pedido.hpp"
class NodoArbol
{
public:
    NodoArbol(Pedido pedido);
    ~NodoArbol();

private:
    Pedido pedido; // Aquí se almacenan enteros pero en vuestra práctica se deben almacenar pacientes
    NodoArbol* izq;
    NodoArbol* der;

    friend class Arbol;
};
typedef NodoArbol* pnodoAbb;
#endif // NODOARBOL_HPP
