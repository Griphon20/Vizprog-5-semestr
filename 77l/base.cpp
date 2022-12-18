#include "base.h"

#include <QDebug>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>



DatabaseConnection::DatabaseConnection(const QString &path)
{
    this->database = QSqlDatabase::addDatabase("QSQLITE");
    this->database.setDatabaseName(path);
    if (!this->database.open()) {
        qDebug() << "ERROR";
    } else {
        qDebug() << "WORKING!";
    }
}


void DatabaseConnection::addRecord(const QString name, const int score) {
    QSqlQuery query;
    query.prepare("INSERT INTO leaderboard (name, score) VALUES (:name, :score)");
    query.bindValue(":name", name);
    query.bindValue(":score", score);
    if (query.exec()) {
        qDebug() << "WORKING!";
    } else {
        qDebug() << "NOT WORKING(";
    }
}


QList<QList<QString> > DatabaseConnection::getRecords() {
    QSqlQuery query(this->database);
    QList<QList<QString> > records;
    if (query.exec("SELECT name, score FROM leaderboard ORDER BY score")) {
        while(query.next()) {
            QList<QString> tmp;
            QString name = query.value(0).toString();
            QString score = query.value(1).toString();
            tmp.append(name);
            tmp.append(score);
            records.append(tmp);
        }
    } else {
        qDebug() << "FAIL";
        qDebug() << query.lastError();
    }

    return records;
}
