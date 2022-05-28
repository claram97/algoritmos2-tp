//BatallaCampal.cpp
#include "BatallaCampal.h"

enum estadoJuego{JUGANDO,FINALIZADO};
enum estadoJugador{GANADOR,PERDEDOR,EN_BATALLA}

BatallaCampal::BatallaCampal(unsigned int cantidadJugadores, unsigned int cantidadSoldados,unsigned int dimensionTablero){

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

	this->jugadores = new Vector <Jugador*>(cantidadJugadores);
	this->turno = 1;
	this->cantidadJugadores = cantidadJugadores;
	this->cantidadSoldados = cantidadSoldados;
 
	for(int i = 0; i < this->jugadores->getLongitud(); i++){
		this->jugadores->agregar(i,new Jugador(i+1, cantidadSoldados));
	}
}


unsigned int BatallaCampal::siguienteTurno(){
	if(this->turno < MAX_JUGADORES){
		this->turno++;
	}else{
		this->turno = 1;
	}
}

BatallaCampal::~BatallaCampal(){
	if(this->jugadores){
		for(int i = 0; i < this->cantidadJugadores; i++){
			delete this->jugadores[i];
		}
	delete [] this->jugadores;
	}
	if(tablero){ 
	//después lo vemos porque no sé cómo pingo se implementa esto  si dejalo.
	}
}
//Recibo una referencia a jugador para cambiar su valor xdd
estadoJugador BattallaCampal::estadoJugador(Jugador& jugador){
	if(jugador.getCantidadDeFichasSoldados() == 0){
		estadoJugador = PERDEDOR;
	}		
}

estadoJuego BatallaCampal::estadoDelJuego(){
	//acá quiero ver que quede un solo jugador con soldados vivos pero no mas de uno
	int contadorJugadoresJugando = 0;
	estadoJuego estadoActual;
	while(contadorJugadoresJugando && )
	if(this->jugadores){
		for(int i = 0; i < this->cantidadJugadores; i++){
			if(estadoJugador(jugador[i]) == EN_BATALLA){
				contadorJugadoresJugando++;
			}
		}
		if(contadorJugadoresJugando == 1){
			estadoActual = FINALIZADO;
		}
		else{
			estadoActual = JUGANDO;
		}
	}
	else{
		estadoActual = FINALIZADO;
	}
	return estadoActual;
}
