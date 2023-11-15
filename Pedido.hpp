#ifndef PEDIDO_HPP
#define PEDIDO_HPP
#include <iomanip>
#include <iostream>
using namespace std;

class Pedido
{
public:
    Pedido();
    bool esUrgente();
    void generarNSeguimiento();
    void generarDNI();
    void mostrar();
    ~Pedido(); 
    
private: 
    char DNI[10] ;
    bool urgente;
    int nSeguimiento;
    int ID;
};

#endif // PEDIDO_HPP