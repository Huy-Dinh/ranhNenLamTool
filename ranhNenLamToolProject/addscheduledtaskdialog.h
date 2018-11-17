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

private:
    QTime lastSelectedTime;
    QString lastSelectedApplication;
    ScheduledTask::scheduledAction_t lastSelectedAction;
    Ui::AddScheduledTaskDialog *ui;
};

#endif // ADDSCHEDULEDTASKDIALOG_H
