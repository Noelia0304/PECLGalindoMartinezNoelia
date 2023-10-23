#include <iostream>
using namespace std;

class NodoLista
{
public:
    NodoLista(Pedido pedido, NodoLista* sig = NULL);
    ~NodoLista();
private:
    Pedido pedido;
    NodoLista* siguiente;
    
    friend class Lista;
};

typedef NodoLista* pnodoLista;