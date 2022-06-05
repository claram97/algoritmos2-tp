#include "BatallaCampal.h"

BatallaCampal::BatallaCampal(unsigned int cantidadJugadores, unsigned int cantidadSoldados,int dimensionTablero){

	estadoDelJuegoActual = JUGANDO;

	if(cantidadJugadores < MIN_JUGADORES || cantidadJugadores > MAX_JUGADORES){
		throw "La cantidad de jugadores elegida es inválida.";
	}else{
		this->cantidadJugadores = cantidadJugadores;
	}
	if(cantidadSoldados < MIN_SOLDADOS || cantidadSoldados > MAX_SOLDADOS){
		throw "La cantidad de soldados elegida es inválida.";
	}else{
		this->cantidadSoldados = cantidadSoldados;
	}
	if(dimensionTablero < MIN_DIMENSION || dimensionTablero > MAX_DIMENSION){
		throw "La dimensión elegida para el tablero es inválida.";
	}else{
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

	this->tablero->getCasilla(x, y, z)->setEstado(INACTIVO); //metodo para dejar INACTIVO

	for(int i = 1; i <= this->jugadores->getLongitud(); i++){
		for(int j = 1; j <= this->jugadores->obtener(i)->getCantidadDeSoldados() ; j++){
			if(this->jugadores->obtener(i)->getSoldado(j)->getPosicionX() == x && this->jugadores->obtener(i)->getSoldado(j)->getPosicionX() == y){
				this->jugadores->obtener(i)->eliminarSoldado(j);

			}
		}
	}

}

bool BatallaCampal::soldadosCoinciden(int x, int y){
	bool coinciden = false;
		for( int j = 1; j <= this->jugadores->obtener(turno)->getCantidadDeSoldados(); j++){
			if(this->jugadores->obtener(turno)->getSoldado(j)->getPosicionX() == x && this->jugadores->obtener(turno)->getSoldado(j)->getPosicionY() == y){
				coinciden = true;
			}
		}
		
		return coinciden;
}

// enemyKill como que no funciona, entra a la función y al primer ciclo pero no se que onda
bool BatallaCampal::enemyKill(int x, int y){
	bool enemigoMuerto = false;
	for(int i = 1; i <= this -> jugadores -> getLongitud(); i++){
		for(int j = 1; j <= this->jugadores->obtener(i)->getCantidadDeSoldados(); j++){
			if(this->jugadores->obtener(i)->getSoldado(j)->getPosicionX() == x && this->jugadores->obtener(i)->getSoldado(j)->getPosicionY() == y && (i != turno)){
				enemigoMuerto = true;
			}
		}
	}
	return enemigoMuerto;
}

void BatallaCampal::moverSoldado(char movimiento, int fila, int col, int jugadorDeTurno){

	int numSoldado;

	for(int i = 1; i <= this->jugadores->obtener(jugadorDeTurno)->getCantidadDeSoldados(); i++){
		if(this->jugadores->obtener(jugadorDeTurno)->getSoldado(i)->getPosicionX() == fila && this->jugadores->obtener(jugadorDeTurno)->getSoldado(i)->getPosicionX() == col){
			numSoldado = i;
		}
	}

	switch(movimiento){

		case ARRIBA:
			if(this->tablero->getCasilla(fila-1, col, 0)->getTipoDeCasilla() == TIERRA || this->tablero->getCasilla(fila-1, col, 0)->getEstado() != INACTIVO ||
				(fila-1) > 0 || fila < this->getDimensionDelTablero() ){

				this->jugadores->obtener(jugadorDeTurno)->getSoldado(numSoldado)->setCoordenadasSoldado(fila-1, col);

			}else{
				throw "Movimiento invÃ¡lido.";
			}
			break;
		case ABAJO:
			if(this->tablero->getCasilla(fila+1, col, 0)->getTipoDeCasilla() == TIERRA || this->tablero->getCasilla(fila+1, col, 0)->getEstado() != INACTIVO ||
				(fila+1) > 0 || fila < this->getDimensionDelTablero() ){

				this->jugadores->obtener(jugadorDeTurno)->getSoldado(numSoldado)->setCoordenadasSoldado(fila+1, col);

			}else{
				throw "Movimiento invÃ¡lido.";
			}
			break;
		case IZQUIERDA:
			if(this->tablero->getCasilla(fila, col-1, 0)->getTipoDeCasilla() == TIERRA || this->tablero->getCasilla(fila, col-1, 0)->getEstado() != INACTIVO ||
				(col-1) > 0 || col < this->getDimensionDelTablero() ){

				this->jugadores->obtener(jugadorDeTurno)->getSoldado(numSoldado)->setCoordenadasSoldado(fila, col-1);

			}else{
				throw "Movimiento invÃ¡lido.";
			}
			break;
		case DERECHA:
			if(this->tablero->getCasilla(fila, col+1, 0)->getTipoDeCasilla() == TIERRA || this->tablero->getCasilla(fila, col+1, 0)->getEstado() != INACTIVO ||
				(col+1) > 0 || col < this->getDimensionDelTablero() ){

				this->jugadores->obtener(jugadorDeTurno)->getSoldado(numSoldado)->setCoordenadasSoldado(fila, col+1);

			}else{
				throw "Movimiento invÃ¡lido.";
			}

			break;
	}
	if(this->soldadosCoinciden(this->jugadores->obtener(jugadorDeTurno)->getSoldado(numSoldado)->getPosicionX(), this->jugadores->obtener(jugadorDeTurno)->getSoldado(numSoldado)->getPosicionY())){

		this->tablero->getCasilla(this->jugadores->obtener(jugadorDeTurno)->getSoldado(numSoldado)->getPosicionX(), this->jugadores->obtener(jugadorDeTurno)->getSoldado(numSoldado)->getPosicionY(), 0)->setEstado(INACTIVO);
	}
}

void BatallaCampal::dispararMisil(int x, int y, int z){

	for (int i = -1; i <= 1; i++){
		for (int j = -1; j <= 1; j++){
			for (int k = -1; k <= 1; k++){
				this->tablero->getCasilla(x+i, y+j, z+k)->setEstado(INACTIVO);
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
				if (this->tablero->getCasilla(x+i, y+j, z+k)->getEstado() == LLENO){
					contador++;
				}
			}
		}
	}
	return contador;
}

void BatallaCampal::dispararSuperMisil(int x, bool filaOColumna){
	if (filaOColumna){
		for (int i = 1; i <= this->getDimensionDelTablero(); i++){
			for (int k = 1; k <= this->getDimensionDelTablero(); k++){
				this->tablero->getCasilla(i, x, k)->setEstado(INACTIVO);
			}
		}
	}else{
		for (int i = 1; i <= this->getDimensionDelTablero(); i++){
			for (int k = 1; k <= this->getDimensionDelTablero(); k++){
				this->tablero->getCasilla(x, i, k)->setEstado(INACTIVO);
			}
		}
	}
}

bool BatallaCampal::verificarCoordenadas(int x, int y, int z){
	if (x < 0 || y < 0 || z < 0 || x > this->getDimensionDelTablero() || y > this->getDimensionDelTablero() || z > this->getDimensionDelTablero()){
		throw "Coorndeadas no estan en el tablero";
	}else{
		return true;
	}
}

void BatallaCampal::iniciarEscenarioUno(unsigned int xMax ,unsigned int yMax, unsigned int zMax){
	
	this->tablero = new Tablero(xMax,yMax,zMax);
	
	for(int x = 1; x<=xMax; x++){
		for(int y = 1; y<=yMax; x++){
			for(int z = 1; z<=zMax; x++){
				
				if(x == 1){

					if(y < z){	
						this->tablero->getCasilla(x,y,z)->setTipo(TIERRA);
					}
					else{
						this->tablero->getCasilla(x,y,z)->setTipo(AGUA);
					}
					
				}else{
					this->tablero->getCasilla(x,y,z)->setTipo(AGUA);
				}
					
			}
		}
	}	
}

void BatallaCampal::ejecutarCarta(int numero, int jugadorDeTurno, int x, int y, int z){
	if (numero < 6 || numero < 1){
		throw "Numero de carta invalido";
	}
	switch(numero){
		case 1:
			if (this->tablero->getCasilla(x, y, z)->getTipoDeCasilla() != AIRE){
				throw "Avion debe estar en el aire";
			}else if (verificarCoordenadas(x, y, z)){
				this->jugadores->obtener(jugadorDeTurno)->nuevaHerramienta(AVION, x, y, z);
				this->tablero->getCasilla(x, y, z)->setEstado(LLENO);
		    }
		case 2:
			if (this->tablero->getCasilla(x, y, z)->getTipoDeCasilla() != AGUA){
				throw "Barco debe estar en el agua";
			}else if (verificarCoordenadas(x, y, z)){
				this->jugadores->obtener(jugadorDeTurno)->nuevaHerramienta(BARCO, x, y, 1);
				this->tablero->getCasilla(x, y, z)->setEstado(LLENO);
			}
		case 3:
			if (this->tablero->getCasilla(x, y, z)->getTipoDeCasilla() != TIERRA){
				throw "Mina debe estar en la tierra";
			}else if (verificarCoordenadas(x, y, z)){
				this->jugadores->obtener(jugadorDeTurno)->nuevaHerramienta(MINA, x, y, 1);
				this->tablero->getCasilla(x, y, z)->setEstado(LLENO);
			}
		case 6:
			if (verificarCoordenadas(x, y, z) && verificarCoordenadas(x+1, y+1, z+1) && verificarCoordenadas(x-1, y-1, z-1)){
			dispararMisil(x, y, z);
			}
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
