#include "Casilla.h"

Casilla::Casilla(unsigned int largo, unsigned int ancho, unsigned int alto, TipoDeCasillero tipo){
  //Esto no va acÃ  creo pero lo dejo aca por si se necesita
    /*if(proporcionesValidasTablero(largo,ancho,alto)){
        this->contenido = VACIO;
        this->tipoDeCasilla = tipo;
        this->coordenadaX = largo;
        this->coordenadaY = ancho;
        this->coordenadaZ = alto;
    }
    */
    if(!proporcionesValidasTablero(largo,ancho,alto)){
        throw "Proporciones invalidas del tablero";
    }
    
}

bool Casilla::proporcionesValidasTablero(unsigned int largo, unsigned int ancho, unsigned int alto){
    return (largo >= 0 && largo < MAX_LARGO && ancho >= 0 && ancho < MAX_ANCHO && alto >= 0 && alto < MAX_ALTO);
}


Casilla::~Casilla(){
  
}
/*
	void Casilla::setContenido(EstadoDelCasillero contenido){
	    if(estadoCasilla == Vacio || estadoCasilla == Lleno || estadoCasilla == Inactivo){
	        this->estadoCasilla = contenido;
	    }
	    else{
	        throw "El contenido es invÃ¡lido, debe ser: VACIO, FULL, INACTIVO";
	    }
	}
*/
TipoDeCasillero Casilla::getContenido(){
    return this->tipoDeCasilla;
}


TipoDeCasillero Casilla::getTipoDeCasilla(){
    return this->tipoDeCasilla;
}

void Casilla::setCoordenadaX(unsigned int coordenadaX){
    if(coordenadaX > 0 && coordenadaX < MAX_LARGO){
        this->coordenadaX = coordenadaX;
    }
    else{
        throw "La coordenada X para la casilla no estÃ¡ dentro de un rango de valores vÃ¡lidos.";
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
    if(coordenadaZ > 0 && coordenadaZ < MAX_ALTO){
        this->coordenadaZ = coordenadaZ;
    }
    else{
        throw "La coordenada Z para la casilla no estÃ¡ dentro de un rango de valores vÃ¡lidos.";
    }
}
void Casilla::setTipo(TipoDeCasillero tipo){
	this->tipoDeCasilla = tipo;
}
unsigned int Casilla::getCoordenadaZ(){
    return this->coordenadaZ;
}
void Casilla::setEstado(EstadoDelCasillero estado){
	this->estadoCasilla = estado;
}
EstadoDelCasillero Casilla::getEstado(){
	return this->estadoCasilla;
}
