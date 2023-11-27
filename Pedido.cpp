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

void Pedido::setId(int numero)
{
    this->ID = numero;
}

int Pedido::getNumSeg()
{
    return this-> numSeg;
}

void Pedido::setNumSeg(int numero)
{
    this->numSeg = numero;
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
    if(urgente){
       urgencia = "urgente"; 
    }
    if(!ID == 0 && !numSeg == 0){
       cout << "\t" << setw(10) << DNI << " del tipo " << urgencia << " con ID " << ID << " con numero de seguimiento " << numSeg << endl;; 
    }else{
        if(numSeg == 0 && !ID == 0){
            cout << "\t" << setw(10) << DNI << " del tipo " << urgencia << " con ID " << ID << endl;
        }else{
           cout << "\t" << setw(10) << DNI << " del tipo " << urgencia << endl; 
        }
    }
}    

Pedido::~Pedido()
{
}

