#ifndef GESTOR_HPP
#define GESTOR_HPP
#include <iostream>
#include <iomanip>
#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include "Arbol.hpp"
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
    int generarId(Pedido pedido);
    int generarNumSeg(Pedido pedido);
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
    void insertarPedidosArbol();
    int PedidosEnArbol();
    void PedidosArbolE();
    void PedidosArbolU();
    void dibujarAbb();
    int NumSegImpar();

private:
    Pila pilaPedidos;
    Cola ColaA;
    Cola ColaB;
    Cola ColaC;
    Cola ColaD;
    Lista ListaEstandar;
    Lista ListaUrgente;
    Arbol arbol;
    int arrayId[48];
    int arrayNumSeg[48];
    int tamanoArrayId;
    int tamanoArrayNumSeg;
};

#endif // GESTOR_HPP