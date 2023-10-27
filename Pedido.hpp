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
    ~Pedido(); 
private: 
    char DNI[10] ;
    int ID;
    int nSeguimiento;
    bool urgente;
    int idPedido;
};

#endif // PEDIDO_HPP