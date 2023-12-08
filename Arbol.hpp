#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "NodoArbol.hpp"
#include "Lista.hpp"

#include <vector>
using namespace std;

class Arbol
{
public:
    Arbol();
    void insertar(Pedido pedido);
    
    void pintar();
    void dibujar();
    int numNodos();
    int numNodos(pnodoAbb nodo);
    void inorden();
    void inorden(pnodoAbb nodo);
    int numImpares();
    int numImpares(pnodoAbb nodo);
    void mostrarPedidosEstandar();
    void mostrarPedidosEstandar(pnodoAbb nodo);
    void mostrarPedidosUrgente();
    void mostrarPedidosUrgente(pnodoAbb nodo);
    void NodoHoja();
    void NodoHoja(pnodoAbb nodo);
    pnodoAbb encontrarMinimo(pnodoAbb nodo);
    pnodoAbb encontrarMaximo(pnodoAbb nodo);
    void buscarAbb();
    void buscarAbb(pnodoAbb nodo);
    ~Arbol();

private:
    pnodoAbb raiz;
    pnodoAbb insertar(pnodoAbb, Pedido);
    pnodoAbb insertarOrdenNumSeg(pnodoAbb, Pedido);
    void pintar(pnodoAbb);
    int altura(pnodoAbb);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int minPos,
                     char linkChar);
};

#endif // ARBOL_HPP
