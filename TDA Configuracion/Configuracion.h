#ifndef SRC_CONFIGURACION_H_
#define SRC_CONFIGURACION_H_

class Configuracion{

	private:
		int cantidadDeJugadores;
		int cantidadDeSoldadosPorJugador;
		int cantidadFilasTablero;
		int cantidadColTablero;
		int alturaDelTablero;


	public:

		Configuracion();
		Configuracion(int,int,int,int,int);
		int getCantidadDeJugadores();
		int getCantidadDeSoldadosPorJugador();
		int getCantidadFilasTablero();
		int getCantidadColTablero();
		int getAlturaDelTablero();
		void setCantidadDeJugadores(int);
		void setCantidadDeSoldadosPorJugador(int);
		void setCantidadFilasTablero(int);
		void setCantidadColTablero(int);
		void setAlturaDelTablero(int);


};



#endif
