#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "BatallaCampal.h"

using namespace std;

int main(){

	try{
		cout << "BATALLA CAMPAL"<<endl;

		int opcionUsuario;
		int cantidadJugadores = 2;
		int cantidadSoldados = 3;
		int dimensionDelTablero = 20;
		int pausa = 0; //para forzar el corte del while

		cout << "1.Partida rápida (2 jugadores)\n2.Partida personalizada (2 o más jugadores)" <<endl;
		cout << "Modo de juego: ";
		cin >> opcionUsuario;

		if( opcionUsuario == 2){
			cout << "Elige cantidad de jugadores (2 a 20): ";
			cin >> cantidadJugadores;
			cout << "Elige cantidad de soldados por jugador (3 a 8): ";
			cin >> cantidadSoldados;
			cout << "Elige elige el tamaño del mapa (20 a 100): ";
			cin >> dimensionDelTablero;


		}

		BatallaCampal* batalla = new BatallaCampal(cantidadJugadores, cantidadSoldados, dimensionDelTablero);

		while( batalla->estadoDelJuego() == JUGANDO && pausa == 0){

			cout << "Turno del jugador: " << batalla->getJugador(batalla->getTurno())->getId() << endl;
			batalla->getJugador(batalla->getTurno())->nuevaCarta();
			cout << "Cartas del jugador: " << batalla->getJugador(batalla->getTurno())->getCantidadDeCartas() <<endl;

			cout << "Cantidad de fichas: "<< batalla->getJugador(batalla->getTurno())->getCantidadDeFichas() << endl;
			cout << "Cantidad de soldados: "<< batalla->getJugador(batalla->getTurno())->getCantidadDeSoldados() << endl;

			batalla->getJugador(batalla->getTurno())->getFicha(1)->setCoordenadas();
			cout << "Posicion 'Y' soldado: "<< batalla->getJugador(batalla->getTurno())->getFicha(1)->getPosicionY()<< endl;

			batalla->siguienteTurno();

			cin >> pausa;
		}
		batalla->getTablero()->rellenarMatriz();
		batalla->getTablero()->mostrarTablero();

		batalla->getTablero()->getCasilla(18,18,18)->setContenido(INACTIVO);
		cout << batalla->getTablero()->getCasilla(18,18,18)->getContenido() <<endl;
		batalla->getTablero()->getCasilla(18,18,18)->setTipoDeCasilla(AGUA);
		cout << batalla->getTablero()->getCasilla(18,18,18)->getTipoDeCasilla() << endl;

		return 0;

	}catch(const char* X){
		cout << "ERROR: " << X <<endl;
	}
}




