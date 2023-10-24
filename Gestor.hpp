#include <iostream>
#include <iomanip>
using namespace std;

class Gestor
{
public:
    Gestor();
    ~Gestor();
    
    void generar12Pedidos();
    void muestraPedidos();
    
private:
    Pila pilaPedidos;
    //Cola ColaA;
    //Cola ColaB;
    //Cola ColaC;
    //Cola ColaD;
    //Lista ListaEstandar;
    //Lista ListaUrgente;
};
