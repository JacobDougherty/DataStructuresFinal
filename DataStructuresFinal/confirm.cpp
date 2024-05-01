#include "confirm.h"
#include "ui_confirm.h"

confirm::confirm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::confirm)
{
    ui->setupUi(this);
}

confirm::~confirm()
{
    delete ui;
}
