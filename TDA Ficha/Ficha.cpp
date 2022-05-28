#include "Ficha.h"
#include <string>
#include <iostream>

Ficha::Ficha(int posicionX,int posicionY,int posicionZ, char tipo){
	
	if ((posicionY < 0) || (posicionY > 20)){  //validar el ingreso de la posicion.
		posicionY = 0;
	}
	
	this->posicionX = posicionX;
	this->posicionY = posicionY;
	this->posicionZ = posicionZ;

	this->tipo = tipo;
	
}


Ficha::~Ficha(){
	
}


char Ficha::verQueFichaEs(){
	
	if (( this->getPosicionY() == 0) && (this->getPosicionX() < 10) && (this->getTipo() == 'B')) { // agregar las 
		
		this->fichaFinal = BARCO;
		
	}
	
	if ((this->getPosicionY() == 0) && (this->getPosicionX() >= 10) && (this->getTipo() == 'S')){ // posiciones
			
		this->fichaFinal = SOLDADO;
				
	}

	
	if ((this->getPosicionY() == 0) && (this->getTipo() == 'M')){ // X y Z para ver si es agua o tierra
		
		this->fichaFinal = MINA;
	}
		
	if ((this->getPosicionY() > 0) && (this->getTipo() == 'A')){
				
		this->fichaFinal = AVION;
		
	}
	
	else{
			
		if( (this->getPosicionY() == 0) && (this->getTipo() == 'A') ){
			
			throw "Los aviones no pueden ir en el suelo";
		}
		
		else{
			if ((this->getPosicionY() != 0) && ((this->getTipo() == 'S') || (this->getTipo() == 'B') || (this->getTipo() == 'M'))){
				
				throw "Esa ficha debe ir en el suelo";
			}
				
		}
	}
	
	return this->fichaFinal;	
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






