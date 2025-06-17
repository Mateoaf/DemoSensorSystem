#include "interfazGrafica.h"
using namespace std;
void InterfazGrafica::mostrarMensajeBienvenida() {
   
    cout << "Bienvenido al sistema de captura y gestion de datos de Sensores" << endl;
    
    
}

void InterfazGrafica::mostrarMenuPrincipal() {
    cout << "Menu Principal" << endl;
    cout << "1. Leer todos los sensores" << endl;
    cout << "2. Calibrar sensores" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: ";
}