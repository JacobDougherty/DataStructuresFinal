#include "addentry.h"
#include "ui_addentry.h"


addentry::addentry(vector<Vehicle> garage, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addentry)
{
    ui->setupUi(this);
    ui->cosmeticRadioButton->setChecked(true);
    tempType = 1;

    for (int i=0; i < garage.size(); i++) {
        ui->VehiclecomboBox->addItem(QString::fromStdString(garage[i].getModel()));
    }

    tempGarage = garage;
}

addentry::~addentry()
{
    delete ui;
}

void addentry::cosmeticChecked() {
    tempType = 1;
}

void addentry::upkeepChecked() {
    tempType = 2;
}

void addentry::fixingChecked() {
    tempType = 3;
}

void addentry::add() {
    if (tempGarage.size() == 0) {
        QDialog::reject();
    }
    else {
        for (auto it = begin(tempGarage); it != end(tempGarage); it++) {
            if (it->getModel() == ui->VehiclecomboBox->currentText().toStdString()) {
                tempVehicle = Vehicle(it->getMake(), it->getModel(), it->getPriority());
            }
        }
        necessary = ui->OpNeccesary->isChecked();
        string tempString = ui->notesTextEdit->toPlainText().toStdString();
        notes = tempString;
        QDialog::accept();
    }
}
