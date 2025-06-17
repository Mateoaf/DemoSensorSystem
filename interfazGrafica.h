#ifndef INTERFAZ_GRAFICA_H
#define INTERFAZ_GRAFICA_H

#include <iostream>
#include <string>
#include "sensorData.h"

namespace InterfazGrafica {
    void mostrarMensajeBienvenida();
    void mostrarMenuPrincipal();
    void pausarYContinuar();
    void displaySensorData(const SensorData& data);
    void displayCalibratedSensor(const std::string& sensorId);
}

#endif