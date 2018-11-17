#include "scheduletasksrunner.h"

ScheduleTasksRunner::ScheduleTasksRunner(QObject *parent,
                                         QListView *itemView,
                                         QPushButton *ActivateButton,
                                         QPushButton *AddButton,
                                         QPushButton *RemoveButton)
    : QAbstractListModel(parent)
{
    pItemView = itemView;
    //pItemView->setModel(this);
}

int ScheduleTasksRunner::rowCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant ScheduleTasksRunner::data(const QModelIndex &index, int role) const
{
    if (index.isValid())
    {
        return "AA";
    }
    else
    {
        QVariant();
    }
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
