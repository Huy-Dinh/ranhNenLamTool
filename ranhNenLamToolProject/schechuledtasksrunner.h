#ifndef SCHECHULEDTASKSRUNNER_H
#define SCHECHULEDTASKSRUNNER_H

#include <QAbstractListModel>

class SchechuledTasksRunner : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit SchechuledTasksRunner(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SCHECHULEDTASKSRUNNER_H
