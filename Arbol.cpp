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

/*pnodoAbb Arbol::insertarOrdenNumSeg(pnodoAbb nodo, Pedido pedidoI)
{
    if(!nodo)
        return new NodoArbol(pedidoI);
    if(pedidoI.getNumSeg() <= nodo->pedido.getNumSeg())
        nodo->der = insertar(nodo->der, pedidoI);
    else
        nodo->izq = insertar(nodo->izq, pedidoI);
    return nodo;
}*/

void Arbol::mostrarPedidosEstandar(pnodoAbb nodo){
    if (nodo){
        mostrarPedidosEstandar(nodo->izq);
        if(!nodo->pedido.esUrgente()){
            nodo->pedido.mostrar();
        }
        mostrarPedidosEstandar(nodo->der);
    }
}
        

void Arbol::pintar()
{
    pintar(raiz);
    cout << '\n';
}

void Arbol::pintar(pnodoAbb nodo)
{
    if(!nodo)
        return;
    pintar(nodo->izq);
    cout << nodo->pedido.getNumSeg() << " ";
    pintar(nodo->der);
}

int Arbol::altura(pnodoAbb nodo)
{
    if(!nodo)
        return 0;
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
    Lista pedidosUrgentes, pedidosNoUrgentes;
    return inorden(raiz, pedidosUrgentes, pedidosNoUrgentes);
}

void Arbol::inorden(pnodoAbb nodo, Lista (pedidosUrgentes), Lista (pedidosNoUrgentes)) {
    if (nodo != nullptr) {
        inorden(nodo->izq, pedidosUrgentes, pedidosNoUrgentes);

        if (nodo->pedido.esUrgente()) {
            // Insertar en orden ascendente en la lista de pedidos urgentes
            pedidosUrgentes.insertarOrdenNumSeg(nodo->pedido);
            pedidosUrgentes.mostrar();
        } else {
            // Insertar en orden ascendente en la lista de pedidos no urgentes
            pedidosNoUrgentes.insertarOrdenNumSeg(nodo->pedido);
            pedidosNoUrgentes.mostrar();
        }

        inorden(nodo->der, pedidosUrgentes, pedidosNoUrgentes);
    }
}

int Arbol::numImpares() {
    return numImpares(raiz);
}

int Arbol::numImpares(pnodoAbb nodo) {
    if (nodo == nullptr) {
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

/*void Arbol::borrarNodo(pnodoAbb nodo){
    pnodoAbb nuevo;
    if(nodo->izq == nullptr){
        nuevo = nodo->der;
        delete nodo; 
    }else{
        if(nodo->der == nullptr){
            nuevo = nodo->izq;
            delete nodo;
        }else{
            pnodoAbb sucesor = encontrarMinimo(nodo->der);
            nodo->pedido = sucesor->pedido;
            nodo->der = borrarNodo(sucesor, nodo->der);
            
        }
    }  
}

pnodoAbb Arbol::borrarNodo(pnodoAbb nodo, pnodoAbb raiz) {
    if (raiz == nullptr) {
        return raiz;
    }

    if (nodo->valor < raiz->valor) {
        raiz->izq = borrarNodo(nodo, raiz->izq);
    } else if (nodo->valor > raiz->valor) {
        raiz->der = borrarNodo(nodo, raiz->der);
    } else {
        
        if (raiz->izq == nullptr) {
            pnodoAbb temp = raiz->der;
            delete raiz;
            return temp;
        } else if (raiz->der == nullptr) {
            pnodoAbb temp = raiz->izq;
            delete raiz;
            return temp;
        }

        // Nodo con dos hijos
        pnodoAbb sucesor = encontrarMinimo(raiz->der);
        raiz->valor = sucesor->valor;
        raiz->der = borrarNodo(sucesor, raiz->der);
    }

    return raiz;
}*/

pnodoAbb Arbol::encontrarMinimo(pnodoAbb nodo) {
    if(nodo == nullptr){
        return nullptr;
    }
    
    while (nodo->izq != nullptr) {
        nodo = nodo->izq;
    }
    return nodo;
}

pnodoAbb Arbol:encontrarMaximo(pnodoAbb nodo){
    if(nodo == nullptr){
        return nullptr;
    }
    
    while(nodo->der != nullptr){
        nodo = nodo->der;
    }
    return nodo;
}

void Arbol::buscarAbb(){
    pnodoAbb minimoEstandar = encontrarMinimo(raiz);
    pnodoAbb maximoEstandar = encontrarMaximo(raiz);
    
    if(minimoEstandar != nullptr){
        cout << "Pedido estandar con menor numero de seguimiento: " << endl;
        minimoEstandar->pedido.mostrar();
    }
    
    if(maximoEstandar != nullptr){
        cout << "Pedido estandar con mayor numero de seguimiento: " << endl;
        maximoEstandar->pedido.mostrar();
    }
    
    buscarAbb(raiz);
}

void Arbol::buscarAbb(pnodoAbb nodo){
    if(nodo == nullptr){
        return;
    } else{
        if(!nodo->pedido.esUrgente()){
            nodo->pedido.mostrar();
            
            pnodoAbb minimo = encontrarMinimo(nodo->izq);
            pnodoAbb maximo = encontrarMaximo(nodo->izq);
            
            if(minimo != nullptr){
                cout << "Pedido urgente con menor ID: " << endl;
                minimo->pedido.mostrar();
            }
            
            if(maximo != nullptr){
                cout << "Pedido urgente con mayor ID: " << endl;
                maximo->pedido.mostrar();
            }
        }
        buscarAbb(nodo->izq);
        buscarAbb(nodo->der);
    }
}

Arbol::~Arbol() {

}
