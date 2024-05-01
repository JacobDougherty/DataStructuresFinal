#ifndef ADDVEHICLE_H
#define ADDVEHICLE_H

#include <QDialog>

namespace Ui {
class addvehicle;
}

class addvehicle : public QDialog
{
    Q_OBJECT

public:
    explicit addvehicle(QWidget *parent = nullptr);
    ~addvehicle();
    QString tempMake;
    QString tempModel;
    int tempPriority;

private slots:
    void makeEdited();
    void modelEdited();
    void lowChecked();
    void medChecked();
    void highChecked();
    void add();

private:
    Ui::addvehicle *ui;
};

#endif // ADDVEHICLE_H
