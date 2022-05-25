/*Casillas: 						Clara
	Coordenada
	Contenido (Vacío, Lleno, Inactivo)
	Tipo (Tierra, Mar, Aire)
*/

#ifndef _CASILLA_
#define _CASILLA_

#ifndef NULL
#define NULL 0
#endif

#define MAX_LENGHT 100
#define MAX_WIDE 100
#define MAX_HEIGHT 100

//content
#define EMPTY ' '
#define FULL '*'
#define INACTIVE 'X'
//type
#define EARTH 'T'
#define AIR 'A'
#define SEA 'S'

class Casilla{

private:
	char content;
    char type;
    unsigned int lenght;
    unsigned int wide;
    unsigned int height;
    Token** tokens;
    unsigned int amountOfTokens;

public:
    //Pre: recibe las coordenadas del tablero.
    //Post: devuelve true si las proporciones del tablero son válidas.
    //(Me parece que esto es más para tablero pero bueno ya lo tenía hecho así que si querés y si te sirve adaptalo)
    //(Y sino cambiame las cosas que creas necesarias)
    bool isValidProportionsForBoard(unsigned int lenght, unsigned int wide, unsigned int height);

    //Pre: recibe las coordenadas del tablero y una cantidad de tokens (fichas).
    //Post: crea una casilla.
    Casilla(unsigned int amountOfTokens, unsigned int lenght, unsigned int wide, unsigned int height);
    
    //Pre: que la casilla exista.
    //Post:
    ~Casilla();

    //Pre:
    //Post: devuelve la cantidad de fichas de una casilla dada.
    unsigned int getAmountOfTokens();

    //Pre: recibe una cantidad de tokens mayor a 0.
    //Post: inicializa la cantidad de tokens.
    void setAmountOfTokens(unsigned int amountOfTokens);

    //Pre: recibe un contenido para la casilla (empty, full o inactiva).
    //Post: inicializa el contenido de la casilla según su tipo.
    void setContent(char content);

    //Pre:
    //Post: devuelve el contenido de la casilla.
    char getContent();

    //Pre: recibe un tipo para la casilla (mar, tierra o aire).
    //Post: inicializa el tipo de la casilla según su tipo.
    void setType(char type);

    //Pre:
    //Post: devuelve el tipo de la casilla.
    char getType();

    //Pre: recibe el largo (coordenada X), que debe estar entre 0 y 100.
    //Post: inicializa lenght de la casilla.
    void setLenght(unsigned int lenght);

    //Pre:
    //Post: devuelve lenght de una casilla dada.
    unsigned int getLenght();

    //Pre: recibe el ancho (coordenada Y), que debe estar entre 0 y 100.
    //Post: inicializa wide de la casilla.
    void setWide(unsigned int lenght);

    //Pre:
    //Post: devuelve wide de una casilla dada.
    unsigned int getWide();

    //Pre: recibe el alto (coordenada Z), que debe estar entre 0 y 100.
    //Post: inicializa height de la casilla.
    void setHeight(unsigned int lenght);

    //Pre:
    //Post: devuelve height de una casilla dada.
    unsigned int getHeight();
}

#endif