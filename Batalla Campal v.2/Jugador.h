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
	 *  Post: Crea una instancia de jugador 
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
	unsigned int getCantidadDeCartas();
	/*
	 *  Pre: 
	 *  Post: 
	 */
	void setHerramienta(Ficha* ficha);
	/*
	 *  Pre: 
	 *  Post: 
	 */
	//Pre: recibe un id de ficha
	//Post: devuelve la ficha.
	Ficha* getHerramienta(int id);
	/*
	 *  Pre: 
	 *  Post: 
	 */
	//Post: agrega una ficha.
	void setSoldado(Ficha* ficha);
	/*
	 *  Pre: 
	 *  Post: 
	 */
	//Pre: recibe un id de soldado
	//Post: devuelve el soldado.
	Ficha* getSoldado(int id);
	/*
	 *  Pre: 
	 *  Post: 
	 */

	//Pre: -
	//Post: de ser posible, agrega la carta al mazo.
	void setCarta(Carta* carta);
	/*
	 *  Pre: 
	 *  Post: 
	 */
	//Pre: (habria que poner alguna condicion, tipo el tipo de carta o algo)
	//Post: devuelve una carta.
	Carta* getCarta(unsigned int i);
	/*
	 *  Pre: 
	 *  Post: 
	 */
	//Pre: recibe un id de una herramienta
	//Post: elimina la herramienta de la lista de herramientas del jugador.
	void eliminarHerramienta(int id);
	/*
	 *  Pre: 
	 *  Post: 
	 */
	//Pre: recibe un estado de jugador
	//Post: cambiar el estado al jugador
	void setEstado(EstadoJugador estado);
	/*
	 *  Pre: 
	 *  Post: 
	 */
	EstadoJugador getEstadoJugador();
	/*
	 *  Pre: 
	 *  Post: 
	 */
	void nuevaCarta(int aleatorio);
	/*
	 *  Pre: 
	 *  Post: 
	 */
	unsigned int getId();
	/*
	 *  Pre: 
	 *  Post: 
	 */
	void nuevoSoldado(int x, int y);
	/*
	 *  Pre: 
	 *  Post: 
	 */
	void eliminarSoldado(int id);
	/*
	 *  Pre: 
	 *  Post: 
	 */
	void nuevaHerramienta(char FICHA, int fila, int columna, int altura);
	/*
	 *  Pre: 
	 *  Post: 
	 */
	void eliminarCarta(int id);
	/*
	 *  Pre: 
	 *  Post: 
	 */
	bool esPosicionValida(int x, int y, int z);
};

#endif
