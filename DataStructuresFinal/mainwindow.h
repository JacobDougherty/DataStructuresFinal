#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QLineEdit>
#include <QSlider>
#include <QGraphicsRectItem>
#include "addvehicle.h"
#include "garage.h"
#include "reportqueue.h"
#include "addentry.h"
#include "nextreport.h"
#include "confirm.h"
namespace Ui {
class mainwindow;
}

class mainwindow : public QWidget
{
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

private slots:
    void addEntry();
    void addVehicleTab();
    void nextEntry();
    void clearSave();

private:
    Ui::mainwindow *ui;
    addvehicle *addVehicleMenu;
    Garage *vehicleGarage;
    ReportQueue *reports;
    addentry *addEntryMenu;
    nextreport *nextEntryMenu;
    confirm *confirmClear;
    void list();
};

#endif // MAINWINDOW_H
