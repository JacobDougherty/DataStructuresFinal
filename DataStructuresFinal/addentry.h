#ifndef ADDENTRY_H
#define ADDENTRY_H
#include "vehicle.h"
#include <QDialog>

namespace Ui {
class addentry;
}

class addentry : public QDialog
{
    Q_OBJECT

public:
    addentry(const vector<Vehicle> garage, QWidget *parent = nullptr);
    ~addentry();
    int tempType;
    Vehicle tempVehicle = Vehicle("", "", 0);
    bool necessary;
    string notes;
private slots:
    void upkeepChecked();
    void cosmeticChecked();
    void fixingChecked();
    void add();

private:
    Ui::addentry *ui;
    vector<Vehicle> tempGarage;
};

#endif // ADDENTRY_H
