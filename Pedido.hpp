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
    bool urgente;
    ~Pedido(); 
    
private: 
    char DNI[10] ;
    
    int nSeguimiento;
    
};

#endif // PEDIDO_HPP