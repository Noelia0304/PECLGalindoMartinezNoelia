#include "Gestor.hpp"


Gestor::Gestor()
{
}

Gestor::generar12Pedido(){
    
    for(int i = 0; i<12; ++i){ \\ no es lista, es pedido
        Pedido unPedido;
        Pila pilaPedidos;
        pilaPedidos.insertar(unPedido);
    }
    
    for (int i = 0; i< 12; ++i){
         pilaPedidos.mostrar();
    }
}

Gestor::~Gestor()
{
}

