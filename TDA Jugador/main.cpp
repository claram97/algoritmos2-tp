#include <iostream>
#include "jugador.h"

using namespace std;

int main() {
	int *cartas = new int[5];
	Jugador* j = new Jugador(1, 2, cartas);
	cout << j->obtenerCantidadDeFichas() << endl;
	return 0;
}
