#include <iostream>

using namespace std;

class NodoLista
{
public:
    NodoLista(Pedido p, NodoLista* sig = NULL);
    ~NodoLista();
private:
    Pedido pedido;
    NodoLista* siguiente;
    
    friend class Lista;
};

typedef NodoLista* pnodoLista;