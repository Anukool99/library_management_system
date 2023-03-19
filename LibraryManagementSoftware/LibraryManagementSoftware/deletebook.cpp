#include "deletebook.h"
#include "ui_deletebook.h"

DeleteBook::DeleteBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteBook)
{
    ui->setupUi(this);
}

DeleteBook::~DeleteBook()
{
    delete ui;
}
