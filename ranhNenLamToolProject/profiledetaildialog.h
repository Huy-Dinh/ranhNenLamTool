#ifndef PROFILEDETAILDIALOG_H
#define PROFILEDETAILDIALOG_H

#include <QDialog>
#include "profileobject.h"
namespace Ui {
class ProfileDetailDialog;
}

class ProfileDetailDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileDetailDialog(QWidget *parent = nullptr);
    explicit ProfileDetailDialog(ProfileObject *p , QWidget *parent = nullptr);
    ~ProfileDetailDialog();

signals:
    void profileCreated(ProfileObject* p, bool activateNow);
    void profileEdited(ProfileObject* p, bool activateNow);
private slots:
    void onProfileCreated();
    void onProfileEdited();
    //void on_Dialog_rejected();


private:
    Ui::ProfileDetailDialog *ui;
    ProfileObject* newProfile;
    ProfileObject* dummyProfile;
};

#endif // ADDPROFILEDIALOG_H
