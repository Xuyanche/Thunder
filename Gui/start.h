#pragma once

#include <QDialog>
#include"QPushButton"
#include "qlabel.h"
#include"qstring.h"
#include"QFont"
namespace Ui {
class startClass;
}

class Dialog : public QDialog
{
	Q_OBJECT

public:
	explicit Dialog(QWidget *parent = 0);
	~Dialog();
	private
slots:
	void receive();
	void on_listbutton_clicked();
	void on_startbutton_clicked();
	void on_peoplebutton_clicked();
signals:
	void showlist();
signals:
	void showgame1();
signals:
	void showpeople();
private:
	Ui::startClass *ui;
};
