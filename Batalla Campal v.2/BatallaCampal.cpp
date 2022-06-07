#include "BatallaCampal.h"

BatallaCampal::BatallaCampal(unsigned int cantidadJugadores, unsigned int cantidadSoldados, int dimensionTablero){

	this->estadoDelJuegoActual = JUGANDO;
	this->turno = 0;

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

	this->jugadores = new Lista<Jugador*>();

	for(unsigned int i = 1; i <= cantidadJugadores; i++){
		this->jugadores->add(new Jugador(i, cantidadSoldados));
	}

	this->tablero = new Tablero(this->dimensionTablero,this->dimensionTablero,this->dimensionTablero);

}

void BatallaCampal::siguienteTurno(){
	if(this->turno < this->jugadores->contarElementos()){
		this->turno++;
	}else{
		this->turno = 1;
	}

}

BatallaCampal::~BatallaCampal(){
	if(this->jugadores){
		for(unsigned int i = 1; i <= this->jugadores->contarElementos(); i++){
			if(this->jugadores->get(i) != NULL){
				this->jugadores->remover(i);
			}
		}
		delete this->jugadores;
	}
	if(tablero){
		delete tablero;
	}
}


void BatallaCampal::estadoActualDelJuego(){
	if(this->jugadores){
		
		int id = 0;

		this->jugadores->reiniciarCursor();
		while(this->jugadores->avanzarCursor()){
			id++;
			if(this->jugadores->getCursor()->getCantidadDeSoldados() == 0){
				this->jugadores->remover(id);
			}
		}
		if(this->jugadores->contarElementos() == 1){
			this->estadoDelJuegoActual = FINALIZADO;

		}else{
			this->estadoDelJuegoActual = JUGANDO;
		}
	}
}

estadoDelJuego BatallaCampal::getEstadoDelJuego(){
	return this->estadoDelJuegoActual;
}

int BatallaCampal::getTurno(){

	return this->turno;
}

Lista <Jugador*>* BatallaCampal::getJugador(){

	return this->jugadores;
}

void BatallaCampal::realizarDisparo(int fila, int columna, int altura){

	this->tablero->getCasilla(fila, columna, altura)->setEstado(INACTIVO);

	this->jugadores->reiniciarCursor();
	while(this->jugadores->avanzarCursor()){
		if(this->jugadores->getCursor()->buscarSoldado(fila, columna)){
			this->jugadores->getCursor()->eliminarSoldado(fila, columna);
		}
	}
}

bool BatallaCampal::soldadosCoinciden(int fila, int columna){

	bool coinciden = false;
	bool corte = false;
	this->jugadores->reiniciarCursor();
	while(this->jugadores->avanzarCursor() && (!corte)){
		if(this->jugadores->getCursor()->getId() == this->turno){
			corte = true;
			this->jugadores->getCursor()->getSoldado()->reiniciarCursor();
			while(this->jugadores->getCursor()->getSoldado()->avanzarCursor()){
				if(this->jugadores->getCursor()->getSoldado()->getCursor()->getPosicionX() == fila && this->jugadores->getCursor()->getSoldado()->getCursor()->getPosicionY() == columna){
					coinciden = true;
				}
			}
		}
	}
	return coinciden;
}

// enemyKill como que no funciona, entra a la función y al primer ciclo pero no se que onda
bool BatallaCampal::enemyKill(int fila, int columna){

	bool enemigoMuerto = false;
	this->jugadores->reiniciarCursor();
	while(this->jugadores->avanzarCursor()){
		if(this->jugadores->getCursor()->getId() != this->turno){
			this->jugadores->getCursor()->getSoldado()->reiniciarCursor();
			while(this->jugadores->getCursor()->getSoldado()->avanzarCursor()){
				if(this->jugadores->getCursor()->getSoldado()->getCursor()->getPosicionX() == fila && this->jugadores->getCursor()->getSoldado()->getCursor()->getPosicionY() == columna){
					enemigoMuerto = true;
				}
			}
		}
	}
	return enemigoMuerto;
}

void BatallaCampal::moverSoldado(char movimiento, int fila, int columna){

	bool corte = false;
	this->jugadores->reiniciarCursor();
	while(this->jugadores->avanzarCursor() && (!corte)){
		if(this->jugadores->getCursor()->getId() == this->turno){
			corte = true;
			this->jugadores->getCursor()->getSoldado()->reiniciarCursor();
			while(this->jugadores->getCursor()->getSoldado()->avanzarCursor()){
				if(this->jugadores->getCursor()->getSoldado()->getCursor()->getPosicionX() == fila && this->jugadores->getCursor()->getSoldado()->getCursor()->getPosicionY() == columna){

					switch(movimiento){

						case ARRIBA:
							if(this->tablero->getCasilla(fila-1, columna, 1)->getTipoDeCasilla() == TIERRA || this->tablero->getCasilla(fila-1, columna, 1)->getEstado() != INACTIVO ||
								(fila-1) > 0 || fila < this->getDimensionDelTablero() ){

								this->jugadores->getCursor()->getSoldado()->getCursor()->setCoordenadasSoldado(fila-1, columna);

							}else{
								throw "Movimiento invÃ¡lido.";
							}
							break;
						case ABAJO:
							if(this->tablero->getCasilla(fila+1, columna, 1)->getTipoDeCasilla() == TIERRA || this->tablero->getCasilla(fila+1, columna, 1)->getEstado() != INACTIVO ||
								(fila+1) > 0 || fila < this->getDimensionDelTablero() ){

								this->jugadores->getCursor()->getSoldado()->getCursor()->setCoordenadasSoldado(fila+1, columna);

							}else{
								throw "Movimiento invÃ¡lido.";
							}
							break;
						case IZQUIERDA:
							if(this->tablero->getCasilla(fila, columna-1, 1)->getTipoDeCasilla() == TIERRA || this->tablero->getCasilla(fila, columna-1, 1)->getEstado() != INACTIVO ||
								(columna-1) > 0 || columna < this->getDimensionDelTablero() ){

								this->jugadores->getCursor()->getSoldado()->getCursor()->setCoordenadasSoldado(fila, columna-1);

							}else{
								throw "Movimiento invÃ¡lido.";
							}
							break;
						case DERECHA:
							if(this->tablero->getCasilla(fila, columna+1, 1)->getTipoDeCasilla() == TIERRA || this->tablero->getCasilla(fila, columna+1, 1)->getEstado() != INACTIVO ||
								(columna+1) > 0 || columna < this->getDimensionDelTablero() ){

								this->jugadores->getCursor()->getSoldado()->getCursor()->setCoordenadasSoldado(fila, columna+1);

							}else{
								throw "Movimiento invÃ¡lido.";
							}

							break;
					}

					if(this->soldadosCoinciden(this->jugadores->getCursor()->getSoldado()->getCursor()->getPosicionX(), this->jugadores->getCursor()->getSoldado()->getCursor()->getPosicionY())){

						this->tablero->getCasilla(this->jugadores->getCursor()->getSoldado()->getCursor()->getPosicionX(), this->jugadores->getCursor()->getSoldado()->getCursor()->getPosicionY(), 1)->setEstado(INACTIVO);
					}

				}
			}
		}
	}
}

void BatallaCampal::dispararMisil(int fila, int columna, int altura){

	for (int i = -1; i <= 1; i++){
		for (int j = -1; j <= 1; j++){
			for (int k = -1; k <= 1; k++){
				this->tablero->getCasilla(fila+i, columna+j, altura+k)->setEstado(INACTIVO);
			}
		}
	}
}

int BatallaCampal::usarRadar(int fila, int columna, int altura){
	int contador = 0;
	//char contenido;
	for (int i = 0; i <= 2; i++){
		for (int j = 0; j <= 2; j++){
			for (int k = 0; k <= 2; k++){
				//contenido = this->tablero->getCasilla(x+i, y+j, z+k)->getContenido();
				if (this->tablero->getCasilla(fila+i, columna+j, altura+k)->getEstado() == LLENO){
					contador++;
				}
			}
		}
	}
	return contador;
}

void BatallaCampal::dispararSuperMisil(int fila, bool filaOColumna){
	if (filaOColumna){
		for (int i = 1; i <= this->getDimensionDelTablero(); i++){
			for (int k = 1; k <= this->getDimensionDelTablero(); k++){
				this->tablero->getCasilla(i, fila, k)->setEstado(INACTIVO);
			}
		}
	}else{
		for (int i = 1; i <= this->getDimensionDelTablero(); i++){
			for (int k = 1; k <= this->getDimensionDelTablero(); k++){
				this->tablero->getCasilla(fila, i, k)->setEstado(INACTIVO);
			}
		}
	}
}

bool BatallaCampal::verificarCoordenadas(int fila, int columna, int altura){
	if (fila < 0 || columna < 0 || altura < 0 || fila > this->getDimensionDelTablero() || columna > this->getDimensionDelTablero() || altura > this->getDimensionDelTablero()){
		throw "Coordenadas no estan en el tablero";
	}else{
		return true;
	}
}

void BatallaCampal::iniciarEscenarioUno(unsigned int xMax ,unsigned int yMax, unsigned int zMax){
	
	for(unsigned int x = 1; x<=xMax; x++){
		for(unsigned int y = 1; y<=yMax; x++){
			for(unsigned int z = 1; z<=zMax; x++){
				
				if(x == 1){

					if(y < z){	
						this->tablero->getCasilla(x,y,z)->setTipoDeCasillero(TIERRA);
					}
					else{
						this->tablero->getCasilla(x,y,z)->setTipoDeCasillero(AGUA);
					}
					
				}else{
					this->tablero->getCasilla(x,y,z)->setTipoDeCasillero(AIRE);
				}
					
			}
		}
	}	
}

void BatallaCampal::ejecutarCarta(int numero, int x, int y, int z){

	bool corte = false;
	this->jugadores->reiniciarCursor();
	while(this->jugadores->avanzarCursor() && (!corte)){
		if(this->jugadores->getCursor()->getId() == this->turno){
			corte = true;

			if (numero < 6 || numero < 1){
				throw "Numero de carta invalido";
			}
			switch(numero){
				case 1:
					if (this->tablero->getCasilla(x, y, z)->getTipoDeCasilla() != AIRE){
						throw "Avion debe estar en el aire";
					}else if (verificarCoordenadas(x, y, z)){
						this->jugadores->getCursor()->nuevaHerramienta(AVION, x, y, z);
						this->tablero->getCasilla(x, y, z)->setEstado(LLENO);
					}
				break;
				case 2:
					if (this->tablero->getCasilla(x, y, z)->getTipoDeCasilla() != AGUA){
						throw "Barco debe estar en el agua";
					}else if (verificarCoordenadas(x, y, z)){
						this->jugadores->getCursor()->nuevaHerramienta(BARCO, x, y, 1);
						this->tablero->getCasilla(x, y, z)->setEstado(LLENO);
					}
				break;
				case 3:
					if (this->tablero->getCasilla(x, y, z)->getTipoDeCasilla() != TIERRA){
						throw "Mina debe estar en la tierra";
					}else if (verificarCoordenadas(x, y, z)){
						this->jugadores->getCursor()->nuevaHerramienta(MINA, x, y, 1);
						this->tablero->getCasilla(x, y, z)->setEstado(LLENO);
					}
				break;
				case 6:
					if (verificarCoordenadas(x, y, z) && verificarCoordenadas(x+1, y+1, z+1) && verificarCoordenadas(x-1, y-1, z-1)){
					dispararMisil(x, y, z);
					}
			}
			this->jugadores->getCursor()->eliminarCarta(numero);

		}
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
