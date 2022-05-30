#ifndef FICHA_H
#define FICHA_H

#define AVION 'A'
#define BARCO 'B'
#define MINA 'N'
#define MISIL 'M'
#define RADAR 'R'
#define SUPER 'K'
#define SOLDADO 'S'
#define SIN_DEFINIR '-'

class Ficha
{
	private:

		int posicionX;
		int posicionY;
		int posicionZ;
		
		char tipo;
		char fichaValida;
		
		
	public:
		
		/*
		 *  Pre:
		 *  Pos:
		 */
		Ficha();

		/*
			Pre: Ingresa las posiciones donde quiere colocar la ficha, mientras esta sea una ficha valida (S,B,A,M)
			Pos: Se coloca la ficha
		*/
		Ficha(char tipo);
		
		
		/*
			Pre: -
			Pos: destruye la ficha
		*/
		virtual ~Ficha();
		
		/*
			pre: - 
			pos: devuelve la posicion Y
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
