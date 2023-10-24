#include <iostream>
#include <iomanip>
using namespace std;

class Gestor
{
public:
    Gestor();
    ~Gestor();
    
    void Generar12Pedidos();
    void muestraPedidos();
    
private:
    Pila pilaPedidos;

};
