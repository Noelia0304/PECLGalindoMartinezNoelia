#include "Gestor.hpp"


Gestor::Gestor()
{
    
}
int Gestor::PedidosEnPila(){
   return pilaPedidos.getLongitud();
}

void Gestor::generar12Pedidos(){
    if (pilaPedidos.getLongitud()<= 36){
        for(int i = 0; i<12; ++i){
            Pedido unPedido;
            pilaPedidos.insertar(unPedido);
        }
    }
}

void Gestor::muestraPedidos()
{
    for (int i = 0; i< pilaPedidos.getLongitud(); ++i){
         pilaPedidos.mostrar();
    }
}

void Gestor::borraPedidosPila()
{
    
}
Gestor::~Gestor()
{
}

