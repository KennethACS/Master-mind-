#include "funciones.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
 
//creada con IA
#if defined(_WIN32) || defined(_WIN64)
    #define SISTEMA_WINDOWS
#endif
//Fin de creacion con IA

//
// limpiarPantalla
// Borra la pantalla y muestra el titulo del juego
void limpiarPantalla() { //Inicio funcion creada con IA
    // Borrar la pantalla (comando distinto segun el sistema operativo)
#ifdef SISTEMA_WINDOWS
    system("cls");
#else
    system("clear");
#endif
 
    // Mostrar el titulo del juego
    cout << "========================================" << endl;
    cout << "         MASTERMIND " << endl;
    cout << "========================================" << endl;
} //Final funcion creada por IA
 

// cargarPreguntasDesdeArchivo
// El archivo tiene 7 lineas por cada pregunta:
//   linea 1: categoria
//   linea 2: enunciado
//   linea 3 a 6: las 4 opciones
//   linea 7: numero de la respuesta correcta

int cargarPreguntasDesdeArchivo(string nombreArchivo, Pregunta preguntas[], int maximo) {
    ifstream archivo(nombreArchivo);
    int total = 0;
 
    // Si el archivo no abrio, se avisa pero el programa sigue
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
    }
 
    string texto;
 
    // Se repite mientras haya lineas para leer
    while (getline(archivo, texto)) {
 
        // Si ya se lleno el arreglo, se detiene
        if (total >= maximo) {
            break;
        }
 
        // Si la linea esta vacia, se ignora y sigue con la siguiente
        if (texto == "") {
            continue;
        }
 
        // "texto" ya trae la categoria (primera linea del bloque)
        Pregunta p;
        p.categoria = texto;
 
        getline(archivo, p.enunciado);
        getline(archivo, p.opciones[0]);
        getline(archivo, p.opciones[1]);
        getline(archivo, p.opciones[2]);
        getline(archivo, p.opciones[3]);
 
        string numero;
        getline(archivo, numero);
        p.respuestaCorrecta = stoi(numero);
 
        preguntas[total] = p;
        total++;
    }
 
    archivo.close();
 
    // Si no se guardo ninguna pregunta, se avisa
    if (total == 0) {
        cout << "El archivo esta vacio o no se pudo leer" << endl;
    }
 
    return total;
}
 

// actualizarPuntaje
// Compara la respuesta del jugador con la correcta

void actualizarPuntaje(int& puntaje, int respuestaJugador, int respuestaCorrecta) {
    if (respuestaJugador == respuestaCorrecta) {
        puntaje = puntaje + 10;
       cout<<"Correcto, sumaste puntos"<<endl;

    }
    else{
        cout<<"incorrecto, no sumaste puntos"<<endl;
    }
    
 
    cout << "Puntaje: " << puntaje << endl;
}
