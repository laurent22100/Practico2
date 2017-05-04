#include "Lectura.h"

Lectura::Lectura(int tipo,int numEntrada) {	
	this->tipo=tipo;
	if(tipo ==0)Data.open("1.txt");
	if (tipo ==1 ) Data.open("2.txt");
	
	num=numEntrada;
		

}

Lectura::~Lectura() {
	
}
bool Lectura::errorLectura(){
	if(Data.fail()){
		cerr << "Error al abrir el archivo " << endl; 
		this->ErrorLec=true;
		return this->ErrorLec;
	} 
	else{
		this->ErrorLec=false;
		return this->ErrorLec;      
	}
}
void Lectura::contadorEjemplos(){
	while(!Data.eof()){
		Data.getline(buffer,sizeof(buffer)); 
		CantidadEjemplos++;
	}
	Data.close();
}
void Lectura::abrirArchivo(){
	if(tipo==0) Data.open("1.txt");
	if(tipo == 1) Data.open("2.txt");
	
}
void Lectura::leerEjemplos(){
	
	int i ;
	X.clear();	
	Data.getline(buffer,sizeof(buffer));
	istringstream isstream (buffer);
	string palabra;	
	while(getline(isstream, palabra,',')){ //getline separa la linea
		E.push_back(palabra); //coloco en el ultimo elemeto vector
	
	}
	n=E.size();  // obtengo tam�o vector
	for(i=0 ; i<n ; i++){
		X.push_back(atof(E[i].c_str()));
	}	
	
	Ej.push_back(new Ejemplos(num,X));
	E.clear();
	
}

void Lectura::calcularValorMaximo(){
	int i , j ;
	double valorE,valorS;
	valorE = Ej[0]->getEjEntrada()[0];
	valorS = Ej[0]->getEjSalida()[0];
	for(i=0 ; i<Ej.size(); i++){
		for(j=0 ; j<Ej[i]->getEjEntrada().size() ; j++){
			if(valorE<Ej[i]->getEjEntrada()[j]) valorE=Ej[i]->getEjEntrada()[j];
		}	
		for(j=0 ; j<Ej[i]->getEjSalida().size() ; j++){
			
			if(valorS<Ej[i]->getEjSalida()[j]) valorS=Ej[i]->getEjSalida()[j];
		}		
		
	}
	this->valorMaximoEntrada=valorE;
	this->valorMaximoSalida=valorS;	

}
void Lectura::calcularValorMinimo(){
	int i , j ;
	double valorE,valorS;
	valorE = Ej[0]->getEjEntrada()[0];
	valorS = Ej[0]->getEjSalida()[0];	
	for(i=0 ; i<Ej.size() ; i++){
		for(j=0 ; j<Ej[i]->getEjEntrada().size() ; j++){
			
			if(valorE>Ej[i]->getEjEntrada()[j]) valorE=Ej[i]->getEjEntrada()[j];
		}	
		for(j=0 ; j<Ej[i]->getEjSalida().size() ; j++){
			
			if(valorS>Ej[i]->getEjSalida()[j]) valorS=Ej[i]->getEjSalida()[j];
		}		
		
	}
	this->valorMinimoEntrada=valorE;
	this->valorMinimoSalida=valorS;	
	
}


void Lectura::leerPrueba(){
	int i ;
	X.clear();
	Data.getline(buffer,sizeof(buffer));
	istringstream isstream (buffer);
	string palabra;	
	while(getline(isstream, palabra,',')){ //getline separa la linea
		E.push_back(palabra); //coloco en el ultimo elemeto vector
		
	}
	n=E.size();  // obtengo tam�o vector
		
	for(i=0 ; i<n ; i++){
		X.push_back(atof(E[i].c_str()));
	}	
E.clear();

}

vector <double> Lectura::getPruebas(){
	return X;
}




double Lectura::getValorMaximoEntrada(){
	
	return valorMaximoEntrada;
}

double Lectura::getValorMinimoEntrada(){
	
	return valorMinimoEntrada;
}
double Lectura::getValorMaximoSalida(){
	
	return valorMaximoSalida;
}
double Lectura::getValorMinimoSalida(){
	
	return valorMinimoSalida;
}



int Lectura::getCantidadEjemplos(){
	return CantidadEjemplos;
}

vector <Ejemplos*> Lectura::getEntradas(){
	return Ej;
}
