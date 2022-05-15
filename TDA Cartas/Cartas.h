#ifndef SRC_CARTAS_H_
#define SRC_CARTAS_H_
#include <string>

const char AVION = 'A';
const char BARCO = 'B';
const char MISIL = 'M';
#define MAX_CARTAS 5

class Cartas{


	private:

		char tipoDeCarta;
		std::string descripcion;
		unsigned int numeroDeCarta;


	public:

		Cartas();
		Cartas(char, unsigned int, std::string);
		Cartas(const Cartas &);

		~Cartas();

		char getTipoDeCarta();
		void setTipoDeCarta(char);

		std::string getDescripcion();
		void setDescripcion(std::string);

		unsigned int getNumeroDeCarta();
		void setNumeroDeCarta(unsigned int);

		void nuevaCarta(int);
		void removerCarta();


};



#endif
