#include "NodoLista.hpp"
class Lista
{
public:
    Lista();
    ~Lista();
    void insertar(Pedido pedido);
    int extraer();
    int cima();
    void mostrar();
    int getLongitud();
private:
    pnodoLista ultimo;
    int longitud;
};


