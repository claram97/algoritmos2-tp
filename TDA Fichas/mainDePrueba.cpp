#include <iostream>
#include "Fichas.h"

using namespace std;

int main() {
	
	try{
		
	Fichas *ficha1 = new Fichas(0,0,4,'B');

	cout<<ficha1->getPosicionX()<<endl;
	cout<<ficha1->getPosicionY()<<endl;
	cout<<ficha1->getPosicionZ()<<endl;
	cout<<ficha1->verQueFichaEs()<<endl;

	
	delete ficha1;
	
	}catch(const char*x){
		cout<<"ERROR: "<<x<<endl;
	}

	return 0;
}
