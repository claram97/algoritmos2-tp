#include "Ficha.h"
#include <string>
#include <iostream>

//Se van a recibir las coordenadas generadas aleatoriamente y el tipo
Ficha::Ficha(char tipo,int posicionX,int posicionY,int posicionZ){

	if(this->esPosicionValida(posicionX, posicionY, posicionZ) && this->esTipoValido(tipo)){

		this->posicionX = posicionX;
		this->posicionY = posicionY; 
		this->posicionZ = posicionZ;
		this->tipo = tipo;
		this->fichaValida = 'O'; //Nose que es


		if(!this->tipoConcuerdaConPosicion(posicionX, posicionY, posicionZ, tipo)){
			this->tipo = SIN_DEFINIR;
		}
	}
	else{
		if(!this->esPosicionValida(posicionX, posicionY, posicionZ)){
			throw "Error en coordenadas de la ficha.";
		}
		if(!this->esTipoValido(tipo)){
			throw "Tipo inválido de ficha.";
		}
	}
}

Ficha::~Ficha(){
	
}

//Valida que las coordenadas sean válidas sin tener en cuenta el tipo
bool Ficha::esPosicionValida(int x, int y, int z){
	bool esValida = false;
	if(x > 0 && /*x < dimension && */ y > 0 /*&& y < dimension*/ && z > 0 /*&& z < dimension*/){
		return true;
	}
	return esValida;
}

bool Ficha::esTipoValido(char tipo){
	return (tipo == BARCO || tipo == MINA || tipo == SOLDADO || tipo == AVION);
}

bool Ficha::tipoConcuerdaConPosicion(int posicionX, int posicionY, int posicionZ, char tipo){
	bool esValida = false;
	if(this->esPosicionValida(posicionX, posicionY, posicionZ) && this->esTipoValido(tipo)){
		if(this->getPosicionZ() == 1){
			if(this->getTipo() == AVION){
				esValida = false;
			}
			else{
				esValida = true;
			}
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
	return esValida;
}


char Ficha::getTipo(){
	return this->tipo;
}

int Ficha::getPosicionX(){
	return this->posicionX;
}

int Ficha::getPosicionY(){
	return this->posicionY;
}

int Ficha::getPosicionZ(){
	return this->posicionZ;
}

void Ficha::definirTipo(char tipo){
	this->tipo = tipo;
	if(!this->esTipoValido(tipo)){
		this->tipo = SIN_DEFINIR;
	}
}
	
//Este lo vamos a usar para mover al soldado
//No se recibe la posición Z porque jamás se debería modificar ya que el soldado no puede volar :)
//Los demás tipos de fichas no se pueden mover
void Ficha::setCoordenadasSoldado(int posicionX, int posicionY){
	if(this->tipo != SOLDADO){
		throw "No deberías cambiar la posición de esta ficha porque no es de soldado :)";
	}
	else{
		this->posicionX = posicionX;
		this->posicionY = posicionY;
	}
}
