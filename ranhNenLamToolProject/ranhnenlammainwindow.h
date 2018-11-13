#ifndef RANHNENLAMMAINWINDOW_H
#define RANHNENLAMMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class ranhNenLamMainWindow;
}

class ranhNenLamMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ranhNenLamMainWindow(QWidget *parent = nullptr);
    ~ranhNenLamMainWindow();

private:
    Ui::ranhNenLamMainWindow *ui;
};

#endif // RANHNENLAMMAINWINDOW_H
