#include<iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"
#include "Red.h"
#include "Datos.h"

#define numEntrada 5
#define numOculta 3
#define numSalida 1
#define e 0.5
#define alfa 0.3
#define numeroDatos 20000

using namespace std;


int main (int argc, char *argv[]) {
	
	srand(time(NULL));
	Red *Clase;
        Datos *Dataset;
        
	Dataset = new Datos(numeroDatos);
        //Dataset->writeDataset();
        //Dataset->writePrueba();
        
	Clase =new Red(numEntrada,numOculta,numSalida,e);

	Clase->entrenamiento();
	Clase->inicializar();
	return 0;
}

