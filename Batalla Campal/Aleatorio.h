/*
 * Aleatorio.h
 *
 *  Created on: 31/05/2022
 *      Author: algo2
 */

#ifndef SRC_ALEATORIO_H_
#define SRC_ALEATORIO_H_

//Hay que ver donde poner esto pero lo voy a usar para generar las coordenadas aleatorias
class Coordenadas{

	private:
		int coordenadaX;
		int coordenadaY;
		int coordenadaZ;

	public:

		Coordenadas();
		virtual ~Coordenadas();
		int getCoordenadaX();
		int getCoordenadaY();
		int getCoordenadaZ();
		void setCoordenadaX(int);
		void setCoordenadaY(int);
		void setCoordenadaZ(int);
}



#endif /* SRC_ALEATORIO_H_ */
