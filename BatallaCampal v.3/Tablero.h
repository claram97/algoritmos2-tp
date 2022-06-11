#ifndef TABLERO_H
#define TABLERO_H
#include "Casilla.h"
#include "Lista.h"

class Tablero{
	private:
		int maxFila;
		int maxColumna;
		int maxAltura;
			
		Lista<Lista<Lista<Casilla*>*>*>* casilleros;
	
	public:
		/*
		 * Pre: los valores deben ser mayores o iguales a 1
		 * Pos: crea un tablero de casilleros con las dimensiones dadas
		 */
		Tablero(int fila, int columna, int altura);
		/*
		 * Pre:
		 * Pos: muestra el tablero por pantalla
		 */
		void mostrarTablero();
		/*
		 * Pre:los valores deben ser mayores o iguales a 1
		 * Pos: devuelve una casilla
		 */
		Casilla* getCasilla(int fila, int columna, int altura);
		 /*
		 * Pre: los valores deben ser mayores o iguales a 1
		 * Pos: Devuelve true si los valores estan dentro de las dimensiones del tablero, sino false.
		 */
		bool esRangoValido(int fila,int columna,int altura);
		/*
		 * Pre: Tablero previamente creado
		 * pos: Destruye el tablero
		*/
		virtual ~Tablero();

};
#endif
