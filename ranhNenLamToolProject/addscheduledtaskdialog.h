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
    void on_browseButton_clicked();
    void on_scheduleButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::AddScheduledTaskDialog *ui;

signals:
    void newTaskAdded(const QTime& time,
                      const QString& appString,
                      const ScheduledTask::scheduledAction_t& action,
                      const QString& arguments);
};

#endif // ADDSCHEDULEDTASKDIALOG_H
