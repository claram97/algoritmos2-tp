#ifndef JUGADOR_H
#define JUGADOR_H
#include <deque>
#define MAX_CARTAS 5

class Jugador {

private:
	unsigned int id;
	Ficha** fichas;
	unsigned int cantidadDeFichas;
	std::deque<int *>* cartas; //TODO: Reemplazar int por TDA cartas

public:
	Jugador(int id, int cantidadDeFichas, std::deque<int*>* cartas);
	
	unsigned int getCantidadDeFichas();
	
    	//Pre: recibe una cantidad de fichas mayor a 0.
    	//Post: inicializa la cantidad de fichas.
    	void setCantidadDeFichas(unsigned int cantidadDeFichas);
	
	unsigned int getCantidadDeCartas();
	void agregarCarta(int*carta); //cambiar por Cartas*
	int* getCarta(); //cambiar por Cartas*
	void decrementarCantidadDeFichas();

};

#endif
