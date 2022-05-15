#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Cartas.h"
#include "Configuracion.h"
#include "Jugador.h"

using namespace std;

int main(){

	cout << "BATALLA CAMPAL"<<endl;

	srand(time(NULL));
	int numeroAleatorio;
	int opcionUsuario;
	char usarCarta;
	Configuracion config;
	Jugador* pJugador;
	int turno;

	cout << "1.Partida rápida (2 jugadores)\n2.Partida personalizada (2 o más jugadores)" <<endl;
	cout << "Modo de juego: ";
	cin >> opcionUsuario;

	if( opcionUsuario == 2){
		cout << "Elige cantidad de jugadores: ";
		cin >> opcionUsuario;
		config.setCantidadDeJugadores(opcionUsuario);
		cout << "Elige cantidad de soldados por jugador: ";
		cin >> opcionUsuario;
		config.setCantidadDeSoldadosPorJugador(opcionUsuario);
		cout << "Elige elige el largo del mapa: ";
		cin >> opcionUsuario;
		config.setCantidadFilasTablero(opcionUsuario);
		cout << "Elige elige el ancho del mapa: ";
		cin >> opcionUsuario;
		config.setCantidadColTablero(opcionUsuario);
		cout << "Elige elige el alto del mapa: ";
		cin >> opcionUsuario;
		config.setAlturaDelTablero(opcionUsuario);
	}

	pJugador = new Jugador[config.getCantidadDeJugadores()];

	cout << "Sistema de turnos" <<endl;
	turno = 1;

	cout << "Turno del jugador: " << turno <<endl;
	cout << "\nCartas disponibles: "<<endl;

	//generar carta
	if(pJugador[0].getCantidadCartas() < 5){

		bool encontrado = false;

		for( int i = 0; i < MAX_CARTAS; i++){

			if(pJugador[0].obtenerCarta(i)->getTipoDeCarta() == ' ' && !(encontrado)){

				numeroAleatorio = 1 + rand()%3;
				pJugador[0].obtenerCarta(i)->nuevaCarta(numeroAleatorio);
				pJugador[0].sumarCantidadCartas();
				encontrado = true;
			}
		}
	}else{
		cout << "No puedes obtener mas cartas" <<endl;
	}

	//mostrar cartas
	for(unsigned int i = 0; i < MAX_CARTAS;i++){

		if(pJugador[0].obtenerCarta(i)->getDescripcion() != ""){

			cout <<"-"<<pJugador[0].obtenerCarta(i)->getDescripcion() << endl;
		}
	}

	//buscar carta
	cin >> usarCarta;
	for (int i = 0; i < MAX_CARTAS; i++){
		if(pJugador[0].obtenerCarta(i)->getTipoDeCarta() == usarCarta){
			cout << "Carta en la posicion: " << i <<endl;
		}
	}

	//borrar carta
	pJugador[0].obtenerCarta(0)->removerCarta();
	pJugador[0].restarCantidadCartas();


	delete []pJugador;

	return 0;
}
