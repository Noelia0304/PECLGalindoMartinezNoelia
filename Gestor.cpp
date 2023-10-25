#include "Gestor.hpp"


Gestor::Gestor()
{
    Pedido unPedido;
}

void Gestor::generar12Pedidos(){
    if (pilaPedidos.getLongitud()<= 36){
        for(int i = 0; i<12; ++i){ 
            pilaPedidos.insertar(unPedido);
        }
    }
    
    
}

void Gestor::muestraPedidos(){
    
    for (int i = 0; i< pilaPedidos.getLongitud(); ++i){
         pilaPedidos.mostrar();
    }
}

Gestor::~Gestor()
{
}

