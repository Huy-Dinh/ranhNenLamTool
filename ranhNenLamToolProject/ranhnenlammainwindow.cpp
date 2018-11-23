#include "ranhnenlammainwindow.h"
#include "ui_ranhnenlammainwindow.h"
#include <QStringListModel>
#include <QStringList>

HWND GetDesktopListViewHWND()
{
  HWND hDesktopListView = NULL;
  HWND hWorkerW = NULL;

  HWND hProgman = FindWindow(_T("Progman"), 0);
  HWND hDesktopWnd = GetDesktopWindow();

  // If the main Program Manager window is found
  if (hProgman)
  {
    // Get and load the main List view window containing the icons (found using Spy++).
    HWND hShellViewWin = FindWindowEx(hProgman, 0, _T("SHELLDLL_DefView"), 0);
    if (hShellViewWin)
      hDesktopListView = FindWindowEx(hShellViewWin, 0, _T("SysListView32"), 0);
    else
        // When this fails (happens in Windows-7 when picture rotation is turned ON), then look for the WorkerW windows list to get the
        // correct desktop list handle.
        // As there can be multiple WorkerW windows, so iterate through all to get the correct one
        do
        {
            hWorkerW = FindWindowEx( hDesktopWnd, hWorkerW, _T("WorkerW"), NULL );
            hShellViewWin = FindWindowEx(hWorkerW, 0, _T("SHELLDLL_DefView"), 0);
        } while (hShellViewWin == NULL && hWorkerW != NULL);

        // Get the ListView control
        hDesktopListView = FindWindowEx(hShellViewWin, 0, _T("SysListView32"), 0);
  }

  return hDesktopListView;
}
ranhNenLamMainWindow::ranhNenLamMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ranhNenLamMainWindow)
{
    ui->setupUi(this);
    p_model = new ProfileListModel(this, ui->profileComboBox, ui->profileActivateButton, ui->profileAddButton, ui->profileRemoveButton, ui->profileEditButton);
    pScheduleTaskRunner = new ScheduleTasksRunner(this, ui->scheduledTaskListView,
                                                  ui->schedulerToggleButton,
                                                  ui->schedulerAddButton,
                                                  ui->schedulerRemoveButton);
}

ranhNenLamMainWindow::~ranhNenLamMainWindow()
{
    delete ui;
    delete pScheduleTaskRunner;
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

    // get the handle of the desktop listview
    handleDesktopWindow = GetDesktopListViewHWND();
    qDebug() << ListView_GetItemCount(handleDesktopWindow);
    ListView_SetItemPosition(handleDesktopWindow, 10, 1000, 500);

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

