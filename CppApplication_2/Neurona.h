#ifndef NEURONA_H
#define NEURONA_H
#include <vector>
#include<iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"

using namespace std;

class Neurona {
	
	private:
		vector <double> pesos;
		double umbral;
	
	public:
		Neurona(int i , int tipo, int numPesos);
		~Neurona();			
		double getPesos(int x);
		double getUmbral();
		void setUmbral(double nuevo);
		void setPesos(int x ,double nuevo);
		
		double funcionActivacion(double x);
		double funcionSalida(double x);
		double derivadaActivacion(double x);
		double derivadaSalida(double x);
		
};

#endif

