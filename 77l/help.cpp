#include "help.h"
#include "ui_help.h"

help::help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);

    this->setWindowTitle("Справка");

    connect(ui->pushButtonAbout, &QPushButton::clicked, this, &help::updateCaption);
    connect(ui->pushButtonRules, &QPushButton::clicked, this, &help::updateCaption);
    connect(ui->pushButtonGoal, &QPushButton::clicked, this, &help::updateCaption);



}

void help::showPage()
{
qDebug() << ":)" << endl;
}

void help::updateCaption()
{
    QString text;

    auto sender = this->sender();



    ui->pushButtonAbout->setChecked(false);
    ui->pushButtonGoal->setChecked(false);
    ui->pushButtonRules->setChecked(false);


    if (sender == ui->pushButtonAbout){
        text="about.txt";
        ui->pushButtonAbout->setChecked(true);
    }else if (sender == ui->pushButtonGoal){
        text="settings.txt";
        ui->pushButtonGoal->setChecked(true);
    }else if (sender == ui->pushButtonRules){
        text="notes.txt";
        ui->pushButtonRules->setChecked(true);
    }
    QString path = QDir::currentPath();

    QFile temp(path +"/media/" + text);


    if(!temp.open(QIODevice::ReadWrite))
    {
        qDebug() << "Ошибка открытия";
    }
    QTextStream in(&temp);
    in.setCodec("UTF-8");
    QString fileText = in.readAll();

    ui->textBrowser->setHtml(fileText);


}


help::~help()
{
    delete ui;
}

void help::on_pushButton_clicked()
{
   QWidget::close();
}
