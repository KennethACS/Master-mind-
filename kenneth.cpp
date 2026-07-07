#include <iostream>
#include <vector> //Crea arrays
#include <algorithm>
#include <random> //Añade funcion generar indice aleatorio
#include <chrono> //generar num aleatorio 
#include <windows.h>
#include "kenneth.h"
using namespace std;


void obtenerPreguntaAleatoria(string preguntas_entrada[], string respuestas_entrada[], string preguntas_salida[], string respuestas_salida[], int tamanoArray){
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    

    struct pregunta
    {
        string pregunta;
        string respuesta;
    };

    pregunta mezclar[tamanoArray];
    

    for (int i = 0; i < tamanoArray; i++)
    {
        mezclar[i].pregunta = preguntas_entrada[i];
        mezclar[i].respuesta = respuestas_entrada[i];
    }
    
    shuffle(mezclar, mezclar + tamanoArray, gen);

    for (int i = 0; i < tamanoArray; i++)
    {
        
        //Quitar comentario para verificar correspondencia de la pregunta con la respuesta
        //COUT no esencial para el funcionamiento de la funcion

        /*
        cout<<mezclar[i].pregunta <<" ";
        cout<<mezclar[i].respuesta <<endl;
        */
        
        

        preguntas_salida[i] = mezclar[i].pregunta;
        respuestas_salida[i] = mezclar[i].respuesta;
    }
    cout<< endl;
}

//La funcion puede recibir valores CHAR o INT, solo modificar parametros de entrada
bool verificar_respuesta(int indice, string respuestas[], string respuesta_usuario){
    if(respuesta_usuario == respuestas[indice]){
        return true;
    }
    else{
        return false;
    }
}


void mostrar_pregunta(int indice, string preguntas[]){
    imprimir_titulo(indice);

    cout<<preguntas[indice] <<endl;
}

void imprimir_titulo(int indice){
    cout<<"\n\n";

    cout<<
      "██████╗░██████╗░███████╗░██████╗░██╗░░░██╗███╗░░██╗████████╗░█████╗░" <<endl
    <<"██╔══██╗██╔══██╗██╔════╝██╔════╝░██║░░░██║████╗░██║╚══██╔══╝██╔══██╗" <<endl
    <<"██████╔╝██████╔╝█████╗░░██║░░██╗░██║░░░██║██╔██╗██║░░░██║░░░███████║" <<endl
    <<"██╔═══╝░██╔══██╗██╔══╝░░██║░░╚██╗██║░░░██║██║╚████║░░░██║░░░██╔══██║" <<endl
    <<"██║░░░░░██║░░██║███████╗╚██████╔╝╚██████╔╝██║░╚███║░░░██║░░░██║░░██║" <<endl
    <<"╚═╝░░░░░╚═╝░░╚═╝╚══════╝░╚═════╝░░╚═════╝░╚═╝░░╚══╝░░░╚═╝░░░╚═╝░░╚═╝" <<endl;

    switch (indice)
    {
    case 0:
        cout
        <<"                         ░░███╗░░"<<endl
        <<"                         ░████║░░"<<endl
        <<"                         ██╔██║░░"<<endl
        <<"                         ╚═╝██║░░"<<endl
        <<"                         ███████╗"<<endl
        <<"                         ╚══════╝"<<endl;
        break;

    case 1:
        cout
        <<"                         ██████╗░"<<endl
        <<"                         ╚════██╗"<<endl
        <<"                         ░░███╔═╝"<<endl
        <<"                         ██╔══╝░░"<<endl
        <<"                         ███████╗"<<endl
        <<"                         ╚══════╝"<<endl;
        break;
    case 2:
        cout
        <<"                         ██████╗░"<<endl
        <<"                         ╚════██╗"<<endl
        <<"                         ░█████╔╝"<<endl
        <<"                         ░╚═══██╗"<<endl
        <<"                         ██████╔╝"<<endl
        <<"                         ╚═════╝░"<<endl;
        break;
    case 3:
       cout
        <<"                         ░░██╗██╗"<<endl
        <<"                         ░██╔╝██║"<<endl
        <<"                         ██╔╝░██║"<<endl
        <<"                         ███████║"<<endl
        <<"                         ╚════██║"<<endl
        <<"                         ░░░░░╚═╝"<<endl;
        break;
    case 4:
        cout
        <<"                         ███████╗"<<endl
        <<"                         ███████╗"<<endl
        <<"                         ██╔════╝"<<endl
        <<"                         ██████╗░"<<endl
        <<"                         ╚════██╗"<<endl
        <<"                         ██████╔╝"<<endl
        <<"                         ╚═════╝░"<<endl;
        break;
    case 5:
        cout
        <<"                         ░█████╗░"<<endl
        <<"                         ██╔═══╝░"<<endl
        <<"                         ██████╗░"<<endl
        <<"                         ██╔══██╗"<<endl
        <<"                         ╚█████╔╝"<<endl
        <<"                         ░╚════╝░"<<endl;
        break;
    case 6:
        cout
        <<"                         ███████╗"<<endl
        <<"                         ╚════██║"<<endl
        <<"                         ░░░░██╔╝"<<endl
        <<"                         ░░░██╔╝░"<<endl
        <<"                         ░░██╔╝░░"<<endl
        <<"                         ░░╚═╝░░░"<<endl;
        break;
    case 7:
        cout
        <<"                         ░█████╗░"<<endl
        <<"                         ██╔══██╗"<<endl
        <<"                         ╚█████╔╝"<<endl
        <<"                         ██╔══██╗"<<endl
        <<"                         ╚█████╔╝"<<endl
        <<"                         ░╚════╝░"<<endl;
        break;
    case 8:
        cout
        <<"                         ░█████╗░"<<endl
        <<"                         ██╔══██╗"<<endl
        <<"                         ╚██████║"<<endl
        <<"                         ░╚═══██║"<<endl
        <<"                         ░█████╔╝"<<endl
        <<"                         ░╚════╝░"<<endl;
        break;
    case 9:
        cout
        <<"                         ░░███╗░░░█████╗░"<<endl
        <<"                         ░████║░░██╔══██╗"<<endl
        <<"                         ██╔██║░░██║░░██║"<<endl
        <<"                         ╚═╝██║░░██║░░██║"<<endl
        <<"                         ███████╗╚█████╔╝"<<endl
        <<"                         ╚══════╝░╚════╝░"<<endl;
        break;
        
    default:
        break;
    }
    cout<<"\n\n";
}