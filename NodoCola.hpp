#include <iostream>
using namespace std;

class NodoCola
{
public:
    NodoCola(Pedido pedido, NodoCola* sig = NULL);
    ~NodoCola();

private:
    Pedido pedido;
    NodoCola* siguiente;
    
    friend class Cola;
};

typedef NodoCola* pnodoCola;
