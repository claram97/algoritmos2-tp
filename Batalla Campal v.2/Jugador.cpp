#include "Jugador.h"

using namespace std;


Jugador::Jugador(unsigned int id, int cantidadSoldados) {
	this->id = id;
	this->cantidadSoldados = cantidadSoldados;
	this->cantidadHerramientas = 0;
	this->herramientas = new Lista<Ficha*>();
	this->soldados = new Lista<Ficha*>();
	this->cartas = new Lista<Carta*>();
	this->estado = EN_BATALLA;
}

Jugador::~Jugador() {
	if (this->soldados) {
		for (int i = 1; i < this->getCantidadDeSoldados(); i++) {
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

Ficha* Jugador::getHerramienta(int id){
	return this->herramientas->get(id);
}

Lista<Ficha*>* Jugador::getSoldado(){
	return this->soldados;
}

unsigned int Jugador::buscarIdSoldado(int fila, int columna){
	bool encontrado = false;
	this->soldados->reiniciarCursor();
	int id = 0;
	while(this->soldados->avanzarCursor() && (!encontrado)){
		id++;
		if(this->soldados->getCursor()->getPosicionX() == fila && this->soldados->getCursor()->getPosicionY() == columna){
			encontrado = true;

		}
	}
	return id;
}

bool Jugador::buscarSoldado(int fila, int columna){
	bool encontrado = false;
	this->soldados->reiniciarCursor();
	while(this->soldados->avanzarCursor() && (!encontrado)){
		if(this->soldados->getCursor()->getPosicionX() == fila && this->soldados->getCursor()->getPosicionY() == columna){
			return this->soldados->getCursor();
			encontrado = true;
		}
	}
	return encontrado;
}

Lista<Carta*>* Jugador::getCarta(){
	return this->cartas;
}

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

void Jugador::eliminarSoldado(int fila, int columna){

	this->soldados->remover(this->buscarIdSoldado(fila, columna));
	this->cantidadSoldados--;
}

void Jugador::eliminarCarta(int id){          //FALTA ELIMINAR
	this->cartas->remover(id);
}

void Jugador::eliminarHerramienta(int id){          //FALTA ELIMINAR
	this->herramientas->remover(id);
}

