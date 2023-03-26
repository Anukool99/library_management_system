#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrManageBooks = new ManageBooks();
    ptrLogin = new Login();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrManageBooks;
    delete ptrLogin;
}



void MainWindow::on_ManageBooks_clicked()
{
    ptrManageBooks->show();
}


void MainWindow::on_pushButton_clicked()
{
    ptrLogin->show();
}

