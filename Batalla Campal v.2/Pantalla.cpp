#include "Pantalla.h"
#include <iostream>

using namespace std;

Pantalla::Pantalla(){

	this->opcionUsuario = 0;
	this->cantidadJugadores = 2;
	this->cantidadSoldados = 3;
	this->dimensionDelTablero = 20;
}

void Pantalla::nuevaPartida(){

	cout << "1.Partida rÃ¡pida (2 jugadores)\n2.Partida personalizada (2 o mÃ¡s jugadores)" <<endl;
	cout << "Modo de juego: ";
	cin >> this->opcionUsuario;

	if( this->opcionUsuario == 2){
		cout << "Elige cantidad de jugadores (2 a 20): ";
		cin >> this->cantidadJugadores;
		cout << "Elige cantidad de soldados por jugador (3 a 8): ";
		cin >> this->cantidadSoldados;
		cout << "Elige elige el tamaÃ±o del mapa (20 a 100): ";
		cin >> this->dimensionDelTablero;


	}

}

int Pantalla::getCantidadJugadores(){
	return this->cantidadJugadores;
}

int Pantalla::getCantidadSoldados(){
	return this->cantidadSoldados;
}

int Pantalla::getDimensionDelTablero(){
	return this->dimensionDelTablero;
}
