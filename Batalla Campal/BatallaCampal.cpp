#include "BatallaCampal.h"
#include "Jugador.h"
#include "Tablero.h"

BatallaCampal::BatallaCampal(unsigned int cantidadJugadores, unsigned int cantidadSoldados,int dimensionTablero){

	estadoDelJuegoActual = JUGANDO;

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

	/*
	//Falta chequear que no se superpongan coordenadas
	for(int i = 1; i < this->cantidadDeSoldados; i++){
		Coordenada coordenada_soldado;
		this->generarCoordenadasSoldados(coordenada_soldado);
		this->jugadores->obtener(i)->soldados->getCursor()->setPosicionX() = coordenada_soldado.getCoordenadaX();
		this->jugadores->obtener(i)->soldados->getCursor()->setPosicionY() = coordenada_soldado.getCoordenadaY();
		this->jugadores->obtener(i)->soldados->getCursor()->setPosicionZ() = coordenada_soldado.getCoordenadaZ();
	}
	*/
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
			if(this->jugadores->obtener(i) != NULL){
				delete this->jugadores->obtener(i);
			}
		}
		delete [] this->jugadores;
	}
	if(tablero){
		delete tablero;
	}
}


void BatallaCampal::estadoActualDelJuego(){
	int contadorJugadoresJugando = 0;
	if(this->jugadores){

		for(int i = 1; i < this->jugadores->getLongitud(); i++){
			if(this->jugadores->obtener(i)->getEstadoJugador() == EN_BATALLA){
				contadorJugadoresJugando++;
			}
		}
		if(contadorJugadoresJugando == 1){
			this->estadoDelJuegoActual = FINALIZADO;
		}
	}
}

estadoDelJuego BatallaCampal::getEstadoDelJuego(){
	return this->estadoDelJuegoActual;
}

int BatallaCampal::getTurno(){

	return this->turno;
}

Jugador* BatallaCampal::getJugador(unsigned int i){

	return this->jugadores->obtener(i);
}

void BatallaCampal::realizarDisparo(int x, int y, int z){

	this->tablero->getCasilla(x, y, z)->setContenido(INACTIVO);

	for(int i = 1; i < this->jugadores->getLongitud(); i++){
		for(unsigned int j = 1; j < this->jugadores->obtener(i)->getCantidadDeSoldados() ; j++){
			if(this->jugadores->obtener(i)->getSoldado(j)->getPosicionX() == x && this->jugadores->obtener(i)->getSoldado(j)->getPosicionX() == y){
				this->jugadores->obtener(i)->eliminarSoldado(j);

			}
		}
	}

}

bool BatallaCampal::soldadosCoinciden(int x, int y){
	bool coinciden = false;
	for(int i = 1; i < this->jugadores->getLongitud(); i++){
		if(this->jugadores->obtener(i)->getId() == this->jugadores->obtener(this->turno)->getId()){
			i++;
		}

		for(unsigned int j = 1; j < this->jugadores->obtener(i)->getCantidadDeSoldados() ; j++){
			if(this->jugadores->obtener(i)->getSoldado(j)->getPosicionX() == x && this->jugadores->obtener(i)->getSoldado(j)->getPosicionY() == y){
				coinciden = true;
			}
		}
	}

	return coinciden;

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

}

void BatallaCampal::moverSoldado(char movimiento, int fila, int col, int jugadorDeTurno){

	int numSoldado;

	for(unsigned int i = 1; i <= this->jugadores->obtener(jugadorDeTurno)->getCantidadDeSoldados(); i++){
		if(this->jugadores->obtener(jugadorDeTurno)->getSoldado(i)->getPosicionX() == fila && this->jugadores->obtener(jugadorDeTurno)->getSoldado(i)->getPosicionX() == col){
			numSoldado = i;
		}
	}

	switch(movimiento){

		case ARRIBA:
			if(this->tablero->getCasilla(fila-1, col, 0)->getTipoDeCasilla() == TIERRA || this->tablero->getCasilla(fila-1, col, 0)->getContenido() != INACTIVO ||
				(fila-1) > 0 || fila < this->getDimensionDelTablero() ){

				this->jugadores->obtener(jugadorDeTurno)->getSoldado(numSoldado)->setCoordenadasSoldado(fila-1, col);

			}else{
				throw "Movimiento inválido.";
			}
			break;
		case ABAJO:
			if(this->tablero->getCasilla(fila+1, col, 0)->getTipoDeCasilla() == TIERRA || this->tablero->getCasilla(fila+1, col, 0)->getContenido() != INACTIVO ||
				(fila+1) > 0 || fila < this->getDimensionDelTablero() ){

				this->jugadores->obtener(jugadorDeTurno)->getSoldado(numSoldado)->setCoordenadasSoldado(fila+1, col);

			}else{
				throw "Movimiento inválido.";
			}
			break;
		case IZQUIERDA:
			if(this->tablero->getCasilla(fila, col-1, 0)->getTipoDeCasilla() == TIERRA || this->tablero->getCasilla(fila, col-1, 0)->getContenido() != INACTIVO ||
				(col-1) > 0 || col < this->getDimensionDelTablero() ){

				this->jugadores->obtener(jugadorDeTurno)->getSoldado(numSoldado)->setCoordenadasSoldado(fila, col-1);

			}else{
				throw "Movimiento inválido.";
			}
			break;
		case DERECHA:
			if(this->tablero->getCasilla(fila, col+1, 0)->getTipoDeCasilla() == TIERRA || this->tablero->getCasilla(fila, col+1, 0)->getContenido() != INACTIVO ||
				(col+1) > 0 || col < this->getDimensionDelTablero() ){

				this->jugadores->obtener(jugadorDeTurno)->getSoldado(numSoldado)->setCoordenadasSoldado(fila, col+1);

			}else{
				throw "Movimiento inválido.";
			}

			break;
	}
	if(this->soldadosCoinciden(this->jugadores->obtener(jugadorDeTurno)->getSoldado(1)->getPosicionX(), this->jugadores->obtener(jugadorDeTurno)->getSoldado(1)->getPosicionY())){

		this->tablero->getCasilla(this->jugadores->obtener(jugadorDeTurno)->getSoldado(1)->getPosicionX(), this->jugadores->obtener(jugadorDeTurno)->getSoldado(1)->getPosicionY(), 0)->setContenido(INACTIVO);
	}
}


Tablero* BatallaCampal::getTablero(){

	return this->tablero;
}

int BatallaCampal::getCantidadDeJugadores(){
	return this->cantidadJugadores;
}

int BatallaCampal::getCantidadDeSoldados(){
	return this->cantidadSoldados;
}

int BatallaCampal::getDimensionDelTablero(){
	return this->dimensionTablero;
}

/*
void BatallaCampal::generarCoordenadasSoldados(Coordenada& coordenada){
	coordenada.setCoordenadaX = rand()%dimension + 1;
	coordenada.setCoordenadaY = rand()%dimension + 1;
	coordenada.setCoordenadaZ = 0;
}
*/
