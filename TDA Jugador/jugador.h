#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador {

private:
	unsigned int id;
	int cantidadDeFichas;
	int* cartas; //TODO: Reemplazar int por TDA cartas

public:
	Jugador(int id, int cantidadDeFichas, int* cartas);

	int obtenerCantidadDeFichas();
};

#endif
