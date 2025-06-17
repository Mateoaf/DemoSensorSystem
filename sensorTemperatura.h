#ifndef SENSOR_TEMPERATURA_H
#define SENSOR_TEMPERATURA_H

#include <iostream>
#include <random>
#include "sensor.h"
#include "sensorData.h"
#include <chrono>

using namespace std;

// Clase SensorTemperatura que hereda de Sensor
// Simula la lectura de datos en un rango predefinido de temperatura
class SensorTemperatura : public Sensor {
    private:
        // Generador de números aleatorios
        mutable default_random_engine generador;
        // Define el rango de valores de temperatura
        mutable uniform_real_distribution<double> distribucion;
    public:
        SensorTemperatura(const string& _id);

        SensorData leerDato() const override;
};

#endif