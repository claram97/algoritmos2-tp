#ifndef SRC_CONFIGURACION_H_
#define SRC_CONFIGURACION_H_

class Configuracion{

	private:
		int cantidadDeJugadores;
		int cantidadDeSoldadosPorJugador;
		int dimensionDelTablero;



	public:

		Configuracion();
		Configuracion(int,int,int,int,int);
		int getCantidadDeJugadores();
		int getCantidadDeSoldadosPorJugador();
		int getDimensionDelTablero();
		void setCantidadDeJugadores(int);
		void setCantidadDeSoldadosPorJugador(int);
		void setDimensionDelTablero(int);



};



#endif
