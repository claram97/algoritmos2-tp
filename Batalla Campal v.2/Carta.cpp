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

std::string Carta::getDescripcion(){

	return this->descripcion;
}

Carta::~Carta(){
}



