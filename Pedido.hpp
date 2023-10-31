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
    void generarID();
    void generarNSeguimiento();
    void generarDNI();
    void mostrar();
    int ID;
    
    ~Pedido(); 
    
private: 
    char DNI[10] ;
    bool urgente;
    int nSeguimiento;
    
};

#endif // PEDIDO_HPP