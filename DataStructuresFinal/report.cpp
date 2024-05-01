#include "report.h"

Report::Report(Vehicle parentVehicle, bool necessary, int type, string notes): parentVehicle(parentVehicle), necessary(necessary), type(type), notes(notes) {computePriority();}
Report::Report(Vehicle parentVehicle, bool necessary, int type, string notes, int priority): parentVehicle(parentVehicle), necessary(necessary), type(type), notes(notes),  priority(priority){}
Report::~Report(){};

Vehicle Report::getParentVehicle() {return parentVehicle;}

bool Report::getNeccesary() {return necessary;}

int Report::getType() {return type;}

string Report::getNotes() {return notes;}

int Report::getPriority() {return priority;}

void Report::setParentVehicle(Vehicle parentVehicle) {this->parentVehicle = parentVehicle;}

void Report::setNeccesary(bool necessary) {this->necessary = necessary;}

void Report::setType(int type) {this->type = type;}

void Report::setNotes(string notes) {this->notes = notes;}

void Report::computePriority() {
    int tempPriority = parentVehicle.getPriority();
    // halfs priority value if not necessary for maintenance
    if (!necessary) {
        tempPriority = tempPriority / 2;
    }
    // multiplies priority value by type of maintenance
    tempPriority = tempPriority * type;
    priority = tempPriority;
}

bool Report::operator<(const Report& r) const {
    return this->priority < r.priority;
}


