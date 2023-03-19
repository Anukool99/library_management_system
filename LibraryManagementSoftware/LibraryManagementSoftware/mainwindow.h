#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <managebooks.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ManageBooks_clicked();

private:
    Ui::MainWindow *ui;
    ManageBooks * ptrManageBooks;

};
#endif // MAINWINDOW_H
