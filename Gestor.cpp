#include "Gestor.hpp"

std::vector<Pedido> crearLista(){
    std::vector<Pedido> lista;
    
    for(int i = 0; i<12; ++i){
        Pedido unPedido;
        lista.push_back(Pedido(unPedido.id, unPedido.dniCliente + std::to_string(unPedido.id), unPedido.nSeguimiento, unPedido.esUrgente)); 
    }
    
    for (const auto& unPedido : lista){
        unPedido.mostrar();
    }
    
}

Gestor::Gestor()
{
}

Gestor::~Gestor()
{
}

