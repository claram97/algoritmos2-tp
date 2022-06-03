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

Casilla::~Casilla(){
  
}

TipoDeCasillero Casilla::getContenido(){
    return this->tipoDeCasilla;
}


TipoDeCasillero Casilla::getTipoDeCasilla(){
    return this->tipoDeCasilla;
}

void Casilla::setCoordenadaX(unsigned int coordenadaX){
    if(coordenadaX > 0){
        this->coordenadaX = coordenadaX;
    }
    else{
        throw "La coordenada X para la casilla no está dentro de un rango de valores válidos.";
    }
}

unsigned int Casilla::getCoordenadaX(){
    return this->coordenadaX;
}

void Casilla::setCoordenadaY(unsigned int coordenadaY){
    if(coordenadaY > 0 && coordenadaY < MAX_ANCHO){
        this->coordenadaY = coordenadaY;
    }
    else{
        throw "La coordenada Y para la casilla no estÃ¡ dentro de un rango de valores vÃ¡lidos.";
    }
}

unsigned int Casilla::getCoordenadaY(){
    return this->coordenadaY;
}

void Casilla::setCoordenadaZ(unsigned int coordenadaZ){
    if(coordenadaZ > 0){
        this->coordenadaZ = coordenadaZ;
    }
    else{
        throw "La coordenada Z para la casilla no está dentro de un rango de valores válidos.";
    }
}
void Casilla::setTipo(TipoDeCasillero tipo){
	if(tipo == AVION || tipo == BARCO || tipo == SOLDADO || tipo == GENERAL){
		this->tipoDeCasilla = tipo;
	}
	else{
		throw "El tipo de casilla ingresado es inválida. Puede ser: AVION, BARCO, SOLDADO o de tipo uso GENERAL".
	}
	
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
