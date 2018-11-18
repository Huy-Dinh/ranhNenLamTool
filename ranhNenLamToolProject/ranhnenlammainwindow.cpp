#include "ranhnenlammainwindow.h"
#include "ui_ranhnenlammainwindow.h"
#include "profilelistmodel.h"

const uint LVM_FIRST = 0x1000;
const uint LVM_GETITEMCOUNT = LVM_FIRST + 4;
const uint LVM_GETITEMW = LVM_FIRST + 75;
const uint LVM_GETITEMPOSITION = LVM_FIRST + 16;
//const uint PROCESS_VM_OPERATION = 0x0008;
//const uint PROCESS_VM_READ = 0x0010;
//const uint PROCESS_VM_WRITE = 0x0020;
//const uint MEM_COMMIT = 0x1000;
//const uint MEM_RELEASE = 0x8000;
//const uint MEM_RESERVE = 0x2000;
//const uint PAGE_READWRITE = 4;
const int LVIF_TEXT = 0x0001;

ranhNenLamMainWindow::ranhNenLamMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ranhNenLamMainWindow)
{
    ui->setupUi(this);
    p_model = new ProfileListModel(this);
    ui->profileComboBox->setModel(p_model);
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
    if(arg1.contains("Activated")) ui->profileActivateButton->setText("Deactivate");
    else ui->profileActivateButton->setText("Activate");
    ui->profileActivateButton->update();
}

void ranhNenLamMainWindow::on_profileAddButton_clicked()
{

}

void ranhNenLamMainWindow::on_profileRemoveButton_clicked()
{
    int id = ui->profileComboBox->itemData(ui->profileComboBox->currentIndex(),p_model->IDRole).toInt();
    p_model->removeProfile(id);
    ui->profileComboBox->update();
}

void ranhNenLamMainWindow::on_profileEditButton_clicked()
{

}

void ranhNenLamMainWindow::on_profileActivateButton_clicked()
{
    int id = ui->profileComboBox->itemData(ui->profileComboBox->currentIndex(),p_model->IDRole).toInt();
    p_model->toggleActivation(id);

    if(ui->profileComboBox->currentText().contains("Activated")) ui->profileActivateButton->setText("Deactivate");
    else ui->profileActivateButton->setText("Activate");
    ui->profileActivateButton->update();
    ui->profileComboBox->update();
}

/************************************************
 * Icon Grouper UI Events
 ***********************************************/
void ranhNenLamMainWindow::on_iconCategorizeButton_clicked()
{

}

void ranhNenLamMainWindow::on_iconGroupButton_clicked()
{
    HWND vHandle = FindWindowA("Progman","Program Manager");
    vHandle = FindWindowExA(vHandle, NULL, "SHELLDLL_DefView", NULL);
    vHandle = FindWindowExA(vHandle, NULL, "SysListView32", "FolderView");

    //Get total count of the icons on the desktop
    int vItemCount = SendMessage(vHandle, LVM_GETITEMCOUNT, 0, 0);
    ui->profileAddButton->setText(QString::number(vItemCount));
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
