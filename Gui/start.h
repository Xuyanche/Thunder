#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QDialog>
#include "ui_start.h"
#include"QPushButton"
#include "Qlabel"
#include"Qstring"
#include"QFont"

class start : public QDialog
{
	Q_OBJECT

public:
	start(QWidget *parent = Q_NULLPTR);

private:
	Ui::startClass ui;
	QLabel *tital = new QLabel(this);
	QPushButton*startbutton = new QPushButton(this);
	QPushButton*quitbutton = new QPushButton(this);
};
