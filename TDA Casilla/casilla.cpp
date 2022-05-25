
#include "casilla.h"

bool Casilla::isValidProportionsForBoard(unsigned int lenght, unsigned int wide, unsigned int height){
    return (lenght > 0 && lenght < MAX_LENGHT && wide > 0 && wide < MAX_WIDE && height > 0 && height < MAX_HEIGHT);
}

Casilla::Casilla(unsigned int amountOfTokens,unsigned int lenght; unsigned int wide, unsigned int height){
    //Acá hay que chequear lenght/wide/height para ver el tipo, no sé si se recibe por parámetro o se
    //saca de otro lado.
    if(isValidProportionsForBoard(lenght,wide,height) && amountOfTokens > 0){
        this->content = VACIO;
        this->type;
        this->lenght = lenght;
        this->wide = wide;
        this->height = height;
        this->tokens = new *tokens[amountOfTokens];
        for(int i = 0; i < amountOfTokens; i++){
            tokens[i] = NULL;
        }
        this->amountOfTokens = amountOfTokens;
    }
    
    if(amountOfTokens <= 0){
        throw "Invalidad amount of tokens.";
    }

    if(!isValidProportionsForBoard(lenght,wide,height)){
        throw "Invalid proportions for board.";
    }
    
}
Casilla::~Casilla(){
    if(tokens){
        for(int i = 0; i < this->amountOfTokens; i++){
            delete tokens[i];
        }
        delete []tokens;
    }
    
}

unsigned int Casilla::getAmountOfTokens(){
    return this->amountOfTokens;
}

void Casilla::setAmountOfTokens(unsigned int amountOfTokens){
    if(amountOfTokens > 0){
        this->amountOfTokens = amountOfTokens;
    }
    else{
        throw "Invalid amount of tokens.";
    }
}

void Casilla::setContent(char content){
    if(content == EMPTY || content == FULL || content == INACTIVE){
        this->content = content;
    }
    else{
        throw "The content you tried to set is invalid.";
    }
}

char Casilla::getContent(){
    return this->content;
}

void Casilla::setType(char type){
    if(type == EARTH || type == AIR || type == SEA){
        this->type = type;
    }
    else{
        throw "Invalid type.";
    }
}

char Casilla::getType(){
    return this->type;
}

void Casilla::setLenght(unsigned int lenght){
    if(lenght > 0 && lenght < MAX_LENGHT){
        this->lenght = lenght;
    }
    else{
        throw "Invalid lenght."
    }
}

unsigned int Casilla::getLenght(){
    return this->lenght;
}

void Casilla::setWide(unsigned int lenght){
    if(wide > 0 && wide < MAX_LENGHT){
        this->wide = wide;
    }
    else{
        throw "Invalid wide."
    }
}

unsigned int Casilla::getWide(){
    return this->wide;
}

void Casilla::setHeight(unsigned int lenght){
    if(height > 0 && height < MAX_LENGHT){
        this->height = height;
    }
    else{
        throw "Invalid height."
    }
}

unsigned int Casilla::getHeight(){
    return this->height;
}