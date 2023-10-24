#include <iostream>
#include <iomanip>
using namespace std;

class Pedido
{
public:
    Pedido(string dni, int id, int NSeguimiento);
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
    bool esUrgente;
    
    
};

