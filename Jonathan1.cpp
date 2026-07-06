#include <iostream> 
using namespace std; 

// variables donde se almacenan los datos de los puntajes de de cada uno de los participantes 

int puntaje1;
int puntaje2;
int puntaje3;


//funcion que pide el puntaje de un participante 

void mostrarpuntaje(int participante){

   //funciones donde se pide el puntaje de los participantes y se guarda
   
    if (participante == 1){
        cout<<"el puntaje  del primer participante es de ";
        cin >> puntaje1;
    }
     else if (participante ==2) {
        cout <<"el puntaje del segundo participante es de ";
        cin >> puntaje2;
     }
     else if (participante ==3) {
        cout <<"el puntaje del tercer participante es de ";
        cin >> puntaje3;
     }
    
     
    }
      
      //solicita el puntaje de los jugadores y finaliza el programa correctamente 
     int main (){
         mostrarpuntaje(1); 
         mostrarpuntaje(2);
         mostrarpuntaje(3);

         return 0;



     }





