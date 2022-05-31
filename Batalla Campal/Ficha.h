#ifndef FICHA_H
#define FICHA_H

//Tipos de fichas
#define AVION 'A'
#define BARCO 'B'
#define MINA 'N'
#define SOLDADO 'S'
#define SIN_DEFINIR '-'

typedef enum tipoDeCarta{MISIL,RADAR,SUPER,BARCOS,AVIONES,MINAS}


class Ficha{
	
private:

	int posicionX;
	int posicionY;
	int posicionZ;
	
	char tipo;
	char fichaValida;
		
		
public:
		
	/*
	 *  Pre:
	 *  Post: crea una ficha con el tipo sin definir y posiciones seteadas en -1 (deben cambiarse luego).
	 */
	Ficha();

	/*
		Pre: recibe un tipo de ficha, con valores válidos: SOLDADO, AVIÓN, BARCO, MINAS.
		Post: Se crea una ficha del tipo dado si el valor es válido, sino deja el tipo sin definir.
		Las posiciones iniciales estarán seteadas en -1, deben actualizarse.
	*/
	Ficha(char tipo);
		
		
	/*
	Pre: -
	Post: destruye la ficha
	*/
	virtual ~Ficha();
	
	/*
		Pre: - 
		Post: devuelve la posicion Y
	*/
	int getPosicionY();
	
	/*
		pre: - 
		pos: devuelve la posicion X
	*/
	int getPosicionX();
	
	/*
		pre: - 
		pos: devuelve la posicion Z
	*/
	int getPosicionZ();
		
	/*
		pre: - 
		pos: devuelve de qué tipo tendría que ser una ficha dadas sus coordenadas actuales.
	*/
	char validarFicha();
	
	/*
		pre: - 
		pos: devuelve el tipo de ficha
	*/
	char getTipo();
	
	/*
		pre: el tipo tiene que ser soldado, avion, barco o mina.
		post: setea el tipo de la ficha actual según el tipo recibido.
	*/
	void setTipo(char tipo);
	
	/*
	 *  pre:
	 *  pos:
	 */
	void setCoordenadas();
		
};

#endif
