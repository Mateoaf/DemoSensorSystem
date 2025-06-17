#include "sensorGPS.h"
using namespace std;

SensorGPS::SensorGPS(const string& _id) : Sensor(_id, "GPS"), 
generador(chrono::system_clock::now().time_since_epoch().count()+1), latitudDistribucion(27.0, 29.00),
longitudDistribucion(-18.0, -13.0){}

SensorData SensorGPS::leerDato() const {
    double lat = latitudDistribucion(generador);
    double lon = longitudDistribucion(generador);

    SensorData data(id, tipo, lat, "grados", std::chrono::system_clock::now().time_since_epoch().count());
    data.additionalData["latitud"] = lat; // Guardamos latitud en additionalData
    data.additionalData["longitud"] = lon; // Guardamos longitud en additionalData
    data.additionalData["valor_principal"] = lat; // Por si el 'value' principal también es la latitud

    return data;
}

