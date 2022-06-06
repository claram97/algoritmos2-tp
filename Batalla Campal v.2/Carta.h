#ifndef SRC_CARTA_H_
#define SRC_CARTA_H_
#include <string>
#include "Ficha.h"

class Carta{


	private:

		char tipoDeCarta;
		std::string descripcion;


	public:

		/*
		 * Pre: Necesita un numero para el tipo de carta
		 * Post: Crea un tipo de carta
		 */
		Carta(int aleatorio);
		/*
		 * Post: Devuelve el tipo de carta
		 */
		char getTipoDeCarta();
		/*
		 * Post: Devuelve la descripcion de la carta
		 */
		std::string getDescripcion();
		/*
		 * Post: Destruye instancia de carta
		 */
		~Carta();


};



#endif
