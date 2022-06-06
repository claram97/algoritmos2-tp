/*
 * Aleatorio.h
 *
 *  Created on: 31/05/2022
 *      Author: algo2
 */

#ifndef SRC_ALEATORIO_H_
#define SRC_ALEATORIO_H_
#include <iostream>
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


/*
	Comentario de lucas C
	--- > yo lo pensaria mas por la opcion que voy a poner debajo, habria que ponerlo en el ultimo for de la matriz cubica nomas
*/
	
void random(){
    const int dimension = 10;
    int tablero[dimension][dimension]; 
    
    
    for (int p=0;p<10;p++)
        {std::cout<<"["<<p<<"]";}
    std::cout<<std::endl;
    
    for (int i=0;i<dimension;i++){
        std::cout<<"["<<i<<"] ";
        
		for(int j=0;j<dimension;j++){
           
            if(tablero[i][j] % 2 ==0){  // aca se puede poner tambien que tablero[i][j][k] == PISO y va a hacer los cambios solo en el piso
                tablero[i][j] = rand()%5; //va a poner numeros random por todo el lugar de 1 a 5, 5 seria reemplazado por numero de jugadores +1 
            }
            else{
                tablero[i][j]= 9 ; // el 9 es una posicion vacia, osea donde no hay ningun jugador
            }
            std::cout<<tablero[i][j]<<"  "; 
            }
        std::cout<<"\n"; 
        }

}
};
#endif /* SRC_ALEATORIO_H_ */
