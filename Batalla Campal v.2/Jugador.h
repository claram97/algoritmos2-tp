#ifndef JUGADOR_H
#define JUGADOR_H
#include "Lista.h"
#include "Ficha.h"
#include "Carta.h"
#define MAX_CARTAS 5
#define MAX_HERRAMIENTAS 7

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
	/*
	 *  Pre: Necesita el id, la cantidad de soldados, y la cantidad de herramientas
	 *  Post: Crea un jugador 
	 */
	Jugador(int id, int cantidadSoldados, int cantidadHerramientas);
	/*
	 *  Post: Destruye la instancia de jugador
	 */
	virtual ~Jugador();
	/*
	 *  Post: Devuelve la cantidad de herramientas.
	 */
	unsigned int getCantidadDeHerramientas();
	/*
	 *  Post: Devuelve la cantidad de soldados
	 */
	int getCantidadDeSoldados();
	/*
	 *  Post: Devuelve la cantidad de cartas
	 */
	//Post: .
	unsigned int getCantidadDeCartas();
	/*
	 *  Pre: 
	 *  Pos: 
	 */
	//Pre: -
	//Post: agrega una ficha.
	void setHerramienta(Ficha* ficha);
	/*
	 *  Pre: 
	 *  Pos: 
	 */
	//Pre: recibe un id de ficha
	//Post: devuelve la ficha.
	Ficha* getHerramienta(int id);
	/*
	 *  Pre: 
	 *  Pos: 
	 */
	//Post: agrega una ficha.
	void setSoldado(Ficha* ficha);
	/*
	 *  Pre: 
	 *  Pos: 
	 */
	//Pre: recibe un id de soldado
	//Post: devuelve el soldado.
	Ficha* getSoldado(int id);
	/*
	 *  Pre: 
	 *  Pos: 
	 */

	//Pre: -
	//Post: de ser posible, agrega la carta al mazo.
	void setCarta(Carta* carta);
	/*
	 *  Pre: 
	 *  Pos: 
	 */
	//Pre: (habria que poner alguna condicion, tipo el tipo de carta o algo)
	//Post: devuelve una carta.
	Carta* getCarta(unsigned int i);
	/*
	 *  Pre: 
	 *  Pos: 
	 */
	//Pre: recibe un id de una herramienta
	//Post: elimina la herramienta de la lista de herramientas del jugador.
	void eliminarHerramienta(int id);
	/*
	 *  Pre: 
	 *  Pos: 
	 */
	//Pre: recibe un estado de jugador
	//Post: cambiar el estado al jugador
	void setEstado(EstadoJugador estado);
	/*
	 *  Pre: 
	 *  Pos: 
	 */
	EstadoJugador getEstadoJugador();
	/*
	 *  Pre: 
	 *  Pos: 
	 */
	void nuevaCarta(int aleatorio);
	/*
	 *  Pre: 
	 *  Pos: 
	 */
	unsigned int getId();
	/*
	 *  Pre: 
	 *  Pos: 
	 */
	void nuevoSoldado(int x, int y);
	/*
	 *  Pre: 
	 *  Pos: 
	 */
	void eliminarSoldado(int id);
	/*
	 *  Pre: 
	 *  Pos: 
	 */
	void nuevaHerramienta(char FICHA, int fila, int columna, int altura);
	/*
	 *  Pre: 
	 *  Pos: 
	 */
	void eliminarCarta(int id);
	/*
	 *  Pre: 
	 *  Pos: 
	 */
	bool esPosicionValida(int x, int y, int z);
};

#endif
