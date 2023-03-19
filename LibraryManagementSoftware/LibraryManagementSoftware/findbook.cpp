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
}
