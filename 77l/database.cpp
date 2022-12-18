/*#include "database.h"
#include "ui_database.h"

DataBase::DataBase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataBase)
ui->setupUi(this);
db = QSqlDatabase::addDatabase("QSQLITE");
db.setDatabaseName("./testDb.db");{



if(db.open()){


    qDebug("open");
}
}


DataBase::~DataBase()
{
    delete ui;
}

*/
