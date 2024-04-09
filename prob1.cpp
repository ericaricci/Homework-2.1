#include <iostream>
#include <string>
#include <vector>

//sourced from chatgpt
// Abstract base class for Sensor
class Sensor {
public:
    virtual void gatherData() = 0;
    virtual void processData() = 0;
};

// Derived class for TemperatureSensor
class TemperatureSensor : public Sensor {
public:
    void gatherData() override {
        std::cout << "Gathering data from Temperature Sensor." << std::endl;
    }

    void processData() override {
        std::cout << "Processing data from Temperature Sensor." << std::endl;
    }
};

// Derived class for PressureSensor
class PressureSensor : public Sensor {
public:
    void gatherData() override {
        std::cout << "Gathering data from Pressure Sensor." << std::endl;
    }

    void processData() override {
        std::cout << "Processing data from Pressure Sensor." << std::endl;
    }
};

// Derived class for PositionSensor
class PositionSensor : public Sensor {
public:
    void gatherData() override {
        std::cout << "Gathering data from Position Sensor." << std::endl;
    }

    void processData() override {
        std::cout << "Processing data from Position Sensor." << std::endl;
    }
};

// SensorFactory class
class SensorFactory {
public:
    static Sensor* createSensor(const std::string& sensorType) {
        if (sensorType == "Temperature") {
            return new TemperatureSensor();
        }
        else if (sensorType == "Pressure") {
            return new PressureSensor();
        }
        else if (sensorType == "Position") {
            return new PositionSensor();
        }
        else {
            return nullptr;
        }
    }
};

// AerospaceControlSystem class
class AerospaceControlSystem {
private:
    std::vector<Sensor*> sensors;

public:
    void addSensor(Sensor* sensor) {
        sensors.push_back(sensor);
    }

    void monitorAndAdjust() {
        for (auto sensor : sensors) {
            sensor->gatherData();
            sensor->processData();
        }
        std::cout << "Adjusting controls based on sensor data." << std::endl;
    }
};

int main() {
    AerospaceControlSystem ctrlSys;
    ctrlSys.addSensor(SensorFactory::createSensor("Temperature"));
    ctrlSys.addSensor(SensorFactory::createSensor("Pressure"));
    ctrlSys.addSensor(SensorFactory::createSensor("Position"));

    ctrlSys.monitorAndAdjust();

    return 0;
}