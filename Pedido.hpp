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
    void generarDNI();
    void mostrar();
    int getId();
    void setId(int ID);
    int getNumSeg();
    void setNumSeg(int numSeg);
    ~Pedido(); 
    
private: 
    char DNI[10] ;
    bool urgente;
    int numSeg;
    int ID;
};

#endif // PEDIDO_HPP