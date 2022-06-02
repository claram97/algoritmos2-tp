#include <iostream>
#include "BatallaCampal.h"
#include "Jugador.h"
#include "Tablero.h"
#include "Ficha.h"
#include "Casilla.h"

BatallaCampal::BatallaCampal(unsigned int cantidadJugadores, unsigned int cantidadSoldados,int dimensionTablero){

	estadoDelJuegoActual = JUGANDO;

	if(cantidadJugadores < MIN_JUGADORES || cantidadJugadores > MAX_JUGADORES){
		this->cantidadJugadores = MIN_JUGADORES;
	}
	else{
		this->cantidadJugadores = cantidadJugadores;
	}
	if(cantidadSoldados < MIN_SOLDADOS || cantidadSoldados > MAX_SOLDADOS){
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

	this->turno = 0;

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

		for(int i = 1; i <= this->jugadores->getLongitud(); i++){
			if(this->jugadores->obtener(i)->getCantidadDeSoldados() == 0){
				this->jugadores->obtener(i)->setEstado(ELIMINADO);
			}
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

	this->tablero->getCasilla(x, y, z)->setContenido(INACTIVO); //metodo para dejar inactivo

	for(int i = 1; i <= this->jugadores->getLongitud(); i++){
		for(unsigned int j = 1; j <= this->jugadores->obtener(i)->getCantidadDeSoldados() ; j++){
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
	if(this->soldadosCoinciden(this->jugadores->obtener(jugadorDeTurno)->getSoldado(numSoldado)->getPosicionX(), this->jugadores->obtener(jugadorDeTurno)->getSoldado(numSoldado)->getPosicionY())){

		this->tablero->getCasilla(this->jugadores->obtener(jugadorDeTurno)->getSoldado(numSoldado)->getPosicionX(), this->jugadores->obtener(jugadorDeTurno)->getSoldado(numSoldado)->getPosicionY(), 0)->setContenido(INACTIVO);
	}
}

void BatallaCampal::dispararMisil(int x, int y, int z){
	for (int i = -1; i <= 1; i++){
		for (int j = -1; j <= 1; j++){
			for (int k = -1; k <= 1; k++){
				this->tablero->getCasilla(x+i, y+j, z+k)->setContenido(INACTIVO);
			}
		}
	}
}

int BatallaCampal::usarRadar(int x, int y, int z){
	int contador = 0;
	char contenido;
	for (int i = 0; i <= 2; i++){
		for (int j = 0; j <= 2; j++){
			for (int k = 0; k <= 2; k++){
				contenido = this->tablero->getCasilla(x+i, y+j, z+k)->getContenido();
				if (contenido == LLENO){
					contador++;
				}
			}
		}
	}
	return contador;
}

void BatallaCampal::dispararSuperMisil(int x){
		for (int i = 0; i <= 2; i++){
			for (int j = 0; j <= 2; j++){
				this->tablero->getCasilla(x, i, j)->setContenido(INACTIVO);
			}
	}
}

void BatallaCampal::ejecutarCarta(int numero, int jugadorDeTurno){
	int x, y ,z;
	char filaOColumna;
	int cantidadFichas;
	switch(numero){
		case 1:
			std::cout << "Ingrese coordenadas de avion: "<<std::endl;
			std::cout << "Fila: ";
			std::cin >> x;
			std::cout << "Columna: ";
			std::cin >> y;
			std::cout << "Altura: ";
			std::cin >> z;
			if (this->tablero->getCasilla(x, y, z)->getTipoDeCasilla() != AIRE){
				throw "Avion debe estar en el aire";
			}else{
				this->jugadores->obtener(jugadorDeTurno)->nuevaHerramienta(AVION, x, y, z);
				this->tablero->getCasilla(x, y, z)->setContenido(LLENO);
			}
		case 2:
			std::cout << "Ingrese coordenadas de barco: "<<std::endl;
			std::cout << "Fila: ";
			std::cin >> x;
			std::cout << "Columna: ";
			std::cin >> y;
			if (this->tablero->getCasilla(x, y, z)->getTipoDeCasilla() != AGUA){
				throw "Barco debe estar en el agua";
			}else{
				this->jugadores->obtener(jugadorDeTurno)->nuevaHerramienta(BARCO, x, y, 1);
				this->tablero->getCasilla(x, y, z)->setContenido(LLENO);
			}
		case 3:
			std::cout << "Ingrese coordenadas de mina: "<<std::endl;
			std::cout << "Fila: ";
			std::cin >> x;
			std::cout << "Columna: ";
			std::cin >> y;
			if (this->tablero->getCasilla(x, y, z)->getTipoDeCasilla() != TIERRA){
				throw "Mina debe estar en la tierra";
			}else{
				this->jugadores->obtener(jugadorDeTurno)->nuevaHerramienta(MINA, x, y, 1);
				this->tablero->getCasilla(x, y, z)->setContenido(LLENO);
			}
		case 4:
			std::cout << "Ingrese coordenadas de radar: "<<std::endl;
			std::cout << "Fila: ";
			std::cin >> x;
			std::cout << "Columna: ";
			std::cin >> y;
			std::cout << "Altura: ";
			std::cin >> z;
			cantidadFichas = usarRadar(x, y ,z);
			std::cout << "En los alrededores se encuentran "<< cantidadFichas << "cantidad de fichas"<<std::endl;
		case 5:
			std::cout << "Elegir Columna: C o Fila: F: "<<std::endl;
			std::cin >> filaOColumna;
		case 6:
			std::cout << "Ingrese coordenadas de disparo del misil: "<<std::endl;
			std::cout << "Fila: ";
			std::cin >> x;
			std::cout << "Columna: ";
			std::cin >> y;
			std::cout << "Altura: ";
			std::cin >> z;
			std::cout << "Disparando misil..." <<std::endl;
			dispararMisil(x, y, z);

	}
	this->jugadores->obtener(jugadorDeTurno)->eliminarCarta(numero);
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

