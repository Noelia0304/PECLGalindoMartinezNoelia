#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"
#include "Pedido.hpp"
#include <iomanip>
class Cola
{
public:
    Cola();
    ~Cola();

    void insertar(Pedido pedido);
    Pedido eliminar();
    Pedido extraer();
    void mostrar();
    Pedido verPrimero();
    int getLongitud();
    void generarID(Pedido pedido);
    
private:
    pnodoCola primero, ultimo;
    int longitud;
    Pedido valor;
};

#endif // COLA_HPP
