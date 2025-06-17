#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <thread>  
#include <chrono>
using namespace std;

#include "gestorSensores.h"
#include "sensorGPS.h"
#include "sensorTemperatura.h"
#include "interfazGrafica.h"

int main(){
    InterfazGrafica::mostrarMensajeBienvenida();
    GestorSensores gestor;

    gestor.agregarSensor(new SensorTemperatura("T1"));
    gestor.agregarSensor(new SensorTemperatura("T2"));

    gestor.agregarSensor(new SensorGPS("GPS A"));
    gestor.agregarSensor(new SensorGPS("GPS B"));

    cout << "Iniciando el sistema de captura y gestion de datos de Sensores" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    gestor.setNewDataCallback(InterfazGrafica::displaySensorData);
    gestor.setSensorCalibratedCallback(InterfazGrafica::displayCalibratedSensor);
    int opcion;

    do {
        InterfazGrafica::mostrarMenuPrincipal();
        while (!( cin >> opcion)) {
            cout << "Entrada no valida. Por favor, introduzca un numero: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max());
        } 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        
        switch (opcion) {
            case 1: 
                gestor.leerTodosLosSensores();
                InterfazGrafica::pausarYContinuar();
                break;
            case 2:
                gestor.calibrarTodosLosSensores();
                InterfazGrafica::pausarYContinuar();
                break;
            case 3: 
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción del 1 al 3." << endl;
            }
            this_thread::sleep_for(chrono::milliseconds(1000)); // Simula un pequeño retraso
        } while (opcion != 3);

        cout << "Gracias por usar el sistema de captura y gestion de datos de Sensores " << endl;

    }
    
