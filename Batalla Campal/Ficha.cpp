#include "Ficha.h"
#include <string>
#include <iostream>

Ficha::Ficha(){
	
	this->fichaValida = SIN_DEFINIR;
	this->tipo = SIN_DEFINIR; //se van a ir definiendo luego así que las inicializamos en algún valor no más
				 //como los valores dependen del tipo y el tipo se define cuando tengas una ficha,
				 //inicializaremos las posiciones en algo para que no tengan basura no más :)
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


char Ficha::validarFicha(){
	
	if (( this->getPosicionY() == 1) && (this->getPosicionX() < 10) && (this->getTipo() == 'B')) { // agregar las
		
		this->fichaValida = BARCO;
		
	}
	
	if ((this->getPosicionY() == 0) && (this->getPosicionX() >= 10) && (this->getTipo() == 'S')){ // posiciones
			
		this->fichaValida = SOLDADO;
				
	}

	
	if ((this->getPosicionY() == 0) && (this->getTipo() == 'M')){ // X y Z para ver si es agua o tierra
		
		this->fichaValida = MINA;
	}
		
	if ((this->getPosicionY() > 0) && (this->getTipo() == 'A')){
				
		this->fichaValida = AVION;
		
	}
	
	else{
			
		if( (this->getPosicionY() == 0) && (this->getTipo() == 'A') ){
			
			throw "Los aviones no pueden ir en el suelo";
		}
		
		else{
			if ((this->getPosicionY() != 1) && ((this->getTipo() == 'S') || (this->getTipo() == 'B') || (this->getTipo() == 'M'))){
				
				throw "Esa ficha debe ir en el suelo";
			}
				
		}
	}
	
	return this->fichaValida;
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

void Ficha::setCoordenadas(){
	if(this->tipo == MINA){
		this->posicionY = 1;//tiene que estar en el piso
	}
	if(this->tipo == BARCO){
		this->posicionY = 1;//tiene que estar en el agua, creo que hay que chusmear la casilla acá
	}
	if(this->tipo == AVION){
		this->posicionY = 8;

	}
	if(this->tipo == SOLDADO){
		this->posicionY = 1;
	
	}
	//ademas de poner las restricciones, hay que hacer lo que sigue, después lo meto en los if correspondientes
	/*
	this->posicionX = rand()%;
	this->posicionY = rand()%;
	this->posicionZ = rand()%;
	*/
	this->validarFicha();	
}
