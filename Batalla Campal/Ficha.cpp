#include "Ficha.h"
#include <string>
#include <iostream>

//Se van a recibir las coordenadas generadas aleatoriamente
Ficha::Ficha(int posicionX,int posicionY,int posicionZ){
	if(this->esPosicionValida()){
		this->posicionX = posicionX;
		this->posicionY = posicionY; 
		this->posicionZ = posicionZ;
		this->tipo = SIN_DEFINIR;
	}
	
}

Ficha::Ficha(char tipo,int posicionX,int posicionY,int posicionZ){
	if(this->esPosicionValida() && this->esTipoValido()){
		this->posicionX = posicionX;
		this->posicionY = posicionY; 
		this->posicionZ = posicionZ;
		this->tipo = tipo;
		if(!this->tipoConcuerdaConPosicion()){
			this->tipo = SIN_DEFINIR;
		}
	}
	else{
		if(!this->esPosicionValida()){
			throw "Error en coordenadas del soldado."
		}
		if(!this->esTipoValido()){
			throw "Tipo inválido de ficha."
		}
	}
}

Ficha::~Ficha(){
	
}

void Ficha::definirTipo(char tipo){
	this->tipo = tipo;
	if(!this->tipoConcuerdaConPosicion()){
		this->tipo = SIN_DEFINIR;
	}
}

//Valida que las coordenadas sean válidas sin tener en cuenta el tipo
bool tipoConcuerdaConPosicion(){
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

bool Ficha::validarFicha(){
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
