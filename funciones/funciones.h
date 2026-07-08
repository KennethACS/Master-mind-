#ifndef Funciones_H
#define Funciones_H
#include <string>
using namespace std;

extern char modo;
extern int opc;
extern string categorias[3];
extern string categoria_seleccionada;


struct Jugador{
    string nombre;
};
//Xavier
void mostrarMenu();
void iniciarJuego(string categoria, bool existeJugador2);
void guardarResultados(int puntajeJugador1, int puntajeJugador2, bool jugador2);
char repetirRespuesta(char respuesta_jugador);

//kenneth
void obtenerPreguntaAleatoria(string preguntas_entrada[], char respuestas_entrada[], string preguntas_salida[], char respuestas_salida[], int tamanoArray);
bool verificar_respuesta(int indice, char respuestas[], char respuesta_usuario);
void mostrar_pregunta(int indice, string preguntas[]);
void imprimir_titulo(int indice);

//fabricio
const int MAX_PREGUNTAS = 50;
 
struct Pregunta {
    string categoria;
    string enunciado;
    string opciones[4];
    int respuestaCorrecta; 
};
void limpiarPantalla();
void cargarPreguntasDesdeArchivo(string preguntas[],char respuestas[],int &cantidadPreguntas, string nombreArchivo);
void actualizarPuntaje(int &puntaje, int numjugador, bool estado);


//jonathan
using namespace std;
void finalizarjuego(float puntaje_jugador1, float puntaje_jugador2, bool jugador2);
void mostrarpuntaje(float puntaje_jugador1, float puntaje_jugador2, bool jugador2); 
#endif