//============================================================================
// Name        : player.cpp
// Author      : Martina Souza
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "jugador.h"

using namespace std;


Jugador::Jugador(int id) {
	this->id = id;
	this->fichas = new std::vector<Ficha*>();
	this->cartas = new std::vector<Carta*>();
	this->estado = EstadoJugador::JUGANDO;
}

Jugador::~Jugador() {
	if (this->fichas) {
		for (unsigned int i = 0; i < this->getCantidadDeFichas(); i++) {
			delete this->fichas->at(i);
		}
		delete[] this->fichas;
	}
	if (this->cartas) {
		for (unsigned int i = 0; i < this->getCantidadDeCartas(); i++) {
			delete this->cartas->at(i);
		}
		delete[] this->cartas;
	}
}

unsigned int Jugador::getCantidadDeFichas() {
	return this->fichas->size();
}

unsigned int Jugador::getCantidadDeSoldados() {
	unsigned int cantidadDeSoldados = 0;
	for (unsigned int i = 0; i < this->getCantidadDeFichas(); i++) {
		if (this->fichas->at(i)->getTipo() == SOLDADO) {
			cantidadDeSoldados++;
		}
	}
	return cantidadDeSoldados;
}

unsigned int Jugador::getCantidadDeCartas() {
	return this->cartas->size();
}

void Jugador::setFicha(Ficha* ficha){
    this->fichas->push_back(ficha);
}

Ficha* Jugador::getFicha(int id){
	return this->fichas->at(id);
}

void Jugador::setCarta(Carta* carta) {
	if (this->getCantidadDeCartas() <= MAX_CARTAS) {
		this->cartas->push_back(carta);
	}
}

Carta* Jugador::getCarta() {
	Carta* carta = this->cartas->begin()[0];
	this->cartas->erase(this->cartas->begin());
	return carta;
}

void Jugador::eliminarFicha(int id){
	Ficha* ficha = this->getFicha(id);
	delete ficha;
}

void Jugador::setEstado(EstadoJugador estado) {
	this->estado = estado;
}
