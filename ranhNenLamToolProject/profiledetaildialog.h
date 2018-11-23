#ifndef PROFILEDETAILDIALOG_H
#define PROFILEDETAILDIALOG_H

#include <QDialog>

namespace Ui {
class ProfileDetailDialog;
}

class ProfileDetailDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileDetailDialog(QWidget *parent = nullptr);
    ~ProfileDetailDialog();

private slots:
    //void on_Dialog_accepted();
    //void on_Dialog_rejected();

private:
    Ui::ProfileDetailDialog *ui;

};

#endif // ADDPROFILEDIALOG_H
