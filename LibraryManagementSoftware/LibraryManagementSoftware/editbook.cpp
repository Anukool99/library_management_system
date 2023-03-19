#include "editbook.h"
#include "ui_editbook.h"

EditBook::EditBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditBook)
{
    ui->setupUi(this);
}

EditBook::~EditBook()
{
    delete ui;
}
