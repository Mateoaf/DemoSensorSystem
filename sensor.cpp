#include "sensor.h"
#include <chrono>
#include <thread>
using namespace std;

Sensor::Sensor(const string& _id, const string& _tipo) : id(_id), tipo(_tipo) {}

void Sensor::calibrar(){
 cout << "[" << tipo << " " << id << "] Calibrando sensor..." << endl;

 this_thread::sleep_for(chrono::milliseconds(500)); // Simula un tiempo de calibración

 cout << "[" << tipo << " " << id << "] Calibracion completa." << endl;
}