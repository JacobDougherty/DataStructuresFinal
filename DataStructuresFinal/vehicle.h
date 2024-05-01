#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
using namespace std;
// this class is the details for the vehicle
class Vehicle
{
private:
    string make;
    string model;
    int priority;
public:
    Vehicle(string make, string model, int priority);
    ~Vehicle();
    string getMake();
    string getModel();
    int getPriority();
    void setMake(string make);
    void setModel(string model);
    void setPriority(int priority);
    string vehicleDetails();
};

#endif // VEHICLE_H
