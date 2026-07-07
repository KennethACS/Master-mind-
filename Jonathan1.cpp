#include <iostream> 
#include "JONATHAN.H"
using namespace std; 

// variables donde se almacenan los datos de los puntajes de de cada uno de los participantes 

int puntaje1 = 50;
int puntaje2 = 20;
int puntaje3 = 85;


//funcion que pide el puntaje de un participante 

void mostrarpuntaje(int participante){

   //funciones donde se pide el puntaje de los participantes y se guarda
   
    if (participante == 1){
        cout<<"el puntaje  del primer participante es de: "<<puntaje1 <<endl;
        
    }
     else if (participante ==2) {
        cout <<"el puntaje del segundo participante es de :"<<puntaje2 <<endl;
        
     }
     else if (participante ==3) {
        cout <<"el puntaje del tercer participante es de: "<<puntaje3 <<endl;
      
     }
     cout <<endl;
    
     
    }
    
    
      





