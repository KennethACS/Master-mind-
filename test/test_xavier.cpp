#include <iostream>
#include <fstream>
#include <cassert>
#include "../funciones/xavier.h"
using namespace std;

void test_guardarResultados() {
    cout << "== Test: guardarResultados ==" << endl;
    guardarResultados();

    ifstream archivo("resultados.txt");
    assert(archivo.is_open());
    cout << "OK: el archivo se creo/abrio correctamente." << endl;
}

void test_iniciarJuego() {
    cout << "== Test: iniciarJuego ==" << endl;
    iniciarJuego("paises.txt");
    cout << "OK: iniciarJuego se ejecuto sin fallar." << endl;
}

int main() {
    cout << "== Iniciando pruebas de Xavier ==" << endl;
    test_iniciarJuego();
    test_guardarResultados();
    cout << "== Todas las pruebas pasaron ==" << endl;
    return 0;
}
