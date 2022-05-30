#include "Jugador.h"
#include "Tablero.h"
#include "Lista.h"
#include "Vector.h"

#define MIN_JUGADORES 2
#define MAX_JUGADORES 20
#define MIN_SOLDADOS 3
#define MAX_SOLDADOS 8
#define MIN_DIMENSION 20
#define MAX_DIMENSION 100

enum estadoJuego{JUGANDO,FINALIZADO};

class BatallaCampal{
	
	private:
		Vector <Jugador*>* jugadores;
		unsigned int turno;
		Tablero* tablero;
		int dimensionTablero;
		int cantidadJugadores;
		unsigned int cantidadSoldados;

	public:

		BatallaCampal();
		BatallaCampal(unsigned int cantJugadores, unsigned int cantidadSoldados, int dimensionTablero);
		void siguienteTurno();
		unsigned int getTurno();
		estadoJuego estadoDelJuego();
		virtual ~BatallaCampal();
		Jugador* getJugador(unsigned int jugador);
		Tablero* getTablero();

};

