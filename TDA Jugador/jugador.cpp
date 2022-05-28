//============================================================================
// Name        : player.cpp
// Author      : Martina Souza
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "jugador.h"

using namespace std;

unsigned int id;
	Ficha** fichas;//el jugador necesita las fichas
	unsigned int cantidadDeFichas;//por si acaso, vemos si se usa
	unsigned int cantidadFichasSoldados; 	//para saber si sigue o no el juego, la cantidad de fichas totales va a ser la cantidad
						//de fichas soldados + las otras :D
	Carta** cartas;
	unsigned int cantCartas;
	estadoJugador estadoDelJugador; //deberia empezar en jugando


Jugador::Jugador(unsigned int id, unsigned int cantidadJugadores) {
	if(id > MIN_JUGADORES &&  id < MAX_JUGADORES){
		this->id = id;
	}
	else{
		throw "Id inválido".
	}
	
	fichas = new Vector <Fichas*>(MAX_FICHAS,NULL);
	
	for(int i = 0; i < MAX_FICHAS; i++){
		fichas[i]->setTipo(soldado);
		fichas[i]->setCoordenadas();
	}
	
	if(cantidadDeSoldados > MIN_SOLDADOS && cantidadDeSoldados < MAX_SOLDADOS){
		this->cantidadDeSoldados = cantidadDeSoldados;
		
	}
	

	for (unsigned int i = 0; i < this->cantidadDeSoldados; i++) {
		int* soldado = new int(i);
		this->soldados->push_back(soldado);
	}

	this->cartas = new std::vector<int*>();
	for (unsigned int i = 0; i < MAX_CARTAS; i++) {
		int* carta = new int(5);
		this->cartas->push_back(carta);
	}
}

Jugador::~Jugador() {
	if (soldados) {
		for (unsigned int i = 0; i < this->cantidadDeSoldados; i++) {
			delete soldados->at(i);
		}
		delete[] soldados;
	}
	if (cartas) {
		for (unsigned int i = 0; i < this->getCantidadDeCartas(); i++) {
			delete cartas->at(i);
		}
		delete[] cartas;
	}
}

unsigned int Jugador::getCantidadDeSoldados() {
	return this->cantidadDeSoldados;
}

void Jugador::setCantidadDeSoldados(unsigned int cantidadDeSoldados) {
	if (cantidadDeSoldados > 0) {
		this->cantidadDeSoldados = cantidadDeSoldados;
	} else {
		throw "Cantidad invalida de soldado.";
	}
}

unsigned int Jugador::getCantidadDeCartas() {
	return this->cartas->size();
}

void Jugador::crearCarta() {
	if (this->getCantidadDeCartas() <= MAX_CARTAS) {
		int* carta = new int();
		this->cartas->push_back(carta);
	}
}
int* Jugador::getCarta() {
	int* carta = this->cartas->begin()[0];
	this->cartas->erase(this->cartas->begin());
	return carta;
}
void Jugador::decrementarCantidadDeSoldados() {
	this->cantidadDeSoldados = this->cantidadDeSoldados - 1;
}
