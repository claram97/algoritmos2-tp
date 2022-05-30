#include "Jugador.h"

using namespace std;


Jugador::Jugador(int id, int cantidadSoldados) {
	this->id = id;
	this->cantidadSoldados = cantidadSoldados;
	this->fichas = new Lista<Ficha*>();

	for(int i = 0; i < cantidadSoldados; i++){
		this->fichas->add(new Ficha(SOLDADO));
	}

	this->cartas = new Lista<Carta*>();
	this->estado = EN_JUEGO;
}

Jugador::~Jugador() {
	if (this->fichas) {
		for (unsigned int i = 0; i < this->getCantidadDeFichas(); i++) {
			this->fichas->remover(i);
		}
		delete[] this->fichas;
	}
	if (this->cartas) {
		for (unsigned int i = 0; i < this->getCantidadDeCartas(); i++) {
			this->cartas->remover(i);
		}
		delete[] this->cartas;
	}
}

unsigned int Jugador::getCantidadDeFichas() {
	return this->fichas->contarElementos();
}

unsigned int Jugador::getCantidadDeSoldados() {
	unsigned int cantidadDeSoldados = 0;
	for (unsigned int i = 0; i < this->getCantidadDeFichas(); i++) {
		if (this->fichas->get(i+1)->getTipo() == SOLDADO) {
			cantidadDeSoldados++;
		}
	}
	return cantidadDeSoldados;
}

unsigned int Jugador::getCantidadDeCartas() {
	return this->cartas->contarElementos();
}

/*
void Jugador::setFicha(Ficha* ficha){
    this->fichas->push_back(ficha);
}
*/

Ficha* Jugador::getFicha(int id){
	return this->fichas->get(id);
}

/*
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
*/

void Jugador::eliminarFicha(int id){
	Ficha* ficha = this->getFicha(id);
	delete ficha;
}

void Jugador::setEstado(EstadoJugador estado) {
	this->estado = estado;
}

EstadoJugador Jugador::getEstadoJugador(){
	return this->estado;
}

void Jugador::nuevaCarta(){
	if( this->cartas->contarElementos() < MAX_CARTAS){
		this->cartas->add(new Carta());
	}
}

Carta* Jugador::getCarta(unsigned int i){
	return this->cartas->get(i);
}

unsigned int Jugador::getId(){
	return this->id;
}
