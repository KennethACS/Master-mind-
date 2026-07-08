#include <iostream>
#include <vector> //Crea arrays
#include <algorithm>
#include <random> //Añade funcion generar indice aleatorio
#include <chrono> //generar num aleatorio 
#include <windows.h>
#include "funciones.h"
#include <fstream>
#include <cstdlib> //Añade funciones con unico proposito
#include <string>

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

//funcion que muestra todos los puntajes finales de los 3 participantes del videojuego 

//Recibe puntajes desde los strucs de jugador 1 y 2
//Recibe el modo de juego seleccionado, 1 o 2 jugadores
void finalizarjuego(float puntaje_jugador1, float puntaje_jugador2, bool jugador2){

    //Esta funcion muetra un mensaje indicando que el juego finalizo 
    cout <<
          "███████╗██╗░░░░░  ░░░░░██╗██╗░░░██╗███████╗░██████╗░░█████╗░" <<endl
        <<"██╔════╝██║░░░░░  ░░░░░██║██║░░░██║██╔════╝██╔════╝░██╔══██╗" <<endl
        <<"█████╗░░██║░░░░░  ░░░░░██║██║░░░██║█████╗░░██║░░██╗░██║░░██║" <<endl
        <<"██╔══╝░░██║░░░░░  ██╗░░██║██║░░░██║██╔══╝░░██║░░╚██╗██║░░██║" <<endl
        <<"███████╗███████╗  ╚█████╔╝╚██████╔╝███████╗╚██████╔╝╚█████╔╝" <<endl
        <<"╚══════╝╚══════╝  ░╚════╝░░╚═════╝░╚══════╝░╚═════╝░░╚════╝░" <<endl
        <<"███████╗██╗███╗░░██╗░█████╗░██╗░░░░░██╗███████╗░█████╗░" <<endl
        <<"██╔════╝██║████╗░██║██╔══██╗██║░░░░░██║╚════██║██╔══██╗" <<endl
        <<"█████╗░░██║██╔██╗██║███████║██║░░░░░██║░░███╔═╝██║░░██║" <<endl
        <<"██╔══╝░░██║██║╚████║██╔══██║██║░░░░░██║██╔══╝░░██║░░██║" <<endl
        <<"██║░░░░░██║██║░╚███║██║░░██║███████╗██║███████╗╚█████╔╝" <<endl
        <<"╚═╝░░░░░╚═╝╚═╝░░╚══╝╚═╝░░╚═╝╚══════╝╚═╝╚══════╝░╚════╝░" <<endl;


    //limpiar pantalla()

    cout
        <<"██████╗░██╗░░░██╗███╗░░██╗████████╗░█████╗░░░░░░██╗███████╗" <<endl
        <<"██╔══██╗██║░░░██║████╗░██║╚══██╔══╝██╔══██╗░░░░░██║██╔════╝" <<endl
        <<"██████╔╝██║░░░██║██╔██╗██║░░░██║░░░███████║░░░░░██║█████╗░░" <<endl
        <<"██╔═══╝░██║░░░██║██║╚████║░░░██║░░░██╔══██║██╗░░██║██╔══╝░░" <<endl
        <<"██║░░░░░╚██████╔╝██║░╚███║░░░██║░░░██║░░██║╚█████╔╝███████╗" <<endl
        <<"╚═╝░░░░░░╚═════╝░╚═╝░░╚══╝░░░╚═╝░░░╚═╝░░╚═╝░╚════╝░╚══════╝" <<endl;
    //muestra el puntaje que obtuvo cada participante 
    cout << "El jugador 1 tuvo: " << puntaje_jugador1 <<" puntos"<<endl;
   if (jugador2 == true)
   {
      cout << "El jugador 2 tuvo: " << puntaje_jugador2 <<" puntos" <<endl;
   }
    
    
     
    //Mensaje de agradecimiento 
    cout<<"Muchas gracias por participar "<<endl;

    cout<<
          "░██████╗░██████╗░░█████╗░░█████╗░██╗░█████╗░░██████╗  ██████╗░░█████╗░██████╗░" <<endl
        <<"██╔════╝░██╔══██╗██╔══██╗██╔══██╗██║██╔══██╗██╔════╝  ██╔══██╗██╔══██╗██╔══██╗" <<endl
        <<"██║░░██╗░██████╔╝███████║██║░░╚═╝██║███████║╚█████╗░  ██████╔╝██║░░██║██████╔╝" <<endl
        <<"██║░░╚██╗██╔══██╗██╔══██║██║░░██╗██║██╔══██║░╚═══██╗  ██╔═══╝░██║░░██║██╔══██╗" <<endl
        <<"╚██████╔╝██║░░██║██║░░██║╚█████╔╝██║██║░░██║██████╔╝  ██║░░░░░╚█████╔╝██║░░██║" <<endl
        <<"░╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░╚═╝╚═╝░░╚═╝╚═════╝░  ╚═╝░░░░░░╚════╝░╚═╝░░╚═╝" <<endl
        <<"░░░░░██╗██╗░░░██╗░██████╗░░█████╗░██████╗░" <<endl
        <<"░░░░░██║██║░░░██║██╔════╝░██╔══██╗██╔══██╗" <<endl
        <<"░░░░░██║██║░░░██║██║░░██╗░███████║██████╔╝" <<endl
        <<"██╗░░██║██║░░░██║██║░░╚██╗██╔══██║██╔══██╗" <<endl
        <<"╚█████╔╝╚██████╔╝╚██████╔╝██║░░██║██║░░██║" <<endl
        <<"░╚════╝░░╚═════╝░░╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝" <<endl;


}

//funcion que pide el puntaje de un participante 
void mostrarpuntaje(float puntaje_jugador1, float puntaje_jugador2, bool jugador2){
   //funciones donde se pide el puntaje de los participantes y se guarda
   
   cout
        <<"██████╗░██╗░░░██╗███╗░░██╗████████╗░█████╗░░░░░░██╗███████╗" <<endl
        <<"██╔══██╗██║░░░██║████╗░██║╚══██╔══╝██╔══██╗░░░░░██║██╔════╝" <<endl
        <<"██████╔╝██║░░░██║██╔██╗██║░░░██║░░░███████║░░░░░██║█████╗░░" <<endl
        <<"██╔═══╝░██║░░░██║██║╚████║░░░██║░░░██╔══██║██╗░░██║██╔══╝░░" <<endl
        <<"██║░░░░░╚██████╔╝██║░╚███║░░░██║░░░██║░░██║╚█████╔╝███████╗" <<endl
        <<"╚═╝░░░░░░╚═════╝░╚═╝░░╚══╝░░░╚═╝░░░╚═╝░░╚═╝░╚════╝░╚══════╝" <<endl;
    //muestra el puntaje que obtuvo cada participante 
   cout << "El jugador 1 tuvo: " << puntaje_jugador1 <<"puntos"<<endl;
   if (jugador2 == true)
   {
      cout << "El jugador 2 tuvo: " << puntaje_jugador2 <<"puntos" <<endl;
   }
    

     cout <<endl;
    
     
}

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

void mostrarMenu(){
    
    //Declaracion de variables locales
    string categorias[3] = {"paises.txt", "ciencia.txt", "futbol.txt"}; //nombres de los archivos
    string categoria_seleccionada;                                      //se guardara el nombre del archivo seleccionado
    bool jugador2 = false;                                              //La variable indica si el jugador 2 existe
    bool repetir_eleccion = false;                                      //variable usada en menus para saber si el usuario debe de escojer nuevamente
    Jugador usuario;                                                    //struck legado, pendiente de eliminar
    int opc = 0;                                                        //variable usada para seleccionar las opcciones en los menus
    
    do{

        cout
            <<"███╗░░░███╗░█████╗░░██████╗████████╗███████╗██████╗░░░░░░░███╗░░░███╗██╗███╗░░██╗██████╗░" <<endl //Titulo principal del juego
            <<"████╗░████║██╔══██╗██╔════╝╚══██╔══╝██╔════╝██╔══██╗░░░░░░████╗░████║██║████╗░██║██╔══██╗" <<endl //arte ascii
            <<"██╔████╔██║███████║╚█████╗░░░░██║░░░█████╗░░██████╔╝█████╗██╔████╔██║██║██╔██╗██║██║░░██║" <<endl
            <<"██║╚██╔╝██║██╔══██║░╚═══██╗░░░██║░░░██╔══╝░░██╔══██╗╚════╝██║╚██╔╝██║██║██║╚████║██║░░██║" <<endl
            <<"██║░╚═╝░██║██║░░██║██████╔╝░░░██║░░░███████╗██║░░██║░░░░░░██║░╚═╝░██║██║██║░╚███║██████╔╝" <<endl
            <<"╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═════╝░░░░╚═╝░░░╚══════╝╚═╝░░╚═╝░░░░░░╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═════╝░" <<endl;

        //Pendiente///////////////////////////////////////
        //////////////////////////////////////////////////
        //limpiar pantalla despues de 2 segundos
        //USAR CHRONO PARA ESPERAR X CANTIDAD DE SEGUNDOS
        //////////////////////////////////////////////////

        //No veo logico pedir nombre de usuario antes que la cantidad de jugadores
        /*
        getline(cin, usuario.nombre);
        cout << endl; //Quite los "" antes de endl, no hacian nada
        cout << "Bienvenido, " << usuario.nombre << endl;
        cout << endl;
        */

        //Cambie el siguiente mensaje para mejor claridad
        cout << "Elige el numero de jugadores:" << endl; //Mostrar menu con opciones de 1 o 2 jugadores
        do { //Empieza el bucle para elegirt la cantidad de jugadores
            cout << "1)Un jugador\n2)Dos jugadores\n";
            cout << "Modo de juego elegido";
            cin >> opc;

            switch (opc) {
                case '1':
                    cout << "usted a seleccionado el modo de un solo jugador\n";
                    repetir_eleccion = false;
                    break;
                case '2':
                    cout << "usted a seleccionado el modo de dos jugadores\n";
                    jugador2 = true; //Se establece que existe un segundo jugador
                    repetir_eleccion = false;
                    break;
                default:
                    cout << "seleccion no valida, vuelve a seleccionar\n"; //repite la eleccion porque el valor ingresado no fue valido
                    repetir_eleccion = true;
                    //limpiar pantalla despues de x segundos
                    break;
            }
        } while (repetir_eleccion == true); //Finaliza el bucle para elegir cantidad de jugadores

        do {//Comienza bucle para seleccion del set de preguntas
            cout<<"Seleccione el set de preguntas:" <<endl <<"1)Paises.txt" <<endl <<"2)Ciencia.txt" <<endl <<"3)Gastronomia.txt" <<endl <<"opccion:";
            cin >> opc;

            switch (opc){
                case 1: //Reduzco lineas de codigo, el programa usaria el mismo codigo para los 3 casos
                case 2:
                case 3:
                    categoria_seleccionada = categorias[opc-1]; //Al usuario se le muestran los menus con un valor al que estan presentes en el array
                    cout<<"Has seleccionado: " <<categoria_seleccionada <<endl;
                    repetir_eleccion = false;
                    break;
                default:
                    cout << "Opcion invalida\nVuelve a elegir\n";
                    repetir_eleccion = true;
                    //limpiar pantalla despues de x segundos
                    break;
            }

            /*
            //codigo antiguo, descomentar si quieres recuperar
            //version mejorada arriba
            switch (opc-1) {
                case 1:
                    categoria_seleccionada = categorias[opc-1];
                    cout<<"Has seleccionado: " <<categoria_seleccionada <<endl;
                    repetir_eleccion = false;
                    break;
                case 2:
                    categoria_seleccionada = categorias[opc-1];
                    repetir_eleccion = false;
                    break;
                case 3:
                    categoria_seleccionada = categorias[opc-1];
                    repetir_eleccion = false;
                    break;
                default:
                    cout << "Opcion invalida\nVuelve a elegir\n";
                    repetir_eleccion = true;
                    //limpiar pantalla despues de x segundos
                    break;
            }    
            */ 
        }while (repetir_eleccion == true); //Finaliza bucle para seleccion de preguntas
        //Repetir opccion añadida, considero mejor para un codigo que se pueda expandir con el tiempo
    

    iniciarJuego(categoria_seleccionada);
    }while (repetir_eleccion == true);//Finaliza bucle principal  
}

void iniciarJuego(string categoria, bool existeJugador2){
    struct preguntas{
        string preguntas;
        string respuestas;
        int cantidad;
    };
    struct jugador{
        string nombre;
        char respuesta;
        int puntaje;
    };

    jugador jugador1, jugador2;
    
    preguntas set;
    cout << "La categoria seleccionada fue " << categoria << endl;
    //cargar preguntas
    //obtener preguntas aleatorias
    
    set.cantidad = sizeof(set.preguntas) / sizeof(set.preguntas[0]); //Calc tamaño del array
    for (int i = 0; i < set.cantidad; i++)
    {
        //mostrar pregunta
        repetirRespuesta(jugador1.respuesta);
        if (existeJugador2 == true){
            repetirRespuesta(jugador2.respuesta);
        }
        //verificar respuesta
        //limpiar pantalla
        //mostrar puntaje

    }//cuando finaliza el bucle terminan las preguntas
    
    guardarResultados(); 
}



void guardarResultados(int jugador){
    string nombre, jugadores;
    ofstream archivo("resultados.txt", ios::app);

    if (archivo.is_open()) {
        archivo << nombre << endl; 
        archivo << jugadores << endl; 
        archivo.close();           
        cout << "sus datos han guardados con exito" << endl;
    } else {
        cout << "Error al intentar abrir el archivo." << endl;
    }
}

void repetirRespuesta(char respuesta_jugador){
    do
    {
        cout<<"La opccion "<<respuesta_jugador <<" no existe, las opcciones disponibles son A, B, C y D" <<endl;
        cout<<"Nueva respuesta: ";
        cin>> respuesta_jugador;
    } while (respuesta_jugador != 'a' && respuesta_jugador !='A' && respuesta_jugador != 'b' && respuesta_jugador !='C'
          && respuesta_jugador != 'c' && respuesta_jugador !='C' && respuesta_jugador != 'd' && respuesta_jugador !='D' );
    
    

}
