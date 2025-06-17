
using namespace std;
#include "sensorTemperatura.h"

SensorTemperatura::SensorTemperatura(const string& _id)
    : Sensor(_id, "Temperatura"),
    generador(chrono::system_clock::now().time_since_epoch().count()),
    distribucion(15.0,30.0) {}

double SensorTemperatura::leerDato() const {
   return distribucion(generador);
}