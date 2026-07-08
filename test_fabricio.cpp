#include <iostream>
#include "funciones.h"
using namespace std;
 
int main() {

     

    Pregunta preguntas[MAX_PREGUNTAS];
 
    // Cargar las preguntas del archivo
    int total = cargarPreguntasDesdeArchivo("preguntas.txt", preguntas, MAX_PREGUNTAS);
 
    if (total == 0) {
        cout << "No hay preguntas para jugar." << endl;
        return 1;
    }
 
    int puntaje = 0;
 
    // Recorrer todas las preguntas cargadas
    for (int i = 0; i < total; i++) {
        limpiarPantalla();
 
        cout << "Categoria: " << preguntas[i].categoria << endl;
        cout << preguntas[i].enunciado << endl << endl;
 
        for (int j = 0; j < 4; j++) {
            cout << j + 1 << ". " << preguntas[i].opciones[j] << endl;
        }
 
        int respuesta;
        cout << "\nTu respuesta: ";
        cin >> respuesta;
 
        actualizarPuntaje(puntaje, respuesta, preguntas[i].respuestaCorrecta);
 
        cout << "\nPresiona Enter para continuar...";
        cin.ignore();
        cin.get();
    }
 
    limpiarPantalla();
    cout << "Juego terminado. Puntaje final: " << puntaje << endl;
 
    return 0;
}