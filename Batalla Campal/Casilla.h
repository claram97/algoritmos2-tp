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
		
		void setTipo(TipoDeCasillero tipo);
		//Pre: recibe una coordenada que se quiere inicializar y el valor al cual se lo quiere inicializar.
		//Post: inicializa la coordenada.
		//Opcion 2
		void setCoordenadas(unsigned int coordenadaX, unsigned int coordenadaY, unsigned int coordenadaZ);
		//Opcion 1
		void setCoordenada(unsigned int &coordenadaAModificar, unsigned int coordenada);
	
		
	public:

		

		/*//Pre: recibe las coordenadas del tablero.
		//Post: devuelve true si las proporciones del tablero son vÃ¡lidas.
		//(Me parece que esto es mÃ¡s para tablero pero bueno ya lo tenÃ­a hecho asÃ­ que si querÃ©s y si te sirve adaptalo)
		//(Y sino cambiame las cosas que creas necesarias)
		bool proporcionesValidasTablero(unsigned int largo, unsigned int ancho, unsigned int alto);
	*/


		//Pre: recibe las coordenadas del tablero y una cantidad de tokens (fichas).
		//Post: crea una casilla.
		Casilla(unsigned int coordenadaX, unsigned int coordenadaY, unsigned int coordenadaZ, TipoDeCasillero tipo);
	

		//Pre: recibe un tipo para la casilla (mar, tierra o aire).
		//Post: inicializa el tipo de la casilla segÃºn su tipo.
		void setTipoDeCasilla(TipoDeCasillero tipoDeCasilla);

		//Pre:
		//Post: devuelve el tipo de la casilla.
		TipoDeCasillero getTipoDeCasilla();
	
		//Pre:
		//Post: devuelve la coordenada X de la casilla.
		unsigned int getCoordenadaX();


	
		//Pre:
		//Post: devuelve la coordenada Y de la casilla.
		unsigned int getCoordenadaY();

		

		//Pre:
		//Post: devuelve la coordenada Z de la casilla.
		unsigned int getCoordenadaZ();
		
		EstadoDelCasillero getEstado();
		
		void setEstado(EstadoDelCasillero estado);

		//pre:
		//post:
		TipoDeCasillero getContenido();

		//pre:
		//post:
		void setTipoDeCasillero(TipoDeCasillero tipo);

		//pre:
		//post:
		void setCoordenadas ();

};
#endif
