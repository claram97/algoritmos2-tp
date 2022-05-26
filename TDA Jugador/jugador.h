#ifndef JUGADOR_H
#define JUGADOR_H
#include <deque>
#define MAX_CARTAS 5

class Jugador {

private:
	unsigned int id;
	int cantidadDeFichas;
	std::deque<int *>* cartas; //TODO: Reemplazar int por TDA cartas

public:
	Jugador(int id, int cantidadDeFichas, std::deque<int*>* cartas);

	int obtenerCantidadDeFichas();
	int obtenerCantidadDeCartas();
	void agregarCarta(int*carta);
	int* obtenerCarta();
	void decrementarCantidadDeFichas();

};

#endif
