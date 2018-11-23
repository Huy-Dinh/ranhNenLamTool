#include "addscheduledtaskdialog.h"
#include "ui_addscheduledtaskdialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include "scheduledtask.h"

#define ACTION_COMBOBOX_OPEN_STRING     "Open"
#define ACTION_COMBOBOX_CLOSE_STRING    "Close"

const static QString fileTypeString = "Executable (*.exe, *.EXE)";

AddScheduledTaskDialog::AddScheduledTaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScheduledTaskDialog)
{
    ui->setupUi(this);
    ui->actionCombobox->addItem(ACTION_COMBOBOX_OPEN_STRING);
    ui->actionCombobox->addItem(ACTION_COMBOBOX_CLOSE_STRING);
}

AddScheduledTaskDialog::~AddScheduledTaskDialog()
{
    delete ui;
}

void AddScheduledTaskDialog::accept()
{
    QString selectedApplication = ui->applicationLineEdit->text();
    if (selectedApplication == "")
    {
        QMessageBox::warning(nullptr, "Warning", "No application selected");
    }
    else
    {
        QDialog::accept();
    }
}

void AddScheduledTaskDialog::on_buttonBox_accepted()
{
    ScheduledTask::scheduledAction_t scheduledAction = ScheduledTask::ACTION_OPEN;
    if (ui->actionCombobox->currentText() == ACTION_COMBOBOX_CLOSE_STRING)
    {
        scheduledAction = ScheduledTask::ACTION_CLOSE;
    }
    QTime scheduledTime = QTime(ui->timeTimeEdit->time());
    QString selectedApplication = ui->applicationLineEdit->text();
    if (selectedApplication != "")
    {
        emit(newTaskAdded(ScheduledTask(QTime(scheduledTime.hour(),
                                              scheduledTime.minute(),
                                              scheduledTime.second()),
                                        selectedApplication,
                                        scheduledAction)));
    }
}

void AddScheduledTaskDialog::on_browseButton_clicked()
{
    QFileDialog fileDialog;
    fileDialog.setNameFilter(fileTypeString);
    if (fileDialog.exec())
    {
        QString fileLocationText = fileDialog.selectedFiles().at(0);
        fileLocationText.replace("/", "\\");
        ui->applicationLineEdit->setText(fileLocationText);
    }
}
