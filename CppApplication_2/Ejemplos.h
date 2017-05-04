#ifndef EJEMPLOS_H
#define EJEMPLOS_H

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include <sstream>
#include <fstream>
using namespace std;
class Ejemplos {
private:	
	vector <double> EjEntrada;
	vector <double>  EjSalida;
	int separador;
public:
	Ejemplos(int numEntrada,vector<double> X);
	~Ejemplos();
	vector <double> getEjSalida();
	vector <double> getEjEntrada();	
	void AlmacenaDatos(vector<double> X);
};

#endif

