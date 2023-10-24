#include "Pedido.hpp"

Pedido::Pedido()
{
    this->urgente = (rand() % 2);
    this ->generarDNI();
    this ->generarID();
    this ->generarNSeguimiento();
}

void Pedido::generarID(){
    if(urgente){
        id = (rand() % 51) + 49;
    } else{
        id = (rand() % 50) + 1;
    } 
}
bool Pedido::esUrgente()
{
    return this -> urgente; // 1: urgente.0: estándar
}
void Pedido::generarNSeguimiento(){
    if(urgente){
        nSeguimiento = (rand() % 501) + 499;
    } else{
        nSeguimiento = (rand() % 499) + 1;
    }
}
void Pedido::mostrar()
{
    string urgencia = "Estandar";
    if(urgente){
        urgencia = "Urgente";
    }
    cout << "\t" << setw(10) << DNI << "con ID" << ID << "del tipo" << urgencia << "con numero de seguimiento" << nSeguimiento << endl;
}
void Pedido::generarDNI()
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

