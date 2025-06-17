

#ifndef SENSOR_GPS_H
#define SENSOR_GPS_H
#include "sensor.h"
#include <random>
#include <chrono>
#include <utility> 

using namespace std;

class SensorGPS : public Sensor {
    private:
        mutable default_random_engine generador;
        // Define la latitud y longitud
        mutable uniform_real_distribution<double> latitudDistribucion;
        mutable uniform_real_distribution<double> longitudDistribucion;
    public:
        SensorGPS(const string& _id);
        double leerDato() const override;
        pair<double, double> obtenerCoordenadas() const;
};

#endif