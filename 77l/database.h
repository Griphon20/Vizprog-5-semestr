#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QWidget>


namespace Ui {
class DataBase;
}

class DataBase : public QWidget
{
    Q_OBJECT

public:
    explicit DataBase(QWidget *parent = nullptr);
    ~DataBase();
private:
    Ui::DataBase *ui;
    QSqlDatabase db;
};

#endif // DATABASE_H
