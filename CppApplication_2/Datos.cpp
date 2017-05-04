#include "Datos.h"




Datos::Datos(int numeroDatos) {
    this->numeroDatos=numeroDatos;
}
void Datos::funcionNonLineal5(double valor_Entrada1[],double valor_Entrada2[],double valor_Entrada3[],double valor_Entrada4[],double valor_Entrada5[]){
    
    for(int count=0; count <=numeroDatos;count++){
        this->valor_Salida[count]=this->valor_Entrada1[count]*this->valor_Entrada2[count]+this->valor_Entrada3[count]+this->valor_Entrada4[count]*this->valor_Entrada5[count];
    } 
        
}

void Datos::writeDataset(){
    
    for(int count=0; count <numeroDatos;count++){
        this->valor_Entrada1[count]= (((double) (rand() % 1000000)) / 1000000);  
        this->valor_Entrada2[count]= (((double) (rand() % 1000000)) / 1000000);  
        this->valor_Entrada3[count]= (((double) (rand() % 1000000)) / 1000000);  
        this->valor_Entrada4[count]= (((double) (rand() % 1000000)) / 1000000);  
        this->valor_Entrada5[count]= (((double) (rand() % 1000000)) / 1000000);  
    } 
    this->funcionNonLineal5(valor_Entrada1,valor_Entrada2,valor_Entrada3,valor_Entrada4,valor_Entrada5);
            
    this->myfile.open ("1.txt", std::ofstream::out | std::ofstream::trunc);
    for(int i=0; i <=numeroDatos;i++){
        myfile << this->valor_Entrada1[i] << "," << this->valor_Entrada2[i] << "," << this->valor_Entrada3[i]<< "," << this->valor_Entrada4[i] << "," << this->valor_Entrada5[i]<< "," << this->valor_Salida[i] <<"\n";
    }
    myfile.close();
    
    
    return;
}
void Datos::writePrueba(){
    for(int count=0; count <numeroDatos;count++){
        this->valor_Entrada1[count]= (((double) (rand() % 1000000)) / 1000000);
        this->valor_Entrada2[count]= (((double) (rand() % 1000000)) / 1000000);  
        this->valor_Entrada3[count]= (((double) (rand() % 1000000)) / 1000000);  
        this->valor_Entrada4[count]= (((double) (rand() % 1000000)) / 1000000);  
        this->valor_Entrada5[count]= (((double) (rand() % 1000000)) / 1000000);  
    }
    
    this->funcionNonLineal5(valor_Entrada1,valor_Entrada2,valor_Entrada3,valor_Entrada4,valor_Entrada5);
            
    this->myfile.open ("2.txt", std::ofstream::out | std::ofstream::trunc);
    for(int i=0; i <numeroDatos/1000;i++){
        myfile << this->valor_Entrada1[i] << "," << this->valor_Entrada2[i] << "," << this->valor_Entrada3[i]<< "," << this->valor_Entrada4[i] << "," << this->valor_Entrada5[i]<< "\n";
    }
    myfile.close();

    this->myfile.open ("3.txt", std::ofstream::out | std::ofstream::trunc);
    for(int i=0; i <numeroDatos/1000;i++){
        myfile << this->valor_Entrada1[i] << "," << this->valor_Entrada2[i] << "," << this->valor_Entrada3[i]<< "," << this->valor_Entrada4[i] << "," << this->valor_Entrada5[i]<< "\t\t" << this->valor_Salida[i] <<"\n";
    }
    myfile.close();
    return;
}
Datos::Datos(const Datos& orig) {
}

Datos::~Datos() {
}

