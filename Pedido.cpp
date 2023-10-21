#include "Pedido.hpp"

Pedido::Pedido()
{
    this->urgente = (rand() % 2);
    this ->generarDNI();
}

void::generarID(bool esUrgente){
    if(esUrgente){
        id = (rand() % 51) + 49;
    } else{
        id = (rand() % 50) + 1;
    }   
}
void::generarNSeguimiento(bool esUrgente){
    if(esUrgente){
        nSeguimiento = (rand() % 501) + 499;
    } else{
        nSeguimiento = (rand() % 499) + 1;
    }
        
}
void ::generarDNI()
{
	char letras[]= "TRWAGMYFPDXBNJZSQVHLCKE";
	int numDNI = 0, aux = 1E7;
	for(int i = 0; i < 8; i++) {
		int num = rand() % 10;
		this->DNI[i] = '0' + num;
		numDNI = numDNI + num * aux;
		aux /= 10;
	}
	this->DNI[8] = letras[numDNI % 23];
	this->DNI[9] = '\0';
}

Pedido::~Pedido()
{
}

