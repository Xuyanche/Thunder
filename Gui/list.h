#pragma once

#include <QDialog>
#include"QPushButton"
namespace Ui { class list; };

class List : public QDialog
{
	Q_OBJECT

public:
	List(QWidget *parent = Q_NULLPTR);
	~List();
private
slots:
	void receivestart_fromlist();
	void on_backbutton_clicked_list();
signals:
	void showstart_fromlist();
private:
	Ui::list *ui;
	QPushButton*backbutton = new QPushButton(this);
};
