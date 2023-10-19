#include "NodoPila.hpp"
class Pila
{
public:
    Pila();
    ~Pila();
    void insertar(Pedido p);
    int extraer();
    int cima();
    void mostrar();
    int getLongitud();

private:
    pnodoPila ultimo;
    int longitud;
};
