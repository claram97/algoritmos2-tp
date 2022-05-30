#include "BatallaCampal.h"
#include "Jugador.h"
#include "Tablero.h"

BatallaCampal::BatallaCampal(unsigned int cantidadJugadores, unsigned int cantidadSoldados,int dimensionTablero){

	if(cantidadJugadores < MIN_JUGADORES || cantidadJugadores > MAX_JUGADORES){
		this->cantidadJugadores = MIN_JUGADORES;
	}
	else{
		this->cantidadJugadores = cantidadJugadores;
	}
	if(cantidadSoldados < MIN_SOLDADOS || cantidadJugadores > MAX_SOLDADOS){
		this->cantidadSoldados = MIN_SOLDADOS;
	}
	else{
		this->cantidadSoldados = cantidadSoldados;
	}
	if(dimensionTablero < MIN_DIMENSION || dimensionTablero > MAX_DIMENSION){
		this->dimensionTablero = MIN_DIMENSION;
	}
	else{
		this->dimensionTablero = dimensionTablero;
	}

	this->turno = 1;

	this->jugadores = new Vector<Jugador*>(cantidadJugadores, NULL);

	for(int i = 1; i <= jugadores->getLongitud(); i++){
		this->jugadores->agregar(i, new Jugador(i, cantidadSoldados));
	}

	this->tablero = new Tablero(this->dimensionTablero,this->dimensionTablero,this->dimensionTablero);

}

void BatallaCampal::siguienteTurno(){
	if(this->turno < this->jugadores->getLongitud()){
		this->turno++;
	}else{
		this->turno = 1;
	}

}


estadoJuego BatallaCampal::estadoDelJuego(){

	int contadorJugadoresJugando = 0;
	estadoJuego estadoActual = JUGANDO;
	if(this->jugadores){

		for(int i = 1; i < this->jugadores->getLongitud(); i++){
			if(this->jugadores->obtener(i)->getEstadoJugador() == EN_BATALLA){
				contadorJugadoresJugando++;
			}
		}
		if(contadorJugadoresJugando == 1){
			estadoActual = FINALIZADO;
		}

	}

	return estadoActual;
}

unsigned int BatallaCampal::getTurno(){

	return this->turno;
}

Jugador* BatallaCampal::getJugador(unsigned int i){

	return this->jugadores->obtener(i);
}

BatallaCampal::~BatallaCampal(){
	if(this->jugadores){
		for(int i = 1; i < this->jugadores->getLongitud(); i++){
			delete this->jugadores->obtener(i);
		}
	delete [] this->jugadores;
	}
	if(tablero){
		delete tablero;
	}
}

Tablero* BatallaCampal::getTablero(){

	return this->tablero;
}
