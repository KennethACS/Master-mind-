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
void iniciarJuego(string categoria);
void guardarResultados();
void repetirRespuesta(char respuesta_jugador);

//kenneth
void obtenerPreguntaAleatoria(string preguntas_entrada[], string respuestas_entrada[], string preguntas_salida[], string respuestas_salida[], int tamanoArray);
bool verificar_respuesta(int indice, string respuestas[], string respuesta_usuario);
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
int cargarPreguntasDesdeArchivo(string nombreArchivo, Pregunta preguntas[], int maximo);
void actualizarPuntaje(int& puntaje, int respuestaJugador, int respuestaCorrecta);


//jonathan
using namespace std;
void finalizarjuego(float puntaje_jugador1, float puntaje_jugador2, bool jugador2);
void mostrarpuntaje(float puntaje_jugador1, float puntaje_jugador2, bool jugador2); 
#endif