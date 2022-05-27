//============================================================================
// Name        : player.cpp
// Author      : Martina Souza
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "jugador.h"

using namespace std;

Jugador::Jugador(int id, int cantidadDeFichas, std::deque<int**> cartas) {
	this->id = id;
	if(cantidadDeFichas > 0){
		this->cantidadDeFichas = cantidadDeFichas;
		this->fichas = new Ficha*[this->cantidadDeFichas];
        	for(int i = 0; i < this->cantidadDeFichas; i++){
            		fichas[i] = NULL;
       		}
	}
	this->cartas = cartas;
	
    }
    
    if(amountOfTokens <= 0){
        throw "Invalidad amount of tokens.";
    }
}

unsigned int Jugador::getCantidadDeFichas() {
	return this->cantidadDeFichas;
}

void Jugador::setCantidadDeFichas(unsigned int cantidadDeFichas){
    if(cantidadDeFichas > 0){
        this->cantidadDeFichas = cantidadDeFichas;
    }
    else{
        throw "Invalid amount of tokens.";
    }
}

unsigned int Jugador::getCantidadDeCartas() {
	return this->cartas->size();
}
void Jugador::setCarta(int* carta) {
	if (this->obtenerCantidadDeCartas() <= MAX_CARTAS) {
		this->cartas->push_back(carta);
	}
}
int* Jugador::getCarta() {
	int *carta = this->cartas->front();
	this->cartas->pop_front();
	return carta;
}
void Jugador::decrementarCantidadDeFichas() {
	this->cantidadDeFichas = this->cantidadDeFichas - 1;
}

