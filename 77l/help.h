#ifndef HELP_H
#define HELP_H

#include <QWidget>
#include <QTextBrowser>
#include <qtextbrowser.h>
#include <QAbstractButton>
#include <QDebug>


#include <QDir>
#include <qapplication.h>
#include <qlayout.h>
#include <qpushbutton.h>

namespace Ui {
class help;
}

class help : public QWidget
{
    Q_OBJECT

public:
    explicit help(QWidget *parent = 0);
    ~help();

private slots:
      void updateCaption();

      void showPage();


      void on_pushButton_clicked();

private:
    Ui::help *ui;
};

#endif // HELP_H
