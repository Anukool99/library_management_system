#ifndef LOGIN_H
#define LOGIN_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    QSqlDatabase mydb;
};
#endif // LOGIN_H
