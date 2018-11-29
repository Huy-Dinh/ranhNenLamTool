#ifndef SCHEDULEDTASK_H
#define SCHEDULEDTASK_H

#include <QObject>
#include <QWidget>
#include <QTime>
#include <QProcess>

class ScheduledTask
{
    friend class ScheduleTasksRunner;
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
    QString mArguments;
    scheduledAction_t mScheduledAction;
    scheduleState_t mScheduleState;
    QProcess *pProcess;
public:
    ScheduledTask(QTime scheduledTime, QString fileLocation, scheduledAction_t scheduledAction, QString arguments);
    ~ScheduledTask();
    void run();
    void setState(scheduleState_t scheduleState);
};

#endif // SCHEDULEDTASK_H
