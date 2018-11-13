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
