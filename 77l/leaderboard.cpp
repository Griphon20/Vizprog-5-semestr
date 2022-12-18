#include "leaderboard.h"
#include <iostream>
#include "ui_leaderboard.h"
#include <QList>
#include <QString>



extern QString text;
extern int scores;
LeaderBoard::LeaderBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LeaderBoard)
{
    ui->setupUi(this);



    DatabaseConnection database=DatabaseConnection(PATH);
    auto records = database.getRecords();
    for(int i = 0; i < records.size(); i++) {
        this->ui->tableWidget->insertRow(i);
        for(int j = 0; j < records[i].size(); j++) {
           // qDebug() << records[i][j];
            //records[i][1]=score2;
           this->ui->tableWidget->setItem(i, j, new QTableWidgetItem(records[i][j]));
           this->ui->tableWidget->sortItems(1,Qt::SortOrder(5));
        }
    }

    Graphics* scene = new Graphics;


    connect(scene, SIGNAL(death(long int)), this, SLOT(writeScore(long int)));

    //ui->tableWidget->setItem(0, 0,new QTableWidgetItem("text") );

}

void LeaderBoard::writeScore(long int score) {


    this->ui->tableWidget->insertRow(ai);
    this->ui->tableWidget->setItem(ai, 1,new QTableWidgetItem(QString::fromStdString(std::to_string(score)) ));
     this->ui->tableWidget->setItem(ai, 0,new QTableWidgetItem(text));
     this->ui->tableWidget->sortItems(1,Qt::SortOrder(score));
score=0;

     ai+=1;
    std::cout<<score;
}

LeaderBoard::~LeaderBoard()
{
    delete ui;
}
