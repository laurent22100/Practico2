#include "Ejemplos.h"

Ejemplos::Ejemplos( int numEntrada,vector<double> X ) {
	this->separador=numEntrada;
	AlmacenaDatos(X);
}

Ejemplos::~Ejemplos() {
	
}

void  Ejemplos::AlmacenaDatos(vector<double> X){
		
	int i ;
	for(i=0 ; i<X.size() ; i++){
		if( i<separador) this->EjEntrada.push_back(X[i]);
		else this->EjSalida.push_back(X[i]);
		
		
	}	
	
}
vector <double> Ejemplos::getEjEntrada(){
	
	return EjEntrada;
}
vector <double> Ejemplos::getEjSalida(){
	return EjSalida;
}
