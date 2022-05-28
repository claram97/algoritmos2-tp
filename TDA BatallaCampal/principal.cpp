#include <iostream>}
#include <stdlib.h>
#include <time.h>
#include "BatallaCampal.h"
#include "configuracion.h"

using namespace std;

int main(){

	cout << "BATALLA CAMPAL"<<endl;

	srand(time(NULL));
	int numeroAleatorio;
	Configuracion* config;
	config = new Configuracion();
	int opcionUsuario;

	cout << "1.Partida rápida (2 jugadores)\n2.Partida personalizada (2 o más jugadores)" <<endl;
	cout << "Modo de juego: ";
	cin >> opcionUsuario;

	if( opcionUsuario == 2){
		cout << "Elige cantidad de jugadores: ";
		cin >> opcionUsuario;
		config->setCantidadDeJugadores(opcionUsuario);
		cout << "Elige cantidad de soldados por jugador: ";
		cin >> opcionUsuario;
		config->setCantidadDeSoldadosPorJugador(opcionUsuario);
		cout << "Elige elige el largo del mapa: ";
		cin >> opcionUsuario;
		config->setDimensionDelTablero(opcionUsuario);
		cout << "Elige elige el ancho del mapa: ";
		cin >> opcionUsuario;

	}

	BatallaCampal* batalla = new BatallaCampal(config->getCantidadDeJugadores(), config->getCantidadDeSoldadosPorJugador(), config->getDimensionDelTablero());


	return 0;
}




