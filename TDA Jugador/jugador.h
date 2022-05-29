#ifndef JUGADOR_H
#define JUGADOR_H
#include <vector>
#include "Ficha.h"
#include "Carta.h"
#define MAX_CARTAS 5

enum EstadoJugador {
	JUGANDO
};

class Jugador {

private:
	unsigned int id;
	std::vector<Ficha*>* fichas;
	std::vector<Carta*>* cartas;
	EstadoJugador estado;

public:
	//Pre: -
	//Post: crea un jugador con su respectivo id, la cantidad de soldados que posee y las cartas en su mazo.
	Jugador(int id);

	//Pre: -
	//Post: destruye la instancia de jugador.
	virtual ~Jugador();

	//Pre: -
	//Post: devuelve la cantidad de fichas.
	unsigned int getCantidadDeFichas();

	//Pre: -
	//Post: devuelve la cantidad de soldados.
	unsigned int getCantidadDeSoldados();

	//Pre: -
	//Post: devuelve la cantidad de cartas.
	unsigned int getCantidadDeCartas();

	//Pre: -
	//Post: agrega una ficha.
	void setFicha(Ficha* ficha);

	//Pre: recibe un id de ficha
	//Post: devuelve la ficha.
	Ficha* getFicha(int id);

	//Pre: -
	//Post: de ser posible, agrega la carta al mazo.
	void setCarta(Carta* carta);

	//Pre: (habria que poner alguna condicion, tipo el tipo de carta o algo)
	//Post: devuelve una carta.
	Carta* getCarta();

	//Pre: recibe un id de ficha
	//Post: elimina la ficha de la lista de fichas del jugador.
	void eliminarFicha(int id);

	//Pre: recibe un estado de jugador
	//Post: cambiar el estado al jugador
	void Jugador::setEstado(EstadoJugador estado);
};

#endif
