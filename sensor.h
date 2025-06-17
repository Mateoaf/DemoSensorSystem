#include <iostream>
#include <string>
#include "sensorData.h"

using namespace std;

#ifndef SENSOR_H
#define SENSOR_H

//clase base para todos los tipos de sensores
class Sensor {
    public: 
        // Identificador del sensor
        string id;
        // Tipo del sensor
        string tipo;
        // Constructor por defecto
        Sensor(const string& _id, const string& _tipo);
        virtual ~Sensor() = default;
    
        
        // Obligan a las clases derivadas a implementar el método leerDato y Calibrar
        virtual SensorData leerDato() const = 0;
        virtual void calibrar();

};

#endif