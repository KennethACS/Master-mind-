#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include "xavier.h"
using namespace std;

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