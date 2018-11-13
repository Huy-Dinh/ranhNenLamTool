#include "scheduledtaskcollection.h"

ScheduledTaskCollection::ScheduledTaskCollection(QWidget* parent)
{
    pScheduleStringListModel = new QStringListModel(parent);
    pScheduleStringListModel->setStringList(mScheduleStringList);
}

QStringListModel* ScheduledTaskCollection::getPointerToStringListModel()
{
    return pScheduleStringListModel;
}

void ScheduledTaskCollection::addScheduleTask(ScheduledTask scheduledTask)
{
    mScheduledTaskList.append(scheduledTask);
    mScheduleStringList << scheduledTask.getFileLocation();
    pScheduleStringListModel->setStringList(mScheduleStringList);
}

void ScheduledTaskCollection::removeTaskAt(int i)
{
    mScheduledTaskList.removeAt(i);
    mScheduleStringList.removeAt(i);
}

ScheduledTaskCollection::~ScheduledTaskCollection()
{
    delete pScheduleStringListModel;
}
