#ifndef NODOPILA_HPP
#define NODOPILA_HPP
#include "Pedido.hpp"

class NodoPila
{
public:
    NodoPila(Pedido p, NodoPila* sig = nullptr);
    ~NodoPila();
private:
    Pedido pedido;
    NodoPila* siguiente;
    
    friend class Pila;
};


typedef NodoPila* pnodoPila;

#endif // NODOPILA_HPP