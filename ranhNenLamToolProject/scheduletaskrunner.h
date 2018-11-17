#ifndef SCHEDULETASKRUNNER_H
#define SCHEDULETASKRUNNER_H


#ifndef SCHEDULEDTASKSRUNNER_H
#define SCHEDULEDTASKSRUNNER_H

#include <QAbstractListModel>
#include <QObject>
#include <QStringList>
#include <scheduledtask.h>
#include <QListView>
#include <QPushButton>
#include <QTimer>

class ScheduleTasksRunner : public QAbstractListModel
{
    Q_OBJECT
public:
    ScheduleTasksRunner(QObject *parent = NULL,
                        QListView *itemView = NULL,
                        QPushButton *ActivateButton = NULL,
                        QPushButton *AddButton = NULL,
                        QPushButton *RemoveButton = NULL);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    void addScheduledTask(ScheduledTask inputTask);
    void removeTaskAt(int taskIndex);
private:
    QList<ScheduledTask> mListOfTasks;
    QAbstractItemView* pItemView;
    QPushButton* pActivateButton;
    QPushButton* pAddButton;
    QPushButton* pRemoveButton;
    QTimer schedulerTimer;
public slots:
    void viewIndexMoved(const QModelIndexList &indexes);
    void activateButtonClicked();
    void addButtonClicked();
    void removeButtonClicked();
};

#endif // SCHEDULEDTASKSRUNNER_H
#endif // SCHEDULETASKRUNNER_H
