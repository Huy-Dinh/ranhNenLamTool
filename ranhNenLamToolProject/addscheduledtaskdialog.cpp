#include "addscheduledtaskdialog.h"
#include "ui_addscheduledtaskdialog.h"

AddScheduledTaskDialog::AddScheduledTaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScheduledTaskDialog)
{
    ui->setupUi(this);
}

AddScheduledTaskDialog::~AddScheduledTaskDialog()
{
    delete ui;
}
