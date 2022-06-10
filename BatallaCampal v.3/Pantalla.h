#ifndef SRC_PANTALLA_H_
#define SRC_PANTALLA_H_
#include <stdlib.h>
   
class Pantalla{

	private:

		int opcionUsuario;
		int cantidadJugadores;
		int cantidadSoldados;
		int dimensionDelTablero;
		int mapaOpcion;

	public:

	Pantalla();

	void nuevaPartida();
	
	void seleccionarMapa();
	
	int mapaElegido();

	int getCantidadJugadores();

	int getCantidadSoldados();

	int getDimensionDelTablero();

};




#endif /* SRC_PANTALLA_H_ */
