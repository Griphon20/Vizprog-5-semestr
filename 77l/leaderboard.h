#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include "graphics_rylskiy.h"

#include <QDialog>
#include <QSqlQuery>
#include <QSqlTableModel>
#include "base.h"

namespace Ui {
class LeaderBoard;
}

class LeaderBoard : public QDialog
{
    Q_OBJECT

public:
    int score2=0;
    int ai=0,aj=0;
    explicit LeaderBoard(QWidget *parent = nullptr);
    ~LeaderBoard();

private:

    Ui::LeaderBoard *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;

private slots:
    void writeScore(long int);
};

#endif // LEADERBOARD_H
