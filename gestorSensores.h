

#ifndef GESTOR_SENSORES_H
#define GESTOR_SENSORES_H

#include <vector>

#include "sensor.h"
using namespace std;
class GestorSensores {
    private:
        vector<Sensor*> sensores; // Vector de punteros a objetos Sensor
    public:
        GestorSensores();
        ~GestorSensores();

        void agregarSensor(Sensor* sensor);
        void leerTodosLosSensores();
        void calibrarTodosLosSensores();
   
};

#endif
