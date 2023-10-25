#ifndef PEDIDO_HPP
#define PEDIDO_HPP
#include <stdio.h>
using namespace std;

class Pedido
{
public:
    Pedido();
    bool esUrgente();
    void generarID();
    void generarNSeguimiento();
    void generarDNI();
    void mostrar();
    ~Pedido(); 
private: 
    string DNI;
    int ID;
    int nSeguimiento;
    bool urgente;
};

#endif // PEDIDO_HPP