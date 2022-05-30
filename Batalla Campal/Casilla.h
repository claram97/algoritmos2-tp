#ifndef _CASILLA_
#define _CASILLA_

#ifndef NULL
#define NULL 0


#define MAX_LARGO 100
#define MAX_ANCHO 100
#define MAX_ALTO 100

//content
#define VACIO ' '
#define FULL '*'
#define INACTIVO 'X'
//type
#define TIERRA 'T'
#define AIRE 'A'
#define AGUA 'H'

class Casilla{

	private:

		char contenido;
		char tipoDeCasilla;
		unsigned int coordenadaX;
		unsigned int coordenadaY;
		unsigned int coordenadaZ;

	public:

		//Pre: recibe las coordenadas del tablero y una cantidad de tokens (fichas).
		//Post: crea una casilla.
		Casilla(unsigned int coordenadaX, unsigned int coordenadaY, unsigned int coordenadaZ, char tipo);

		//Pre: recibe las coordenadas del tablero.
		//Post: devuelve true si las proporciones del tablero son válidas.
		//(Me parece que esto es más para tablero pero bueno ya lo tenía hecho así que si querés y si te sirve adaptalo)
		//(Y sino cambiame las cosas que creas necesarias)
		bool proporcionesValidasTablero(unsigned int largo, unsigned int ancho, unsigned int alto);


		//Pre: -
		//Post: elimina la casilla existente.
		virtual ~Casilla();


		//Pre: recibe un contenido para la casilla (vacío, full o inactiva).
		//Post: inicializa el contenido de la casilla según su tipo.
		void setContenido(char contenido);

		//Pre:
		//Post: devuelve el contenido de la casilla.
		char getContenido();

		//Pre: recibe un tipo para la casilla (mar, tierra o aire).
		//Post: inicializa el tipo de la casilla según su tipo.
		void setTipoDeCasilla(char tipoDeCasilla);

		//Pre:
		//Post: devuelve el tipo de la casilla.
		char getTipoDeCasilla();

		//Pre: recibe el largo (coordenada X), que debe estar entre 0 y 100.
		//Post: inicializa lenght de la casilla.
		void setCoordenadaX(unsigned int coordenadaX);

		//Pre:
		//Post: devuelve lenght de una casilla dada.
		unsigned int getCoordenadaX();

		//Pre: recibe el ancho (coordenada Y), que debe estar entre 0 y 100.
		//Post: inicializa wide de la casilla.
		void setCoordenadaY(unsigned int coordenadaY);

		//Pre:
		//Post: devuelve wide de una casilla dada.
		unsigned int getCoordenadaY();

		//Pre: recibe el alto (coordenada Z), que debe estar entre 0 y 100.
		//Post: inicializa height de la casilla.
		void setCoordenadaZ(unsigned int coordenadaZ);

		//Pre:
		//Post: devuelve height de una casilla dada.
		unsigned int getCoordenadaZ();
};

#endif
#endif
