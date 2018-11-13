#include "ranhnenlammainwindow.h"
#include "ui_ranhnenlammainwindow.h"

ranhNenLamMainWindow::ranhNenLamMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ranhNenLamMainWindow)
{
    ui->setupUi(this);
}

ranhNenLamMainWindow::~ranhNenLamMainWindow()
{
    delete ui;
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
