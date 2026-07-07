#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include "xavier.h"
using namespace std;

char modo;
int opc = 0;
string categorias[3] = {"paises.txt", "ciencia.txt", "futbol.txt"};
string categoria_seleccionada;


void mostrarMenu() {
    Jugador usuario; 

    cout << "Bienvenido/a jugador por favor ingrese su nombre: ";
    getline(cin, usuario.nombre);
    cout << "" << endl;
    cout << "Bienvenido, " << usuario.nombre << endl;
    cout << "" << endl;
    cout << "Acontinuacion se le van a mostrar cuantos jugadores pueden jugar " << endl;
    
    do {
        cout << " un jugador-> 1\n dos jugadores-> 2\n";
        cout << "selecione uno porfavor:";
        cin >> modo;

        switch (modo) {
            case '1':
                cout << "usted a seleccionado el modo de un solo jugador\n"; 
                break;
            case '2':
                cout << "usted a seleccionado el modo de dos jugadores\n";
                break;
            default:
                cout << "seleccion no valida, vuelve a seleccionar\n";
                break;
        }
    } while (modo != '1' && modo != '2');

    do {
cout<<"Ingrese una categoria: " <<endl <<"1 -> paises.txt" <<endl <<"2 -> ciencia.txt" <<endl <<"3 -> gastronomia.txt" <<endl <<"opccion:";
        cin >> opc;

        switch (opc) {
            case 1:
                categoria_seleccionada = categorias[0];
                break;
            case 2:
                categoria_seleccionada = categorias[1];
                break;
            case 3:
                categoria_seleccionada = categorias[2];
                break;
            default:
                cout << "Opcion invalida\n";
                break;
        }    
    } while (opc != 1 && opc != 2 && opc != 3);

    iniciarJuego(categoria_seleccionada);
}

void iniciarJuego(string categoria) {
    cout << "La categoria seleccionada fue " << opc << endl;
    cargarpreguntas(categoria);
    guardarResultados();
}

string cargarpreguntas(string opc) {
    cout << "Se esta iniciando el juego" << endl;
    cout << "cargando preguntas..." << endl;

    return opc; 
}

void guardarResultados() {
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
