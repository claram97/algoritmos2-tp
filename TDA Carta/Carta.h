#ifndef SRC_CARTA_H_
#define SRC_CARTA_H_
#include <string>

const char AVION = 'A';
const char BARCO = 'B';
const char MISIL = 'M';
const char MINAS = 'm';
const char RADAR = 'R';
const char SUPER = 'S';
#define MAX_CARTAS 5

class Carta{


	private:

		char tipoDeCarta;
		std::string descripcion;
		unsigned int numeroDeCarta;


	public:

		Carta();
		Carta(char, unsigned int, std::string);
		Carta(const Carta &);

		~Carta();

		char getTipoDeCarta();
		void setTipoDeCarta(char);

		std::string getDescripcion();
		void setDescripcion(std::string);

		unsigned int getNumeroDeCarta();
		void setNumeroDeCarta(unsigned int);

		void removerCarta();


};



#endif
