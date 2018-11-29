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

void AddScheduledTaskDialog::on_browseButton_clicked()
{
    QFileDialog fileDialog;
    fileDialog.setNameFilter(fileTypeString);
    if (fileDialog.exec())
    {
        QString fileLocationText = fileDialog.selectedFiles().at(0);
        fileLocationText.replace("/", "\\");
        ui->applicationTextEdit->setText(fileLocationText);
    }
}

void AddScheduledTaskDialog::on_scheduleButton_clicked()
{
    ScheduledTask::scheduledAction_t scheduledAction = ScheduledTask::ACTION_OPEN;
    if (ui->actionCombobox->currentText() == ACTION_COMBOBOX_CLOSE_STRING)
    {
        scheduledAction = ScheduledTask::ACTION_CLOSE;
    }
    QTime scheduledTime = ui->timeTimeEdit->time();
    QString selectedApplication = ui->applicationTextEdit->toPlainText();
    QString inputArguments = ui->argumentLineEdit->text();
    if (selectedApplication != "")
    {
        emit(newTaskAdded(ScheduledTask(scheduledTime,
                                        selectedApplication,
                                        scheduledAction,
                                        inputArguments)));
        accept();
    }
    else
    {
        QMessageBox::warning(nullptr, "Warning", "No application selected");
    }
}

void AddScheduledTaskDialog::on_cancelButton_clicked()
{
    reject();
}
