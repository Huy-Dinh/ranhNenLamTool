#include "profiledetaildialog.h"
#include "ui_profiledetaildialog.h"
#include <qmessagebox.h>
ProfileDetailDialog::ProfileDetailDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfileDetailDialog)
{
    ui->setupUi(this);
}

ProfileDetailDialog::~ProfileDetailDialog()
{
    delete ui;
}

