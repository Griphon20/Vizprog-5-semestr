#include "liderboard.h"
#include <QList>
#include <QString>
#include "ui_dialog.h"

LiderBoard::LiderBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LiderBoard)
{
    ui->setupUi(this);
    this->ui->tableWidget->insertRow(0);

    this->ui->tableWidget->setItem(0, 0,new QTableWidgetItem("text") );
}

LiderBoard::~LiderBoard()
{
    delete ui;
}
