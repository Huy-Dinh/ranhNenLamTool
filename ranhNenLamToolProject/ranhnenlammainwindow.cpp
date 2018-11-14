#include "ranhnenlammainwindow.h"
#include "ui_ranhnenlammainwindow.h"
#include <QStringListModel>
#include <QStringList>

ranhNenLamMainWindow::ranhNenLamMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ranhNenLamMainWindow)
{
    ui->setupUi(this);
    scheduledTaskCollection = new SchedulerRunner(this);
    ui->scheduledTaskListView->setModel(scheduledTaskCollection->getPointerToStringListModel());
}

ranhNenLamMainWindow::~ranhNenLamMainWindow()
{
    delete ui;
    delete scheduledTaskCollection;
}


/************************************************
 * Profile Selector UI Events
 ***********************************************/
void ranhNenLamMainWindow::on_profileComboBox_currentIndexChanged(const QString &arg1)
{

}

void ranhNenLamMainWindow::on_profileAddButton_clicked()
{

}

void ranhNenLamMainWindow::on_profileRemoveButton_clicked()
{

}

void ranhNenLamMainWindow::on_profileEditButton_clicked()
{

}

void ranhNenLamMainWindow::on_profileActivateButton_clicked()
{

}

/************************************************
 * Icon Grouper UI Events
 ***********************************************/
void ranhNenLamMainWindow::on_iconCategorizeButton_clicked()
{

}

void ranhNenLamMainWindow::on_iconGroupButton_clicked()
{

}

/************************************************
 * Scheduler UI Events
 ***********************************************/

void ranhNenLamMainWindow::on_schedulerAddButton_clicked()
{
    scheduledTaskCollection->addScheduleTask(ScheduledTask(QTime(10, 10, 10), "xyz", ScheduledTask::ACTION_OPEN));
}

void ranhNenLamMainWindow::on_schedulerRemoveButton_clicked()
{

}

void ranhNenLamMainWindow::on_schedulerToggleButton_clicked()
{

}

void ranhNenLamMainWindow::on_scheduledTaskListView_indexesMoved(const QModelIndexList &indexes)
{

}
