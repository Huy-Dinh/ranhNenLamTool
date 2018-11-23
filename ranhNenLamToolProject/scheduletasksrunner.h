#ifndef SCHEDULEDTASKSRUNNER_H
#define SCHEDULEDTASKSRUNNER_H

#include <QAbstractListModel>
#include <QObject>
#include <QStringList>
#include <scheduledtask.h>
#include <QListView>
#include <QPushButton>
#include <QTimer>
#include <addscheduledtaskdialog.h>

class ScheduleTasksRunner : public QAbstractListModel
{
    Q_OBJECT
public:
    ScheduleTasksRunner(QObject *parent = nullptr,
                        QAbstractItemView *itemView = nullptr,
                        QPushButton *ActivateButton = nullptr,
                        QPushButton *AddButton = nullptr,
                        QPushButton *RemoveButton = nullptr);
    ~ScheduleTasksRunner();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
private:
    QList<ScheduledTask> mListOfTasks;
    QAbstractItemView* pItemView;
    QPushButton* pActivateButton;
    QPushButton* pAddButton;
    QPushButton* pRemoveButton;
    QTimer schedulerTimer;
    int mSelectedIndex;
    AddScheduledTaskDialog* pAddScheduledTaskDialog;

    void addScheduledTask(ScheduledTask inputTask);
    void removeTaskAt(int taskIndex);
    void updateActivateButton(int updateIndex);
public slots:
    void selectedIndexChange(const QModelIndex & current, const QModelIndex & previous);
    void activateButtonClicked();
    void addButtonClicked();
    void removeButtonClicked();
    void newTaskAdded(ScheduledTask newTask);
};

#endif // SCHEDULEDTASKSRUNNER_H
