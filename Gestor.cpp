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
    
    while(pilaPedidos.getLongitud()!=0){
          Pedido pedido;
          pedido = pilaPedidos.extraer(); 
          if(pedido.esUrgente() == 1){
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

void Gestor:: muestraPedidosSalasAyB()
{
    cout << " Los pedidos en las salas A y B son: " << endl;
    cout << "A: ";
    ColaA.mostrar();
    cout << "B: ";
    ColaB.mostrar();
    cout << endl;
}

void Gestor:: muestraPedidosSalasCyD()
{
    cout << " Los pedidos en las salas C y D son: " << endl;
    cout << "C: ";
    ColaC.mostrar();
    cout << "D: ";
    ColaD.mostrar();
    cout << endl;
}

void Gestor:: borraPedidosColas()
{
    while(ColaA.getLongitud() !=0){   
        ColaA.eliminar();
    }
    while(ColaB.getLongitud() !=0){
        ColaB.eliminar();
    }
    while(ColaC.getLongitud()!=0){
        ColaC.eliminar();
    }
    while(ColaD.getLongitud()!=0){
        ColaD.eliminar();
    }
        
}

void Gestor::enlistarPedidos()
{
    Pedido pedido; 
    while(ColaA.getLongitud() !=0){
        pedido = ColaA.extraer();
        ListaEstandar.insertar(pedido);
    }
    while(ColaB.getLongitud()!=0){
        pedido = ColaB.extraer();
        ListaEstandar.insertar(pedido);
    }
    while(ColaC.getLongitud()!=0){
        pedido = ColaC.extraer();
        ListaUrgente.insertar(pedido);
    }
    while(ColaD.getLongitud()!=0){
        pedido = ColaD.extraer();
        ListaUrgente.insertar(pedido);
    }
}

int Gestor::PedidosEnListaEstandar(){
   return ListaEstandar.getLongitud();
}

int Gestor::PedidosEnListaUrgente(){
   return ListaUrgente.getLongitud();
}

void Gestor::muestraPedidosEstandar(){
    ListaEstandar.mostrar();
}

void Gestor::muestraPedidosUrgentes(){
    ListaUrgente.mostrar();
}

void Gestor:: reiniciar()
{
    pilaPedidos.desapilar();
    ColaA.eliminar();
    ColaB.eliminar();
    ColaC.eliminar();
    ColaD.eliminar();
}
Gestor::~Gestor()
{
}

