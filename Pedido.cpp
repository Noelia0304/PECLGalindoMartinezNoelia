#include "Pedido.hpp"

Pedido::Pedido()
{
    this->urgente = (rand() % 2);
    this ->generarDNI();
    this ->generarNSeguimiento();
    
}
bool Pedido::esUrgente()
{
    return this->urgente; // 1: urgente.0: estándar
}

int Pedido::getId()
{
    return this-> ID;
}
void Pedido:: setId(int ID)
{
    this->ID = ID;
}

void Pedido::generarNSeguimiento(){
    if(urgente){
        nSeguimiento = (rand() % 501) + 499;
    } else{
        nSeguimiento = (rand() % 499) + 1;
    }
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

void Pedido::mostrar()
{
    string urgencia = "estandar";
    if(urgente)
        urgencia = "urgente";
    
    cout << "\t" << setw(10) << DNI << " con ID " << ID << " del tipo " << urgencia << " con numero de seguimiento " << nSeguimiento << endl;
}

Pedido::~Pedido()
{
}

