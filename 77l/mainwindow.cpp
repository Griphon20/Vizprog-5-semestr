#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

#include "help.h"

QString text;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Космический шутер");
 /*   db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./testDb.db");
    if(db.open()){
        qDebug("open");
    }
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE LiderBoard(Name TEXT,Score INT);");
    query->exec("ADD TABLE (Name TEXT,Score INT);");
    model = new QSqlTableModel(this,db);
    model->setTable("LiderBoard");
    model->select();
    model->insertRow(model->rowCount());*/
    //this->ui->tableWidget->insertRow(0);

   // this->ui->tableWidget->setItem(0, 0,new QTableWidgetItem("text") );
   // ui->tableWidget->setStyleSheet("border: none;");
    //lider = new LeaderBoard;
    lider = new LeaderBoard;
    spravka = new help;
    Graphics* scene = new Graphics;
    ui->graphicsView->setFixedSize(820, 620);
    ui->graphicsView->setSceneRect(0, 0, 810, 610);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setStyleSheet("border: none;");
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->lineEdit->text();

  }


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
     spravka->show();
}


void MainWindow::on_pushButton_3_clicked()

{

text = ui->lineEdit->text();
if(text!=""){
inf = new info;
inf->show();}
if(text==""){
dialog = new Dialog;
dialog->show();}

}



void MainWindow::on_pushButton_5_clicked()
{

    lider->show();
}
