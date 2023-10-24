#include <iostream> 
#include "Pedido.hpp"
using namespace std;

class NodoPila
{
public:
    NodoPila(Pedido p, NodoPila* sig = NULL);
    ~NodoPila();
private:
    Pedido pedido;
    NodoPila* siguiente;
    
    friend class Pila;
};


typedef NodoPila* pnodoPila;