#include "addbook.h"
#include "ui_addbook.h"

AddBook::AddBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBook)
{
    ui->setupUi(this);
}

AddBook::~AddBook()
{
    delete ui;
}

void AddBook::on_btnAddBook_clicked()
{
    QString BookISBN = ui->txtBookISBN->text();
    QString BookName = ui->txtBookName->text();
    QString BookAuthor = ui->txtBookAuthor->text();
    QString BookPublisher = ui->txtBookPublisher->text();

    qDebug() << "Book ISBN: " + BookISBN + " Book Name: " + BookName + " BookAuthor: " + BookAuthor + " BookPublisher " + BookPublisher;

    //Following code is for Database Connectivity.
    //First Define database object name
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    //Set database path
    database.setDatabaseName("H:/C++ QT/library_management_system/LibraryManagementSoftware/Database/LibraryManagement.db");

    //Check if file exists
    if(QFile::exists("H:/C++ QT/library_management_system/LibraryManagementSoftware/Database/LibraryManagement.db"))
        qDebug() << "Database File Exists";
    else
    {
        qDebug() << "Database File Does Not Exist";
        return;
    }

    //OPEN DATABASE FILE
    if(!database.open()) {
        qDebug() << "Error: Unable to open Database";
    }
    else {
        qDebug() <<"Database opened successfully";
    }

    /****************************************Adding SQL Query**************************/

    QSqlQuery query(database);

    query.prepare("insert into BookDetails (BookISBN, BookName, BookAuthor, BookPublisher) values('"+BookISBN + "','" +BookName + "','" + BookAuthor+ "','" +BookPublisher + "')");
    query.exec();
    qDebug() << "Last Error: " + query.lastError().text();

    database.close();


}

