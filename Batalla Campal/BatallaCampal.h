#ifndef BATALLACAMPAL_H
#define BATALLACAMPAL_H
#include "Jugador.h"
#include "Tablero.h"
#include "Lista.h"
#include "Vector.h"
#include "Casilla.h"
#include "Ficha.h"
#include <iostream>

#define MIN_JUGADORES 2
#define MAX_JUGADORES 20
#define MIN_SOLDADOS 3
#define MAX_SOLDADOS 8
#define MIN_DIMENSION 20
#define MAX_DIMENSION 100

enum estadoJuego{
	JUGANDO,
	FINALIZADO
}

#define ARRIBA 'W'
#define ABAJO 'S'
#define DERECHA 'D'
#define IZQUIERDA 'A'


enum estadoDelJuego{JUGANDO,FINALIZADO};

class BatallaCampal{
	
	private:
		Vector <Jugador*>* jugadores;
		Tablero* tablero;
		int turno;
		int dimensionTablero;
		int cantidadJugadores;
		unsigned int cantidadSoldados;
		estadoDelJuego estadoDelJuegoActual;

	public:

		/*
		 * Pre:
		 * Pos:
		 */
		BatallaCampal(unsigned int cantJugadores, unsigned int cantidadSoldados, int dimensionTablero);
		/*
		 * Pre:
		 * Pos:
		 */
		void siguienteTurno();
		/*
		 * Pre:
		 * Pos:
		 */
		void estadoActualDelJuego();
		/*
		 * Pre:
		 * Pos:
		 */
		estadoDelJuego getEstadoDelJuego();
		/*
		 * Pre:
		 * Pos:
		 */
		int getTurno();
		/*
		 * Pre:
		 * Pos:
		 */
		Jugador* getJugador(unsigned int jugador);
		/*
		 * Pre:
		 * Pos:
		 */
		Tablero* getTablero();
		/*
		 * Pre:
		 * Pos:
		 */
		virtual ~BatallaCampal();

		void moverSoldado(char movimiento, int x, int y, int turno);

		int getCantidadDeJugadores();

		int getCantidadDeSoldados();

		void eliminarSoldado();

		bool soldadosCoinciden(int x, int y);

		int getDimensionDelTablero();

		void realizarDisparo(int x, int y, int z);

		void ejecutarCarta(int numero, int turno);

		void dispararMisil(int x, int y, int z);

		int usarRadar(int x, int y, int z);

		void dispararSuperMisil(int x, bool filaOColumna);

		bool verificarCoordenadas(int x, int y, int z);

};

#endif
