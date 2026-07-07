#include <iostream> 
#include "JONATHAN.H"
using namespace std; 

// variables donde se almacenan los datos de los puntajes de de cada uno de los participantes 

int puntaje1 = 50;
int puntaje2 = 20;
int puntaje3 = 85;


//funcion que pide el puntaje de un participante 
void mostrarpuntaje(string puntaje_jugador1, string puntaje_jugador2, bool jugador2){
   //funciones donde se pide el puntaje de los participantes y se guarda
   
   cout
        <<"██████╗░██╗░░░██╗███╗░░██╗████████╗░█████╗░░░░░░██╗███████╗" <<endl
        <<"██╔══██╗██║░░░██║████╗░██║╚══██╔══╝██╔══██╗░░░░░██║██╔════╝" <<endl
        <<"██████╔╝██║░░░██║██╔██╗██║░░░██║░░░███████║░░░░░██║█████╗░░" <<endl
        <<"██╔═══╝░██║░░░██║██║╚████║░░░██║░░░██╔══██║██╗░░██║██╔══╝░░" <<endl
        <<"██║░░░░░╚██████╔╝██║░╚███║░░░██║░░░██║░░██║╚█████╔╝███████╗" <<endl
        <<"╚═╝░░░░░░╚═════╝░╚═╝░░╚══╝░░░╚═╝░░░╚═╝░░╚═╝░╚════╝░╚══════╝" <<endl;
    //muestra el puntaje que obtuvo cada participante 
   cout << "El jugador 1 tuvo:" << puntaje_jugador1 <<endl;
   if (jugador2 == true)
   {
      cout << "El jugador 2 tuvo:" << puntaje_jugador2 <<endl;
   }
    

     cout <<endl;
    
     
}
    
    
      





