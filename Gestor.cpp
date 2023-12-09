#include "Gestor.hpp"


Gestor::Gestor()
{
 tamanoArrayNumSeg = 0;
 tamanoArrayId = 0;
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

int Gestor::generarId(Pedido pedido)
{
    int idN;
    bool existe;
    do {
        if(pedido.esUrgente()){
            idN = rand() % 49 + 51;
        } else {
            idN = rand() % 49 + 1;
        }
        existe = false;
        for(int i = 0; i < tamanoArrayId; i++){
            if(arrayId[i] == idN){
                existe = true;
                break;
            }
        }
    } while(existe);
    if(tamanoArrayId<48){
        arrayId[tamanoArrayId] = idN;
        tamanoArrayId++;
    }
    return idN;

}

int Gestor::generarNumSeg(Pedido pedido){
    int NumSegS;
    bool existe;
    do {
        if(pedido.esUrgente()){
            NumSegS = rand() % 499 + 501;
        } else {
            NumSegS = rand() % 499 + 1;
        }
        existe = false;
        for(int i = 0; i < tamanoArrayNumSeg; i++){
            if(arrayNumSeg[i] == NumSegS){
                existe = true;
                break;
            }
        }
    } while(existe);
    if(tamanoArrayNumSeg<48){
        arrayNumSeg[tamanoArrayNumSeg] = NumSegS;
        tamanoArrayNumSeg++;
    } 
    return NumSegS;
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
          int id = generarId(pedido);
          pedido.setId(id);
          if(pedido.esUrgente() == 1) {
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
    for(int i = 0; i < tamanoArrayId; i++){
        arrayId[i] = 0;
    }
    for(int i = 0; i < tamanoArrayNumSeg; i++){
        arrayNumSeg[i] = 0;
    }
    
    tamanoArrayId = 0;
    tamanoArrayNumSeg = 0;
}

void Gestor::enlistarPedidos()
{
    Pedido pedido;
    while(ColaA.getLongitud() !=0){
        pedido = ColaA.extraer();
        int numseg = generarNumSeg(pedido);
        pedido.setNumSeg(numseg);
        ListaEstandar.insertar(pedido);
    }
    while(ColaB.getLongitud()!=0){
        pedido = ColaB.extraer();
        int numseg = generarNumSeg(pedido);
        pedido.setNumSeg(numseg);
        ListaEstandar.insertar(pedido);
    }
    while(ColaC.getLongitud()!=0){
        pedido = ColaC.extraer();
        int numseg = generarNumSeg(pedido);
        pedido.setNumSeg(numseg);
        ListaUrgente.insertar(pedido);
    }
    while(ColaD.getLongitud()!=0){
        pedido = ColaD.extraer();
        int numseg = generarNumSeg(pedido);
        pedido.setNumSeg(numseg);
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

void Gestor::buscarPedidos()
{
    Pedido pedidoMe = ListaUrgente.getMenor();
    Pedido pedidoMa = ListaEstandar.getMayor();
    
    cout << "Los pedidos menor y mayor son: " << endl;
    pedidoMe.mostrar();
    pedidoMa.mostrar();
    cout << endl;
}

void Gestor:: reiniciar()
{
    pilaPedidos.desapilar();
    borraPedidosColas();
    ListaUrgente.eliminar();
    ListaEstandar.eliminar();
    
    for(int i = 0; i < tamanoArrayId; i++){
        arrayId[i] = 0;
    }
    for(int i = 0; i < tamanoArrayNumSeg; i++){
        arrayNumSeg[i] = 0;
    }
    
    tamanoArrayId = 0;
    tamanoArrayNumSeg = 0;
}

void Gestor::insertarPedidosArbol(){
    Pedido pedido; 
    while(ListaUrgente.getLongitud() != 0){
         pedido = ListaUrgente.extraer();
         arbol.insertar(pedido);
    }
    while(ListaEstandar.getLongitud()!= 0){
        pedido = ListaEstandar.extraer();
        arbol.insertar(pedido);
    }
}

int Gestor::PedidosEnArbol(){
    return arbol.numNodos();  
}

void Gestor::dibujarAbb(){ //Apartado M
    Pedido pedidoAux;
    pedidoAux.setNumSeg(500);
    pedidoAux.setId(generarId(pedidoAux));
    arbol.insertar(pedidoAux);
    insertarPedidosArbol();
    arbol.dibujar();
}

void Gestor::pedidosArbolE(){ //Apartado N 
    cout << "\t" << setw(10) << "Los pedidos estandar son: " << endl;
    arbol.mostrarPedidosEstandar();
}

void Gestor::pedidosArbolU(){ //Apartado O
    cout << "\t" << setw(10) << "Los pedidos urgentes son: " << endl;
    arbol.mostrarPedidosUrgente();
}

void Gestor::PedidosInorden(){ //Apartado P
    cout << "\t" << setw(10) << "Los pedidos en colocados en inorden son: " << endl;
    arbol.inorden();
}

void Gestor::buscarPedidosArbol(){ //Apartado Q
    cout << "\t" << setw(10) << "Los pedidos buscados son: " << endl;
    arbol.buscarAbb();
}

void Gestor::NumSegImpar(){ // Apartado R
    cout <<  "\t"<< setw(10) << " Hay " << arbol.numImpares() << " pedidos con numero de seguimiento impar " << endl;
}

void Gestor::PedidosNodoHoja(){ //Apartado T
    cout <<"\t" << setw(10) << " Los pedidos que estan en un NodoHoja son: " << endl;
    arbol.NodoHoja();
    cout << endl;
}

void Gestor::eliminarPedido(){ //Apartado U
    
}

Gestor::~Gestor()
{
}

