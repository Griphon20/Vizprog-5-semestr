#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "leaderboard.h"
#include "help.h"
#include "graphics_rylskiy.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>

#include <QTableWidget>
#include <QDataWidgetMapper>
#include <QLineEdit>
#include <QDialog>
#include <QTime>
#include <QTimer>
#include <QString>
#include "info.h"
#include "dialog.h"

namespace Ui {
class MainWindow;
}





class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    bool is_changed;
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    QLineEdit *line;
    LeaderBoard * lider;
    help * spravka;
    info * inf;
    Dialog * dialog;

};


#endif // MAINWINDOW_H
