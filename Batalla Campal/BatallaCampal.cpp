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

//Acá debería entrar a la casilla o al tablero, a este punto ya ni idea
//Y fijarse si el contenido es INACTIVO
bool BatallaCampal::esPosicionValida(){
	bool posicionValida = true;
	//chequeo, si no es true, lo cambio a false.
	return posicionValida;
}

//Luego de mover el soldado, tengo que ver si se pisó con los n-1 restantes.
bool BatallaCampal::soldadosCoinciden(){
	bool coinciden = false;
	unsigned int jugadorActual = this->turno;
	for(int i = 1; i < this->cantidadDeJugadores; i++){
		//Acá evito que se compare consigo mismo
		if(this->jugadores->obtener(i)->getId() == jugadorActual){
			i++;
		}
		
		//No sé cómo entrar a la lista de fichas acá xD
		//Lo intento y cualquier cosa ustedes lo arreglan
		//La onda acá es ver si las posiciones X e Y del jugador actual y de los demás coinciden o no
		//Si coinciden hay que poner inactiva la casilla
		
		//Dejo pseudo-código acá y si puedo intento implementarlo
		
		//Recorro la lista del jugador actual
		//Cuando encuentro un soldado, empiezo a buscar los soldados del otro jugador y miro si coinciden
		//Sigo recorriendo la lista del jugador actual
		//Cuando encuentro otro soldado, vuelvo a buscar los soldados del otro jugador y miro si coinciden
		//Se recorren ambas listas en tanto y en cuanto que el cursor no sea NULL
		//Esa es la idea pero no sé si lo implementé bien o si la sintaxis en sí está bien
		
			for(int j = 1; j < this->jugadores->obtener(i)->getCursor() == NULL; j++){
				for(int k = 1; k < this->jugadores->obtener(jugadorActual)->getCursor() == NULL; j++){
					if(this->jugadores->obtener(i)->getCursor()->getPosicionX() == this->jugadores->obtener(jugadorActual)->getCursor()->getPosicionX()
					   && this->jugadores->obtener(i)->getCursor()->getPosicionY() == this->jugadores->obtener(jugadorActual)->getCursor()->getPosicionY()
					   && this->jugadores->obtener(jugadorActual)->getCursor()->getTipo() == SOLDADO
					   && this->jugadores->obtener(i)->getCursor()->getTipo() == SOLDADO){
						coinciden = true;
					}
					this->jugadores->obtener(jugadorActual)->avanzarCursor();
				}
				this->jugadores->obtener(i)->avanzarCursor();
			}	
		}
	}
	return coinciden;
}


//Primero chequea si la posición es válida. Si lo es, hace el movimiento. Sino, no hace nada.
void BatallaCampal::moverSoldado(char movimiento){
	switch(movimiento){
		case ADELANTE:
			if(esPosicionValida()){
				//hago el movimiento
				if(soldadosCoinciden()){
					//poner inactiva la casilla
				}
			}
			break;
		case ATRÁS:
			if(esPosicionValida){
				//hago el movimiento
				if(soldadosCoinciden()){
					//poner inactiva la casilla
				}
			}
			break;
		case IZQUIERDA:
			if(esPosicionValida){
				//hago el movimiento
				if(soldadosCoinciden()){
					//poner inactiva la casilla
				}
			}
			break;
		case DERECHA:
			if(esPosicionValida){
				//hago el movimiento
				if(soldadosCoinciden()){
					//poner inactiva la casilla
				}
			}
			break;
	}	
}


Tablero* BatallaCampal::getTablero(){

	return this->tablero;
}
