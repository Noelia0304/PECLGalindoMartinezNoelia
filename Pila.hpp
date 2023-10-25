#ifndef PILA_HPP
#define PILA_HPP
#include "NodoPila.hpp"
#include "Pedido.hpp"

class Pila
{
public:
    Pila();
    ~Pila();
    void insertar(Pedido pedido);
    Pedido extraer();
    Pedido cima();
    void mostrar();
    int getLongitud();
    void desapilar();

private:
    pnodoPila ultimo;
    int longitud;
};

#endif // PILA_HPP