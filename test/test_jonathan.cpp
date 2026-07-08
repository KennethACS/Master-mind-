#include <iostream>
#include <windows.h> 
#include "JONATHAN.h"

using namespace std; 

int puntaje1 = 100; //Probar si la funcion puede recibir valoresde tipo int
float puntaje2 = 200;
bool estadoJugador2 = true;

int main (){
    SetConsoleOutputCP(CP_UTF8);
    cout<<"Testeo de finalizacion de juego: " <<endl;
    finalizarjuego(puntaje1, puntaje2, estadoJugador2);

    cout<<"Testeo de mostrar puntacion de jugadores: " <<endl;
    mostrarpuntaje(puntaje1, puntaje2, estadoJugador2);

    return 0;
}