#include "Red.h"
#include <iomanip>
#include <iostream>

Red::Red(int numEntrada ,int numOculta, int numSalida,double e) {
	int i,j;	
	this->numEntrada=numEntrada;
	this->numOculta=numOculta;
	this->numSalida=numSalida;
	this->e=e;
	
	LeeArchivo = new Lectura(0,numEntrada);
	Prueba=new Lectura(1,numEntrada);
	for(i=0;i<numEntrada ; i++){		
		capaEntrada.push_back(new Neurona(i,0,numOculta));
		
	}
	
	for(i=0;i<numOculta ; i++){		
		capaOculta.push_back(new Neurona(i,1,numSalida));	
		
	}

	for(i=0;i<numSalida ; i++){		
		capaSalida.push_back(new Neurona(i,2,0));	
		
	}	
}


Red::~Red() {
	int i,j;
	for (i = 0; i < numEntrada; i++) {
		free(Wji[i]);
	}
	free(Wji);
	for (j = 0; j < numOculta; j++) {
		free(Wkj[j]);
	}
	free(Wkj);
}



void Red ::matrizW(){
	int i;
	int j;	

	
//	Wji = new double*[numEntrada + 1] ;
//	for(int i = 0; i <= numEntrada; i++)
//		Wji[i] = new double[numOculta];
//		
//	Wkj = new double*[numOculta + 1] ;
//	for(int i = 0; i <= numOculta; i++)
//		Wkj[i] = new double[numSalida];
//			
	// -------Matriz Wji-----
	for (i=0 ; i <numOculta ; i++){			
		Wji[i][0]=capaOculta[i]->getUmbral();
	}

	for(i=0 ; i<numOculta ; i++){
		for (j=0 ; j <numEntrada ; j++){			
			Wji[i][j+1]=capaEntrada[j]->getPesos(i);
		}
	}		
				
	// -------Matriz Wkj-----
	
	for (i=0 ; i <numSalida ; i++){			
		Wkj[i][0]=capaSalida[i]->getUmbral();
	}
	for(i=0 ; i<numSalida ; i++){
		for (j=0 ; j <numOculta ; j++){			
			Wkj[i][j+1]=capaOculta[j]->getPesos(i);
		}
	}
	

	
		
	
}

void Red::SalidaOculta(int Neurona_Oculta){
	
	int i;
	double Salida;
	Salida=0;
	for(i=0;i<numEntrada;i++){
		
		Salida +=(Wji[Neurona_Oculta][i+1]*X[i]);
		
	}	
		
	Salida-=Wji[Neurona_Oculta][0];

	Y.push_back(capaOculta[Neurona_Oculta]->funcionActivacion(Salida));
	
}


void Red::salidaReal(int Neurona_Salida){
	int i;
	double h;
	h=0;
	for(i=0;i<numOculta;i++){ // cambiar NEURONAS_CAPA_OCULTA---------------------
		
		h +=(Wkj[Neurona_Salida][i+1]*Y[i]);
		
	}	
	h-=Wkj[Neurona_Salida][0];
	
	Z.push_back(capaSalida[Neurona_Salida]->funcionSalida(h));
	
	
	
}
//-----------------------------------------------------

void Red::renuevaCapaSalida(int Neurona_Salida){
	
	int i;
	double h=0;
	double dWkj=0;
	
	for(i=0;i<numOculta;i++){ // cambiar NEURONAS_CAPA_OCULTA---------------------
		
		h +=(Wkj[Neurona_Salida][i+1]*Y[i]);
		
	}	
	h-=Wkj[Neurona_Salida][0];
	
	delta0.push_back(((T[Neurona_Salida])-(capaSalida[Neurona_Salida]->funcionSalida(h)))*(capaSalida[Neurona_Salida]->derivadaSalida(h)));
//	cout<<"Delta 0"<<delta0[Neurona_Salida];
//	cout<<endl;
			
	for(i=0;i<numOculta;i++){
				//dWkj=e*delta0[Neurona_Salida]*Y[i]+dWkj[Neurona_Salida]
		if(i==0){
			dWkj=e*delta0[Neurona_Salida]*(-1);
			Wkj[Neurona_Salida][i]=Wkj[Neurona_Salida][i]+dWkj;
		}		
		dWkj=e*delta0[Neurona_Salida]*Y[i];
		Wkj[Neurona_Salida][i+1]=Wkj[Neurona_Salida][i+1]+dWkj;
				
					
	}	
	
			
}

//---------------------------------------------------------

void Red::renuevaCapaOculta(int Neurona_Oculta){
	
	int i, j;
	double h=0;
	double dWji=0;
	double Suma=0;
	double delta1=0;
	for(i=0;i<numEntrada;i++){ // cambiar NEURONAS_CAPA_Entrada---------------------
		
		h +=(Wji[Neurona_Oculta][i+1]*X[i]);
		
	}	
	h-=Wji[Neurona_Oculta][0];
	
	for(i=0 ; i<delta0.size() ; i++){
	
		Suma+=delta0[i]*(capaOculta[Neurona_Oculta]->getPesos(i));
		
	}


	delta1=Suma*(capaOculta[Neurona_Oculta]->derivadaActivacion(h));
//	cout<<delta1;
//	cout<<endl;		
	
	for(i=0;i<numEntrada;i++){
				
		if(i==0){
			dWji=e*delta1*(-1);
			Wji[Neurona_Oculta][i]=Wji[Neurona_Oculta][i]+dWji;
		}
		
		dWji=e*delta1*X[i];		
		Wji[Neurona_Oculta][i+1]=Wji[Neurona_Oculta][i+1]+dWji;
		
		
				
	}	
	
}






void Red::lecturaArchivo(){
	int i;
	i=0;
	LeeArchivo->contadorEjemplos();
	LeeArchivo->abrirArchivo();
	if(LeeArchivo->errorLectura() ==false){	
				
		while(i<(LeeArchivo->getCantidadEjemplos())){
			LeeArchivo->leerEjemplos();	
			i++;
		}
	}
	LeeArchivo->calcularValorMaximo();
	LeeArchivo->calcularValorMinimo();
}


void Red::lecturaDatos(int i){
	
	Xi=LeeArchivo->getEntradas()[i]->getEjEntrada();
//	cout << X[1];
//	cout << endl;
	Ti=LeeArchivo->getEntradas()[i]->getEjSalida();
//	cout << T[0];
//	cout << endl;	
}





void Red::actualizaNeurona(){
	int i,j ;
	// -------Matriz Wji-----
	for (i=0 ; i <numOculta ; i++){	
		capaOculta[i]->setUmbral(Wji[i][0]);
	}
	for(i=0 ; i<numOculta ; i++){
		for (j=0 ; j <numEntrada ; j++){
			capaEntrada[j]->setPesos(i,Wji[i][j+1]);
			
		}
	}
	
	// -------Matriz Wkj-----
	
	for (i=0 ; i <numSalida ; i++){		
		capaSalida[i]->setUmbral(Wkj[i][0]);
		
	}
	for(i=0 ; i<numSalida ; i++){
		for (j=0 ; j <numOculta ; j++){	
			capaOculta[j]->setPesos(i,Wkj[i][j+1]);

		}
	}
	
	
	
	
}






void Red::limpiaVectores(){
	X.clear();
	Y.clear();
	Z.clear();
	T.clear();
	Xi.clear();
	Zi.clear();
	Ti.clear();
	delta0.clear();
}




void Red::normalizar(){	
	int i;
	
//	for(i=0 ; i<Xi.size() ; i++){
//		X.push_back(((MaximoObjetivo)-(MinimoObjetivo))*((Xi[i]-(LeeArchivo->getValorMinimoEntrada()))/((LeeArchivo->getValorMaximoEntrada())-(LeeArchivo->getValorMinimoEntrada())))+(MinimoObjetivo));
//	}
//	for(i=0 ; i<Ti.size() ; i++){
//		T.push_back(((MaximoObjetivo)-(MinimoObjetivo))*((Ti[i]-(LeeArchivo->getValorMinimoSalida()))/((LeeArchivo->getValorMaximoSalida())-(LeeArchivo->getValorMinimoSalida())))+(MinimoObjetivo));
//	}
	if((LeeArchivo->getValorMaximoEntrada())>((LeeArchivo->getValorMinimoEntrada())*(-1))){
		 normalX= LeeArchivo->getValorMaximoEntrada();
	}
	else normalX= LeeArchivo->getValorMinimoEntrada()*(-1);
	   
	if((LeeArchivo->getValorMaximoSalida())>((LeeArchivo->getValorMinimoSalida())*(-1))){
		normalT= LeeArchivo->getValorMaximoSalida();
	}
	else normalT= LeeArchivo->getValorMinimoSalida()*(-1);  
	
	
	
	if(normalT>normalX)normal=normalT;
	else normal=normalX;
//	cout<< normalX;
//	cout<<endl;
//	cout<< normalT;
//	cout<<endl;
	
	for(i=0 ; i<Xi.size() ; i++){
		X.push_back((Xi[i])/(normalX));
	}
	for(i=0 ; i<Ti.size() ; i++){
		T.push_back((Ti[i])/(normalT));
	}
	
}

void Red :: Dnormalizar(){
	int i;
//	for(i=0 ; i<Z.size() ; i++){
//		Zi.push_back((((Z[i]-MinimoObjetivo)/(MaximoObjetivo-MinimoObjetivo))*((LeeArchivo->getValorMaximoSalida())-(LeeArchivo->getValorMinimoSalida())))+(LeeArchivo->getValorMinimoSalida()));
//					 
//	}
	
	for(i=0 ; i<Z.size() ; i++){
		Zi.push_back((Z[i])*(normalT));
	}
	
}
void Red::entrenamiento(){
	
	int i,j,m;	
	matrizW();	
	lecturaArchivo();
        double s;
        m=0;
            
        while(m<(LeeArchivo->getCantidadEjemplos())){			
                lecturaDatos(m)		;
                normalizar();
                for(i=0 ; i<numOculta ; i++){
                        SalidaOculta(i);
                }		
                for(i=0 ; i<numSalida ; i++){
                        renuevaCapaSalida(i);                            
                }	
                for(i=0 ; i<numOculta ; i++){
                        renuevaCapaOculta(i);
                }	

                actualizaNeurona();		
                limpiaVectores();	

                m++;
        }

	
	
}

void Red::inicializar(){
	int i,j,m;
	Prueba->contadorEjemplos();
	Prueba->abrirArchivo();
	m=0;	
	
	while(m<(Prueba->getCantidadEjemplos())){
		
		Prueba->leerPrueba();
		Xi=Prueba->getPruebas();
		cout << endl;
		for(i=0 ; i<Prueba->getPruebas().size() ; i++){
			cout << " Xi =" << Prueba->getPruebas()[i];
		}
		cout << endl;
		cout << endl;
		normalizar();
		
		for(i=0 ; i<numOculta ; i++){
			SalidaOculta(i);
		}
		for(i=0 ; i<numSalida ; i++){
					salidaReal(i);
		}		
		for(i=0 ; i<numSalida ; i++){
			cout << " Z Normalizado=" << Z[i];
		}
		Dnormalizar();		
		for(i=0 ; i<numSalida ; i++){
			cout << " Z  =" << Zi[i];
		}
		cout << endl;
		limpiaVectores();
		m++;
	}

	
}







////	for(i=0 ; i<numOculta ; i++){
////		for(j=0 ; j<numEntrada+1 ; j++){
////			cout<<" "<<Wji[i][j];
////		}
////		cout << endl;
////	}
////	for(i=0 ; i<numSalida ; i++){
////		for(j=0 ; j<numOculta+1 ; j++){
////			cout<<" "<<Wkj[i][j];
////		}
////		cout << endl;
////	}
//	
//	
//	double x1;
//	double x2;
//	double x3;
//	double x4;
//
//	double x5;
//	
//	m=1;
//	while(m==1){
//		cout<<"ingresar entradas 1"<<endl;
//		cin>>x1;
//		cout<<"ingresar entradas 2"<<endl;
//		cin>>x2;
////		cout<<"ingresar entradas 1"<<endl;
////		cin>>x3;
////		cout<<"ingresar entradas 2"<<endl;
////		cin>>x4;
////		cout<<"ingresar entradas 1"<<endl;
////		cin>>x5;
//		
//		Xi.push_back(x1);	
//		Xi.push_back(x2);
////		X.push_back(x3);
////		X.push_back(x4);
////		X.push_back(x5);
//		
//		limpiaVectores();	
//		cout<<"continuar si=1 no=0"<<endl;
//		cin>>m;
