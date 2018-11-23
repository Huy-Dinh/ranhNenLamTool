#ifndef ADDSCHEDULEDTASKDIALOG_H
#define ADDSCHEDULEDTASKDIALOG_H

#include <QDialog>
#include <scheduledtask.h>

namespace Ui {
class AddScheduledTaskDialog;
}

class AddScheduledTaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddScheduledTaskDialog(QWidget *parent = nullptr);
    ~AddScheduledTaskDialog();
    ScheduledTask getNewScheduledTask();
    void getAllData(QTime& time, QString &appString, ScheduledTask::scheduledAction_t &action);

private slots:
    void on_buttonBox_accepted();
    void on_browseButton_clicked();

private:
    QTime mLastSelectedTime;
    QString mLastSelectedApplication;
    ScheduledTask::scheduledAction_t mLastSelectedAction;
    Ui::AddScheduledTaskDialog *ui;
};

#endif // ADDSCHEDULEDTASKDIALOG_H
