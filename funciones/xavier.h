#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
using namespace std;

extern char modo;
extern int opc;
extern string categorias[3];
extern string categoria_seleccionada;


struct Jugador {
    string nombre;
};

void mostrarMenu();
void iniciarJuego(string categoria);
void guardarResultados();
void repetirRespuesta(char respuesta_jugador);
#endif