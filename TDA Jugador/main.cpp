#include <iostream>
#include "jugador.h"
#include <vector>
using namespace std;

int main() {
	Jugador* j = new Jugador(1, 3);
    cout << "Cantidad de soldados: " << j->getCantidadDeSoldados() << endl;
    cout << "Cantidad de cartas: " << j->getCantidadDeCartas() << endl;
    cout << "Carta obtenida: " << *j->getCarta() << endl;
    j->decrementarCantidadDeSoldados();
    cout << "Cantidad de soldados: " << j->getCantidadDeSoldados() << endl;
	return 0;
}
