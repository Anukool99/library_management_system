#ifndef EDITBOOK_H
#define EDITBOOK_H

#include <QDialog>

namespace Ui {
class EditBook;
}

class EditBook : public QDialog
{
    Q_OBJECT

public:
    explicit EditBook(QWidget *parent = nullptr);
    ~EditBook();

private:
    Ui::EditBook *ui;
};

#endif // EDITBOOK_H
