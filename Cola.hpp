
class Cola
{
public:
    Cola();
    ~Cola();

    void insertar(Pedido p);
    int eliminar();
    void mostrar();
    int verPrimero();
    
private:
    pnodoCola primero, ultimo;
    int longitud;
};


