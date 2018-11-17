#ifndef ADDSCHEDULEDTASKDIALOG_H
#define ADDSCHEDULEDTASKDIALOG_H

#include <QDialog>

namespace Ui {
class AddScheduledTaskDialog;
}

class AddScheduledTaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddScheduledTaskDialog(QWidget *parent = nullptr);
    ~AddScheduledTaskDialog();

private:
    Ui::AddScheduledTaskDialog *ui;
};

#endif // ADDSCHEDULEDTASKDIALOG_H
