#ifndef SCHEDULEDTASKCOLLECTION_H
#define SCHEDULEDTASKCOLLECTION_H

#include <QObject>
#include <scheduledtask.h>
#include <QStringListModel>
class ScheduledTaskCollection
{
private:
    QStringListModel* pScheduleStringListModel;
    QStringList mScheduleStringList;
    QList<ScheduledTask> mScheduledTaskList;

public:
    ScheduledTaskCollection(QWidget* parent);
    QStringListModel* getPointerToStringListModel();
    void addScheduleTask(ScheduledTask scheduledTask);
    void removeTaskAt(int i);
    ~ScheduledTaskCollection();
};

#endif // SCHEDULEDTASKCOLLECTION_H
