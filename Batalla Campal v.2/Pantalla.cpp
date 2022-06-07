#include "Pantalla.h"
#include <iostream>

using namespace std;

Pantalla::Pantalla(){

	this->opcionUsuario = 0;
	this->cantidadJugadores = 2;
	this->cantidadSoldados = 3;
	this->dimensionDelTablero = 20;
	this->mapaOpcion = rand() % 3 + 1;
}

void Pantalla::nuevaPartida(){

	cout << "1.Partida rapida (2 jugadores)\n2.Partida personalizada (2 o mas jugadores)" <<endl;
	cout << "Modo de juego: ";
	cin >> this->opcionUsuario;
	
	cout<<"Toco el mapa: "<<mapaElegido()<<endl;
	
	if( this->opcionUsuario == 2){
		cout << "Elige cantidad de jugadores (2 a 20): ";
		cin >> this->cantidadJugadores;
		cout << "Elige cantidad de soldados por jugador (3 a 8): ";
		cin >> this->cantidadSoldados;
		cout << "Elige el tamanio del mapa (20 a 100): ";
		cin >> this->dimensionDelTablero;
	}
	
	
}

int Pantalla::mapaElegido(){
	

	return this->mapaOpcion;
}

void Pantalla::seleccionarMapa(){
	
	if(this->mapaElegido() == 1){
		//mapa 1
	}
	else{
		if(this->mapaElegido() == 2){
			// mapa 2
		}else{
			//mapa 3
		}
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
