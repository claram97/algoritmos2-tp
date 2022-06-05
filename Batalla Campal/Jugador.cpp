#include "Jugador.h"

using namespace std;


Jugador::Jugador(int id, int cantidadSoldados) {
	this->id = id;
	this->cantidadSoldados = cantidadSoldados;
	this->cantidadHerramientas = cantidadHerramientas;
	this->herramientas = new Lista<Ficha*>();
	this->soldados = new Lista<Ficha*>();
	this->cartas = new Lista<Carta*>();
	this->estado = EN_BATALLA;
}

Jugador::~Jugador() {
	if (this->soldados) {
		for (unsigned int i = 1; i < this->getCantidadDeSoldados(); i++) {
			this->soldados->remover(i);
		}
		delete[] this->soldados;
	}
	if (this->herramientas) {
		for (unsigned int i = 1; i < this->getCantidadDeHerramientas(); i++) {
			this->herramientas->remover(i);
		}
		delete[] this->herramientas;
	}
	if (this->cartas) {
		for (unsigned int i = 0; i < this->getCantidadDeCartas(); i++) {
			this->cartas->remover(i);
		}
		delete[] this->cartas;
	}
}

unsigned int Jugador::getCantidadDeHerramientas() {
	return this->herramientas->contarElementos();
}

int Jugador::getCantidadDeSoldados() {
	return this->soldados->contarElementos();

}

unsigned int Jugador::getCantidadDeCartas() {
	return this->cartas->contarElementos();
}

/*
void Jugador::setFicha(Ficha* ficha){
    this->fichas->push_back(ficha);
}
*/

Ficha* Jugador::getHerramienta(int id){
	return this->herramientas->get(id);
}

Ficha* Jugador::getSoldado(int numSoldado){
	return this->soldados->get(numSoldado);
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


void Jugador::setEstado(EstadoJugador estado) {
	this->estado = estado;
}

EstadoJugador Jugador::getEstadoJugador(){
	return this->estado;
}

void Jugador::nuevaCarta(int aleatorio){
	if( this->cartas->contarElementos() < MAX_CARTAS){
		this->cartas->add(new Carta(aleatorio));
	}
}

Carta* Jugador::getCarta(unsigned int i){
	return this->cartas->get(i);
}

unsigned int Jugador::getId(){
	return this->id;
}


void Jugador::nuevoSoldado(int fila, int columna){

	this->soldados->add(new Ficha(SOLDADO, fila, columna, 1));
}

void Jugador::nuevaHerramienta(char FICHA, int fila, int columna, int altura){
	if( this->cartas->contarElementos() < MAX_HERRAMIENTAS){
		this->herramientas->add(new Ficha(FICHA, fila, columna, altura));
	}else{
		throw "No se pueden poner mas herramientas";
	}
}

void Jugador::eliminarSoldado(int id){

	this->soldados->remover(id);
	this->cantidadSoldados--;
}

void Jugador::eliminarCarta(int id){
	this->cartas->remover(id);
}

void Jugador::eliminarHerramienta(int id){
	this->herramientas->remover(id);
}

