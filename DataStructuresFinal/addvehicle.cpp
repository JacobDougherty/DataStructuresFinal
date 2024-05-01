#include "addvehicle.h"
#include "ui_addvehicle.h"
addvehicle::addvehicle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addvehicle)
{
    ui->setupUi(this);

    ui->lowRadioButton->setChecked(true);
    tempPriority = 1;
}

addvehicle::~addvehicle()
{
    delete ui;
}

void addvehicle::makeEdited() {
    tempMake = ui->makeLineEdit->text();
}

void addvehicle::modelEdited() {
    tempModel = ui->modelLineEdit->text();
}

void addvehicle::lowChecked() {
    tempPriority = 1;
}

void addvehicle::medChecked() {
    tempPriority = 2;
}

void addvehicle::highChecked() {
    tempPriority = 3;
}

void addvehicle::add() {
    if (tempMake == NULL || tempModel == NULL || tempModel == "" || tempMake =="") {
        QDialog::reject();
    }
    else {
        QDialog::accept();
    }
}

