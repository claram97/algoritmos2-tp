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
		 * Pre: Necesita su respectivo id, la cantidad de soldados que posee y las cartas en su mazo
		 * Post: Crea una instancia de jugador 
		 */
		Jugador(unsigned int id, int cantidadSoldados);
		/*
		 * Post: Destruye la instancia de jugador
		 */
		virtual ~Jugador();
		/*
		 * Post: Devuelve la cantidad de herramientas
		 */
		unsigned int getCantidadDeHerramientas();
		/*
		 * Post: Devuelve la cantidad de soldados
		 */
		int getCantidadDeSoldados();
		/*
		 * Post: Devuelve la cantidad de cartas
		 */ 
		unsigned int getCantidadDeCartas();
		/*
		 * Pre: Necesita un recibe un id de la herramienta
		 * Post: Devielve la ficha
		 */
		Ficha* getHerramienta(int id);
		/*
		 * Post: Devuelve el soldado
		 */
		Lista<Ficha*>* getSoldado();
		/*
		 * Post: Devuelve una carta
		 */
		Lista<Carta*>* getCarta();
		/*
		 * Pre: Recibe un id de una herramienta
		 * Post: eElimina la herramienta de la lista de herramientas del jugador
		 */
		void eliminarHerramienta(int id);
		/*
		 * Pre: Recibe un estado de jugador
		 * Post: Cambia el estado al jugador
		 */
		void setEstado(EstadoJugador estado);
		/*
		 * Post: Devuelve el estado del jugador
		 */
		EstadoJugador getEstadoJugador();
		/*
		 * Pre: Necesita un numero entre el 1 y el 6 para el tipo de carta
		 * Post: Crea un tipo de carta
		 */
		void nuevaCarta(int aleatorio);
		/*
		 * Post: Devuelve el id
		 */
		unsigned int getId();
		/*
		 * Pre: Necesita las coordenadas de la fila y la columna
		 * Post: Crea un soldado
		 */
		void nuevoSoldado(int fila, int columna);
		/*
		 * Pre: Necesita las coordenadas de la fila y la columna
		 * Post: Elimina un soldado
		 */
		void eliminarSoldado(int fila, int columna);
		/*
		 * Pre: Necesita un tipo de ficha y las coordenadas de la casilla
		 * Post: Crea una nueva herramienta
		 */
		void nuevaHerramienta(char FICHA, int fila, int columna, int altura);
		/*
		 * Pre: Necesita un id
		 * Post: Elimina una carta
		 */
		void eliminarCarta(int id);
		/*
		 * Pre: Necesita las coordenadas de la casilla
		 * Post: Devuelve true si se encuentra un soldado
		 */
		bool buscarSoldado(int fila, int columna);
		/*
		 * Pre: Necesita las coordenadas de la casilla
		 * Post: Devuelve el id del soldado
		 */
		unsigned int buscarIdSoldado(int fila, int columna);
	};

#endif
