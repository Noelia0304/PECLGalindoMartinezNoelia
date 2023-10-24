#include <iostream>
#include <iomanip>
using namespace std;

class Pedido
{
public:
    Pedido(string dniCliente, int id, int nSeguimiento);
    ~Pedido();
    void generarDNI();
    void generarID();
    void generarNSeguimiento();
    void mostrar();
    
private: 
    string dniCliente;
    int id;
    int nSeguimiento;
    bool esUrgente;
    
    
};

