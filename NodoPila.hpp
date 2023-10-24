<<<<<<< HEAD
#ifndef NODOPILA_HPP
#define NODOPILA_HPP

=======
#include <iostream> 
#include "Pedido.hpp"
using namespace std;
>>>>>>> 2f454e902f5b14e6a8bed2d5056e472b577e14fb

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