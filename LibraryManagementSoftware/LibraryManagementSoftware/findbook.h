#ifndef FINDBOOK_H
#define FINDBOOK_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class FindBook;
}

class FindBook : public QDialog
{
    Q_OBJECT

public:
    explicit FindBook(QWidget *parent = nullptr);
    ~FindBook();

private slots:
    void on_btnFind_clicked();

private:
    Ui::FindBook *ui;
    QSqlQueryModel *model;
};

#endif // FINDBOOK_H
