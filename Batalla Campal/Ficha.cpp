#include "Ficha.h"
#include <string>
#include <iostream>

//Se van a recibir las coordenadas generadas aleatoriamente
Ficha::Ficha(int posicionX,posicionY,posicionZ){
	
	this->fichaValida = SIN_DEFINIR;
	this->tipo = SIN_DEFINIR; //se van a ir definiendo luego así que las inicializamos en algún valor no más
				 //como los valores dependen del tipo y el tipo se define cuando tengas una ficha,
	if(this->posicionX > 0 && this->posicionX < dimension &&)		
	this->posicionX = -1;
	this->posicionY = -1; 
	this->posicionZ = -1;
	
}

Ficha::Ficha(char tipo){

	this->fichaValida = SIN_DEFINIR;
	if(tipo == BARCO || tipo == AVION || tipo == MINAS || tipo == SOLDADO){
		this->tipo = tipo;
	}
	else{
		this->tipo = SIN_DEFINIR;
	}
	this->posicionX = -1;
	this->posicionY = -1;
	this->posicionZ = -1;


}

Ficha::~Ficha(){
	
}

//Valida que las coordenadas sean válidas sin tener en cuenta el tipo
bool esPosicionValida(){
	bool esValida = false;
	if(this->getPosicionX() > 0 && this->getPosicionX() < dimension
	   && this->getPosicionY() > 0 && this->getPosicionY() < dimension
	   && this->getPosicionZ() > 0 && this->getPosicionZ() < dimension){
		return true;
	}
	return esValida;
}

bool Ficha::esTipoValido(){
	return (this->getTipo() == BARCO || this->getTipo() == MINA || this->getTipo() == SOLDADO || this->getTipo () == AVION)
}
char Ficha::validarFicha(){
	bool esValida = false;
	if(this->esPosicionValida() && this->esTipoValido()){
		if(this->getPosicionZ() == 1){
			if(this->getTipo() == AVION){
				esValida = false;
			}
			else{
				esValida = true;
			}
		else{
			if(this->getTipo() == AVION){
				esValida = true;
			}
			else{
				esValida = false;
			}
		}
	}
}

int Ficha::getPosicionY(){
	return this->posicionY;
}


char Ficha::getTipo(){
	return this->tipo;
}

int Ficha::getPosicionX(){
	return this->posicionX;
}

int Ficha::getPosicionZ(){
	return this->posicionZ;
}

void Ficha::setTipo(char tipo){
	if(tipo == BARCO || tipo == AVION || tipo == MINA || tipo ==SOLDADO){
		this->tipo = tipo;
	}
	else{
		throw "El tipo de ficha ingresado es erróneo. El tipo debe ser BARCO, AVION, MINA o SOLDADO.";
	}
}
	
//Este lo vamos a usar para mover al soldado
//No se recibe la posición Z porque jamás se debería modificar ya que el soldado no puede volar :)
//Los demás tipos de fichas no se pueden mover
void Ficha::setCoordenadasSoldado(int posicionX, int posicionY){
	if(this->tipo != SOLDADO){
		throw "No deberías cambiar la posición de esta ficha porque no es de soldado :)"
	}
	else{
		this->posicionX = posicionX;
		this->posicionY = posicionY;
	}
}
