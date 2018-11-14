#include "schedulerrunner.h"

SchedulerRunner::SchedulerRunner(QWidget* parent)
{
    pScheduleStringListModel = new QStringListModel(parent);
    pScheduleStringListModel->setStringList(mScheduleStringList);
}

QString SchedulerRunner::createStringFromTask(ScheduledTask scheduleTask)
{
    QString returnString;
    QString actionString;
    QString stateString;
    if (scheduleTask.getAction() == ScheduledTask::ACTION_OPEN)
    {
        actionString = "Open";
    }
    else
    {
        actionString = "Close";
    }
    if (scheduleTask.getState() == ScheduledTask::STATE_ACTIVE)
    {
        stateString = "(A)";
    }
    else
    {
        stateString = "(D)";
    }
    returnString += scheduleTask.getScheduledTime().toString() + " ";
    returnString += actionString + " ";
    returnString += scheduleTask.getFileLocation() + " ";
    returnString += stateString;
    return returnString;
}
QString SchedulerRunner::createStringAt(int i)
{
    return createStringFromTask(mScheduledTaskList[i]);
}

void SchedulerRunner::updateModelAt(int i)
{
    mScheduleStringList[i] = createStringAt(i);
    pScheduleStringListModel->setStringList(mScheduleStringList);
}

QStringListModel* SchedulerRunner::getPointerToStringListModel()
{
    return pScheduleStringListModel;
}

void SchedulerRunner::addScheduleTask(ScheduledTask scheduledTask)
{
    mScheduledTaskList.append(scheduledTask);
    mScheduleStringList << createStringFromTask(scheduledTask);
    pScheduleStringListModel->setStringList(mScheduleStringList);
}

void SchedulerRunner::removeTaskAt(int i)
{
    mScheduledTaskList.removeAt(i);
    mScheduleStringList.removeAt(i);
}

SchedulerRunner::~SchedulerRunner()
{
    delete pScheduleStringListModel;
}
