#include <iostream>
#include <iomanip>
using namespace std;

class Pedido
{
public:
    Pedido(string dni, int id, int NSeguimiento);
    ~Pedido();
    void generarDNI();
    void generarID();
    void generarNSeguimiento();
    void mostrar();
    
private: 
    string DNI;
    int ID;
    int nSeguimiento;
    bool esUrgente;
    
    
};

