#include <iostream>
using namespace std;

class NodoCola
{
public:
    NodoCola(Pedido p, NodoCola* sig = NULL);
    ~NodoCola();

private:
    int valor;
    NodoCola* siguiente;
    
    friend class Cola;
};

typedef NodoCola* pnodoCola;
