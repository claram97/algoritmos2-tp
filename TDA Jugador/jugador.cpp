//============================================================================
// Name        : player.cpp
// Author      : Martina Souza
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>


using namespace std;

class Jugador {

private:
	unsigned int id;
	int cantidadDeFichas;
	int* cartas; //TODO: Reemplazar int por TDA cartas

public:
	Jugador(int id, int cantidadDeFichas, int* cartas) {
		this->id = id;
		this->cantidadDeFichas = cantidadDeFichas;
		this->cartas = cartas;
	}

	int obtenerCantidadDeFichas() {
		return this->cantidadDeFichas;
	}
};

