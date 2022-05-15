//============================================================================
// Name        : player.cpp
// Author      : Martina Souza
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "jugador.h"

using namespace std;

Jugador::Jugador(int id, int cantidadDeFichas, int* cartas) {
	this->id = id;
	this->cantidadDeFichas = cantidadDeFichas;
	this->cartas = cartas;
}

int Jugador::obtenerCantidadDeFichas() {
	return this->cantidadDeFichas;
}

