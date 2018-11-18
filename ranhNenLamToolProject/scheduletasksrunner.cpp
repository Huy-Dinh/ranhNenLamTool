#include "scheduletasksrunner.h"

ScheduleTasksRunner::ScheduleTasksRunner(QObject *parent,
                                         QListView *itemView,
                                         QPushButton *ActivateButton,
                                         QPushButton *AddButton,
                                         QPushButton *RemoveButton)
    : QAbstractListModel(parent)
{
    pItemView = itemView;
    pAddButton = AddButton;
    pActivateButton = ActivateButton;
    pRemoveButton = RemoveButton;

    if (pItemView != NULL)
    {
        pItemView->setModel(this);
    }
    if (pAddButton != NULL)
        connect(pAddButton, SIGNAL(clicked()), this, SLOT(addButtonClicked()));
    if (pActivateButton != NULL)
    {

    }


}

int ScheduleTasksRunner::rowCount(const QModelIndex &parent) const
{
    return mListOfTasks.count();
}

QVariant ScheduleTasksRunner::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= mListOfTasks.count())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        ScheduledTask displayedTask = mListOfTasks.at(index.row());
        QString displayedString = "";
        if (displayedTask.mScheduleState == ScheduledTask::STATE_ACTIVE)
        {
            displayedString += "(A) ";
        }
        else
        {
            displayedString += "(D) ";
        }
        displayedString += displayedTask.mScheduledTime.toString();
        displayedString += " ";
        return displayedString;
    }
    else
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
    beginInsertRows(QModelIndex(), mListOfTasks.count(),mListOfTasks.count());
    mListOfTasks.append(ScheduledTask(QTime(10, 10, 10), "xadsdd", ScheduledTask::ACTION_OPEN));
    endInsertRows();
}

void ScheduleTasksRunner::removeButtonClicked()
{

}
