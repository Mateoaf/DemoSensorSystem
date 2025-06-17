#include "interfazGrafica.h"
#include "sensorData.h"
#include <iostream>
#include <iomanip> 
#include <limits>
#include <thread>
#include <chrono>
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

void InterfazGrafica::pausarYContinuar() {
    std::cout << "\nPresione ENTER para continuar...";
    std::cin.get(); 
}

// Implementación del callback para mostrar datos de sensor
void InterfazGrafica::displaySensorData(const SensorData& data) {
    std::cout << "[NUEVO DATO] ID: " << data.sensorId
              << " | Tipo: " << data.sensorType
              << " | Valor: " << std::fixed << std::setprecision(2) << data.value << " " << data.units;

    if (data.sensorType == "GPS") {
        auto it_lat = data.additionalData.find("latitud");
        auto it_lon = data.additionalData.find("longitud");
        if (it_lat != data.additionalData.end() && it_lon != data.additionalData.end()) {
            std::cout << " | Latitud: " << std::fixed << std::setprecision(6) << it_lat->second
                      << ", Longuitud: " << std::fixed << std::setprecision(6) << it_lon->second;
        }
    }
    std::cout << " | Timestamp: " << data.timestamp << "" << std::endl;
}

// Implementación del callback para mostrar sensor calibrado
void InterfazGrafica::displayCalibratedSensor(const std::string& sensorId) {
    std::cout << "[CALIBRACION] Sensor '" << sensorId << "' ha sido calibrado." << std::endl;
}