#include <iostream>
#include "jugador.h"
#include <deque>
using namespace std;

int main() {
	std::deque <int*>*cartas=new std::deque<int*>();
	Jugador* j = new Jugador(1, 3,  cartas);
	int* carta = new int(12);
	j->agregarCarta(carta);
    cout << "Cantidad de fichas: " << j->obtenerCantidadDeFichas() << endl;
    cout << "Cantidad de cartas: " << j->obtenerCantidadDeCartas() << endl;
    cout << "Cartas obtenidas: " << *j->obtenerCarta() << endl;
    j->decrementarCantidadDeFichas();
    cout << "Cantidad de fichas: " << j->obtenerCantidadDeFichas() << endl;
	return 0;
}
