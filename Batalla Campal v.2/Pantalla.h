#ifndef SRC_PANTALLA_H_
#define SRC_PANTALLA_H_

class Pantalla{

	private:

		int opcionUsuario;
		int cantidadJugadores;
		int cantidadSoldados;
		int dimensionDelTablero;


	public:

	Pantalla();

	void nuevaPartida();

	int getCantidadJugadores();

	int getCantidadSoldados();

	int getDimensionDelTablero();

};




#endif /* SRC_PANTALLA_H_ */
