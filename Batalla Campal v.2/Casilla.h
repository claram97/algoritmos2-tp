#ifndef _CASILLA_H
#define _CASILLA_H

enum EstadoDelCasillero{
	VACIO,
	INACTIVO,
	LLENO
};

enum TipoDeCasillero{
	AIRE,
	TIERRA,
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
		/*
		 * Pre: Recibe las coordenadas del tablero y una cantidad de tokens (fichas)
		 * Post: Crea una instancia de casilla
		 */
		Casilla(unsigned int coordenadaX, unsigned int coordenadaY, unsigned int coordenadaZ, TipoDeCasillero tipo);
		/*
		 *Pre: recibe una coordenada que se quiere inicializar y el valor al cual se lo quiere inicializar.
		 *Post: inicializa la coordenada.
		 */
		void setCoordenada(unsigned int &coordenadaAModificar, unsigned int coordenada);
		/*
		 * Pre: Recibe un tipo para la casilla (mar, tierra o aire)
		 * Post: Inicializa el tipo de la casilla segÃºn su tipo
		 */
		void setTipoDeCasillero(TipoDeCasillero tipoDeCasilla);
		/*
		 * Post: Devuelve el tipo de casilla
		 */
		TipoDeCasillero getTipoDeCasilla();
		/*
		 * Post: Devuelve la coordenada X/fila de la casilla
		 */
		unsigned int getCoordenadaX();
		/*
		 * Post: Devuelve la coordenada Y/columna de la casilla
		 */
		unsigned int getCoordenadaY();
		/*
		 * Post: Devuelve la coordenada Z/altura de la casilla
		 */
		unsigned int getCoordenadaZ();
		/*
		 * Post: Devuelve el estado del casillero
		 */
		EstadoDelCasillero getEstado();
		/*
		 * Pre: Necesita un tipo de estado
		 * Post: Setea el estado del casillero al tipo usado
		 */
		void setEstado(EstadoDelCasillero estado);
		/*
		 * Post: Setea las coordenadas al casillero si estas son válidas
		 */
		void setCoordenadas ();

};
#endif
