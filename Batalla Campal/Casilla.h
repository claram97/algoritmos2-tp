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

		/*
		 * Pre: Recibe las coordenadas del tablero y una cantidad de tokens (fichas)
		 * Pos: Crea una casilla
		 */
		Casilla(unsigned int coordenadaX, unsigned int coordenadaY, unsigned int coordenadaZ, TipoDeCasillero tipo);
		/*
		 * Pre: Recibe un tipo para la casilla (mar, tierra o aire)
		 * Pos: Inicializa el tipo de la casilla segÃºn su tipo
		 */
		void setTipoDeCasilla(TipoDeCasillero tipoDeCasilla);
		/*
		 * Pos: Devuelve el tipo de casilla
		 */
		TipoDeCasillero getTipoDeCasilla();
		/*
		 * Pos: Devuelve la coordenada X/fila de la casilla
		 */
		unsigned int getCoordenadaX();
		/*
		 * Pos: Devuelve la coordenada Y/columna de la casilla
		 */
		unsigned int getCoordenadaY();
		/*
		 * Pos: Devuelve la coordenada Z/altura de la casilla
		 */
		unsigned int getCoordenadaZ();
		/*
		 * Pos: Devuelve el estado del casillero
		 */
		EstadoDelCasillero getEstado();
		/*
		/* Pre: Necesita un tipo de estado
		 * Pos: Setea el estado del casillero al tipo usado
		 */	
		void setEstado(EstadoDelCasillero estado);
		/*
		 * Pos: Devuelve el contenido del casillero
		 */
		TipoDeCasillero getContenido();
		/*
		/* Pre: Necesita un tipo de casilla
		 * Pos: Setea el tipo del casillero al tipo usado
		 */	
		void setTipoDeCasillero(TipoDeCasillero tipo);
		/*
		 * Pos: Setea las coordenadas al casillero si estas son válidas 
		 */
		void setCoordenadas ();
};
#endif
