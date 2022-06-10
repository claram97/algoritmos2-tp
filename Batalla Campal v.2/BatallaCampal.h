#ifndef BATALLACAMPAL_H
#define BATALLACAMPAL_H
#include "Jugador.h"
#include "Tablero.h"
#include "Lista.h"
#include "Casilla.h"
#include "Ficha.h"

#define MIN_JUGADORES 2
#define MAX_JUGADORES 20
#define MIN_SOLDADOS 3
#define MAX_SOLDADOS 8
#define MIN_DIMENSION 20
#define MAX_DIMENSION 100

enum estadoDelJuego{
	JUGANDO,
	FINALIZADO
};

#define ARRIBA 'W'
#define ABAJO 'S'
#define DERECHA 'D'
#define IZQUIERDA 'A'
#define DIAGONAL_SUP_IZQ 'Q'
#define DIAGONAL_SUP_DER 'E'
#define DIAGONAL_INF_IZQ 'Z'
#define DIAGONAL_INF_DER 'C'

class BatallaCampal{
	
	private:
		Lista <Jugador*>* jugadores;
		Tablero* tablero;
		unsigned int turno;
		int dimensionTablero;
		int cantidadJugadores;
		unsigned int cantidadSoldados;
		estadoDelJuego estadoDelJuegoActual;

	public:

		/*
		 * Pre: Necesita la cantidad de jugadores, de soldados, de herramientas y la dimension del tablero
		 * Post: Si las cantidades son validas, crea una partida de batalla con las especificaciones mencionadas
		 */
		BatallaCampal(unsigned int cantidadJugadores, unsigned int cantidadSoldados, int dimensionTablero);
		/*
		 * Post: Pasa el turno al siguiente jugador
		 */
		void siguienteTurno();
		/*
		 * Post: Dependiendo del estado del juego, decide continuarlo o finalizarlo (cambia el estado)
		 */
		void estadoActualDelJuego();
		/*
		 * Post: Devuelve el estado del juego actual
		 */
		estadoDelJuego getEstadoDelJuego();
		/*
		 * Post: Devuelve de quien es turno
		 */
		int getTurno();
		/*
		 * Pre: Necesita el numero/id del jugador
		 * Pos: Devuelve el jugador
		 */
		Lista <Jugador*>* getJugador();
		/*
		 * Post: Devuelve el tablero
		 */
		Tablero* getTablero();
		/*
		 * Post: Destruye el TDA BatallaCampal
		 */
		virtual ~BatallaCampal();
		/*
		 * Pre: Necesita el tipo de movimento, las coordenadas de la fila y la columna, y el turno
		 * Post: Si el movimiento es valido, mueve un soldado a una casilla de distancia
		 */
		void moverSoldado(char movimiento, int x, int y);
		/*
		 * Post: Devuelve la cantidad de jugadores que hay en la batalla
		 */
		int getCantidadDeJugadores();
		/*
		 * Post: Devuelve la cantidad de soldados que hay en la batalla
		 */
		int getCantidadDeSoldados();

		void eliminarSoldado();
		/*
		 * Pre: Necesita las coordenadas de la fila y la columna
		 * Post: Devuelve true si hay dos soldados en una misma casilla
		 */
		bool soldadosCoinciden(int x, int y);
		/*
		 * Post: Devuelve la dimension del tablero
		 */
		int getDimensionDelTablero();
		/*
		 * Pre: Necesita las coordenadas de la casilla
		 * Pos: Inactiva la casilla, y si hay una ficha en la casilla, esta se elimina
		 */
		void realizarDisparo(int x, int y, int z);
		/*
		 * Pre: Necesita las coordenadas de la casilla y el numero de la carta
		 * Post: Se activa la carta del numero usado
		 */
		void usarCarta(int numero, int x, int y, int z);
		/*
		 * Pre: Necesita las coordenadas de la casilla
		 * Post: Inactiva la casillas y sus alrededores a una casilla de distancia, si hay fichas es algunas de las casillas,
		 * 		se eliminan
		 */
		void dispararMisil(int x, int y, int z);
		/*
		 * Pre: Necesita las coordenadas de la casilla
		 * Post: Devuelve la cantidad de fichas que hay en los alrededores la casilla seleccionada a 2 casillas de distancia
		 */
		int usarRadar(int x, int y, int z);
		/*
		 * Pre: Necesita la coordenada de la fila o columna y si es una fila o columna
		 * Post: Inactiva toda la fila o columna y elimina todas las fichas que se encuentran en la fila o columna
		 */
		void dispararSuperMisil(int x, char tipoDeCasilla);
		/*
		 * Pre: Necesita las coordenadas de la casilla
		 * Post: Verifica si la casilla se encuentra en el tablero
		 */
		bool esCoordenadaValida(int x, int y, int z);
		bool esCoordenadaValida(int fila, int columna);
		/*
		 * Pre: Necesita las coordenadas de la casilla
		 * Post: Devuelve true si se eliminÃ³ un soldado
		 */
		bool eliminarEnemigo(int x, int y);

		void iniciarEscenarioUno();
		void iniciarEscenarioDos();
		void iniciarEscenarioTres();

};

#endif
