#include "gestorSensores.h"
#include "sensorGPS.h"

#include <iostream>
using namespace std;

GestorSensores::GestorSensores() {}

GestorSensores::~GestorSensores(){
    for (Sensor* s: sensores){
        delete s;
    }
    sensores.clear();
}

void GestorSensores::agregarSensor(Sensor* sensor) {
    sensores.push_back(sensor);
    cout << "Sensor de " << sensor->tipo << " (" << sensor->id << ") agregado." << endl;

}

void GestorSensores::leerTodosLosSensores() {
    cout << "Leyendo datos de todos los sensores " << endl;
    for (Sensor* s : sensores) {
        if (s -> tipo == "GPS") {
            SensorGPS* gps = static_cast<SensorGPS*>(s);
            pair<double, double> coords = gps->obtenerCoordenadas();
            cout << "[" << s->tipo << " " << s->id << "] Coordenadas: Latitud " << coords.first << ", Longitud " << coords.second << endl;
        } else {
            cout << "[" << s->tipo << " " << s->id << "] Dato: " << s->leerDato() << endl;
        }
    }
}

void GestorSensores::calibrarTodosLosSensores() {
    cout << "Calibrando todos los sensores " << endl;
    for (Sensor* s: sensores) {
        s->calibrar();
    }
}