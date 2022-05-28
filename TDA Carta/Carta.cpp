#include "Carta.h"
#include "Jugador.h"
#include <iostream>


using namespace std;

Carta::Carta(){

	this->tipoDeCarta = ' ';
	this->numeroDeCarta = NULL;
	this->descripcion = "";
}

Carta::Carta(char tipo, unsigned int numero, string descripcion){

	this->tipoDeCarta = tipo;
	this->numeroDeCarta = numero;
	this->descripcion = descripcion;
}

Carta::Carta(const Carta & carta){

	this->tipoDeCarta = carta.tipoDeCarta;
	this->numeroDeCarta = carta.numeroDeCarta;
	this->descripcion = carta.descripcion;
}

char Carta::getTipoDeCarta(){

	return this->tipoDeCarta;
}

void Carta::setTipoDeCarta(char carta){

	this->tipoDeCarta = carta;
}

string Carta::getDescripcion(){

	return this->descripcion;
}

void Carta::setDescripcion(string descripcion){

	this->descripcion = descripcion;
}

unsigned int Carta::getNumeroDeCarta(){

	return this->numeroDeCarta;
}

void Carta::setNumeroDeCarta(unsigned int numero){

	this->numeroDeCarta = numero;
}

Carta::~Carta(){
}

void Carta::removerCarta(){  //provisorio

	this->tipoDeCarta = ' ';
	this->numeroDeCarta = NULL;
	this->descripcion = "";
}


