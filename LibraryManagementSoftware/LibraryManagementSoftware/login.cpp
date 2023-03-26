#include "login.h"
#include "ui_login.h"
#include<QDebug>

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

}



void Login::on_pushButton_clicked()
{
    QString username, password;
    //1. EDIT OBJECT NAMES
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();


    //Following code is for Database Connectivity.
    //First Define database object name
    QSqlDatabase mydb= QSqlDatabase::addDatabase("QSQLITE");
    //set database path
    mydb.setDatabaseName("H:/C++ QT/library_management_system/pesonal_Info.db");


    //Check if file exists
    if(QFile::exists("H:/C++ QT/library_management_system/LibraryManagementSoftware/Database/personal_Info.db"))
        qDebug() << "Database File Exists";
    else
    {
        qDebug() << "Database File Does Not Exist";
        return;
    }


    if(!mydb.open())
    {
         qDebug() << "Error: Unable to open Database";

    }
    else
    {
       qDebug() <<"Database opened successfully";
    }

    /****************************************Adding SQL Query**************************/

    QSqlQuery qry;
    qry.prepare("SELECT * FROM personalInfo WHERE username = :username AND password = :password");
    qry.bindValue(":username", username);
    qry.bindValue(":password", password);

    //3. EXPLANATION OF THE WORKING OF THE CODE
    if (qry.exec()) {
        int count = 0;
        while (qry.next()) {
            count++;
        }
        if (count == 1) {
            ui->label->setText("Username and password is correct");
        }
        else if (count > 1) {
            ui->label->setText("Please choose another username");
        }
        else {
            ui->label->setText("Username and password is incorrect");
        }
    }
    else {
        ui->label->setText("Failed to execute query");
        qDebug() << qry.lastError().text();
    }
}






Login::~Login()
{
    delete ui;
}



