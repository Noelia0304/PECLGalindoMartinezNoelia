#ifndef NODOPILA_HPP
#define NODOPILA_HPP


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