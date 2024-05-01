#include "nextreport.h"
#include "ui_nextreport.h"

nextreport::nextreport(Report nextReport, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nextreport)
{
    ui->setupUi(this);
    tempVehicleName = QString::fromStdString(nextReport.getParentVehicle().getMake() + " " + nextReport.getParentVehicle().getModel());
    tempIsNecessary = nextReport.getNeccesary();
    tempType = nextReport.getType();
    tempNotes = QString::fromStdString(nextReport.getNotes());

    setValues();
}

nextreport::~nextreport()
{
    delete ui;
}

void nextreport::setValues() {
    ui->selectedVehicle->setText(tempVehicleName);
    if (tempIsNecessary) {
        ui->selectedNecessary->setText("Yes");
    }
    else if (!tempIsNecessary) {
        ui->selectedNecessary->setText("No");
    }

    if (tempType == 1) {
        ui->selectedMaintenance->setText("Cosmetic");
    }
    else if (tempType == 2) {
        ui->selectedMaintenance->setText("Upkeep");
    }
    else if (tempType == 3) {
        ui->selectedMaintenance->setText("Fixing");
    }
    else {
        ui->selectedMaintenance->setText("You shouldn't see this - bug in setValues");
    }
    ui->notesBrowser->setText(tempNotes);
}

void nextreport::complete() {
    QDialog::accept();
}

void nextreport::cancel() {
    QDialog::reject();
}
