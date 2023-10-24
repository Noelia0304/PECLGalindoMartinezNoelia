#include "Gestor.hpp"


Gestor::Gestor()
{
}

Gestor::generar12Pedido(){
    if (pilaPedidos.size()<= 36){
        for(int i = 0; i<12; ++i){ \\ no es lista, es pedido
            Pedido unPedido;
            pilaPedidos.insertar(unPedido);
        }
    fo    }
    
    for (int i = 0; i< 12; ++i){
         pilaPedidos.mostrar();
    }
}

Gestor::~Gestor()
{
}

