#include "Casilla.h"

/*Casilla::Casilla(unsigned int largo, unsigned int ancho, unsigned int alto, TipoDeCasillero tipo){
  //Esto no va acá  creo pero lo dejo aca por si se necesita
    /*if(proporcionesValidasTablero(largo,ancho,alto)){
        this->contenido = VACIO;
        this->tipoDeCasilla = tipo;
        this->coordenadaX = largo;
        this->coordenadaY = ancho;
        this->coordenadaZ = alto;
    }
    
    if(!proporcionesValidasTablero(largo,ancho,alto)){
        throw "Proporciones invalidas del tablero";
    }
    
}
bool Casilla::proporcionesValidasTablero(unsigned int largo, unsigned int ancho, unsigned int alto){
    return (largo >= 0 && largo < MAX_LARGO && ancho >= 0 && ancho < MAX_ANCHO && alto >= 0 && alto < MAX_ALTO);
}
*/

//Opcion 1: me parece la mejor porque reutilizas el código y yadayada
void setCoordenada(unsigned int &coordenadaAModificar, unsigned int coordenada){
		if(coordenada > 0){
			coordenadaAModificar = coordenada;
		}
		else{
			throw "Las coordenadas de un casillero no pueden ser negativas.";
		}
	}
//Opcion 2
void Casilla::setCoordenadas(){
	if(coordenadaX > 0 && coordenadaY > 0 && coordenadaZ > 0){
		this->coordenadaX = coordenadaX;
		this->coordenadaY = coordenadaY;
		this->coordenadaZ = coordenadaZ;
	}
	else{
		throw "Las coordenadas de un casillero no pueden ser negativas.";
	}
}	

void Casilla::setTipoDeCasillero(TipoDeCasillero tipo){
	if(tipo == AVION || tipo == BARCO || tipo == SOLDADO || tipo == GENERAL){
		this->tipoDeCasilla = tipo;
	}
	else{
		throw "El tipo de casilla ingresado es inválida. Puede ser: AVION, BARCO, SOLDADO o de tipo uso GENERAL.";
	}
	
}

//Voy a hacer la lógica del tipo en Batalla Campal y entonces se manda el tipo que va
Casilla::Casilla(unsigned int coordenadaX, unsigned int coordenadaY, unsigned int coordenadaZ, TipoDeCasillero tipo){
	//Opcion 1:
	setCoordenada(this->coordenadaX,coordenadaX);
	setCoordenada(this->coordenadaY,coordenadaY);
	setCoordenada(this->coordenadaZ,coordenadaZ);
	
	//Opcion 2:
	setCoordenadas(coordenadaX,coordenadaY,coordenadaZ);
		
	setTipoDeCasillero(tipo);
	estado = VACIO; //se crean vacias y luego se cambian
}


TipoDeCasillero Casilla::getContenido(){
    return this->tipoDeCasilla;
}


TipoDeCasillero Casilla::getTipoDeCasilla(){
    return this->tipoDeCasilla;
}

unsigned int Casilla::getCoordenadaX(){
    return this->coordenadaX;
}

unsigned int Casilla::getCoordenadaY(){
    return this->coordenadaY;
}


unsigned int Casilla::getCoordenadaZ(){
    return this->coordenadaZ;
}

void Casilla::setEstado(EstadoDelCasillero estadoCasilla){
    if(estadoCasilla == VACIO || estadoCasilla == LLENO || estadoCasilla == INACTIVO){
        this->estadoCasilla = estadoCasilla;
    }
    else{
        throw "El contenido es invalido, debe ser: VACIO, FULL, INACTIVO";
    }
}

EstadoDelCasillero Casilla::getEstado(){
	return this->estadoCasilla;
}
