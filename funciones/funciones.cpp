//Importaciones
#include <iostream>
#include <vector>       //Crea arrays
#include <algorithm>
#include <random>       //Añade funcion generar indice aleatorio
#include <chrono>       //generar num aleatorio 
#include <windows.h>
#include "funciones.h"  //libreria general
#include <fstream>
#include <cstdlib>
#include <string>

//Uso de un namespace std
using namespace std;
 
//creada con IA///////////////////////
#if defined(_WIN32) || defined(_WIN64)
    #define SISTEMA_WINDOWS
#endif
//Fin de creacion con IA//////////////



// Borra la pantalla y muestra el titulo del juego
void limpiarPantalla() { //Inicio funcion creada con IA
    // Borrar la pantalla (comando distinto segun el sistema operativo)
#ifdef SISTEMA_WINDOWS
    system("cls");
#else
    system("clear");
#endif
 
    // Mostrar el titulo del juego
    cout
            <<"███╗░░░███╗░█████╗░░██████╗████████╗███████╗██████╗░░░░░░░███╗░░░███╗██╗███╗░░██╗██████╗░" <<endl //Titulo principal del juego
            <<"████╗░████║██╔══██╗██╔════╝╚══██╔══╝██╔════╝██╔══██╗░░░░░░████╗░████║██║████╗░██║██╔══██╗" <<endl //arte ascii
            <<"██╔████╔██║███████║╚█████╗░░░░██║░░░█████╗░░██████╔╝█████╗██╔████╔██║██║██╔██╗██║██║░░██║" <<endl //No fue creado con IA
            <<"██║╚██╔╝██║██╔══██║░╚═══██╗░░░██║░░░██╔══╝░░██╔══██╗╚════╝██║╚██╔╝██║██║██║╚████║██║░░██║" <<endl
            <<"██║░╚═╝░██║██║░░██║██████╔╝░░░██║░░░███████╗██║░░██║░░░░░░██║░╚═╝░██║██║██║░╚███║██████╔╝" <<endl
            <<"╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═════╝░░░░╚═╝░░░╚══════╝╚═╝░░╚═╝░░░░░░╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═════╝░" <<endl;
} //Final funcion creada por IA

void cargarPreguntasDesdeArchivo(string preguntas[],char respuestas[],int &cantidadPreguntas,string nombreArchivo){
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()){ //Abrir el archivo
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    string linea;
    cantidadPreguntas = 0;
    while (getline(archivo, linea)){ // El bucle se repeti mientras todavia hayan lineas en el archvo
        // Saltar líneas vacías
        if (linea.empty())
            continue;
        // Guardar la pregunta
        preguntas[cantidadPreguntas] = linea + "\n";
        // Leer todas las opciones
        while (getline(archivo, linea)){
            // Si la línea tiene solo una letra,
            // es la respuesta correcta.
            if (linea.length() == 1){
                respuestas[cantidadPreguntas] = linea[0];
                break;
            }
            preguntas[cantidadPreguntas] += linea + "\n";
        }
        cantidadPreguntas++; //aumenta en 1 por cada iteracion
    }
    archivo.close();
}

// actualizarPuntaje
void actualizarPuntaje(int &puntaje, int numjugador, bool estado){ //Estado es recibe si la respuesta fue correcta
    if (estado == true){
        puntaje = puntaje + 10;
        cout<<"Correcto, jugador " <<numjugador <<", sumaste puntos"<<endl;
    }
    else{
        cout<<"incorrecto, jugador " <<numjugador <<", no sumaste puntos"<<endl;
    }
    cout << "Puntaje 1: " << puntaje << endl;
}
//funcion que muestra todos los puntajes finales de los 2 participantes del videojuego 

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

    cout<<"Presiona enter para continuar...";
    cin.ignore(2);
    limpiarPantalla();

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
    
    cout<<"Presiona enter para continuar...";
    cin.ignore(2);
    limpiarPantalla();
     
    //Mensaje de agradecimiento 
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

void obtenerPreguntaAleatoria(string preguntas_entrada[], char respuestas_entrada[], string preguntas_salida[], char respuestas_salida[], int tamanoArray){
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    struct pregunta{
        string pregunta;
        char respuesta;
    };
    pregunta mezclar[tamanoArray];
    for (int i = 0; i < tamanoArray; i++)
    {
        //Se asignan variables para ser mezcladas localmente
        mezclar[i].pregunta = preguntas_entrada[i];
        mezclar[i].respuesta = respuestas_entrada[i];
    }
    
    shuffle(mezclar, mezclar + tamanoArray, gen);

    for (int i = 0; i < tamanoArray; i++)
    {
        //Se asigna variable de salida
        preguntas_salida[i] = mezclar[i].pregunta;
        respuestas_salida[i] = mezclar[i].respuesta;
    }
    cout<< endl;
}

//La funcion puede recibir valores CHAR o INT, solo modificar parametros de entrada
bool verificar_respuesta(int indice, char respuestas[], char respuesta_usuario){
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
    string categorias[3] = {"../preguntas/paises.txt", "../preguntas/futbol.txt", "../preguntas/gastronomia.txt"}; //ubicacion de los archivos
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

        cout<<"Presiona enter para continuar...";
        cin.ignore();
        limpiarPantalla();

        //Cambie el siguiente mensaje para mejor claridad
        cout << "Elige el numero de jugadores: " << endl; //Mostrar menu con opciones de 1 o 2 jugadores
        do { //Empieza el bucle para elegirt la cantidad de jugadores
            cout << "1)Un jugador\n2)Dos jugadores\n";
            cout << "Modo de juego elegido: ";
            cin >> opc;
            cout<<endl;

            switch (opc) {
                case 1:
                    cout << "usted a seleccionado el modo de un solo jugador\n";
                    repetir_eleccion = false;
                    break;
                case 2:
                    cout << "usted a seleccionado el modo de dos jugadores\n";
                    jugador2 = true; //Se establece que existe un segundo jugador
                    repetir_eleccion = false;
                    break;
                default:
                    cout << "seleccion no valida, vuelve a seleccionar\n"; //repite la eleccion porque el valor ingresado no fue valido
                    repetir_eleccion = true;
                    cout<<"Presiona enter para continuar...";
                    cin.ignore();
                    limpiarPantalla();
                    break;
            }
        } while (repetir_eleccion == true); //Finaliza el bucle para elegir cantidad de jugadores

        cout<<endl;

        do {//Comienza bucle para seleccion del set de preguntas
            cout<<"Seleccione el set de preguntas:" <<endl <<"1)Paises" <<endl <<"2)Futbol" <<endl <<"3)Gastronomia" <<endl <<"opccion: ";
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
                    cout<<"Presiona enter para continuar...";
                    cin.ignore();
                    limpiarPantalla();
                    break;
            }

        }while (repetir_eleccion == true); //Finaliza bucle para seleccion de preguntas
        //Repetir opccion añadida, considero mejor para un codigo que se pueda expandir con el tiempo

    iniciarJuego(categoria_seleccionada, jugador2);

    do
    {
        cout<<"¿Desea jugar otra ronda?\n1)Si\n2)No\n";
        cin>>opc;
        switch (opc)
        {
        case 1:
            repetir_eleccion = true;
            break;
        case 2:
            repetir_eleccion = false;
            break;
        
        default:
            cout<<"Opccion no valida\n";
            cout<<"Presiona enter para continuar...";
            cin.ignore(2);
            limpiarPantalla();
            break;
        }
    } while (opc != 1 && opc != 2);
    
    
    
    }while (repetir_eleccion == true);//Finaliza bucle principal  
}

void iniciarJuego(string categoria, bool existeJugador2){
    struct preguntas{
        string preguntas[15];
        char respuestas[15];
        int cantidad;
    };
    struct jugador{
        string nombre;
        char respuesta;
        int puntaje;
    };
    preguntas set;
    set.cantidad = 0;

    jugador jugador1, jugador2;
    jugador1.puntaje = 0;
    jugador2.puntaje = 0;
    
    
    cout << "La categoria seleccionada fue " << categoria << endl;
    cargarPreguntasDesdeArchivo(set.preguntas, set.respuestas, set.cantidad, categoria);
    //set.cantidad = sizeof(set.preguntas) / sizeof(set.preguntas[0]); //Calc tamaño del array
    obtenerPreguntaAleatoria(set.preguntas, set.respuestas, set.preguntas, set.respuestas, set.cantidad);
    
    for (int i = 0; i < set.cantidad; i++){
        mostrar_pregunta(i, set.preguntas);
        cin.ignore();
        cout<<"Respuesta jugador 1: ";
        cin>>jugador1.respuesta;
        if (jugador1.respuesta != 'a' && jugador1.respuesta !='A' && jugador1.respuesta != 'b' && jugador1.respuesta !='B'&& jugador1.respuesta != 'c' && jugador1.respuesta !='C' && jugador1.respuesta != 'd' && jugador1.respuesta !='D' ){
            jugador1.respuesta = repetirRespuesta(jugador1.respuesta);
        }
        
        if (existeJugador2 == true){
            cout<<"Respuesta jugador 2: ";
            cin>>jugador2.respuesta;
            if (jugador2.respuesta != 'a' && jugador2.respuesta !='A' && jugador2.respuesta != 'b' && jugador2.respuesta !='B'&& jugador2.respuesta != 'c' && jugador2.respuesta !='C' && jugador2.respuesta != 'd' && jugador2.respuesta !='D' ){
            jugador2.respuesta = repetirRespuesta(jugador2.respuesta);
            }  
        }
        
        actualizarPuntaje(jugador1.puntaje, 1, verificar_respuesta(i, set.respuestas, jugador1.respuesta));
        if (existeJugador2 == true){
            actualizarPuntaje(jugador2.puntaje, 2, verificar_respuesta(i, set.respuestas, jugador2.respuesta));
        }
        
        cout<<"Presiona enter para continuar...";
        cin.ignore(2);
        limpiarPantalla();
        
    }//cuando finaliza el bucle terminan las preguntas
    
    finalizarjuego(jugador1.puntaje, jugador2.puntaje, existeJugador2);
    guardarResultados(jugador1.puntaje, jugador2.puntaje, existeJugador2); 
}



void guardarResultados(int puntajeJugador1, int puntajeJugador2, bool jugador2){
    ofstream archivo("resultados.txt", ios::app);

    if (!archivo)
    {
        cout << "Error: No se pudo crear el archivo resultados.txt" << endl;
        return;
    }

    archivo << "=================================\n";
    archivo << "      RESULTADOS DEL JUEGO\n";
    archivo << "=================================\n\n";

    archivo << "Jugador 1: " << puntajeJugador1 << " puntos\n";

    if (jugador2)
    {
        archivo << "Jugador 2: " << puntajeJugador2 << " puntos\n";
    }

    archivo << "\n=================================\n";

    archivo.close();
}


char repetirRespuesta(char respuesta_jugador){
    do{
        cout<<"La opccion "<<respuesta_jugador <<" no existe, las opcciones disponibles son A, B, C y D" <<endl;
        cout<<"Nueva respuesta: ";
        cin>> respuesta_jugador;
    } while (respuesta_jugador != 'a' && respuesta_jugador !='A' && respuesta_jugador != 'b' && respuesta_jugador !='B'
          && respuesta_jugador != 'c' && respuesta_jugador !='C' && respuesta_jugador != 'd' && respuesta_jugador !='D' );

    return respuesta_jugador;
}