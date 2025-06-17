
using namespace std;
#include "sensorTemperatura.h"
#include "sensorData.h"

SensorTemperatura::SensorTemperatura(const string& _id)
    : Sensor(_id, "Temperatura"),
    generador(chrono::system_clock::now().time_since_epoch().count()),
    distribucion(15.0,30.0) {}

SensorData SensorTemperatura::leerDato() const {
   double temp = distribucion(generador);

   return SensorData(id, tipo, temp, " grados ", chrono::system_clock::now().time_since_epoch().count());
}