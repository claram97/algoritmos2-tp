//============================================================================
// Name        : player.cpp
// Author      : Martina Souza
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "jugador.h"

using namespace std;

Jugador::Jugador(int id, int cantidadDeFichas, std::deque<int*>* cartas) {
	this->id = id;
	this->cantidadDeFichas = cantidadDeFichas;
	this->cartas = cartas;
}

int Jugador::obtenerCantidadDeFichas() {
	return this->cantidadDeFichas;
}
int Jugador::obtenerCantidadDeCartas() {
	return this->cartas->size();
}
void Jugador::agregarCarta(int* carta) {
	if (this->obtenerCantidadDeCartas() <= MAX_CARTAS) {
		this->cartas->push_back(carta);
	}
}
int* Jugador::obtenerCarta() {
	int *carta = this->cartas->front();
	this->cartas->pop_front();
	return carta;
}
void Jugador::decrementarCantidadDeFichas() {
	this->cantidadDeFichas = this->cantidadDeFichas - 1;
}

