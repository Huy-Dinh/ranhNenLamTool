#include "scheduletasksrunner.h"
#include "addscheduledtaskdialog.h"

#define ACT_BUTTON_ACT_STRING   "Activate"
#define ACT_BUTTON_DEACT_STRING "Deactivate"

ScheduleTasksRunner::ScheduleTasksRunner(QObject *parent,
                                         QAbstractItemView *itemView,
                                         QPushButton *ActivateButton,
                                         QPushButton *AddButton,
                                         QPushButton *RemoveButton)
    : QAbstractListModel(parent)
{
    pItemView = itemView;
    pAddButton = AddButton;
    pActivateButton = ActivateButton;
    pRemoveButton = RemoveButton;
    pAddScheduledTaskDialog = new AddScheduledTaskDialog();
    // Set the model to the ItemView, allows the content to be displayed
    // register the slot for viewIndexMoved
    if (pItemView != nullptr)
    {
        pItemView->setModel(this);
        connect(pItemView->selectionModel(), SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)),
                this, SLOT(selectedIndexChange(const QModelIndex &, const QModelIndex &)));
    }
    // Register slots
    if (pAddButton != nullptr)
    {
        connect(pAddButton, SIGNAL(clicked()), this, SLOT(addButtonClicked()));
    }
    if (pActivateButton != nullptr)
    {
        connect(pActivateButton, SIGNAL(clicked()), this, SLOT(activateButtonClicked()));
        pActivateButton->setEnabled(false); // Always disable the activate button the first time
    }
    if (pRemoveButton != nullptr)
    {
        connect(pRemoveButton, SIGNAL(clicked()), this, SLOT(removeButtonClicked()));
        pRemoveButton->setEnabled(false);
    }
    connect(pAddScheduledTaskDialog, SIGNAL(newTaskAdded(ScheduledTask)), this, SLOT(newTaskAdded(ScheduledTask)));
    connect(&schedulerTimer, SIGNAL(timeout()), this, SLOT(cyclicTaskRunner()));
    schedulerTimer.start(1000);
}

ScheduleTasksRunner::~ScheduleTasksRunner()
{
    delete pAddScheduledTaskDialog;
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
        if (displayedTask.mScheduledAction == ScheduledTask::ACTION_OPEN)
            displayedString += "Open ";
        else
            displayedString += "Close ";
        displayedString += displayedTask.mFileLocation.mid(displayedTask.mFileLocation.lastIndexOf("\\") + 1);
        return displayedString;
    }
    else
        return QVariant();
}

void ScheduleTasksRunner::selectedIndexChange(const QModelIndex & current, const QModelIndex & previous)
{
    if (current.isValid())
    {
        int selectedIndex = current.row();
        updateActivateButton(selectedIndex);
        if (pRemoveButton != nullptr)
        {
            pRemoveButton->setEnabled(true);
        }
    }
}

void ScheduleTasksRunner::activateButtonClicked()
{
    int selectedIndex = pItemView->selectionModel()->selectedRows().at(0).row();
    if (pActivateButton->isEnabled())
    {
        if (mListOfTasks.at(selectedIndex).mScheduleState == ScheduledTask::STATE_ACTIVE)
        {
            mListOfTasks[selectedIndex].setState(ScheduledTask::STATE_INACTIVE);
        }
        else
        {
            mListOfTasks[selectedIndex].setState(ScheduledTask::STATE_ACTIVE);
        }
        updateActivateButton(selectedIndex);
        QModelIndex currentIndex = createIndex(selectedIndex, 0);
        emit dataChanged(currentIndex,currentIndex);
    }
}

void ScheduleTasksRunner::addButtonClicked()
{
    pAddScheduledTaskDialog->exec();
}

void ScheduleTasksRunner::removeButtonClicked()
{
    // mSelectedIndex does not work here since it will ignore
    // the changes made by the last removal process
    int selectedIndex = pItemView->selectionModel()->selectedRows().at(0).row();
    beginRemoveRows(QModelIndex(), selectedIndex, selectedIndex);
    mListOfTasks.removeAt(selectedIndex);
    endRemoveRows();
    if (mListOfTasks.count() == 0)
    {
        pRemoveButton->setEnabled(false);
        if (pActivateButton != nullptr)
        {
            pActivateButton->setEnabled(false);
        }
    }
}

void ScheduleTasksRunner::updateActivateButton(int updateIndex)
{
    if (pActivateButton != nullptr)
    {
        pActivateButton->setEnabled(true);
        if (mListOfTasks.at(updateIndex).mScheduleState == ScheduledTask::STATE_ACTIVE)
        {
            pActivateButton->setText(ACT_BUTTON_DEACT_STRING);
        }
        else
        {
            pActivateButton->setText(ACT_BUTTON_ACT_STRING);
        }
    }
}

void ScheduleTasksRunner::newTaskAdded(ScheduledTask newTask)
{
    beginInsertRows(QModelIndex(), mListOfTasks.count(),mListOfTasks.count());
    mListOfTasks.append(newTask);
    endInsertRows();
}

void ScheduleTasksRunner::cyclicTaskRunner()
{
    for (int i = 0; i < mListOfTasks.count(); ++i)
    {
        mListOfTasks[i].run();
    }
}
