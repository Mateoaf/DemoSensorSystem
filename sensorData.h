#ifndef SENSOR_DATA_HPP
#define SENSOR_DATA_HPP

#include <string>
#include <map>
#include <chrono> // Para el timestamp

// Para encasuplar datos de sensores
struct SensorData {
    std::string sensorId;
    std::string sensorType;
    double value;
    std::string units;
    long long timestamp; 
    std::map<std::string, double> additionalData; 

    SensorData(const std::string& id, const std::string& type, double val,
               const std::string& u, long long ts)
        : sensorId(id), sensorType(type), value(val), units(u), timestamp(ts) {}

    
    SensorData() : value(0.0), timestamp(0) {}
};

#endif 