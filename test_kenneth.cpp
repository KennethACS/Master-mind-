#include <iostream>
#include <windows.h>
#include "kenneth.h"

using namespace std;

string preguntas_entrada[] = {"a", "b", "c", "d", "e"};
string respuestas_entrada[] = {"1","2","3","4","5"};
string preguntas_salida[5];
string respuestas_salida[5];

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    //Datos de prueba, llamada de funcion como test
    /*
    Parametros de la funcion: 
    string preguntas_entrada[] - SET DE PREGUNTAS Y RESPUESTAS DE ENTRADA 
    string respuestas_entrada[] -NO se modifican estos arrays
    string preguntas_salida[] - SET DE PREGUNTAS Y RESPUESTA DE SALIDA YA BARAJEADAS
    string respuestas_salida[] - El contenido de estos arrays se SUSTITURA
    int tamanoAreglo
    */

    int tamano = sizeof(preguntas_entrada) / sizeof(preguntas_entrada[0]);
    cout<<"Tamaño array: " <<tamano <<endl;
    obtenerPreguntaAleatoria(preguntas_entrada,respuestas_entrada,preguntas_salida,respuestas_salida, tamano);

    cout<<"Distribucion aleatoria con correspondencia generada: " <<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<preguntas_salida[i] <<" ";
        cout<<respuestas_salida[i] <<endl;
    }

    cout<<"Titulos de las preguntas: " <<endl;
    string preguntas_entrada[] = {"1","2","3","4","5","6","7","8","9","10"};
    for (int i = 0; i < 10; i++)
    {
        mostrar_pregunta(i, preguntas_entrada);
    }

    cout<<"verificar respuesta:";
    string valores[] = {"a", "b", "c", "d", "e"};
    for (int i = 0; i < 5; i++)
    {
        cout<<verificar_respuesta(i, valores, "a"); //Entrada quemada para verificar comportamiento
    }
    return 0;
}