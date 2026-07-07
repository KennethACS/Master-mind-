 #include <iostream> 
 #include "JONATHAN.h"
using namespace std;

//funcion que muestra todos los puntajes finales de los 3 participantes del videojuego 

void finalizarvideojuego(int Puntos1, int Puntos2, int Puntos3){

    //Esta funcion muetra un mensaje indicando que el juego finalizo 
    cout <<"---------EL JUEGO TERMINO-----------"<<endl;
   
    //muestra el puntaje que obtuvo cada participante 
    cout << "El jugador 1 tuvo:" << Puntos1 <<endl;
     cout << "El jugador 2 tuvo:" << Puntos2 <<endl;
      cout << "El jugador 3 tuvo:" << Puntos3 <<endl;
     
      //Mensaje de agradecimiento 
      cout<<" gracias por participar "<<endl;



}
