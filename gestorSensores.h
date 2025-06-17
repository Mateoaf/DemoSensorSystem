

#ifndef GESTOR_SENSORES_H
#define GESTOR_SENSORES_H

#include <vector>
#include <functional>
#include "sensor.h"
#include "sensorData.h"
using namespace std;

using SensorDataCallback = std::function<void(const SensorData&)>;
using SensorCalibratedCallback = std::function<void(const std::string& sensorId)>;

class GestorSensores {
    private:
        vector<Sensor*> sensores; // Vector de punteros a objetos Sensor
        vector<SensorData> dataHistory; // Vector para almacenar los datos de los sensores
        SensorDataCallback newDataCallback;
        SensorCalibratedCallback sensorCalibratedCallback;
    public:
        GestorSensores();
        ~GestorSensores();

        void agregarSensor(Sensor* sensor);
        void setNewDataCallback(SensorDataCallback callback);
        void setSensorCalibratedCallback(SensorCalibratedCallback callback);
        void leerTodosLosSensores();
        void calibrarTodosLosSensores();

        const std::vector<SensorData>& getDataHistory() const;
};

#endif
