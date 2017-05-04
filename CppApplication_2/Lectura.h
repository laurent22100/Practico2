#ifndef LECTURA_H
#define LECTURA_H

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <windows.h>
#include <sstream>
#include <fstream>
#include"Ejemplos.h"

using namespace std;
class Lectura {
private:
	vector <Ejemplos*> Ej;
	string NomFile;
	char buffer[2048];
	bool ErrorLec;
	ifstream Data;
	int Error;
	int CantidadEjemplos;
	vector <string> E;
	int n ;
	vector <double> X;
	int num;
	double valorMaximoEntrada;
	double valorMinimoEntrada;
	double valorMaximoSalida;
	double valorMinimoSalida;
	int tipo; // Diferencia entre Archivo de dataset y Archivo de prueba 0:dataset y 1 :Prueba 
public:
	Lectura(int tipo ,int numEntrada);
	~Lectura();
	void abrirArchivo();
	bool errorLectura();
	void contadorEjemplos();
	void leerEjemplos();	
	int getCantidadEjemplos();	
	vector <Ejemplos*> getEntradas();
	void calcularValorMaximo();
	void calcularValorMinimo();
	double getValorMaximoSalida();
	double getValorMinimoSalida();
	double getValorMaximoEntrada();
	double getValorMinimoEntrada();
	void leerPrueba();
	vector <double> getPruebas();
	
};

#endif

