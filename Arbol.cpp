#include "Arbol.hpp"

Arbol::Arbol() { 
    raiz = nullptr; 
}

void Arbol::insertar(Pedido pedido) { 
    raiz = insertar(raiz, pedido); 
}

pnodoAbb Arbol::insertar(pnodoAbb nodo, Pedido pedidoI)
{
    if(!nodo)
        return new NodoArbol(pedidoI);
    if(pedidoI.getNumSeg() <= nodo->pedido.getNumSeg())
        nodo->izq = insertar(nodo->izq, pedidoI);
    else
        nodo->der = insertar(nodo->der, pedidoI);
    return nodo;
}

void Arbol::pintar()
{
    pintar(raiz);
    cout << '\n';
}

void Arbol::pintar(pnodoAbb nodo)
{
    if(!nodo){
        return;
    }
    pintar(nodo->izq);
    cout << nodo->pedido.getNumSeg() << " ";
    pintar(nodo->der);
}

int Arbol::altura(pnodoAbb nodo)
{
    if(!nodo){
        return 0;
    }
    return 1 + max(altura(nodo->izq), altura(nodo->der));
}

void Arbol::dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int p,
                        char linkChar)
{
    if(!nodo)
        return;

    int h = output.size();
    string SP = " ";

    if(p < 0) {
        string extra(-p, ' ');
        for(string& s : output)
            if(!s.empty())
                s = extra + s;
        for(string& s : linkAbove)
            if(!s.empty())
                s = extra + s;
    }
    if(nivel < h - 1)
        p = max(p, (int)output[nivel + 1].size());
    if(nivel > 0)
        p = max(p, (int)output[nivel - 1].size());
    p = max(p, (int)output[nivel].size());

    if(nodo->izq) {
        int numeroQueQuieroImprimirEnElArbol =
            nodo->izq->pedido.getNumSeg(); 
        string izqdato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
        dibujarNodo(output, linkAbove, nodo->izq, nivel + 1, p - izqdato.size(), 'L');
        p = max(p, (int)output[nivel + 1].size());
    }

    int space = p - output[nivel].size();
    if(space > 0)
        output[nivel] += string(space, ' ');
    int numeroQueQuieroImprimirEnElArbol =
        nodo->pedido.getNumSeg();
    string nododato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
    output[nivel] += nododato;

    space = p + SP.size() - linkAbove[nivel].size();
    if(space > 0)
        linkAbove[nivel] += string(space, ' ');
    linkAbove[nivel] += linkChar;

    if(nodo->der)
        dibujarNodo(output, linkAbove, nodo->der, nivel + 1, output[nivel].size(), 'R');
}

void Arbol::dibujar()
{
    int h = altura(raiz);
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');

    for(int i = 1; i < h; i++) {
        for(int j = 0; j < linkAbove[i].size(); j++) {
            if(linkAbove[i][j] != ' ') {
                int size = output[i - 1].size();
                if(size < j + 1)
                    output[i - 1] += string(j + 1 - size, ' ');
                int jj = j;
                if(linkAbove[i][j] == 'L') {
                    while(output[i - 1][jj] == ' ')
                        jj++;
                    for(int k = j + 1; k < jj - 1; k++)
                        output[i - 1][k] = '_';
                } else if(linkAbove[i][j] == 'R') {
                    while(output[i - 1][jj] == ' ')
                        jj--;
                    for(int k = j - 1; k > jj + 1; k--)
                        output[i - 1][k] = '_';
                }
                linkAbove[i][j] = '|';
            }
        }
    }

    cout << '\n' << '\n';
    for(int i = 0; i < h; i++) {
        if(i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << '\n' << '\n';
}

int Arbol::numNodos() {
   return numNodos(raiz);
}

int Arbol::numNodos(pnodoAbb nodo) {
    if (nodo == nullptr) {
        return 0;
    }else{
        if(nodo -> pedido.getNumSeg() == 500){
            return 0 + numNodos(nodo->izq) + numNodos(nodo->der);
        }else{
            return 1 + numNodos(nodo->izq) + numNodos(nodo->der);
        }
        
    }
}

void Arbol::inorden(){
    inorden(raiz);
}

void Arbol::inorden(pnodoAbb nodo) {
    if (nodo != nullptr) {
        inorden(nodo->izq);
        nodo->pedido.mostrar();
        
        inorden(nodo->der);
    } 
}

void Arbol::mostrarPedidosEstandar(){
    mostrarPedidosEstandar(raiz);
    cout << "\n" ;
}

void Arbol::mostrarPedidosEstandar(pnodoAbb nodo){
    if (nodo != nullptr){
        mostrarPedidosEstandar(nodo->izq);
        if(!nodo->pedido.esUrgente() && nodo->pedido.getNumSeg() != 500) {
            nodo->pedido.mostrar();
        }
        mostrarPedidosEstandar(nodo->der);
    }
}

void Arbol::mostrarPedidosUrgente(){
    mostrarPedidosUrgente(raiz);
    cout << "\n";
}

void Arbol::mostrarPedidosUrgente(pnodoAbb nodo){
    if(nodo != nullptr){
        mostrarPedidosUrgente(nodo->izq);
    if(nodo->pedido.getNumSeg() != 500 && nodo->pedido.esUrgente()){
        nodo->pedido.mostrar();
    }
    mostrarPedidosUrgente(nodo->der);
    }
}

int Arbol::numImpares() {
    return numImpares(raiz);
}

int Arbol::numImpares(pnodoAbb nodo) {
    if (nodo == nullptr){
        return 0;
    }

    int cont = 0;

    if (nodo->pedido.getNumSeg() % 2 != 0) {
        cont = 1;
    }
    cont += numImpares(nodo->izq);
    cont += numImpares(nodo->der);

    return cont;
}

void Arbol::NodoHoja(){
    NodoHoja(raiz);
}

void Arbol::NodoHoja(pnodoAbb nodo){
    if(nodo == nullptr){
        return;
    }
    
    if(nodo->izq == nullptr && nodo->der == nullptr){
        nodo->pedido.mostrar();
    }
    NodoHoja(nodo->izq);
    NodoHoja(nodo->der);
}

void Arbol::borrarNodoNumSeg(int numSeg){
    borrarNodoNumSeg(raiz, numSeg);
}

pnodoAbb Arbol::borrarNodoNumSeg(pnodoAbb nodo, int numSeg){
    if (numSeg < nodo->pedido.getNumSeg()) {
        nodo->izq = borrarNodoNumSeg(nodo->izq, numSeg);
    } else if (numSeg > nodo->pedido.getNumSeg()) {
        nodo->der = borrarNodoNumSeg(nodo->der, numSeg);
    } else {
        
        if (!nodo->izq) {
            pnodoAbb temp = nodo->der;
            delete nodo;
              return temp;
        } else if (!nodo->der) {
            pnodoAbb temp = nodo->izq;
            delete nodo;
            return temp;  
        }

        
        pnodoAbb temp = encontrarMinimo(nodo->der);
        nodo->pedido = temp->pedido;  
        nodo->der = borrarNodoNumSeg(nodo->der, temp->pedido.getNumSeg());  
    }
    
    return nodo;
}


pnodoAbb Arbol::encontrarMinimo(pnodoAbb nodo) {
    if(nodo == nullptr || nodo->izq == nullptr){
        return nodo;
    }
    return encontrarMinimo(nodo->izq);
}

pnodoAbb Arbol::encontrarMaximo(pnodoAbb nodo){
    if(nodo == nullptr || nodo->der == nullptr){
        return nodo;
    }
    return encontrarMaximo(nodo->der);
}

void Arbol::buscarAbb(){
    buscarAbb(raiz);
}

void Arbol::buscarAbb(pnodoAbb nodo){
    if(nodo != nullptr){
            
        pnodoAbb minimo = encontrarMinimo(nodo->izq);
        if(minimo != nullptr){
            cout <<"\t" << setw(10) << "Pedido estandar con menor numero de seguimiento: " << endl;
            minimo->pedido.mostrar();
        }
            
        pnodoAbb maximo = encontrarMaximo(nodo->izq);
        if(maximo != nullptr){
            cout << "\t" << setw(10) << "Pedido estandar con mayor numero de seguimiento: " << endl;
            maximo->pedido.mostrar();
        }

        pnodoAbb minimoU = encontrarMinimo(nodo->der);
        if(minimoU != nullptr){
            cout << "\t" << setw(10) << "Pedido urgente con menor ID: " << endl;
            minimoU->pedido.mostrar();
        }
            
        pnodoAbb maximoU = encontrarMaximo(nodo->der);
        if(maximoU != nullptr){
            cout << "\t" << setw(10) << "Pedido urgente con mayor ID: " << endl;
            maximoU->pedido.mostrar();
        }
    
    }
}
void Arbol::eliminar(){
     raiz = eliminar(raiz);
}

pnodoAbb Arbol::eliminar(pnodoAbb nodo){
    if(nodo != nullptr){
        eliminar(nodo->izq);
        eliminar(nodo->der);
        delete nodo;
        return nullptr;
    }
    numNodos(raiz);
    return nullptr;
}

Arbol::~Arbol()
{
    
}
