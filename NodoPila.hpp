#include <iostream> 
using namespace std;

class NodoPila
{
public:
    NodoPila(Pedido pedido, NodoPila* sig = NULL);
    ~NodoPila();
private:
    Pedido pedido;
    NodoPila* siguiente;
    friend class Pila;
};

typedef NodoPila* pnodoPila;