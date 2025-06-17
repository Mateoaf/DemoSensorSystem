#include "sensorGPS.h"
using namespace std;

SensorGPS::SensorGPS(const string& _id) : Sensor(_id, "GPS"), 
generador(chrono::system_clock::now().time_since_epoch().count()+1), latitudDistribucion(27.0, 29.00),
longitudDistribucion(-18.0, -13.0){}

double SensorGPS::leerDato() const {
    return latitudDistribucion(generador);
}

pair<double, double> SensorGPS::obtenerCoordenadas() const {
    return {latitudDistribucion(generador), longitudDistribucion(generador)};
}