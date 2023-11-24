#include "Pedido.hpp"

Pedido::Pedido()
{
    this->urgente = (rand() % 2);
    this ->generarDNI();
    this -> ID = 0;
    this -> numSeg = 0; 
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

int Pedido::getNumSeg()
{
    return this-> numSeg;
}

void Pedido:: setNumSeg(int numSeg)
{
    this->numSeg = numSeg;
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
    cout << "\t" << setw(10) << DNI << " del tipo " << urgencia << endl;
}

Pedido::~Pedido()
{
}

