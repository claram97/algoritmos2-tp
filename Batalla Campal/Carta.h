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
		 * Pre:
		 * Pos:
		 */
		Carta();
		/*
		 * Pre:
		 * Pos:
		 */
		Carta(int aleatorio);

		/*
		 * Pre:
		 * Pos:
		 */
		char getTipoDeCarta();
		/*
		 * Pre:
		 * Pos:
		 */
		void setTipoDeCarta(char);
		/*
		 * Pre:
		 * Pos:
		 */
		std::string getDescripcion();
		/*
		 * Pre:
		 * Pos:
		 */
		void setDescripcion(std::string);
		/*
		 * Pre:
		 * Pos:
		 */
		~Carta();
		/*
		 * Pre:
		 * Pos:
		 */
		void removerCarta();


};



#endif
