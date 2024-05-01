#ifndef GARAGE_H
#define GARAGE_H
#include "vehicle.h"
#include <vector>
#include <fstream>
// this class will be used for selecting what vehicle the report will be based on
class Garage
{

public:
    Garage();
    ~Garage();
    void addVehicle(string make, string model, int priority);
    vector<Vehicle> garageVector;
    void clear();
    void save();
    void readSave();
private:
    string validSave(string s);
};

#endif // GARAGE_H
