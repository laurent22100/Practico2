/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Datos.h
 * Author: laure
 *
 * Created on 3 mai 2017, 22:27
 */

#ifndef DATOS_H
#define DATOS_H

#include <cassert>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <sstream>
#include <unistd.h>
using namespace std;
#include <string>
#include <cstdlib>
#include <ctime>


class Datos {
public:
    Datos(int numeroDatos);
    Datos(const Datos& orig);
    void funcionNonLineal5(double valor_Entrada1[],double valor_Entrada2[],double valor_Entrada3[],double valor_Entrada4[],double valor_Entrada5[]);
    void writeDataset();
    void writePrueba();
    virtual ~Datos();

private:
    int numeroDatos;
    ofstream myfile;
    double valor_Entrada1[20000];
    double valor_Entrada2[20000];
    double valor_Entrada3[20000];
    double valor_Entrada4[20000];
    double valor_Entrada5[20000];
    double valor_Salida[20000] ;
    
    
    
};

#endif /* DATOS_H */

