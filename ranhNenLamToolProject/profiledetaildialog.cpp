#include "profiledetaildialog.h"
#include "ui_profiledetaildialog.h"
#include <qmessagebox.h>
ProfileDetailDialog::ProfileDetailDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfileDetailDialog)
{
    ui->setupUi(this);
    connect(this,SIGNAL(accepted()),this,SLOT(onProfileCreated()));
    this->setModal(true);
    this->setWindowTitle("Add new profile");
}

ProfileDetailDialog::ProfileDetailDialog(ProfileObject *p, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfileDetailDialog)
{
    this->setWindowTitle("Edit profile");
    this->setModal(true);
    ui->setupUi(this);

    ui->ProfileNameEdit->setText(p->profileName);

    if(p->listType==ProfileObject::black)
        ui->BlackListRadioButton->setChecked(true);
    else
        ui->WhitelistRadioButton->setChecked(true);
    if(p->checkActivated()) ui->ActivateNowCheckBox->setDisabled(true);
    connect(this,SIGNAL(accepted()),this,SLOT(onProfileEdited()));

}

ProfileDetailDialog::~ProfileDetailDialog()
{
    delete ui;
}


void ProfileDetailDialog::onProfileCreated(){
    QString pname = ui->ProfileNameEdit->text();
    if(pname.isEmpty())
    {
        QMessageBox::warning(this,"Missing profile name","Please input profile name");
    }
    else{
        if(ui->BlackListRadioButton->isChecked())
        {
            newProfile = new ProfileObject(pname,ProfileObject::black);
        }
        else
        {
            newProfile = new ProfileObject(pname,ProfileObject::white);
        }
        emit(this->profileCreated(newProfile,ui->ActivateNowCheckBox->isChecked()));
    }
}

void ProfileDetailDialog::onProfileEdited(){
    QString pname = ui->ProfileNameEdit->text();
    if(pname.isEmpty())
    {
        QMessageBox::warning(this,"Missing profile name","Please input profile name");
    }
    else{
        if(ui->BlackListRadioButton->isChecked())
        {
            newProfile = new ProfileObject(pname,ProfileObject::black);
        }
        else
        {
            newProfile = new ProfileObject(pname,ProfileObject::white);
        }
        emit(this->profileEdited(newProfile,ui->ActivateNowCheckBox->isChecked()));
    }
}
