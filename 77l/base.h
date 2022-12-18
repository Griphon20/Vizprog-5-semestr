#ifndef BASE_H
#define BASE_H


#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>

#define PATH "D:\\QT\\77l\\database.db"

class DatabaseConnection
{
public:
    DatabaseConnection(const QString &path);
    void addRecord(const QString name, const int score);
    QList<QList<QString> >  getRecords();
private:
    QSqlDatabase database;

};

#endif // BASE_H
