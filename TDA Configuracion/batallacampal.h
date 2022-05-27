//BatallaCampal.h

#define MIN_JUGADORES 20;
#define MAX_JUGADORES 20;

class BatallaCampal {
	
private:
	Vector <Jugador**> jugadores;
	unsigned int turno;
	Vector <Tablero**> tablero;
	unsigned int dimensionTablero;
	unsigned int cantidadJugadores;
	unsigned int cantidadSoldados;
public:

	BatallaCampal(unsigned int cantJugadores, usigned int cantidadSoldados, unsigned int dimensionTablero);
	virtual ~BatallaCampal();
	unsigned int siguienteTurno();
	bool estadoDelJuego(); 
}

