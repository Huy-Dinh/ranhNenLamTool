#include "scheduledtask.h"

ScheduledTask::ScheduledTask(QTime scheduledTime, QString fileLocation, ScheduledTask::scheduledAction_t scheduledAction)
{
    mScheduledTime = scheduledTime;
    mFileLocation = fileLocation;
    mScheduledAction = scheduledAction;
}

QTime ScheduledTask::getScheduledTime()
{
    return mScheduledTime;
}

QString ScheduledTask::getFileLocation()
{
    return mFileLocation;
}

ScheduledTask::scheduledAction_t ScheduledTask::getAction()
{
    return mScheduledAction;
}

void ScheduledTask::setState(ScheduledTask::scheduleState_t scheduleState)
{
    mScheduleState = scheduleState;
}
