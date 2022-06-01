#include "Carta.h"
#include "Jugador.h"

Carta::Carta(int aleatorio){

	switch (aleatorio){
		case 1:
			this->tipoDeCarta = AVION;
			this->descripcion = "Avion";
			break;
		case 2:
			this->tipoDeCarta = BARCO;
			this->descripcion = "Barco";
			break;
		case 3:
			this->tipoDeCarta = MINA;
			this->descripcion = "Mina";
			break;
		case 4:
			this->tipoDeCarta = RADAR;
			this->descripcion = "Radar";
			break;
		case 5:
			this->tipoDeCarta = SUPER;
			this->descripcion = "Super Bomba";
			break;
		case 6:
			this->tipoDeCarta = MISIL;
			this->descripcion = "Misil";
			break;
	}
}

char Carta::getTipoDeCarta(){

	return this->tipoDeCarta;
}

void Carta::setTipoDeCarta(char carta){

	this->tipoDeCarta = carta;
}

std::string Carta::getDescripcion(){

	return this->descripcion;
}

void Carta::setDescripcion(std::string descripcion){

	this->descripcion = descripcion;
}

Carta::~Carta(){
}

void Carta::removerCarta(){  //provisorio

	this->tipoDeCarta = ' ';
	this->descripcion = "";
}


