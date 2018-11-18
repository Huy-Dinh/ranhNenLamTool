#ifndef RANHNENLAMMAINWINDOW_H
#define RANHNENLAMMAINWINDOW_H

#include <QMainWindow>
#include <QModelIndexList>
#include "profilelistmodel.h"

#include <windows.h>

namespace Ui {
class ranhNenLamMainWindow;
}

class ranhNenLamMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ranhNenLamMainWindow(QWidget *parent = nullptr);
    ~ranhNenLamMainWindow();

private slots:
    void on_profileComboBox_currentIndexChanged(const QString &arg1);

    void on_profileAddButton_clicked();

    void on_profileRemoveButton_clicked();

    void on_profileEditButton_clicked();

    void on_profileActivateButton_clicked();

    void on_iconCategorizeButton_clicked();

    void on_iconGroupButton_clicked();

    void on_schedulerAddButton_clicked();

    void on_schedulerRemoveButton_clicked();

    void on_schedulerToggleButton_clicked();

    void on_scheduledTaskListView_indexesMoved(const QModelIndexList &indexes);

private:
    Ui::ranhNenLamMainWindow *ui;
    ProfileListModel *p_model;
};

struct LVITEM
{
   int mask;
   int iItem;
   int iSubItem;
   int state;
   int stateMask;
   intptr_t pszText; // string
   int cchTextMax;
   int iImage;
   intptr_t lParam;
   int iIndent;
   int iGroupId;
   int cColumns;
   intptr_t puColumns;
};

#endif // RANHNENLAMMAINWINDOW_H
