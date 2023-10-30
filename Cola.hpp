#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"
#include "Pedido.hpp"
class Cola
{
public:
    Cola();clTabCtrl
    ~Cola();

    void insertar(Pedido pedido);
    Pedido eliminar();
    Pedido extraer();
    void mostrar();
    Pedido verPrimero();
    int getLongitud();
    
private:
    pnodoCola primero, ultimo;
    int longitud;
    Pedido valor;
};

#endif // COLA_HPP
