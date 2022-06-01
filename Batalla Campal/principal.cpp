#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "BatallaCampal.h"

using namespace std;

int main(){

	try{
		cout << "BATALLA CAMPAL"<<endl;

		srand(time(NULL));

		int opcionUsuario;
		char opcionUsuarioC;
		int coordX;
		int coordY;
		int coordZ;
		char movimiento;
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
		cout << batalla->getCantidadDeSoldados();
		for(int i = 1; i <= batalla->getCantidadDeJugadores(); i++){
			for( int j = 1; j <= batalla->getCantidadDeSoldados(); j++){
				cout << "Jugador " << i << " elija posiciones para el soldado [" << j << "]: " <<endl;
				cout << "fila: ";
				cin >> coordX;
				cout << "columna: ";
				cin >> coordY;
				if( coordX < batalla->getDimensionDelTablero() && coordY < batalla->getDimensionDelTablero()){
					batalla->getJugador(i)->nuevoSoldado(coordX, coordY);
				}else{
					throw "Coordenada inválida";
				}
				batalla->getTablero()->getCasilla(coordX, coordY, 1)->setContenido(LLENO);

			}
		}

		while( batalla->getEstadoDelJuego() == JUGANDO && pausa == 0){

			cout << "Turno del jugador: " << batalla->getJugador(batalla->getTurno())->getId() << endl;
			int aleatorio = rand() %6 +1;
			batalla->getJugador(batalla->getTurno())->nuevaCarta(aleatorio);
			cout << "Cartas del jugador: " << batalla->getJugador(batalla->getTurno())->getCantidadDeCartas() <<endl;
			//preguntar usar carta
			cout << "Cantidad de fichas: "<< batalla->getJugador(batalla->getTurno())->getCantidadDeHerramientas() << endl;
			cout << "Cantidad de soldados: "<< batalla->getJugador(batalla->getTurno())->getCantidadDeSoldados() << endl;

			//batalla->getTablero()->mostrarTablero();

			cout <<" Desea mover un soldado? (SI: S, NO: N): ";
			cin >> opcionUsuarioC;
			if(opcionUsuarioC == 'S'){
				cout << "elija el soldado a mover: " <<endl;
				for(unsigned int i = 1; i <= batalla->getJugador(batalla->getTurno())->getCantidadDeSoldados(); i++){
					cout << "Soldado: ["<<batalla->getJugador(batalla->getTurno())->getSoldado(i)->getPosicionX() <<","<<batalla->getJugador(batalla->getTurno())->getSoldado(i)->getPosicionY() <<"]"<<endl;
				}
				cout << "fila: ";
				cin >> coordX;
				cout << "columna: ";
				cin >> coordY;

				cout << "Elija movimiento (WASD): ";
				cin >> movimiento;
				batalla->moverSoldado(movimiento, coordX, coordY, batalla->getTurno());
			}

			cout << "Ingrese coordenadas de disparo: "<<endl;

			cout << "fila: ";
			cin >> coordX;
			cout << "columna: ";
			cin >> coordY;
			cout << "Altura: ";
			cin >> coordZ;

			batalla->realizarDisparo(coordX, coordY, coordZ);

			cout << "La casilla ahora está: "<< batalla->getTablero()->getCasilla(coordX, coordY, coordZ)->getContenido() <<endl;

			cout << "Cartas disponibles: "<<endl;
			for(unsigned int i = 1; i <= batalla->getJugador(batalla->getTurno())->getCantidadDeCartas(); i++){
				cout << i <<"."<< batalla->getJugador(batalla->getTurno())->getCarta(i)->getDescripcion() <<endl;
			}
			cout << "Desea usar una carta? (SI: S, NO: N): ";
			cin >> opcionUsuarioC;
			if(opcionUsuarioC == 'S'){

			}

			batalla->siguienteTurno();
			//batalla->getTablero()->mostrarTablero();
			cin >> pausa;
		}



		return 0;

	}catch(const char* X){
		cout << "ERROR: " << X <<endl;
	}
}




