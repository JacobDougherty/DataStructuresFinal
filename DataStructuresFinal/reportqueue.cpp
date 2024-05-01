#include "reportqueue.h"

ReportQueue::ReportQueue()
{

}

void ReportQueue::addReport(Vehicle parentVehicle, bool neccesary, int type, string notes) {
    Report tempReport = Report(parentVehicle, neccesary, type, notes);
    reports.push(tempReport);
}

void ReportQueue::clear() {
    //erases save
    ofstream clear;
    clear.open("reportSave.txt", std::ofstream::out | std::ofstream::trunc);
    clear.close();
}

string ReportQueue::validSave(string s) {
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

void ReportQueue::save() {
    //clears existing data, to ensure no duplicates are entered
    clear();
    fstream fout;
    fout.open("reportSave.txt", ios::out | ios::app);
    priority_queue<Report> tempQueue = reports;
    while (tempQueue.size() != 0) {
        Report tempReport = tempQueue.top();
        Vehicle tempVehicle = tempReport.getParentVehicle();
        tempQueue.pop();
        string tempMake = validSave(tempVehicle.getMake());
        string tempModel = validSave(tempVehicle.getModel());
        string tempNotes = validSave(tempReport.getNotes());
        fout << tempMake << ","
             << tempModel << ","
             << tempVehicle.getPriority() << ","
             << tempReport.getNeccesary() << ","
             << tempReport.getType() << ","
             << tempNotes << ","
             << tempReport.getPriority() << endl;
    }
}

void ReportQueue::readSave() {
    ifstream fin;
    fin.open("reportSave.txt");
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
            string tempNecessary = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            string tempType = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            string tempNotes = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            string tempRepPriority= line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());

            Report tempReport = Report(tempVehicle, toBool(tempNecessary), stoi(tempType), tempNotes, stod(tempRepPriority));
            reports.push(tempReport);
        }

        fin.close();
    }

}

bool ReportQueue::toBool(string const& s) {
    return s != "0" && s != "false";
}
