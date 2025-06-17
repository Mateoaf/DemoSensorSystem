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

void GestorSensores::setNewDataCallback(SensorDataCallback callback) {
    newDataCallback = callback;
}

void GestorSensores::setSensorCalibratedCallback(SensorCalibratedCallback callback) {
    sensorCalibratedCallback = callback;
}

void GestorSensores::leerTodosLosSensores() {
    cout << "Leyendo datos de todos los sensores " << endl;
    for (Sensor* s : sensores) {
         SensorData data = s->leerDato();
        dataHistory.push_back(data);

        // Notificar a la UI (o cualquier suscriptor)
        if (newDataCallback) {
            newDataCallback(data);
        }
    }
    std::cout << "Lectura terminada" << std::endl;
    }


void GestorSensores::calibrarTodosLosSensores() {
    cout << "Calibrando todos los sensores " << endl;
    for (Sensor* s: sensores) {
        if (sensorCalibratedCallback) {
            sensorCalibratedCallback(s->id); // El gestor notifica cuando un sensor ha terminado de calibrarse
        }
    }
    cout << "Calibracion de todos los sensores completada." << endl;
}

const vector<SensorData>& GestorSensores::getDataHistory() const {
    return dataHistory;
}