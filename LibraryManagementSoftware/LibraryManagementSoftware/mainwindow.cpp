#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrManageBooks = new ManageBooks();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrManageBooks;
}



void MainWindow::on_ManageBooks_clicked()
{
    ptrManageBooks->show();
}

