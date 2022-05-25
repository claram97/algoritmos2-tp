#include "Cartas.h"
#include "Jugador.h"
#include <iostream>


using namespace std;

Cartas::Cartas(){

	this->tipoDeCarta = ' ';
	this->numeroDeCarta = NULL;
	this->descripcion = "";
}

Cartas::Cartas(char tipo, unsigned int numero, string descripcion){

	this->tipoDeCarta = tipo;
	this->numeroDeCarta = numero;
	this->descripcion = descripcion;
}

Cartas::Cartas(const Cartas & carta){

	this->tipoDeCarta = carta.tipoDeCarta;
	this->numeroDeCarta = carta.numeroDeCarta;
	this->descripcion = carta.descripcion;
}

char Cartas::getTipoDeCarta(){

	return this->tipoDeCarta;
}

void Cartas::setTipoDeCarta(char carta){

	this->tipoDeCarta = carta;
}

string Cartas::getDescripcion(){

	return this->descripcion;
}

void Cartas::setDescripcion(string descripcion){

	this->descripcion = descripcion;
}

unsigned int Cartas::getNumeroDeCarta(){

	return this->numeroDeCarta;
}

void Cartas::setNumeroDeCarta(unsigned int numero){

	this->numeroDeCarta = numero;
}

void Cartas::nuevaCarta(int aleatorio){   //constructor?

	switch(aleatorio){
		case 1:
			tipoDeCarta = AVION;
			descripcion = "Avion";
			break;

		case 2:
			tipoDeCarta = BARCO;
			descripcion = "Barco";
			break;

		case 3:
			tipoDeCarta = MISIL;
			descripcion = "Misil";
			break;
		
		case 4:
		    tipoDeCarta = MINAS;
		    descripcion = "Minas";
		    break;

		case 5:
		    tipoDeCarta = RADAR;
		    descripcion = "Radar";
		    break;

		case 6:
		    tipoDeCarta = SUPER;
		    descripcion = "Super";
		    break;

	}
}

Cartas::~Cartas(){
}

void Cartas::removerCarta(){  //provisorio

	this->tipoDeCarta = ' ';
	this->numeroDeCarta = NULL;
	this->descripcion = "";
}


