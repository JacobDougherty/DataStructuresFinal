#ifndef REPORTQUEUE_H
#define REPORTQUEUE_H
#include "report.h"
#include <queue>
#include <fstream>
// this class includes the report queue
using namespace std;
class ReportQueue
{
public:
    priority_queue<Report> reports;
    ReportQueue();
    void addReport(Vehicle parentVehicle, bool neccesary, int type, string notes);
    void save();
    void readSave();
    void clear();
private:
    bool toBool(string const& s);
    string validSave(string s);
};

#endif // REPORTQUEUE_H
