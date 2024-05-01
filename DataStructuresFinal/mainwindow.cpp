#include "mainwindow.h"
#include "ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);

    vehicleGarage = new Garage();
    reports = new ReportQueue();
    vehicleGarage->readSave();
    reports->readSave();
    list();

}

mainwindow::~mainwindow()
{
    delete ui;
    delete vehicleGarage;
    delete reports;
}

void mainwindow::addVehicleTab() {
    addVehicleMenu = new addvehicle(this);
    addVehicleMenu->setModal(true);
    int exec = addVehicleMenu->exec();
    if (exec == QDialog::Accepted) {
        vehicleGarage->addVehicle(addVehicleMenu->tempMake.toStdString(), addVehicleMenu->tempModel.toStdString(), addVehicleMenu->tempPriority);
        vehicleGarage->save();
    }
}

void mainwindow::addEntry() {
    addEntryMenu = new addentry(vehicleGarage->garageVector, this);
    addEntryMenu->setModal(true);
    int exec = addEntryMenu->exec();
    if (exec == QDialog::Accepted) {
        reports->addReport(addEntryMenu->tempVehicle, addEntryMenu->necessary, addEntryMenu->tempType, addEntryMenu->notes);
        reports->save();
        list();
    }
}

void mainwindow::nextEntry() {
    if (reports->reports.size() != 0) {
        nextEntryMenu = new nextreport(reports->reports.top(), this);
        nextEntryMenu->setModal(true);
        int exec = nextEntryMenu->exec();
        if (exec == QDialog::Accepted) {
            reports->reports.pop();
            reports->save();
            list();
        }
    }
}

void mainwindow::list() {
    QString Log;
    priority_queue<Report> tempQueue = reports->reports;
    ui->UpcomingLogs->clear();
    while (tempQueue.size() != 0) {
        Report tempReport = tempQueue.top();
        Vehicle tempVehicle = tempReport.getParentVehicle();
        Log = "Vehicle: " + QString::fromStdString(tempVehicle.getMake()) + " " + QString::fromStdString(tempVehicle.getModel()) + ",  Type: " + QString::number(tempReport.getType()) + ", Priority: " + QString::number(tempReport.getPriority());
        QListWidgetItem* tempItem = new QListWidgetItem();
        ui->UpcomingLogs->addItem(tempItem);
        tempItem->setText(Log);
        tempQueue.pop();
    }
}

void mainwindow::clearSave() {
    confirmClear = new confirm(this);
    confirmClear->setModal(true);
    int exec = confirmClear->exec();
    if (exec == QDialog::Accepted) {
        reports->clear();
        vehicleGarage->clear();
        ui->UpcomingLogs->clear();
    }
}
