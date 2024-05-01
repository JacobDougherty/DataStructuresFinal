#include "vehicle.h"

Vehicle::Vehicle(string make, string model, int priority): make(make), model(model), priority(priority) {}
Vehicle::~Vehicle(){}

string Vehicle::getMake() {return make;}

string Vehicle::getModel() {return model;}

int Vehicle::getPriority() {return priority;}

void Vehicle::setMake(string make) {this->make = make;}

void Vehicle::setModel(string model) {this->model = model;}

void Vehicle::setPriority(int priority) {this->priority = priority;}

string Vehicle::vehicleDetails() {
    string vehicleString = make + " "  + model;
    return vehicleString;
}
