#include "garage.h"

Garage::Garage(){}
Garage::~Garage(){}

void Garage::addVehicle(string make, string model, int priority) {
    Vehicle tempVehicle = Vehicle(make, model, priority);
    garageVector.push_back(tempVehicle);
}
void Garage::clear() {
    //erases save
    ofstream clear;
    clear.open("vehicleSave.txt", std::ofstream::out | std::ofstream::trunc);
    clear.close();
}

string Garage::validSave(string s) {
    // validifies string for csv
    string comma = ",";
    string newline = "\n";
    string toReplace = " ";

    size_t posC = s.find(comma);
    size_t posN = s.find(newline);
    while (posC != string::npos) {
        s.replace(posC, comma.size(), toReplace);
        posC = s.find(comma);
    }
    while (posN != string::npos) {
        s.replace(posC, comma.size(), toReplace);
        posN = s.find(newline);
    }
    return s;
}

void Garage::save() {
    //clears existing data, to ensure no duplicates are entered
    clear();
    fstream fout;
    fout.open("vehicleSave.txt", ios::out | ios::app);
    for (auto it = begin(garageVector); it != end(garageVector); it++) {
        // this is making sure csv wont be broken by input
        string tempMake = validSave(it->getMake());
        string tempModel = validSave(it->getModel());
        fout << tempMake << ","
             << tempModel << ","
             << it->getPriority() << endl;
    }
}

void Garage::readSave() {
    ifstream fin;
    fin.open("vehicleSave.txt");
    string line;
    if (fin.is_open()) {
        while (getline(fin, line)) {
            string delimiter = ",";
            string tempMake = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            string tempModel = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            string tempPriority = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            Vehicle tempVehicle = Vehicle(tempMake, tempModel, stoi(tempPriority));
            garageVector.push_back(tempVehicle);
        }

        fin.close();
    }

}
