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
    void generaridPedido();
    int getidPedido();
    int idPedido;
    ~Pedido(); 
private: 
    char DNI[10] ;
    int ID;
    int nSeguimiento;
    bool urgente;
    
};

#endif // PEDIDO_HPP