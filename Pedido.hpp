class Pedido
{
public:
    Pedido();
    ~Pedido();
    
private: 
    string dniCliente;
    int id;
    int nSeguimiento;
    bool esUrgente;
    
    void generarDNI();
};

