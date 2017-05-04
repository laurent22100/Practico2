#ifndef RED_H
#define RED_H
#include<iostream>
#include <iomanip> 
#include "Neurona.h"
#include "Lectura.h"
#include <cstdlib>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"

using namespace std;

class Red {
	
	private:
		vector <Neurona*> capaEntrada;
		vector <Neurona*> capaOculta;
		vector <Neurona*> capaSalida;
		Lectura* LeeArchivo;
		Lectura* Prueba;
		vector <double> X;
		vector <double> Y;
		vector <double> Z;
		vector <double> T;
		vector <double> Zi;
		vector <double> Xi;		
		vector <double> Ti;//no normalizados
		double normalX ;// valor para normalizar
		double normalT ;// valor para normalizar
		double normal;
		vector <double> delta0;
		double MaximoObjetivo =1;
		double MinimoObjetivo = 0;
//		
//		double ** Wkj;
//		double ** Wji;
		double  Wji[100][100];
		double  Wkj[100][100];
		int numEntrada;
		int numOculta;
		int numSalida;
		double e;
		
		
	public:
		
		Red(int numEntrada ,int numOculta, int numSalida,double e);
		~Red();
		
		void matrizW();
		void lecturaArchivo();
		void lecturaDatos(int i);
		void entrenamiento();
		void inicializar();
		void renuevaCapaOculta(int Neurona_Oculta);
		void renuevaCapaSalida(int Neurona_Salida);
		void SalidaOculta(int Neurona_Oculta);
		void salidaReal(int Neurona_Salida);
		void actualizaNeurona();
		void limpiaVectores();
		void normalizar();
		void Dnormalizar();
		
		
};

#endif

