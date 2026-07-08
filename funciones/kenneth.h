#ifndef KENNETH_H
#define KENNETH_H
#include <string>
using namespace std;
void obtenerPreguntaAleatoria(string preguntas_entrada[], string respuestas_entrada[], string preguntas_salida[], string respuestas_salida[], int tamanoArray);
bool verificar_respuesta(int indice, string respuestas[], string respuesta_usuario);
void mostrar_pregunta(int indice, string preguntas[]);
void imprimir_titulo(int indice);
#endif