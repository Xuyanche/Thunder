#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"QPushButton"
#include "qlabel.h"
#include"qstring.h"
#include"QFont"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QLabel *tital=new QLabel(this);
    QPushButton*startbutton=new QPushButton(this);
    QPushButton*quitbutton=new QPushButton(this);
};

#endif // DIALOG_H
