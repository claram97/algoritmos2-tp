#ifndef FICHA_H
#define FICHA_H
#include "jugador.h"
#include <string>
#include <iostream>

typedef enum tipoDeFicha{
	AVION,
	BARCO,
	MINA,
	SOLDADO,
	SIN_DEFINIR
};

typedef enum tipoDeCarta{
	MISIL,
	RADAR,
	SUPER,
	BARCOS,
	AVIONES,
	MINAS
};


class Ficha{
	
private:

	int posicionX;
	int posicionY;
	int posicionZ;
	
	Jugador* jugador;
	char tipo;
		
		
public:
		
	/*
	 *  Post: Crea una ficha con el tipo sin definir y posiciones seteadas en -1 (deben cambiarse luego).
	 */
	Ficha();
	/*
	 *	Pre: Recibe un tipo de ficha, con valores válidos: SOLDADO, AVIÓN, BARCO, MINAS
	 *	Post: Se crea una ficha del tipo dado si el valor es válido, sino deja el tipo sin definir,
	 *		  las posiciones iniciales estarán seteadas en -1, deben actualizarse
	 */
	Ficha(char tipo, int x, int y, int z);
	/*
	 *  Pos: Devuelve la posicion X/fila
	 */
	int getPosicionX();	
	/*
	 *  Pos: Devuelve la posicion Y/columna
	 */
	int getPosicionY();
	/*
	 *  Pos: Devuelve la posicion Z/altura
	 */
	int getPosicionZ();
	/*
	 *  Pos: Devuelve el tipo de ficha
	 */
	char getTipo();	
	/*
	 *  Pre: Necesita las coordenadas de la fila y la columna
	 *  Pos: Si es soldado, cambia su posicion
	 */
	void setCoordenadasSoldado(int posicionX, int posicionY);
	/*
	 *  Pre: Necesita las coordenadas de la casilla
	 *  Pos: Devuelve true si la casilla es valida
	 */
	bool esPosicionValida(int x, int y, int z);
	/*
	 *  Pre: Necesita un tipo de ficha
	 *  Pos: Devuelve true si el tipo de ficha es valido
	 */
	bool esTipoValido(char tipo);
	/*
	 *  Pre: Necesita las coordenadas y un tipo de ficha
	 *  Pos:
	 */
	bool tipoConcuerdaConPosicion(int x, int y, int z, char tipo);
	/*
	 *  Pre: Necesita un tipo de ficha
	 *  Pos: Setea la ficha al tipo dado
	 */
	void definirTipo(char tipo);
};


#endif
