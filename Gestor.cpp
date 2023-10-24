#include "Gestor.hpp"


Gestor::Gestor()
{
}

void Gestor::generar12Pedidos(){
    if (pilaPedidos.size()<= 36){
        for(int i = 0; i<12; ++i){ // no es lista, es pedido
            Pedido unPedido;
            pilaPedidos.insertar(unPedido);
        }
    }
    
    
}

void Gestor::muestraPedidos(){
    
    for (int i = 0; i< pilaPedidos.size(); ++i){
         pilaPedidos.mostrar();
    }
}

Gestor::~Gestor()
{
}

