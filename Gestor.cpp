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
     pilaPedidos.mostrar();
}

void Gestor::borraPedidosPila()
{
    pilaPedidos.desapilar();
}

void Gestor::encolarPedidos()
{
    Pedido pedido;
    for(int i=0; i <= pilaPedidos.getLongitud(); i++){
        pilaPedidos.extraer();
        if(pedido.esUrgente()){
            if(ColaC.getLongitud() >= ColaD.getLongitud()){
                ColaD.insertar(pedido);
            }else{
                ColaC.insertar(pedido);
            }
        }else{
            if(ColaA.getLongitud() >= ColaB.getLongitud()){
                ColaB.insertar(pedido);
            }else{
                ColaA.insertar(pedido);
            }   
        }
    }
}

int Gestor::PedidosEnSalaA(){
   return ColaA.getLongitud();
}

int Gestor::PedidosEnSalaB(){
    return ColaB.getLongitud();
}

int Gestor::PedidosEnSalaC(){
   return ColaC.getLongitud();
}

int Gestor::PedidosEnSalaD(){
   return ColaD.getLongitud();
}

Gestor::~Gestor()
{
}

