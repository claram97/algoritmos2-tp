#include "BatallaCampal.h"
#include "jugador.h"

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

	this->jugadores = new Vector<Jugador**>(cantidadJugadores,NULL);
	this->turno = 1;
	this->cantidadJugadores = cantidadJugadores;
	this->cantidadSoldados = cantidadSoldados;

	this->tablero = new Tablero(this->dimensionTablero,this->dimensionTablero,this->dimensionTablero);
 
	for(int i = 0; i < this->jugadores->getLongitud(); i++){
		this->jugadores->agregar(i,new Jugador(i+1));
	}
}


void BatallaCampal::siguienteTurno(){
	if(this->turno < MAX_JUGADORES){
		this->turno++;
	}else{
		this->turno = 1;
	}

}

BatallaCampal::~BatallaCampal(){
	if(this->jugadores){
		for(int i = 0; i < this->cantidadJugadores; i++){
			delete this->jugadores->obtener(i);
		}
	delete [] this->jugadores;
	}
	if(tablero){ 
		delete tablero;
	}
}

estadoJuego BatallaCampal::estadoDelJuego(){ //acá quiero ver que quede un solo jugador con soldados vivos pero no mas de uno

	int contadorJugadoresJugando = 0;
	estadoJuego estadoActual = JUGANDO;
	if(this->jugadores){

		for(int i = 0; i < this->cantidadJugadores; i++){
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
