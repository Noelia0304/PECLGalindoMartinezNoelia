#ifndef GESTOR_HPP
#define GESTOR_HPP
#include <iostream>
#include <iomanip>
#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
using namespace std;

class Gestor
{
public:
    Gestor();
    ~Gestor();
    int PedidosEnPila();
    void generar12Pedidos();
    void muestraPedidos();
    void borraPedidosPila();
    void encolarPedidos();
    int PedidosEnSalaA();
    int PedidosEnSalaB();
    int PedidosEnSalaC();
    int PedidosEnSalaD();
    void muestraPedidosSalasAyB();
    void muestraPedidosSalasCyD();
    void borraPedidosColas();
    void enlistarPedidos();
    int PedidosEnListaUrgente();
    int PedidosEnListaEstandar();
    void muestraPedidosEstandar();
    void muestraPedidosUrgentes();
    void buscarPedidos();
    void reiniciar();

private:
    Pila pilaPedidos;
    Cola ColaA;
    Cola ColaB;
    Cola ColaC;
    Cola ColaD;
    Lista ListaEstandar;
    Lista ListaUrgente;
};

#endif // GESTOR_HPP