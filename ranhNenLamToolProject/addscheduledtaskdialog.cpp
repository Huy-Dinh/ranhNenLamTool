#include "addscheduledtaskdialog.h"
#include "ui_addscheduledtaskdialog.h"
#include <QFileDialog>
#include "scheduledtask.h"

#define ACTION_COMBOBOX_OPEN_STRING     "Open"
#define ACTION_COMBOBOX_CLOSE_STRING    "Close"

AddScheduledTaskDialog::AddScheduledTaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScheduledTaskDialog)
{
    ui->setupUi(this);
    ui->actionCombobox->addItem(ACTION_COMBOBOX_OPEN_STRING);
    ui->actionCombobox->addItem(ACTION_COMBOBOX_CLOSE_STRING);
    this->setAttribute(Qt::WA_DeleteOnClose, false);
}

AddScheduledTaskDialog::~AddScheduledTaskDialog()
{
    delete ui;
}

void AddScheduledTaskDialog::on_buttonBox_accepted()
{
    mLastSelectedAction = ScheduledTask::ACTION_OPEN;
    mLastSelectedTime = ui->timeTimeEdit->time();
    mLastSelectedApplication = ui->applicationLineEdit->text();
    this->accept();
}

ScheduledTask AddScheduledTaskDialog::getNewScheduledTask()
{
    return ScheduledTask(mLastSelectedTime, mLastSelectedApplication, mLastSelectedAction);
}

void AddScheduledTaskDialog::getAllData(QTime& time, QString &appString, ScheduledTask::scheduledAction_t &action)
{
    time = mLastSelectedTime;
    appString = mLastSelectedApplication;
    action = mLastSelectedAction;
}

void AddScheduledTaskDialog::on_browseButton_clicked()
{
    QFileDialog fileDialog;
    if (fileDialog.exec())
        ui->applicationLineEdit->setText(fileDialog.selectedFiles().at(0));
}
