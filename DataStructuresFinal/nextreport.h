#ifndef NEXTREPORT_H
#define NEXTREPORT_H

#include <QDialog>
#include "report.h"
#include <queue>

namespace Ui {
class nextreport;
}

class nextreport : public QDialog
{
    Q_OBJECT

public:
    nextreport(const Report nextReport, QWidget *parent = nullptr);
    ~nextreport();
private slots:
    void complete();
    void cancel();

private:
    Ui::nextreport *ui;
    void setValues();
    QString tempVehicleName;
    bool tempIsNecessary;
    int tempType;
    QString tempNotes;
};

#endif // NEXTREPORT_H
