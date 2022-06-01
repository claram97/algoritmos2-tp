#ifndef JUGADOR_H
#define JUGADOR_H
#include "Lista.h"
#include "Ficha.h"
#include "Carta.h"
#define MAX_CARTAS 5

enum EstadoJugador {
	ELIMINADO,
	EN_BATALLA
};

class Jugador {

private:
	unsigned int id;
	unsigned int cantidadSoldados;
	unsigned int cantidadHerramientas;
	Lista<Ficha*>* herramientas;
	Lista<Ficha*>* soldados;
	Lista<Carta*>* cartas;
	EstadoJugador estado;

public:
	//Pre: -
	//Post: crea un jugador con su respectivo id, la cantidad de soldados que posee y las cartas en su mazo.
	Jugador(int id, int cantidadSoldados);

	//Pre: -
	//Post: destruye la instancia de jugador.
	virtual ~Jugador();

	//Pre: -
	//Post: devuelve la cantidad de herramientas.
	unsigned int getCantidadDeHerramientas();

	//Pre: -
	//Post: devuelve la cantidad de soldados.
	unsigned int getCantidadDeSoldados();

	//Pre: -
	//Post: devuelve la cantidad de cartas.
	unsigned int getCantidadDeCartas();

	//Pre: -
	//Post: agrega una ficha.
	void setHerramienta(Ficha* ficha);

	//Pre: recibe un id de ficha
	//Post: devuelve la ficha.
	Ficha* getHerramienta(int id);

	//Pre: -
	//Post: agrega una ficha.
	void setSoldado(Ficha* ficha);

	//Pre: recibe un id de soldado
	//Post: devuelve el soldado.
	Ficha* getSoldado(int id);

	//Pre: -
	//Post: de ser posible, agrega la carta al mazo.
	void setCarta(Carta* carta);

	//Pre: (habria que poner alguna condicion, tipo el tipo de carta o algo)
	//Post: devuelve una carta.
	Carta* getCarta(unsigned int i);

	//Pre: recibe un id de una herramienta
	//Post: elimina la herramienta de la lista de herramientas del jugador.
	void eliminarHerramienta(int id);

	//Pre: recibe un estado de jugador
	//Post: cambiar el estado al jugador
	void setEstado(EstadoJugador estado);

	//Pre:
	//Post:
	EstadoJugador getEstadoJugador();

	//Pre:
	//Post:
	void nuevaCarta(int aleatorio);

	//Pre:
	//Post:
	unsigned int getId();

	void nuevoSoldado(int x, int y);

	void eliminarSoldado(int id);

	void eliminarCarta(int id);

	bool esPosicionValida(int x, int y, int z);
};

#endif
