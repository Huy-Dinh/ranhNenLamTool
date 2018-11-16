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
    //If the task is active
    if (mScheduleState == ScheduledTask::STATE_ACTIVE)
    {
        //And its time has come
        QTime currentTime = QTime::currentTime();
        if (currentTime.hour() == mScheduledTime.hour()
            &&  currentTime.minute() == mScheduledTime.minute()
            &&  currentTime.second() == mScheduledTime.second())
        {
            QString executableName = mFileLocation.mid(mFileLocation.lastIndexOf("\\") + 1);
            // Perform the scheduled action
            if (mScheduledAction == ScheduledTask::ACTION_CLOSE)
            {
                QProcess::startDetached("taskkill /im " + executableName + " /f");
            }
            else if (mScheduledAction == ScheduledTask::ACTION_OPEN)
            {
                QProcess::startDetached(mFileLocation);
            }
            //Auto deactivate itself
            mScheduleState = ScheduledTask::STATE_INACTIVE;
        }
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
