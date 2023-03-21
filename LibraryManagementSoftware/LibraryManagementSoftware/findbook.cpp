#include "findbook.h"
#include "ui_findbook.h"

FindBook::FindBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindBook)
{
    ui->setupUi(this);
}

FindBook::~FindBook()
{
    delete ui;
    //Ensure deletion of model pointer
    delete model;
}

void FindBook::on_btnFind_clicked()
{
    QString BookName = ui->txtBookName->text();
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

    query.prepare("select * from BookDetails where BookName like '%" +BookName + "%'");
    query.exec();
    qDebug() << "Last Query: " + query.lastQuery();
    qDebug() << "Last Error: " + query.lastError().text();

    if (model==NULL) {
        model = new QSqlQueryModel();
    }
    model -> setQuery(std::move(query));
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,200);
    ui->tableView->setColumnWidth(1,200);
    ui->tableView->setColumnWidth(2,200);


    database.close();

}

