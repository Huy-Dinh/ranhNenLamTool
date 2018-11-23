#ifndef RANHNENLAMMAINWINDOW_H
#define RANHNENLAMMAINWINDOW_H

#include <QMainWindow>
#include <QModelIndexList>
#include "Windows.h"
#include "WinUser.h"
#include "CommCtrl.h"
#include "qdebug.h"
#include "tchar.h"
#include <scheduletasksrunner.h>
#include "profilelistmodel.h"
#include "profiledetaildialog.h"

namespace Ui {
class ranhNenLamMainWindow;
}

class ranhNenLamMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ranhNenLamMainWindow(QWidget *parent = nullptr);
    ~ranhNenLamMainWindow();

private slots:
    void on_profileComboBox_currentIndexChanged(const QString &arg1);

    void on_profileAddButton_clicked();

    void on_profileRemoveButton_clicked();

    void on_profileEditButton_clicked();

    void on_profileActivateButton_clicked();

    void on_iconCategorizeButton_clicked();

    void on_iconGroupButton_clicked();

    void on_schedulerAddButton_clicked();

    void on_schedulerRemoveButton_clicked();

    void on_schedulerToggleButton_clicked();

    void on_scheduledTaskListView_indexesMoved(const QModelIndexList &indexes);

private:
    Ui::ranhNenLamMainWindow *ui;
    HWND handleDesktopWindow;
    ScheduleTasksRunner *pScheduleTaskRunner;
    ProfileListModel *p_model;
};

#endif // RANHNENLAMMAINWINDOW_H
