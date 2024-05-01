#ifndef REPORT_H
#define REPORT_H
#include "vehicle.h"
// this class is the actual report
class Report
{
private:
    // vehicle problem belongs to
    Vehicle parentVehicle;
    // is it neccesary for operation
    bool necessary;
    // type of maintenance, will be selectable from options in ui
    int type;
    // user notes for when report is later retrieved
    string notes;
    // computes priority
    int priority;
public:
    Report(Vehicle parentVehicle, bool neccesary, int type, string notes);
    // constructor for reading saved content, doesnt compute priority on startup
    Report(Vehicle parentVehicle, bool neccesary, int type, string notes, int priority);
    ~Report();
    Vehicle getParentVehicle();
    bool getNeccesary();
    int getType();
    string getNotes();
    void setParentVehicle(Vehicle parentVehicle);
    void setNeccesary(bool neccesary);
    void setType(int type);
    void setNotes(string notes);
    int getPriority();
    void computePriority();
    bool operator<(const Report& r) const;

};

#endif // REPORT_H
