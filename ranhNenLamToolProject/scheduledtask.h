#ifndef SCHEDULEDTASK_H
#define SCHEDULEDTASK_H

#include <QObject>
#include <QWidget>
#include <QTime>


class ScheduledTask
{
public:
    typedef enum
    {
        ACTION_OPEN,
        ACTION_CLOSE,
        ACTION_INVALID
    } scheduledAction_t;
    typedef enum
    {
        STATE_ACTIVE,
        STATE_INACTIVE,
        STATE_INVALID
    } scheduleState_t;

private:
    QTime mScheduledTime;
    QString mFileLocation;
    scheduledAction_t mScheduledAction;
    scheduleState_t mScheduleState;
public:
    ScheduledTask(QTime scheduledTime, QString fileLocation, scheduledAction_t scheduledAction);
    QTime getScheduledTime();
    QString getFileLocation();
    scheduledAction_t getAction();
    void setState(scheduleState_t scheduleState);
};

#endif // SCHEDULEDTASK_H
