#ifndef SCHEDULEDTASKCOLLECTION_H
#define SCHEDULEDTASKCOLLECTION_H

#include <QObject>
#include <scheduledtask.h>
#include <QStringListModel>
class SchedulerRunner
{
private:
    QStringListModel* pScheduleStringListModel;
    QStringList mScheduleStringList;
    QList<ScheduledTask> mScheduledTaskList;
    QString createStringFromTask(ScheduledTask scheduleTask);
    QString createStringAt(int i);
    void updateModelAt(int i);
public:
    SchedulerRunner(QWidget* parent);
    QStringListModel* getPointerToStringListModel();
    void addScheduleTask(ScheduledTask scheduledTask);
    void removeTaskAt(int i);
    ~SchedulerRunner();
};

#endif // SCHEDULEDTASKCOLLECTION_H
