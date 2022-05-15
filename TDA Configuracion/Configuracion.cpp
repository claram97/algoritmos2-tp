#include "Configuracion.h"


Configuracion::Configuracion(){

	this->cantidadDeJugadores = 2;
	this->cantidadDeSoldadosPorJugador = 6;
	this->cantidadFilasTablero = 40;
	this->cantidadColTablero = 40;
	this->alturaDelTablero = 40;

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
void Configuracion::setCantidadFilasTablero(int opcionUsuario){

	if((opcionUsuario > 20) && (opcionUsuario < 100)){

		this->cantidadFilasTablero = opcionUsuario;
	}else{
		this->cantidadFilasTablero = 40;
	}
}
void Configuracion::setCantidadColTablero(int opcionUsuario){

	if((opcionUsuario > 20) && (opcionUsuario < 100)){

		this->cantidadColTablero = opcionUsuario;
	}else{
		this->cantidadColTablero = 40;
	}
}
void Configuracion::setAlturaDelTablero(int opcionUsuario){

	if((opcionUsuario > 20) && (opcionUsuario < 100)){

		this->alturaDelTablero = opcionUsuario;
	}else{
		this->alturaDelTablero = 40;
	}
}

int Configuracion::getCantidadDeJugadores(){

	return this->cantidadDeJugadores;
}
int Configuracion::getCantidadDeSoldadosPorJugador(){

	return this->cantidadDeSoldadosPorJugador;
}
int Configuracion::getCantidadFilasTablero(){

	return this->cantidadFilasTablero;
}
int Configuracion::getCantidadColTablero(){

	return this->cantidadColTablero;
}
int Configuracion::getAlturaDelTablero(){

	return this->alturaDelTablero;
}

