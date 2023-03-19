#include "managebooks.h"
#include "ui_managebooks.h"

ManageBooks::ManageBooks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageBooks)
{
    ui->setupUi(this);
    ptrAddBook = new AddBook();
    ptrEditBook = new EditBook();
    ptrDeleteBook = new DeleteBook();
    ptrFindBook = new FindBook();
}

ManageBooks::~ManageBooks()
{
    delete ptrFindBook;
    delete ptrDeleteBook;
    delete ptrEditBook;
    delete ptrAddBook;
    delete ui;
}



void ManageBooks::on_AddBook_clicked()
{
    ptrAddBook->show();
}


void ManageBooks::on_EditBook_clicked()
{
    ptrEditBook->show();
}



void ManageBooks::on_DeleteBook_clicked()
{
    ptrDeleteBook->show();
}



void ManageBooks::on_FindBook_clicked()
{
    ptrFindBook->show();
}

