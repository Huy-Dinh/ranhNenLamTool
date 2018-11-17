#include "scheduletaskrunner.h"

ScheduleTasksRunner::ScheduleTasksRunner(QObject *parent,
                                         QListView *itemView,
                                         QPushButton *ActivateButton,
                                         QPushButton *AddButton,
                                         QPushButton *RemoveButton)
    : QAbstractListModel(parent)
{

}
int ScheduleTasksRunner::rowCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant ScheduleTasksRunner::data(const QModelIndex &index, int role) const
{
    return QVariant();
}

void ScheduleTasksRunner::viewIndexMoved(const QModelIndexList &indexes)
{

}

void ScheduleTasksRunner::activateButtonClicked()
{

}

void ScheduleTasksRunner::addButtonClicked()
{

}

void ScheduleTasksRunner::removeButtonClicked()
{

}
