#ifndef SRC_CARTA_H_
#define SRC_CARTA_H_
#include <string>
#include "Ficha.h"

class Carta{


	private:

		char tipoDeCarta;
		std::string descripcion;
		unsigned int numeroDeCarta;


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
		Carta(char, unsigned int, std::string);
		/*
		 * Pre:
		 * Pos:
		 */
		Carta(const Carta &);
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
		unsigned int getNumeroDeCarta();
		/*
		 * Pre:
		 * Pos:
		 */
		void setNumeroDeCarta(unsigned int);
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
