#include "scheduledtask.h"
ScheduledTask::ScheduledTask(QTime scheduledTime, QString fileLocation, ScheduledTask::scheduledAction_t scheduledAction)
{
    mScheduledTime = scheduledTime;
    mFileLocation = fileLocation;
    mScheduledAction = scheduledAction;
    mScheduleState = ScheduledTask::STATE_ACTIVE;
}

void ScheduledTask::run()
{
    if (mScheduleState == ScheduledTask::STATE_ACTIVE)
    {
        QString executableName = mFileLocation.mid(mFileLocation.lastIndexOf("\\") + 1);
        if (mScheduledAction == ScheduledTask::ACTION_CLOSE)
        {
            QProcess::startDetached("taskkill /im " + executableName + " /f");
        }
        else if (mScheduledAction == ScheduledTask::ACTION_OPEN)
        {
            QProcess::startDetached(mFileLocation);
        }
        //Auto deactivate itself

    }
}

void ScheduledTask::setState(ScheduledTask::scheduleState_t scheduleState)
{
    mScheduleState = scheduleState;
}

ScheduledTask::~ScheduledTask()
{
  delete pProcess;
}
