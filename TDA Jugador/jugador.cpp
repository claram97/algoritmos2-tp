//============================================================================
// Name        : player.cpp
// Author      : Martina Souza
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "jugador.h"

using namespace std;

Jugador::Jugador(int id, int cantidadDeSoldados) {
	this->id = id;
	this->cantidadDeSoldados = cantidadDeSoldados;

	this->soldados = new std::vector<int*>();
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
