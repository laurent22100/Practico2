#include "Neurona.h"

Neurona::Neurona(int i , int tipo, int numPesos) {
	
	switch(tipo){
		case 0:
			for(i=0;i<numPesos;i++){
				pesos.push_back(((double) (rand() % 1000000)) / 1000000);
				
			}		
		break;		
		case 1:
			umbral=(((double) (rand() % 1000000)) / 1000000);
			for(i=0;i<numPesos;i++){
				pesos.push_back(((double) (rand() % 1000000)) / 1000000);
			}				
		break;
		case 2:
			
			umbral=(((double) (rand() % 1000000)) / 1000000);				
		break;
			
	}
}

Neurona::~Neurona() {
	
}

double Neurona::getPesos(int x){	
	return pesos[x];
}

double Neurona ::getUmbral(){
	return umbral;
}

void Neurona::setPesos(int x ,double nuevo){
	
	pesos[x]=nuevo;
	
}
void Neurona::setUmbral(double nuevo){
	this->umbral=nuevo;
	
}

double Neurona :: funcionActivacion(double x){
	return 1 / (1 + pow(M_E, -x));
}

double Neurona :: funcionSalida(double x){
	return x;
}

double Neurona::derivadaActivacion(double x){
	
	return pow(M_E, -x) / ((1 + pow(M_E, -x))*(1 + pow(M_E, -x)));
	
}
double Neurona::derivadaSalida(double x){
	
	return 1;
	
}
