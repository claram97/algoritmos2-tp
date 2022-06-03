#ifndef _CASILLA_H
#define _CASILLA_H

enum EstadoDelCasillero{
	VACIO,
	INACTIVO,
	LLENO
};

enum TipoDeCasillero{
	TIERRA,
	AIRE,
	AGUA,
	GENERAL
};

class Casilla{

	private:

		unsigned int coordenadaX;
		unsigned int coordenadaY;
		unsigned int coordenadaZ;
		EstadoDelCasillero estadoCasilla;
		TipoDeCasillero tipoDeCasilla;
		

	public:

		//Pre: recibe las coordenadas del tablero y una cantidad de tokens (fichas).
		//Post: crea una casilla.
		Casilla(unsigned int coordenadaX, unsigned int coordenadaY, unsigned int coordenadaZ, TipoDeCasillero tipo);

		/*//Pre: recibe las coordenadas del tablero.
		//Post: devuelve true si las proporciones del tablero son vÃ¡lidas.
		//(Me parece que esto es mÃ¡s para tablero pero bueno ya lo tenÃ­a hecho asÃ­ que si querÃ©s y si te sirve adaptalo)
		//(Y sino cambiame las cosas que creas necesarias)
		bool proporcionesValidasTablero(unsigned int largo, unsigned int ancho, unsigned int alto);
	*/

		//Pre: -
		//Post: elimina la casilla existente.
		virtual ~Casilla();
/*

		//Pre: recibe un contenido para la casilla (vacÃ­o, full o inactiva).
		//Post: inicializa el contenido de la casilla segÃºn su tipo.
		void setContenido(EstadoDelCasillero contenido);
*/
		//Pre:
		//Post: devuelve el contenido de la casilla.
		TipoDeCasillero getContenido();

		//Pre: recibe un tipo para la casilla (mar, tierra o aire).
		//Post: inicializa el tipo de la casilla segÃºn su tipo.
/*
		void setTipoDeCasilla(TipoDeCasillero tipoDeCasilla);
*/
		//Pre:
		//Post: devuelve el tipo de la casilla.
		TipoDeCasillero getTipoDeCasilla();

		//Pre: recibe una coordenada X.
		//Post: inicializa la coordenada X.
		void setCoordenadaX(unsigned int coordenadaX);

		//Pre:
		//Post: devuelve la coordenada X de la casilla.
		unsigned int getCoordenadaX();

		//Pre: recibe una coordenada Y.
		//Post: inicializa la coordenada Y de la casilla.
		void setCoordenadaY(unsigned int coordenadaY);

		//Pre:
		//Post: devuelve la coordenada Y de la casilla.
		unsigned int getCoordenadaY();

		//Pre: recibe la coordenada Z.
		//Post: inicializa la coordenada Z de la casilla.
		void setCoordenadaZ(unsigned int coordenadaZ);

		//Pre:
		//Post: devuelve la coordenada Z de la casilla.
		unsigned int getCoordenadaZ();
		
		EstadoDelCasillero getEstado();
		
		void setEstado(EstadoDelCasillero estado);
	
		void setTipo(TipoDeCasillero tipo);
};
#endif
