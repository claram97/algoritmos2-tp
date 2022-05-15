#include <iostream>
#include <stdio.h>
#include "jugador.cpp"

using namespace std;

class Jugador {

public:
	Jugador(int id, int cantidadDeFichas, int* cartas);

	int obtenerCantidadDeFichas();
};
