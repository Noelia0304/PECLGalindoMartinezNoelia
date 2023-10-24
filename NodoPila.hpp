#include <iostream> 

using namespace std;

class NodoPila
{
public:
    NodoPila(Pedido pedido, NodoPila* sig = NULL);
    ~NodoPila();
private:
    
    NodoPila* siguiente;
    Pedido valor;
    
    friend class Pila;
};


typedef NodoPila* pnodoPila;