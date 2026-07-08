#ifndef FUNCIONES_H
#define FUNCIONES_H
 
#include <string>
using namespace std;
 
// Cantidad maxima de preguntas que se pueden guardar
const int MAX_PREGUNTAS = 50;
 
// Guarda todos los datos de UNA pregunta
struct Pregunta {
    string categoria;
    string enunciado;
    string opciones[4];
    int respuestaCorrecta; // numero de 1 a 4
};
 
// Limpia la pantalla y muestra el titulo del juego
void limpiarPantalla();
 
// Lee las preguntas de un archivo y las guarda en el arreglo "preguntas"
// Devuelve cuantas preguntas se lograron leer
int cargarPreguntasDesdeArchivo(string nombreArchivo, Pregunta preguntas[], int maximo);
 
// Revisa si la respuesta es correcta, suma puntos si es asi,
// y muestra el puntaje
void actualizarPuntaje(int& puntaje, int respuestaJugador, int respuestaCorrecta);
 
#endif