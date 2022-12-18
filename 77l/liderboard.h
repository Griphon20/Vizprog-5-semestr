#ifndef LIDERBOARD_H
#define LIDERBOARD_H

#include <QDialog>

namespace Ui {
class LiderBoard;
}

class LiderBoard : public QDialog
{
    Q_OBJECT

public:
    explicit LiderBoard(QWidget *parent = nullptr);
    ~LiderBoard();

private:
    Ui::LiderBoard *ui;
};

#endif // LIDERBOARD_H
