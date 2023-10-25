#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"
#include "Pedido.hpp"
class Cola
{
public:
    Cola();
    ~Cola();

    void insertar(Pedido pedido);
    int eliminar();
    void mostrar();
    int verPrimero();
    
private:
    pnodoCola primero, ultimo;
    int longitud;
};

#endif // COLA_HPP
