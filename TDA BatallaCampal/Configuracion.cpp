#include "Configuracion.h"


Configuracion::Configuracion(){

	this->cantidadDeJugadores = 2;
	this->cantidadDeSoldadosPorJugador = 6;
	this->dimensionDelTablero = 40;


}

void Configuracion::setCantidadDeJugadores(int opcionUsuario){

	if( (opcionUsuario > 2) && (opcionUsuario < 20)){
		this->cantidadDeJugadores = opcionUsuario;
	}else{
		this->cantidadDeJugadores = 2;
	}
}
void Configuracion::setCantidadDeSoldadosPorJugador(int opcionUsuario){

	if( (opcionUsuario > 3) && (opcionUsuario < 8)){
		this->cantidadDeSoldadosPorJugador = opcionUsuario;
	}else{
		this->cantidadDeSoldadosPorJugador = 6;
	}
}
void Configuracion::setDimensionDelTablero(int opcionUsuario){

	if((opcionUsuario > 20) && (opcionUsuario < 100)){

		this->dimensionDelTablero = opcionUsuario;
	}else{
		this->dimensionDelTablero = 40;
	}
}

int Configuracion::getCantidadDeJugadores(){

	return this->cantidadDeJugadores;
}
int Configuracion::getCantidadDeSoldadosPorJugador(){

	return this->cantidadDeSoldadosPorJugador;
}
int Configuracion::getDimensionDelTablero(){

	return this->dimensionDelTablero;
}


